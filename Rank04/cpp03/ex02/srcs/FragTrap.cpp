/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:41:08 by masoares          #+#    #+#             */
/*   Updated: 2024/05/28 14:16:31 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap( ) 
{
    this->health = 100;
    this->energy = 100;
    this->attDamage = 30;
    std::cout << "Hola from the constructor of the FragTrap!" << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "Hola from the destructor of FragTrap!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap( name )
{
    this->health = 100;
    this->energy = 100;
    this->attDamage = 30;
    std::cout << "Hola from the constructor of the FragTrap!" << std::endl;
}


FragTrap::FragTrap(FragTrap &src) : ClapTrap( src )
{
   
    this->health = 100;
    this->energy = 100;
    this->attDamage = 30;
    std::cout << "Hola from the constructor of the FragTrap!" << std::endl;
}

FragTrap & FragTrap::operator= (FragTrap &src)
{
    Name = src.Name;
    health = src.health;
    energy = src.energy;
    attDamage = src.attDamage;
    return (*this);
}

void FragTrap::highFivesGuys( void )
{
    std::cout << "FragTrap " << Name << " is now waiting with hands up in the air!!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (energy == 0)
    {
        std::cout << "FragTrap " << Name << " ran out of energy and can't attack.";
        return;
    }
    energy--;
    std::cout << "FragTrap " << Name << " attacks " << target <<", causing " << attDamage << " points of damage!" << std::endl;
}