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

void    print_duration(struct timeval debut, struct timeval fin, int size, std::string type)
{
    long seconds = fin.tv_sec - debut.tv_sec;
    long microseconds = fin.tv_usec - debut.tv_usec;
    
    if (microseconds < 0) {
        microseconds += 1000000;
        seconds--;
    }
    
    double total_microseconds = seconds * 1000000 + microseconds;
    
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " 
              << size 
              << " elements with std::" 
              << type << " " 
              << total_microseconds / 1000000 << " us" << std::endl;
}

int main(int ac, char* av[])
{
    if (ac < 2)
    {
        std::cerr << "This program needs integers as arguments to run." << std::endl;
        return (1);
    }

    try 
    {
        PmergeMe<std::vector<int> > vectorTest(av);
        PmergeMe<std::deque<int> > dequeTest(av);

        struct timeval debut_vector, fin_vector;
        struct timeval debut_deque, fin_deque;

        std::cout << "Before: ";
        vectorTest.printC();

        gettimeofday(&debut_vector, NULL);
        vectorTest.sort();
        gettimeofday(&fin_vector, NULL);
        
        gettimeofday(&debut_deque, NULL);
        dequeTest.sort();
        gettimeofday(&fin_deque, NULL);

        std::cout << "After: ";
        vectorTest.printC();

        print_duration(debut_vector, fin_vector , vectorTest.getContainer().size(), "vector");
        print_duration(debut_deque, fin_deque , dequeTest.getContainer().size(), "deque");
    }
    catch( const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return (0);

}
