/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:37:01 by npremont          #+#    #+#             */
/*   Updated: 2024/12/13 16:03:09 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

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
{}

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

const int Form::getGradeRequiredToSign()
{
    return (this->grade_required_to_sign);
}
const int Form::getGradeRequiredToExec()
{
    return (this->grade_required_to_exec);
}