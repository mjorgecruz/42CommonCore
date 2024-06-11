/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:00:29 by masoares          #+#    #+#             */
/*   Updated: 2024/06/05 17:55:35 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AMateria.hpp"

AMateria::AMateria(){}

AMateria::AMateria(std::string const & type) 
{
    this->type = type;
}

AMateria::~AMateria(){}


AMateria::AMateria(AMateria &src)
{
    this->type = src.type;
}

AMateria &AMateria::operator=(AMateria &src)
{
    this->type = src.type;
    return *this;
}

std::string const & AMateria::getType() const
{
    return(type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* shoots nothing at " << target.getName() << " *" << std::endl;
}