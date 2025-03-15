/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:43:48 by npremont          #+#    #+#             */
/*   Updated: 2025/03/12 12:46:26 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "../includes/AForm.hpp"
# include <string>
# include <cstdlib>
# include <ctime>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string const target;
        static std::string const tree;
        
    public:
        RobotomyRequestForm(std::string const target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        std::string const getTarget();

        void execute(Bureaucrat const& executor);
        void robotomise();

};



#endif