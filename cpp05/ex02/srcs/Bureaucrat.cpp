/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:34:46 by npremont          #+#    #+#             */
/*   Updated: 2025/04/14 10:44:35 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : 
    name(name),
    grade(grade)
{
    if (grade < 1) 
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
    name(other.name),
    grade(other.grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->grade = other.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void    Bureaucrat::incrementGrade(int value)
{
    if (this->grade - value < 1)
    {
        throw GradeTooHighException();
        return ;
    }
    this->grade = this->grade - value;
}

void    Bureaucrat::decrementGrade(int value)
{
    if (this->grade + value > 150)
    {
        throw GradeTooLowException();
        return ;
    }
    this->grade = this->grade + value;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("the grade attribued is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("the grade attribued is too low!");
}

void    Bureaucrat::signForm(AForm& target)
{
    try {
        target.beSigned(*this);
        std::cout << this->getName() << " signed " << target.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->getName() << " couldn't sign " << target.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm& target) const
{
    try 
    {
        if (!target.getIsSigned())
            throw AForm::FormIsUnsignedException();
        if (target.getGradeRequiredToExec() < this->grade)
            throw GradeTooLowException();
        target.execute(*this);
        std::cout << *this << " executes " << target << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << this->getName() << " couldn't execute " << target.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& target)
{
    o << target.getName() << ", bureaucrat grade " << target.getGrade() << ". ";
    return (o);
}
