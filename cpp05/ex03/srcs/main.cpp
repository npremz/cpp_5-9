/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:32:21 by npremont          #+#    #+#             */
/*   Updated: 2025/04/14 10:48:23 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"


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

    std::cout << "=====================" << std::endl;

    try
    {
        pota = new Bureaucrat("Pota", 159);
        ShrubberyCreationForm* form = new ShrubberyCreationForm("waf");
        pota->signForm(*form);
        pota->executeForm(*form);
        delete pota;
        delete form;
    }
    catch (const std::exception& e)
    {
        std::cout << "couldn't init program because: " << e.what() << std::endl;
    }

    std::cout << "========================" << std::endl;

    try
    {
        pota = new Bureaucrat("Pota", 1);
        RobotomyRequestForm* form = new RobotomyRequestForm("waf");
        pota->signForm(*form);
        pota->executeForm(*form);
        delete pota;
        delete form;
    }
    catch (const std::exception& e)
    {
        std::cout << "couldn't init program because: " << e.what() << std::endl;
    }

    std::cout << "========================" << std::endl;

    try
    {
        pota = new Bureaucrat("Pota", 1);
        PresidentialPardonForm* form = new PresidentialPardonForm("waf");
        pota->signForm(*form);
        pota->executeForm(*form);
        delete pota;
        delete form;
    }
    catch (const std::exception& e)
    {
        std::cout << "couldn't init program because: " << e.what() << std::endl;
    }

    std::cout << "========================" << std::endl;

    try
    {
        pota = new Bureaucrat("Pota", 1);
        Intern* larbin = new Intern();
        AForm* form = larbin->makeForm("Robotomy request", "Waf");
        if (form != NULL)
        {
            pota->signForm(*form);
            pota->executeForm(*form);
        }
        delete form;
        delete pota;
    }
    catch (const std::exception& e)
    {
        std::cout << "couldn't execute program because: " << e.what() << std::endl;
    }

    try
    {
        pota = new Bureaucrat("Pota", 1);
        Intern* larbin = new Intern();
        AForm* form = larbin->makeForm("Robotmy request", "Waf");
        if (form != NULL)
        {
            pota->signForm(*form);
            pota->executeForm(*form);
        }
        delete form;
        delete pota;
    }
    catch (const std::exception& e)
    {
        std::cout << "couldn't execute program because: " << e.what() << std::endl;
    }


    return (0);
}
