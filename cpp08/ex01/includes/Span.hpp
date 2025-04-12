/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:52:49 by npremont          #+#    #+#             */
/*   Updated: 2025/04/07 16:46:24 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <limits>

class Span {
    private:
        unsigned int        n;
        unsigned int        array_size;
        std::vector<int>    array_numbers;
    
    public:
        Span(unsigned int value);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void    addNumber(int number);
        void    addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int     shortestSpan();
        int     longestSpan();
};

#endif