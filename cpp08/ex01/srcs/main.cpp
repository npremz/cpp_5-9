/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:52:37 by npremont          #+#    #+#             */
/*   Updated: 2025/04/12 12:33:47 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main()
{
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    
    std::cout << std::endl << "====" << std::endl << std::endl;

    try 
    {
        Span sp_multi(5);
        std::vector<int> vec;
        vec.push_back(6);
        vec.push_back(3);
        vec.push_back(17);
        vec.push_back(9);
        vec.push_back(11);
        sp_multi.addNumbers(vec.begin(), vec.end());
        std::cout << sp_multi.shortestSpan() << std::endl;
        std::cout << sp_multi.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "====" << std::endl << std::endl;

    try 
    {
        Span sp_multi(5);
        std::vector<int> vec;
        vec.push_back(6);
        vec.push_back(3);
        vec.push_back(17);
        vec.push_back(9);
        vec.push_back(11);
        vec.push_back(25);
        sp_multi.addNumbers(vec.begin(), vec.end());
        std::cout << sp_multi.shortestSpan() << std::endl;
        std::cout << sp_multi.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "====" << std::endl << std::endl;

    {
        Span sp = Span(0);

        try
        {
            sp.addNumber(12);
        }
        catch (const std::exception& e)
        {
            std::cout << e.what();
        }
    }
    
    std::cout << std::endl << "====" << std::endl << std::endl;

    {
        Span sp = Span(0);

        try
        {
            sp.shortestSpan();
        }
        catch (const std::exception& e)
        {
            std::cout << e.what();
        }
    }
    
    return 0;
}