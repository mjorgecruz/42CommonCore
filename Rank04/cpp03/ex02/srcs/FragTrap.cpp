/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:41:08 by masoares          #+#    #+#             */
/*   Updated: 2024/05/24 15:58:46 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->Name = "noName";
    this->health = 100;
    this->energy = 100;
    this->attDamage = 30;
    std::cout << "Hola from the constructor of the FragTrap!" << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "Hola from the destructor of FragTrap!" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->Name = name;
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

void FragTrap::takeDamage(unsigned int amount)
{
    if (health == 0)
    {
        std::cout << "FragTrapp " << Name << " is already dead..." << std::endl;
        return;
    }   
    if (amount > health)
    {
        std::cout << "FragTrap " << Name << " was attacked, causing "  << health << " damage." << std::endl;
        std::cout << "FragTrap " << Name << " is dead" << std::endl;
        health = 0;
        return;
    }
    health-=amount;
    std::cout << "FragTrap " << Name << " was attacked, causing "  << amount << " damage." << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (energy == 0)
    {
        std::cout << "FragTrap " << Name << " ran out of energy and can't repair itself." << std::endl;
        return;
    }
    energy--;
    health+=amount;
    std::cout << "FragTrap " << Name << " is repairing itself. Health is now: " << health << std::endl;
}

void FragTrap::setAttDamage( unsigned int amount )
{
    std::cout << "FragTrap " << Name << " has picked a new weapon. The attacking damage is now: " << amount << std::endl; 
    this->attDamage = amount;
}

void FragTrap::blow(FragTrap &attacked)
{
    this->attack(attacked.getName());
    attacked.takeDamage(this->attDamage);

    std::cout << attacked.getName() << " Health: " << attacked.getHealth() << std::endl; 
    std::cout << Name << " Energy: " << energy << std::endl; 
}