/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:36:02 by npremont          #+#    #+#             */
/*   Updated: 2025/03/29 13:08:33 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::Base()
{}

Base::~Base()
{}

Base* generate(void)
{
    srand(time(NULL));
    int i = rand();

    switch (i % 3)
    {
        case 0:
            std::cout << "Type A generated" << std::endl;
            return (new A);
            break;
        case 1:
            std::cout << "Type B generated" << std::endl;
            return (new B);
            break;
        case 2:
            std::cout << "Type C generated" << std::endl;
            return (new C);
            break;
    }
    return (NULL);
}

void identify(Base* p)
{
    if (!p)
    {
        std::cout << "Cannot identify pointer: pointer is null" << std::endl;
        return;
    }

    if (dynamic_cast<A*>(p))
        std::cout << "Pointer is identified of type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer is identified of type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer is identified of type C" << std::endl;
    else
        std::cout << "Cannot identify pointer: unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a_ref = dynamic_cast<A&>(p);
        std::cout << &a_ref << ": Reference is indentified of type A" << std::endl;
    }
    catch (const std::exception& e)
    {
        try
        {
            B& b_ref = dynamic_cast<B&>(p);
            std::cout << &b_ref << ": Reference is identified of type B" << std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                C& c_ref = dynamic_cast<C&>(p);
                std::cout << &c_ref << ": Reference is identified of type C" << std::endl;
            }
            catch (const std::exception& e)
            {
                std::cout << "Cannot identify reference: unknown type" <<std::endl;
            }
        }
        
    }
}