/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:23:05 by npremont          #+#    #+#             */
/*   Updated: 2025/03/11 14:15:31 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat;

class Form
{
    private:
        const std::string   name;
        bool                is_signed;
        const int           grade_required_to_sign;
        const int           grade_required_to_exec;

    public:
        Form();
        Form(const std::string name, int grade_required_to_sign, int grade_required_to_exec);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string   getName();
        bool                getIsSigned();
        int                 getGradeRequiredToSign();
        int                 getGradeRequiredToExec();

        void                beSigned(const Bureaucrat& target);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif