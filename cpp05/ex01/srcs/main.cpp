/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:32:21 by npremont          #+#    #+#             */
/*   Updated: 2024/12/13 13:58:39 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(void)
{
    Bureaucrat* frederic;
    Bureaucrat* pota;

    try 
    {
        frederic = new Bureaucrat("Fred", 52);
        std::cout << *frederic;
        try
        {
            frederic->incrementGrade(158);
            std::cout << frederic->getName() << " incremented" << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException& e)
        {

            std::cout << "Error on " << frederic->getName() << " incrementation: " << e.what() << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException& e)
        {
            std::cout << "Error on " << frederic->getName() << " decrementation: " << e.what() << std::endl;
        }
        delete frederic;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        pota = new Bureaucrat("Pota", 152);
        std::cout << *pota;
        delete pota;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        pota = new Bureaucrat("Pota", 0);
        std::cout << *pota;
        delete pota;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}