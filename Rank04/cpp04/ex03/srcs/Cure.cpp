/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:12:53 by masoares          #+#    #+#             */
/*   Updated: 2024/06/05 18:15:15 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Cure.hpp"

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria *clone = new Cure;
	return (clone);
}

Cure::Cure()
{
	type = "cure";
}

Cure::~Cure(){}

Cure::Cure(Cure &src)
{
	(void) src;
	type = "cure";
}

Cure & Cure::operator=(Cure &src)
{
	(void) src;
	type = "cure";
	return *this;
}