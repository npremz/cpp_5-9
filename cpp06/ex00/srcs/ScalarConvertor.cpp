/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:01:36 by npremont          #+#    #+#             */
/*   Updated: 2025/03/29 11:29:01 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConvertor.hpp"

ScalarConvertor::ScalarConvertor() {}

ScalarConvertor::ScalarConvertor(ScalarConvertor const &other)
{
    *this = other;
}

ScalarConvertor& ScalarConvertor::operator=(ScalarConvertor const& other)
{
    (void)other;
    return (*this);
}

ScalarConvertor::~ScalarConvertor() {}

int isPseudo(std::string str)
{
    return (str == "+inff"
        || str == "-inff"
        || str == "nanf"
        || str == "+inf"
        || str == "-inf"
        || str == "nan");
}

type getType(std::string str)
{
    if (str.length() == 1 && !isdigit(str.at(0)) && !isspace(str.at(0)))
        return (CHAR);
    if (isPseudo(str))
        return (PSEUDO);
    
    size_t i = 0;
    while (i < str.length() && isspace(str[i]))
        ++i;
    if (str[i] == '+' || str[i] == '-')
        ++i;
    
    bool hasDigits;
    bool hasDot;
    while (i < str.length())
    {
        if (isdigit(str[i]))
            hasDigits = true;
        else if (str[i] == '.')
        {
            if (hasDot)
                return (std::cerr << "Error: too many dots found in input." << std::endl, INVALID);
            hasDot = true;
        }
        else if (str[i] == 'f')
        {
            if (i == str.length() - 1)
                return (FLOAT);
            return (std::cerr << "Error: 'f' is found but not at the end of input." << std::endl, INVALID);
        }
        else
            return (INVALID);
        ++i;
    }
    if (hasDigits && hasDot)
        return (DOUBLE);
    if (hasDigits)
        return (INT);
    return (INVALID);
}

void    printConvertion(val values)
{
    if (!isprint(values.c_value))
        std::cout << "char: Non displayable" << std::endl;
    else if (!values.is_c_valid)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: '" << values.c_value << "'" << std::endl;
    std::cout << "int: " << values.int_value << std::endl;
    std::cout << "float: " << values.f_value;
    if (std::fmod(values.f_value, 1.0) == 0.0)
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    std::cout << "double: " << values.double_value;
    if (std::fmod(values.double_value, 1.0) == 0.0)
        std::cout << ".0" << std::endl;
    else
        std::cout << std::endl;
}

void    handleChar(char value)
{
    val values;

    values.c_value = value;
    values.int_value = static_cast<int>(value);
    values.f_value = static_cast<float>(value);
    values.double_value = static_cast<double>(value);
    values.is_c_valid = true;
    printConvertion(values);
}

void    handleInt(int value)
{
    val values;

    values.c_value = static_cast<char>(value);
    values.int_value = value;
    values.f_value = static_cast<float>(value);
    values.double_value = static_cast<double>(value);
    values.is_c_valid = true;
    printConvertion(values);
}

void    handleFloat(float value)
{
    val values;

    values.f_value = value;
    values.double_value = static_cast<double>(value);
    values.c_value = static_cast<char>(value);
    if (values.double_value > std::numeric_limits<int>::max()
        || values.double_value < std::numeric_limits<int>::min())
    {
        values.int_value = INT_MIN;
        values.is_c_valid = false;
    }
    else
    {
        values.int_value = static_cast<int>(value);
        values.c_value = true;
    }
    printConvertion(values);
}

void    handleDouble(double value)
{
        val values;

    values.f_value = static_cast<float>(value);
    values.double_value = value;
    values.c_value = static_cast<double>(value);
    if (values.double_value > std::numeric_limits<int>::max()
        || values.double_value < std::numeric_limits<int>::min())
    {
        values.int_value = INT_MIN;
        values.is_c_valid = false;
    }
    else
    {
        values.int_value = static_cast<int>(value);
        values.c_value = true;
    }
    printConvertion(values);
}

void    handlePseudo(std::string const str)
{
    val values;

    values.f_value = static_cast<float>(atof(str.c_str()));
    values.double_value = static_cast<double>(values.f_value);
    values.int_value = INT_MIN;
    values.c_value = '\0';
    values.is_c_valid = false;
    printConvertion(values);
}

void   ScalarConvertor::convert(std::string const& str)
{
    type input_type = getType(str);
    double str_in_double = atof(str.c_str());
    if (str_in_double > std::numeric_limits<int>::max() || str_in_double < std::numeric_limits<int>::min())
        input_type = DOUBLE;

    switch (input_type)
    {
        case CHAR:
            handleChar(str.at(0));
            break;
        case INT:
            handleInt(atoi(str.c_str()));
            break;
        case FLOAT:
            handleFloat(atof(str.c_str()));
            break;
        case DOUBLE:
            handleDouble(atof(str.c_str()));
            break;
        case PSEUDO:
            handlePseudo(str);
            break;
        case INVALID:
            std::cerr << "Error: invalid input" << std::endl;
            return;
    }
}