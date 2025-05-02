/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:53:27 by npremont          #+#    #+#             */
/*   Updated: 2025/05/01 11:53:27 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

Date::Date() : year(1970), month(1), day(1) {}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

Date::Date(const Date& other) : year(other.year), month(other.month), day(other.day) {}

Date& Date::operator=(const Date& other)
{
    if (this != &other)
    {
        year = other.year;
        month = other.month;
        day = other.day;
    }
    return (*this);
}

Date::~Date() {}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

std::string Date::toString() const {
    std::ostringstream oss;

    oss << year << "-";
    if (month < 10)
        oss << "0";
    oss << month << "-";
    if (day < 10)
        oss << "0";
    oss << day;
    
    return (oss.str());
}

int Date::getYear() const
{
    return (year);
}

int Date::getMonth() const
{
    return (month);
}

int Date::getDay() const
{
    return (day);
}

///////---//////////////////////////////////////////////---//////
//---//////-------------------------------------------//////---//
/////////////////////////////////////////////////////////////////

bool isDateValid(int y, int m, int d) {
    if (y > 2009) {
    } else if (y == 2009) {
        if (m > 1) {
        } else if (m == 1) {
            if (d < 2) {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }

    if (m < 1 || m > 12) {
        return false;
    }

    int joursParMois[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) {
        joursParMois[2] = 29; 
    }

    if (d < 1 || d > joursParMois[m]) {
        return false;
    }
    return true;
}

Evaluation::Evaluation()
{
    std::string     db_src("files/data.csv");
    std::ifstream   db_file(db_src.c_str());

    if (!db_file.is_open())
    {
        throw std::runtime_error("the program can't open file \"" + db_src + "\"");
    }
    
    std::string line;
    std::getline(db_file, line);

    while (std::getline(db_file, line, '-'))
    {
        int                 y, m, d;
        double              value;
        std::string         buffer;

        y = atoi(line.c_str());
        std::getline(db_file, line, '-');
        m = atoi(line.c_str());
        std::getline(db_file, line, ',');
        d = atoi(line.c_str());

        std::getline(db_file, line);
        std::istringstream iss(line);
        iss >> value;

        if (!isDateValid(y, m, d)
            || value < 0)
            throw std::runtime_error("invalid database");
        
        db[Date(y, m, d)] = value;
    }

    db_file.close();
}

Evaluation::~Evaluation() {}

void    Evaluation::evaluate(std::string input_src)
{
    std::ifstream   input_file(input_src.c_str());

    if (!input_file.is_open())
    {
        throw std::runtime_error("the program can't open file \"" + input_src + "\"");
    }

    std::string line;
    std::getline(input_file, line);

    while (std::getline(input_file, line))
    {
        try 
        {
            int                 y, m, d;
            double              value;
            std::string         buffer;
            std::stringstream   ss(line);

            if (!std::getline(ss, buffer, '-'))
                throw std::runtime_error("bad input => " + line);
            y = atoi(buffer.c_str());
            if (!std::getline(ss, buffer, '-'))
                throw std::runtime_error("bad input => " + line);
            m = atoi(buffer.c_str());
            if (!std::getline(ss, buffer, '|'))
                throw std::runtime_error("bad input => " + line);
            d = atoi(buffer.c_str());
            if (!std::getline(ss, buffer))
                throw std::runtime_error("bad input => " + line);
            std::istringstream iss(buffer);
            iss >> value;

            Date line_date(y, m, d);
            
            if (!isDateValid(y, m, d))
                 throw std::runtime_error("bad input => " + line_date.toString());
            if (value < 0)
                throw std::runtime_error("not a positive number.");
            if (value > 2147483647)
                throw std::runtime_error("too large a number.");

            std::map<Date, double>::iterator it = db.upper_bound(line_date);
            it--;

            std::cout << std::fixed << std::setprecision(2)
                      << line_date.toString()
                      << " => " 
                      << value 
                      << " = " 
                      << value * it->second << std::endl;
        } 
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }

    }
}