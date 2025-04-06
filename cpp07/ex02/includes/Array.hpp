/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:20:15 by npremont          #+#    #+#             */
/*   Updated: 2025/04/06 13:13:54 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
    private:
        T* data;
        unsigned int len;
    public:
        Array()
        {
            this->len = 0;
            this->data = new T[0];
        }

        Array(unsigned int n)
        {
            this->len = n;
            this->data = new T[n];
        }

        Array(Array const& other)
        {
            if (other.len > 0)
            {
                this->len = other.len;
                this->data = new T[other.len];
                for (unsigned int i = 0; i < other.len; ++i)
                {
                    this->data[i] = other.data[i];
                }
            }
            else
            {
                this->len = 0;
                this->data = new T[0];
            }
        }

        Array& operator=(Array const& other)
        {
            if (this->data)
                delete[] data;
            if (other.len > 0)
            {
                this->len = other.len;
                this->data = new T[other.len];
                for (unsigned int i = 0; i < other.len; ++i)
                {
                    this->data[i] = other.data[i];
                }
            }
            else
            {
                this->len = 0;
                this->data = new T[0];
            }
            return (*this);
        }

        T& operator[](unsigned int index)
        {
            if (index >= this->len)
                throw std::out_of_range("Index out of range.");
            return (this->data[index]);
        }

        const T& operator[](unsigned int index) const
        {
            if (index >= this->len)
                throw std::out_of_range("Index out of range.");
            return (this->data[index]);
        }
        
        ~Array()
        {
            if (this->len > 0)
                delete[] data;
        }

        unsigned int size(void) const
        {
            return (this->len);
        }

        void print(void) const
        {
            for (unsigned int i = 0; i < this->len; ++i)
            {
                std::cout << "Array [" << i << "]: " << this->data[i] << std::endl;
            }
        }
};

#endif