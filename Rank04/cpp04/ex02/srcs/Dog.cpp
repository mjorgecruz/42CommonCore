/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:53:11 by masoares          #+#    #+#             */
/*   Updated: 2024/06/06 11:38:34 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Dog.hpp"

Dog::Dog( void )
{
    this->type = "Dog";
    std::cout << "The Dog was created" << std::endl;
    ideas = new Brain;

}
    
Dog::~Dog( void )
{
    delete ideas;
    std::cout << "The Dog was destroyed" << std::endl;
}

Dog::Dog (Dog &src)
{
    type = src.type;
    std::cout << "The Dog was created" << std::endl;
    ideas = new Brain;
    *ideas = *(src.ideas);
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

void Dog::thoughts( void )
{
    ideas->printIdeas();
}

void Dog::setType( std::string type )
{
    this->type = type; 
}

std::string Dog::getType( void )
{
    return (type);
}

void Dog::setIdea( std::string idea, int pos)
{
    ideas->setIdea(idea, pos);
}

std::string Dog::getIdea(int pos)
{
    return(ideas->getIdea(pos));
}