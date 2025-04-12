/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:57:34 by npremont          #+#    #+#             */
/*   Updated: 2025/04/12 12:34:11 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span(unsigned int n) : n(n)
{}

Span::Span(const Span& other)
{
    this->n = other.n;
    this->array_size = other.array_size;
    this->array_numbers = other.array_numbers;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->n = other.n;
        this->array_size = other.array_size;
        this->array_numbers = other.array_numbers;
    }
    return (*this);
}

Span::~Span()
{}

void Span::addNumber(int number)
{
    if (this->array_numbers.size() >= this->n)
        throw std::out_of_range("No space left in array.\n");
    this->array_numbers.push_back(number);
}

int Span::shortestSpan()
{
    if (this->array_numbers.empty() || this->array_numbers.size() == 1)
        throw std::out_of_range("Array has less than two value\n");

    std::vector<int> tmp = this->array_numbers;
    std::sort(tmp.begin(), tmp.end());
    
    int res = std::numeric_limits<int>::max();
    for (size_t i = 0; i < this->array_numbers.size() - 1; ++i)
    {
        int tmp_res = tmp[i + 1] - tmp[i];
        if (tmp_res < res)
            res = tmp_res;
    }
    return (res);
}

int Span::longestSpan()
{
    if (this->array_numbers.empty() || this->array_numbers.size() == 1)
        throw std::out_of_range("Array has less than two value\n");

    std::vector<int>::const_iterator max_value = std::max_element(array_numbers.begin(), array_numbers.end());
    std::vector<int>::const_iterator min_value = std::min_element(array_numbers.begin(), array_numbers.end());
    return (*max_value - *min_value);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->array_numbers.size() + std::distance(begin, end) > this->n)
        throw std::out_of_range("The range cannot fit in the span.");
    this->array_numbers.insert(this->array_numbers.begin(), begin, end);
}