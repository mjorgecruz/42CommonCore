/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:53:11 by masoares          #+#    #+#             */
/*   Updated: 2024/06/03 16:27:16 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AAnimal.hpp"

AAnimal::AAnimal( void )
{
    this->type = "none";
    std::cout << "The animal was created" << std::endl;

}
    
AAnimal::~AAnimal( void )
{
  std::cout << "The animal was destroyed" << std::endl;
}

AAnimal::AAnimal (AAnimal &src)
{
    type = src.type;
    std::cout << "The animal was created" << std::endl;
}

AAnimal & AAnimal::operator= (AAnimal &src)
{
    type = src.type;
    return (*this);
}

std::string AAnimal::getType( void ) const
{
    return (type);
}