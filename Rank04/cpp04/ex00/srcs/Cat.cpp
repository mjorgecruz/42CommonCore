/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:53:11 by masoares          #+#    #+#             */
/*   Updated: 2024/06/06 18:29:54 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Cat.hpp"

Cat::Cat( void )
{
    this->type = "Cat";
    std::cout << "The Cat was created" << std::endl;

}
    
Cat::~Cat( void )
{
  std::cout << "The Cat was destroyed" << std::endl;
}

Cat::Cat (Cat &src)
{
    type = src.type;
    std::cout << "The Cat was created" << std::endl;
}

Cat & Cat::operator= (Cat &src)
{
    type = src.type;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "MIAU MIAU" << std::endl;
}