/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:46:52 by npremont          #+#    #+#             */
/*   Updated: 2025/04/12 12:49:32 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

int main(void)
{
    std::stack<int> stack;

    stack.push(11);
    stack.push(7);
    stack.push(12);

    std::cout << stack.top() << std::endl;
}