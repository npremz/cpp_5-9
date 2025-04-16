/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:56:43 by npremont          #+#    #+#             */
/*   Updated: 2025/04/16 14:44:51 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <algorithm>
# include <cmath>

# define DEBUG 1 

template <typename C>
class PmergeMe {
    private:
        C container;
         
    public:
        PmergeMe(char **av)
        {
            std::string sequence_str;
            for (size_t i = 1; av[i]; ++i)
            {
                sequence_str += av[i];
                if (av[i])
                    sequence_str += " ";
            }
            std::istringstream      sequence_stream(sequence_str);
            typename C::value_type  n;
            while (sequence_stream >> n)
            {
                if (std::find(container.begin(), container.end(), n) != container.end())
                    throw std::runtime_error("duplicated values\n");
                container.push_back(n);
            }
        }
       
        ~PmergeMe()
        {}
        
        void printC(int order = 1)
        {
            typename C::iterator start;
            int i = 0;

            std::cout << "order " << order << ": ";
            for (start = container.begin(); start != container.end(); start++)
            {
                if (i % order == 0)
                    std::cout << "[";
                std::cout << *start;
                if ((i + 1) % order == 0)
                    std::cout << "]";
                std::cout << " ";
                ++i;
            }
            std::cout << std::endl;
        }

        int jacobsthal(int k)
        {
            return ((pow(2, k + 1) + pow(-1, k)) / 3);
        }

        void insert(C& main, C& pend, C&rest)
        {
            (void)rest;
            typename C::iterator end;

            if (pend.size() == 1)
            {
                end = std::upper_bound(main.begin(), main.end(), *pend.begin());
                main.insert(end, *pend.begin());
            }

            if (pend.size() > 1)
            {
                size_t  jc = 3;
                size_t  idx = 0;
                size_t  decreased = 0;
                size_t  count = 0;

                while (!pend.empty())
                {
                    idx = jacobsthal(jc) - jacobsthal(jc - 1);

                    if (idx > pend.size())
                        idx = pend.size();

                    decreased = 0;

                    while (idx)
                    {
                        if (jacobsthal(jc + count) - decreased <= main.size())
                            end = main.begin() + jacobsthal(jc + count) - decreased;
                        else
                            end = main.end();
                        end = std::upper_bound(main.begin(), end, *(pend.begin() + idx - 1));
                        main.insert(end, *(pend.begin() + idx - 1));
                        pend.erase(pend.begin() + idx - 1);

                        idx--;
                        decreased++;
                        count++;
                    }
                    jc++;
                }

                for (typename C::iterator it_rest = rest.begin(); !rest.empty();)
                {
                    end = std::upper_bound(main.begin(), main.end(), *it_rest);
                    main.insert(end, *(it_rest));
                    rest.erase(it_rest);
                }

                this->container = main;
                
            }
        }

        void sort(int order = 1)
        {
            size_t unit_count = this->container.size() / order;
            if (unit_count < 2)
                return;
            
            if (DEBUG)
                this->printC(order);

            int                     is_count_odd = unit_count % 2 == 1;
            typename C::iterator    start = this->container.begin();
            typename C::iterator    end = start + ((unit_count * order) - (is_count_odd * order));
            
            for (typename C::iterator it = start; it < end; it += order * 2)
            {
                if (*(it + (order - 1)) > *(it + (order * 2 - 1)))
                {
                    for (int i = 0; i < order; ++i)
                    {
                        std::swap(*(it + i), *(it + i + order));
                    }
                }
            }

            if (DEBUG)
            {
                this->printC(order);
                std::cout << std::endl;
            }

            sort(order * 2);

            C main;
            C pend;
            C rest;

            for (typename C::iterator it = start; it < end; it++)
            {
                if (it < (start + order * 2))
                {
                    main.push_back(*it);
                    continue;
                }
                for (typename C::iterator it_start = it; it_start < it + order; it_start++)
                {
                    pend.push_back(*it_start);
                    main.push_back(*(it_start + order));
                }
                it += order * 2 - 1;
            }

            if (is_count_odd)
            {
                for (typename C::iterator odd_start = end; odd_start < end + order; odd_start++)
                {
                    pend.push_back(*odd_start);
                }
            }

            rest.insert(rest.begin(), end + (order * is_count_odd), this->container.end());

            if (DEBUG)
            {
                std::cout << "order " << order << ": ";
                std::cout << "main: [";
                for (typename C::iterator main_start = main.begin(); main_start < main.end(); main_start++)
                {
                    std::cout << *main_start << " ";
                }
                std::cout << "] ";
                std::cout << "pend: [";
                for (typename C::iterator pend_start = pend.begin(); pend_start < pend.end(); pend_start++)
                {
                    std::cout << *pend_start << " ";
                }
                std::cout << "] ";
                std::cout << "rest: [";
                for (typename C::iterator rest_start = rest.begin(); rest_start < rest.end(); rest_start++)
                {
                    std::cout << *rest_start << " ";
                }
                std::cout << "]" << std::endl;
            }

            if (!pend.empty())
                insert(main, pend, rest);

            if (DEBUG)
            {
                std::cout << "order " << order << ": ";
                std::cout << "main: [";
                for (typename C::iterator main_start = main.begin(); main_start < main.end(); main_start++)
                {
                    std::cout << *main_start << " ";
                }
                std::cout << "] ";
                std::cout << "pend: [";
                for (typename C::iterator pend_start = pend.begin(); pend_start < pend.end(); pend_start++)
                {
                    std::cout << *pend_start << " ";
                }
                std::cout << "] ";
                std::cout << "rest: [";
                for (typename C::iterator rest_start = rest.begin(); rest_start < rest.end(); rest_start++)
                {
                    std::cout << *rest_start << " ";
                }
                std::cout << "]" << std::endl << std::endl;
            }
        }
};


#endif
