/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:53:11 by masoares          #+#    #+#             */
/*   Updated: 2024/06/06 11:33:50 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Cat.hpp"

Cat::Cat( void )
{
    this->type = "Cat";
    std::cout << "The Cat was created" << std::endl;
    ideas = new Brain;
}
    
Cat::~Cat( void )
{
    delete ideas;
    std::cout << "The Cat was destroyed" << std::endl;
}

Cat::Cat (Cat &src)
{
    type = src.type;
    std::cout << "The Cat was created" << std::endl;
    ideas = new Brain;
    *ideas = *(src.ideas);
}

Cat & Cat::operator= (Cat &src)
{
    type = src.type;
    *ideas = *(src.ideas);
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "MIAU MIAU" << std::endl;
}

void Cat::thoughts( void )
{
    ideas->printIdeas();
}
void Cat::setType( std::string type )
{
    this->type = type; 
}
void Cat::setIdea( std::string idea, int pos)
{
    ideas->setIdea(idea, pos);
}

std::string Cat::getIdea(int pos)
{
    return(ideas->getIdea(pos));
}