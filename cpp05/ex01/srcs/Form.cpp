/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:37:01 by npremont          #+#    #+#             */
/*   Updated: 2025/03/11 14:58:28 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form() : 
    name("Default form"),
    is_signed(false),
    grade_required_to_sign(150),
    grade_required_to_exec(150) 
{}

Form::Form(const std::string name, int grade_required_to_sign, int grade_required_to_exec) :
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

Form::Form(const Form& other) :
    name(other.name),
    is_signed(other.is_signed),
    grade_required_to_sign(other.grade_required_to_sign),
    grade_required_to_exec(other.grade_required_to_exec)
{}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return (*this);
}


Form::~Form() 
{}

const std::string Form::getName()
{
    return (this->name);
}

bool Form::getIsSigned()
{
    return (this->is_signed);
}

int Form::getGradeRequiredToSign()
{
    return (this->grade_required_to_sign);
}

int Form::getGradeRequiredToExec()
{
    return (this->grade_required_to_exec);
}


const char* Form::GradeTooHighException::what() const throw()
{
    return ("the grade is to high to perfom action!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("the grade is to low to perform action!");
}

void Form::beSigned(const Bureaucrat& target)
{
    if (target.getGrade() > this->grade_required_to_sign)
        throw Form::GradeTooLowException();
    this->is_signed = true;
}

std::ostream& operator<<(std::ostream& o, Form& target)
{
    o << "Form " << target.getName() << 
    ", status: " << target.getIsSigned() << 
    ", grade to sign: " << target.getGradeRequiredToSign() << 
    ", grade to exec: " << target.getGradeRequiredToExec();
    return (o);
}