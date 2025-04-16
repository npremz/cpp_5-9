/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:18:57 by npremont          #+#    #+#             */
/*   Updated: 2025/04/14 10:46:35 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

class AForm;

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{}

AForm*  Intern::makeForm(const std::string type, const std::string target)
{
    try
    {
        const std::string formTypes[] = {
            "Shrubbery form",
            "Robotomy request",
            "Presidential pardon"
        };

        AForm* forms[] = {
            new ShrubberyCreationForm(target),
            new RobotomyRequestForm(target),
            new PresidentialPardonForm(target)
        };

        AForm* resForm = NULL;

        for (int i = 0; i < 3; i++)
        {
            if (type == formTypes[i])
            {
                std::cout << "Intern creates " << formTypes[i] << std::endl;
                resForm = forms[i];
            }
            else
                delete forms[i];
        }
        if (resForm == NULL)
            throw std::invalid_argument("form type \"" + type + "\" does not exist");
        return (resForm);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error while an intern tried to create the form: " << e.what() << std::endl;
        return (NULL);
    }
}
