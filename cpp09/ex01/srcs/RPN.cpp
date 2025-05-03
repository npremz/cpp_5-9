/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:16:13 by npremont          #+#    #+#             */
/*   Updated: 2025/05/03 11:16:13 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN() 
{}

RPN::RPN(const RPN& other)
{
    s = other.s;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        s = other.s;
    }
    return (*this);
}

RPN::~RPN()
{}

std::stack<int> RPN::getStack()
{
    return (s);
}

void    RPN::execute(std::string str)
{
    std::stringstream   ss(str);
    std::string         buf;

    ss >> buf;
    if (!std::isdigit(buf[0]) || buf.size() != 1)
        throw std::runtime_error("invalid input.");
    s.push(atoi(buf.c_str()));

    ss >> buf;
    if (!std::isdigit(buf[0]) || buf.size() != 1)
        throw std::runtime_error("invalid input.");
    s.push(atoi(buf.c_str()));

    while (ss >> buf)
    {
        if (buf.size() != 1)
            throw std::runtime_error("invalid input.");
        
        if (std::isdigit(buf[0]))
            s.push(atoi(buf.c_str()));
        else if (buf[0] == '+' || buf[0] == '-' || buf[0] == '*' || buf[0] == '/')
        {
            if (s.size() < 2)
                throw std::runtime_error("invalid input.");
            int a, b, res;
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();

            switch (buf[0])
            {
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = a - b;
                    break;
                case '*':
                    res = a * b;
                    break;
                case '/':
                    res = a / b;
                    break;
            }
            s.push(res);
        }
        else
            throw std::runtime_error("invalid input.");
    }
}