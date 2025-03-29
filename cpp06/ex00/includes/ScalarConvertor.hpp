/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:19:26 by npremont          #+#    #+#             */
/*   Updated: 2025/03/26 13:36:04 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTOR_HPP
# define SCALARCONVERTOR_HPP

# include <iostream>
# include <limits>
# include <climits>
# include <cmath>

enum type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};

struct val
{
    char c_value;
    int int_value;
    float f_value;
    double double_value;
    bool is_c_valid;
};


class ScalarConvertor {
    private:
        ScalarConvertor();
        ScalarConvertor(const ScalarConvertor& other);
        ScalarConvertor& operator=(const ScalarConvertor& other);
        ~ScalarConvertor();

    public:
        static void convert(std::string const& value);
};

#endif