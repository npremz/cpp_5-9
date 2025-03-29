/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:12:52 by npremont          #+#    #+#             */
/*   Updated: 2025/03/26 13:15:52 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConvertor.hpp"

int main(int ac, char *av[]) {
    if (ac != 2)
        return (std::cout << "This program takes only one parameter." << std::endl, 0);
    std::string arg(av[1]);
    ScalarConvertor::convert(arg);
}