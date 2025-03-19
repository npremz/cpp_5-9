/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:21:52 by npremont          #+#    #+#             */
/*   Updated: 2025/03/15 16:16:39 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/AForm.hpp"

std::string const ShrubberyCreationForm::tree = std::string(
"                     ; ; ;\n"\
"                  ;        ;  ;     ;;    ;\n"\
"               ;                 ;         ;  ;\n"\
"                               ;\n"\
"                              ;                ;;\n"\
"              ;          ;            ;              ;\n"\
"              ;            ';,        ;               ;\n"\
"              ;              'b      *\n"\
"               ;              '$    ;;                ;;\n"\
"              ;    ;           $:   ;:               ;\n"\
"            ;;      ;  ;;      ;  @):        ;   ; ;\n"\
"                         ;     :@,@):   ,;**:'   ;\n"\
"             ;      ;,         :@@: ;;*'      ;   ;\n"\
"                      ';o;    ;:(@';@\"'  ;\n"\
"              ;  ;       'bq,;;:,@@'   ,      ;  ;\n"\
"                         ,p$q8,:@)'  ;p'      ;\n"\
"                  ;     '  ; '@@Pp@@'    ;  ;\n"\
"                   ;  ; ;;    Y7'.'     ;  ;\n"\
"                             :@):.\n"\
"                            .:@:'.\n"\
"                          .::(@:.\n"
);

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) 
    : AForm("ShrubberyCreationForm", 145, 137),
    target(target) 
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
    (void)other;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

std::string const ShrubberyCreationForm::getTarget()
{
    return (this->target);
}

const char* ShrubberyCreationForm::CannotOpenFileException::what() const throw()
{
    return "cannot open file.";
}

const char* ShrubberyCreationForm::WriteErrorException::what() const throw()
{
    return "error while writing to the file.";
}

void ShrubberyCreationForm::drawTree()
{
    std::string const output_file_name = (this->target + "_shrubbery");
    std::ofstream file;

    file.open(output_file_name.c_str());
    if (!file.is_open() || file.bad())
        throw CannotOpenFileException();
    for (int i = 0; i < 5; i++)
    {
        file << this->tree;
        if (file.bad())
        {
            file << std::endl;
            file.close();
            throw WriteErrorException();
        }
    }
    file.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor)
{
    AForm::execute(executor);
    this->drawTree();
}