/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:21:52 by npremont          #+#    #+#             */
/*   Updated: 2025/03/13 11:46:04 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const target) 
    : AForm("RobotomyRequestForm", 72, 45),
    target(target) 
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
    (void)other;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

std::string const RobotomyRequestForm::getTarget()
{
    return (this->target);
}

void RobotomyRequestForm::robotomise()
{
    srand(static_cast<unsigned int>(time(NULL)));
    int random_value = rand();
    if (random_value % 2 == 0)
    {
        std::cout << "BZZZZZRRRRRRRR... , " << this->target << " has been robotomized." << std::endl;
    }
    else
    {
        std::cout << "BZZZZZRRRRRRR.. AAAAAAARGHGH... , " << this->target << " robotimisation failed..." << std::endl;
    }
}

void RobotomyRequestForm::execute(Bureaucrat const& executor)
{
    AForm::execute(executor);
    this->robotomise();
}