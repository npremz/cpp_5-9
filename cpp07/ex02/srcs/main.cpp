/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:22:54 by npremont          #+#    #+#             */
/*   Updated: 2025/04/06 13:14:16 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"



int main(void)
{
    Array<int> int_a(5);
    int_a[0] = 10;
    int_a[1] = 20;
    int_a[2] = 30;
    int_a[3] = 40;
    int_a[4] = 50;

    Array<int> int_a_copy(0);
    try
    {
        int_a_copy[2] = 0;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    int_a_copy = int_a;
    int_a_copy[2] = 70;

    int_a.print();
    std::cout << std::endl;
    int_a_copy.print();
    std::cout << std::endl;
    int_a.print();
}