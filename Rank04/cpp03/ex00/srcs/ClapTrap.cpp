/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:53:11 by masoares          #+#    #+#             */
/*   Updated: 2024/05/24 09:31:53 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ): Name("NoName"), health(10), energy(10), attDamage(0) 
{
    std::cout << "ClapTrap " << Name << " is ready to fight!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &src)
{
    *this = src;
    std::cout << "ClapTrap " << Name << " is ready to fight!" << std::endl;
}

ClapTrap::~ClapTrap( void ) 
{
    std::cout << "ClapTrap " << Name << " has perished..." << std::endl;
}

ClapTrap &ClapTrap::operator= (ClapTrap &src)
{
    Name = src.Name;
    health = src.health;
    energy = src.energy;
    attDamage = src.attDamage;
    return (*this);
}

ClapTrap::ClapTrap(std::string name): Name(name), health(10), energy(10), attDamage(0) 
{
    std::cout << "ClapTrap " << Name << " is ready to fight!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energy == 0)
    {
        std::cout << "ClapTrap " << Name << " ran out of energy and can't attack.";
        return;
    }
    energy--;
    std::cout << "ClapTrap " << Name << " attacks " << target <<", causing " << attDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (health == 0)
    {
        std::cout << "ClapTrap " << Name << " is already dead..." << std::endl;
        return;
    }   
    if (amount > health)
    {
        std::cout << "ClapTrap " << Name << " was attacked, causing "  << health << " damage." << std::endl;
        std::cout << "ClapTrap " << Name << " is dead" << std::endl;
        health = 0;
        return;
    }
    health-=amount;
    std::cout << "ClapTrap " << Name << " was attacked, causing "  << amount << " damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy == 0)
    {
        std::cout << "ClapTrap " << Name << " ran out of energy and can't repair itself." << std::endl;
        return;
    }
    energy--;
    health+=amount;
    std::cout << "ClapTrap " << Name << " is repairing itself. Health is now: " << health << std::endl;
}

void ClapTrap::setAttDamage( unsigned int amount )
{
    std::cout << "ClapTrap " << Name << " has picked a new weapon. The attacking damage is now: " << amount << std::endl; 
    this->attDamage = amount;
}

unsigned int ClapTrap::getAttDamage( void )
{
    return(this->attDamage);
}

std::string ClapTrap::getName( void )
{
    return(Name);
}

unsigned int ClapTrap::getHealth( void )
{
    return(health);
}

unsigned int ClapTrap::getEnergy( void )
{
    return(energy);
}

void ClapTrap::blow(ClapTrap &attacked)
{
    this->attack(attacked.getName());
    attacked.takeDamage(this->attDamage);

    std::cout << attacked.getName() << " Health: " << attacked.getHealth() << std::endl; 
    std::cout << Name << " Energy: " << energy << std::endl; 
}
