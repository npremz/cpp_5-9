/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:52:16 by npremont          #+#    #+#             */
/*   Updated: 2025/04/07 15:38:15 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T& array, int value)
{
    typename T::const_iterator found;

    found = std::find(array.begin(), array.end(), value);
    if (found != array.end())
        return (found);
    throw std::runtime_error("Value not found.");
}

#endif