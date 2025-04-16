/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:21:52 by npremont          #+#    #+#             */
/*   Updated: 2025/03/13 11:46:04 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const target) 
    : AForm("PresidentialPardonForm", 72, 45),
    target(target) 
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), target(other.target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
    (void)other;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

std::string const PresidentialPardonForm::getTarget()
{
    return (this->target);
}

void PresidentialPardonForm::pardon()
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor)
{
    AForm::execute(executor);
    this->pardon();
}
