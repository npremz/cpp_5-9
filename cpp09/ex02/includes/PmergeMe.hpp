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

        void insert(C& main, C& pend, C&rest, int order)
        {
            // si pend vide, on sort

            (void)main;
            (void)pend;
            (void)rest;
            (void)order;

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

            std::cout << "\t main_u: ";
            for (typename C::iterator it = main_upper.begin(); it < main_upper.end(); it++)
            {
                std::cout << *it << ", ";
            }

            std::cout << "\t pend_u: ";
            for (typename C::iterator it = pend_upper.begin(); it < pend_upper.end(); it++)
            {
                std::cout << *it << ", ";
            }

            // Definir la valeur jacobsthal
            int k = 2;
            while (!pend_upper.empty())
            {
                int jc = jacobsthal(k);
                unsigned int idx = jc - 1;
                
                std::cout << "\n\tk: " << k << ", jc: " << jc << std::endl;

                std::cout << "\t main: ";

                for (typename C::iterator it = main.begin(); it < main.end(); it++)
                {
                    std::cout << *it << ", ";
                }

                std::cout << "\n\t pend: ";

                for (typename C::iterator it = pend.begin(); it < pend.end(); it++)
                {
                    std::cout << *it << ", ";
                }
                std::cout << std::endl;

                if (idx > pend_upper.size())
                    idx = pend_upper.size();
                typename C::iterator end = main_upper.end();
                while (idx)
                {
                    if (main_upper.size() < idx * 2 - 1)
                        end = main_upper.begin() + idx * 2 - 1;
                    std::cout << "value to upper:" << *(pend_upper.begin() + idx - 1) << std::endl;
                    std::cout << "value found: " << *std::upper_bound(main_upper.begin(), end, *(pend_upper.begin() + idx - 1)) << std::endl;

                    typename C::iterator ip = std::upper_bound(main_upper.begin(), end, *(pend_upper.begin() + idx - 1));
                    std::cout << "ip: " << *ip << std::endl;
                    main_upper.insert(ip, *(pend_upper.begin() + (idx - 1)));
                    pend_upper.erase(pend_upper.begin() + idx - 1);
                    idx--;
                }
                k++;
            }
            
            main.insert(main.end(), rest.begin(), rest.end());
            rest.clear();

            this->container = main;

            // Inserer en reverse order les [b] a partir du [b] jc
            // comparer jusqu'au [a] correspondant si pas present, comparer avec tout
            // comparer l'element le plus grand de la paire (le dernier) avec ceux des autres paires

            // ajouter le reste a la fin de la boucle



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
                insert(main, pend, rest, order);

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
