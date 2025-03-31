/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:58:42 by npremont          #+#    #+#             */
/*   Updated: 2025/03/31 13:14:56 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T* array, size_t len, void (*function)(T& e))
{
    for (size_t i = 0; i < len; ++i)
    {
        (*function)(array[i]);
    }
}

template <typename T>
void printElem(T& e)
{
    std::cout << e << std::endl;
}

#endif