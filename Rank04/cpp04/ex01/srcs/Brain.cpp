/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:42:15 by masoares          #+#    #+#             */
/*   Updated: 2024/06/06 11:32:29 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Brain.hpp"

Brain::Brain( void )
{
    this->ideas = new std::string[100];
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "LOLOL";
    std::cout << "Mega Brain is in the workings" << std::endl;
}
Brain::~Brain( void )
{
    std::cout << "Mega Brain is no longer in the workings" << std::endl;
    delete[] ideas;
}
Brain::Brain (Brain &src)
{
    this->ideas = new std::string[100];
    for (int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
}

Brain & Brain::operator= (Brain &src)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
    return *this;
}

void    Brain::printIdeas( void )
{
    std::cout << this->ideas[0] << std::endl;
}

void Brain::setIdea(std::string idea, int pos)
{
    this->ideas[pos] = idea;
}

std::string Brain::getIdea (int pos)
{
    return (ideas[pos]);
}