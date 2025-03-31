/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:12:52 by npremont          #+#    #+#             */
/*   Updated: 2025/03/31 12:54:05 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/templates.hpp"
#include <iostream>

int main()
{
    std::cout << "-- string test --" << std::endl;

    std::string s1 = "oue oue";
    std::string s2 = "waf waf";
    
    std::cout << "s1 value: " << s1 << ", s2 value: " << s2 << std::endl;
    std::cout << "max: " << ::max(s1, s2) << std::endl;
    std::cout << "min: " << ::min(s1, s2) << std::endl;

    ::swap(s1, s2);
    std::cout << "s1 value: " << s1 << ", s2 value: " << s2 << std::endl;

    std::cout << "-- int test --" << std::endl;

    int i1 = 19;
    int i2 = 42;

    std::cout << "i1 value: " << i1 << ", i2 value: " << i2 << std::endl;

    std::cout << "max: " << ::max(i1, i2) << std::endl;
    std::cout << "min: " << ::min(i1, i2) << std::endl;

    ::swap(i1, i2);
    std::cout << "i1 value: " << i1 << ", i2 value: " << i2 << std::endl;


}