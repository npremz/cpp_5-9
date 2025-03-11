/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:31:46 by npremont          #+#    #+#             */
/*   Updated: 2025/03/11 13:16:35 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat* pota = new Bureaucrat("Pota", 12);
        std::cout << *pota;
        delete pota;
    } catch (const std::exception& e1) {
        std::cout << e1.what() << std::endl;
    }

    try {
        Bureaucrat* pota = new Bureaucrat("Pota", 210);
        std::cout << *pota;
        delete pota;
    } catch (const std::exception& e1) {
        std::cout << e1.what() << std::endl;
    }

    try {
        Bureaucrat* pota = new Bureaucrat("Pota", 0);
        std::cout << *pota;
        delete pota;
    } catch (const std::exception& e1) {
        std::cout << e1.what() << std::endl;
    }

    try {
        Bureaucrat* pota = new Bureaucrat("Pota", 131);
        std::cout << *pota;
        pota->decrementGrade();
        std::cout << *pota;
        delete pota;
    } catch (const std::exception& e1) {
        std::cout << e1.what() << std::endl;
    }

    try {
        Bureaucrat* pota = new Bureaucrat("Pota", 150);
        std::cout << *pota;
        pota->decrementGrade();
        std::cout << *pota; 
        delete pota;
    } catch (const std::exception& e1) {
        std::cout << e1.what() << std::endl;
    }

    try {
        Bureaucrat* pota = new Bureaucrat("Pota", 1);
        std::cout << *pota;
        pota->incrementGrade();
        std::cout << *pota;
        delete pota;
    } catch (const std::exception& e1) {
        std::cout << e1.what() << std::endl;
    }
}