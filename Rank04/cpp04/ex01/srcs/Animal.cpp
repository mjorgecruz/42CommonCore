/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:53:11 by masoares          #+#    #+#             */
/*   Updated: 2024/06/03 14:15:36 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

Animal::Animal( void )
{
    this->type = "none";
    std::cout << "The animal was created" << std::endl;

}
    
Animal::~Animal( void )
{
  std::cout << "The animal was destroyed" << std::endl;
}

Animal::Animal (Animal &src)
{
    type = src.type;
    std::cout << "The animal was created" << std::endl;
}

Animal & Animal::operator= (Animal &src)
{
    type = src.type;
    return (*this);
}

void Animal::makeSound() const
  {   std::cout << "The animal made a weird sound" << std::endl;
}

std::string Animal::getType( void ) const
{
    return (type);
}