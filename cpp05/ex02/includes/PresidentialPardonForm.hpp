/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:43:48 by npremont          #+#    #+#             */
/*   Updated: 2025/03/12 12:46:26 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "../includes/AForm.hpp"
# include <string>
# include <cstdlib>
# include <ctime>

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private:
        std::string const target;
        static std::string const tree;
        
    public:
        PresidentialPardonForm(std::string const target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        std::string const getTarget();

        void execute(Bureaucrat const& executor);
        void pardon();

};



#endif