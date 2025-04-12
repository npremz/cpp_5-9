/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:11:03 by npremont          #+#    #+#             */
/*   Updated: 2025/04/12 15:24:58 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <vector>

int main(void)
{
    std::vector<int> values;

    values.push_back(10);
    values.push_back(20);
    values.push_back(30);
    values.push_back(40);
    values.push_back(50);

    try
    {
        std::vector<int>::const_iterator r = easyfind(values, 30);
        std::cout << *r << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::const_iterator r = easyfind(values, 70);
        std::cout << *r << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}