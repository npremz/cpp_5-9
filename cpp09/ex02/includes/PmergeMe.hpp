/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:56:43 by npremont          #+#    #+#             */
/*   Updated: 2025/04/13 14:15:02 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <vector>

template <typename C>
class PmergeMe {
    private:
        C container;
         
    public:
        PmergeMe(char **av)
        {
            std::string sequence_str;
            for (size_t i = 0; av[i]; ++i)
            {
                sequence_str += av[i];
                if (av[i])
                    sequence_str += " ";
            }
            std::istringstream  sequence_stream(sequence_str);
            C::value_type       n;
            while (sequence_stream >> n)
            {
                
                C.push_back(n);
            }
        }
       
        ~PmergeMe()
        {}
        
};


#endif