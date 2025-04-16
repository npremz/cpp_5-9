/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:11:21 by npremont          #+#    #+#             */
/*   Updated: 2025/04/16 11:00:07 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int ac, char* av[])
{
    (void)ac;
    PmergeMe<std::vector<int> > test(av);
    try 
    {
        test.sort();
    }
    catch( const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

}
