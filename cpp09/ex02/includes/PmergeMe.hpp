/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:56:43 by npremont          #+#    #+#             */
/*   Updated: 2025/04/27 19:23:51 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <deque>
# include <algorithm>
# include <cmath>
# include <sys/time.h>
# include <iomanip>

# define DEBUG 0

template <typename C>
class PmergeMe {
    private:
        C               container;
         
    public:
        PmergeMe()
        {
            throw std::runtime_error("no argument");
        }

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
                    throw std::runtime_error("duplicated values as argument");
                container.push_back(n);
            }
        }
       
        ~PmergeMe()
        {}

        C   getContainer()
        {
            return (this->container);
        }
        
        void printC()
        {
            typename C::iterator start;
            for (start = container.begin(); start != container.end(); start++)
            {
                std::cout << *start;
                std::cout << " ";
            }
            std::cout << std::endl;
        }

        int jacobsthal(int k)
        {
            return ((pow(2, k + 1) + pow(-1, k)) / 3);
        }

        void insert(C& main, C& pend, C&rest, int order)
        {
            if (pend.empty())
                return;

            C main_upper;
            C pend_upper;
            
            for (typename C::iterator it = main.begin() + order - 1; it < main.end(); it += order)
            {
                main_upper.push_back(*it);
            }

            for (typename C::iterator it = pend.begin() + order - 1; it < pend.end(); it += order)
            {
                pend_upper.push_back(*it);
            }

            int k = 2;
            while (!pend_upper.empty())
            {
                int jc = jacobsthal(k);
                unsigned int idx = jc - 1;
                if (idx > pend_upper.size())
                    idx = pend_upper.size();
                while (idx)
                {
                    typename C::iterator ip = std::upper_bound(main_upper.begin(), main_upper.end(), *(pend_upper.begin() + idx - 1));
                    int ref = *ip;

                    main_upper.insert(ip, *(pend_upper.begin() + (idx - 1)));
                    pend_upper.erase(pend_upper.begin() + idx - 1);

                    typename C::iterator it = std::find(main_upper.begin(), main_upper.end(), ref);
                    int position = std::distance(main_upper.begin(), it);
                    int count = 0;
                    for (typename C::iterator it = pend.begin() + (idx - 1) * order; it < pend.begin() + (idx * order); it++)
                    {
                        main.insert(main.begin() + ((position - 1) * order) + count, *it);
                        count++;
                    }
                    pend.erase(pend.begin() + (idx - 1) * order, pend.begin() + (idx * order));
                    idx--;
                }
                k++;
            }
            
            main.insert(main.end(), rest.begin(), rest.end());
            rest.clear();

            this->container = main;
        }

        void sort(int order = 1)
        {
            size_t unit_count = this->container.size() / order;
            if (unit_count < 2)
                return;

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

            if (!pend.empty())
                insert(main, pend, rest, order);
        }
};


#endif
