/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:21:29 by masoares          #+#    #+#             */
/*   Updated: 2024/06/05 18:15:43 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Ice.hpp"

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots ice at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
    AMateria *clone = new Ice;
    return (clone);
}

Ice::Ice()
{
    type = "ice";
}

Ice::~Ice(){}

Ice::Ice(Ice &src)
{
    (void) src;
    type = "ice";
}
Ice &Ice::operator=(Ice &src)
{
    (void) src;
    type = "ice";
    return *this;
}