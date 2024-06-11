/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:53:11 by masoares          #+#    #+#             */
/*   Updated: 2024/06/06 18:29:59 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Dog.hpp"

Dog::Dog( void )
{
    this->type = "Dog";
    std::cout << "The Dog was created" << std::endl;

}
    
Dog::~Dog( void )
{
  std::cout << "The Dog was destroyed" << std::endl;
}

Dog::Dog (Dog &src)
{
    type = src.type;
    std::cout << "The Dog was created" << std::endl;
}

Dog & Dog::operator= (Dog &src)
{
    type = src.type;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "WOOF WOOF" << std::endl;
}
