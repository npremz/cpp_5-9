/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:07:33 by npremont          #+#    #+#             */
/*   Updated: 2025/05/02 01:07:33 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
        std::cerr << "Error: could not open file." << std::endl;

    (void)av;

    try
    {
        Evaluation ev;
        std::string input(av[1]);
        ev.evaluate(input);
    } 
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return (0);
}