/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:07:16 by npremont          #+#    #+#             */
/*   Updated: 2025/03/29 12:15:01 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main(void)
{
    Data dt;

    dt.int_value = 19;
    dt.string_value = "Ce code est frais.";

    std::cout << "-- Before serialization --" << std::endl;
    std::cout << "Data.int = " << dt.int_value << std::endl;
    std::cout << "Data.string = " << dt.string_value << std::endl;

    uintptr_t serialized_ptr = Serializer::serialize(&dt);
    Data* deserialized_ptr = Serializer::deserialize(serialized_ptr);

    std::cout << "-- After serialization --" << std::endl;
    std::cout << "Data.int = " << deserialized_ptr->int_value << std::endl;
    std::cout << "Data.string = " << deserialized_ptr->string_value << std::endl;
}