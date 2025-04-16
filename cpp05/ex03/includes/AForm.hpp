/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:23:05 by npremont          #+#    #+#             */
/*   Updated: 2025/03/11 15:32:48 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat;

class AForm
{
    protected:
        const std::string   name;
        bool                is_signed;
        const int           grade_required_to_sign;
        const int           grade_required_to_exec;

    public:
        AForm();
        AForm(const std::string name, int grade_required_to_sign, int grade_required_to_exec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        const std::string   getName() const;
        bool                getIsSigned() const;
        int                 getGradeRequiredToSign() const;
        int                 getGradeRequiredToExec() const;

        void                beSigned(const Bureaucrat& target);

        virtual void        execute(Bureaucrat const& executor) = 0;

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

        class FormIsAlreadySignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class FormIsUnsignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& o, const AForm& target);

#endif
