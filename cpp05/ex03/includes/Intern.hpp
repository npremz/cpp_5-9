/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:19:06 by npremont          #+#    #+#             */
/*   Updated: 2025/04/14 10:46:57 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "../includes/AForm.hpp"
# include "../includes/PresidentialPardonForm.hpp"
# include "../includes/RobotomyRequestForm.hpp"
# include "../includes/ShrubberyCreationForm.hpp"

class Intern 
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
        
        AForm* makeForm(std::string id, std::string target);
};

#endif
