/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:31:02 by npremont          #+#    #+#             */
/*   Updated: 2025/05/02 12:31:02 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int ac, char* av[])
{
    if (ac != 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }

    try
    {
        RPN rpn;

        rpn.execute(av[1]);
        std::cout << rpn.getStack().top() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
    }


}