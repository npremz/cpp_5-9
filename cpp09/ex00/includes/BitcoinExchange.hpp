/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:53:31 by npremont          #+#    #+#             */
/*   Updated: 2025/05/01 11:53:31 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <iomanip>

class Date
{
    private:
        int year, month, day;
    public:
        Date();
        Date(int y, int m, int d);
        Date(const Date& other);
        Date& operator=(const Date& other);
        ~Date();

        bool operator<(const Date& other) const;

        std::string toString() const;
        int         getYear() const;
        int         getMonth() const;
        int         getDay() const;
};

class Evaluation 
{
    private:
        std::map<Date, double> db;

    public:
        Evaluation();
        Evaluation(const Evaluation& other);
        Evaluation& operator=(const Evaluation& other);
        ~Evaluation();

        void    evaluate(std::string input_src);
};

#endif