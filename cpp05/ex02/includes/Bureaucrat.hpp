/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:34:43 by npremont          #+#    #+#             */
/*   Updated: 2025/03/12 13:14:41 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class AForm;

class Bureaucrat 
{
    private:
        const   std::string   name;
        int     grade;

    public:
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        std::string    getName() const;
        int            getGrade() const;
        void           incrementGrade(int value = 1);
        void           decrementGrade(int value = 1);

        void            signForm(AForm& target);
        void            executeForm(AForm& target) const;

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

std::ostream& operator<<(std::ostream& o, const Bureaucrat& target);


#endif
