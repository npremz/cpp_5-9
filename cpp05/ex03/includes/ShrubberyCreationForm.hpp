/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:43:48 by npremont          #+#    #+#             */
/*   Updated: 2025/04/14 10:47:10 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATEFORM_H
# define SHRUBBERYCREATEFORM_H

# include "../includes/AForm.hpp"
# include <string>
# include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string const target;
        static std::string const tree;
        
    public:
        ShrubberyCreationForm(std::string const target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        std::string const getTarget();
        void execute(Bureaucrat const& executor);
        void drawTree();
        
        class CannotOpenFileException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class WriteErrorException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

#endif
