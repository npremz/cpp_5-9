/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:37:01 by npremont          #+#    #+#             */
/*   Updated: 2025/03/11 14:58:28 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm() : 
    name("Default form"),
    is_signed(false),
    grade_required_to_sign(150),
    grade_required_to_exec(150) 
{}

AForm::AForm(const std::string name, int grade_required_to_sign, int grade_required_to_exec) :
    name(name),
    is_signed(false),
    grade_required_to_sign(grade_required_to_sign),
    grade_required_to_exec(grade_required_to_exec)
{
    if (grade_required_to_exec > 150)
        throw GradeTooLowException();
    if (grade_required_to_sign > 150)
        throw GradeTooLowException();
    if (grade_required_to_exec < 1)
        throw GradeTooHighException();
    if (grade_required_to_sign < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm& other) :
    name(other.name),
    is_signed(other.is_signed),
    grade_required_to_sign(other.grade_required_to_sign),
    grade_required_to_exec(other.grade_required_to_exec)
{}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return (*this);
}


AForm::~AForm() 
{}

const std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getIsSigned() const
{
    return (this->is_signed);
}

int AForm::getGradeRequiredToSign() const
{
    return (this->grade_required_to_sign);
}

int AForm::getGradeRequiredToExec() const
{
    return (this->grade_required_to_exec);
}


const char* AForm::GradeTooHighException::what() const throw()
{
    return ("the grade is to high to perform action!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("the grade is to low to perform action!");
}

const char* AForm::FormIsAlreadySignedException::what() const throw()
{
    return ("the form is already signed!");
}

const char* AForm::FormIsUnsignedException::what() const throw()
{
    return ("the form is unsigned!");
}

void AForm::execute(Bureaucrat const& executor)
{
    if (executor.getGrade() > this->grade_required_to_exec)
        throw AForm::GradeTooLowException();
    if (!this->is_signed)
        throw AForm::FormIsUnsignedException();
} 

void AForm::beSigned(const Bureaucrat& target)
{
    if (target.getGrade() > this->grade_required_to_sign)
        throw AForm::GradeTooLowException();
    if (this->is_signed)
        throw AForm::FormIsAlreadySignedException();
    this->is_signed = true;
}

std::ostream& operator<<(std::ostream& o, const AForm& target)
{
    o << "Form " << target.getName() << 
    ", status: " << target.getIsSigned() << 
    ", grade to sign: " << target.getGradeRequiredToSign() << 
    ", grade to exec: " << target.getGradeRequiredToExec();
    return (o);
}
