/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:03:16 by masoares          #+#    #+#             */
/*   Updated: 2024/05/24 15:29:46 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->Name = "noName";
    this->health = 100;
    this->energy = 50;
    this->attDamage = 20;
    std::cout << "Hola from the constructor of the ScavTrap!" << std::endl;
}
ScavTrap::~ScavTrap()
{
    std::cout << "Hola from the destructor of ScavTrap!" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->Name = name;
    this->health = 100;
    this->energy = 50;
    this->attDamage = 20;
    std::cout << "Hola from the constructor of the ScavTrap!" << std::endl;
}

ScavTrap & ScavTrap::operator= (ScavTrap &src)
{
    Name = src.Name;
    health = src.health;
    energy = src.energy;
    attDamage = src.attDamage;
    return (*this);
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name << " is now in GateKeeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energy == 0)
    {
        std::cout << "ScavTrap " << Name << " ran out of energy and can't attack.";
        return;
    }
    energy--;
    std::cout << "ScavTrap " << Name << " attacks " << target <<", causing " << attDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (health == 0)
    {
        std::cout << "ScavTrapp " << Name << " is already dead..." << std::endl;
        return;
    }   
    if (amount > health)
    {
        std::cout << "ScavTrap " << Name << " was attacked, causing "  << health << " damage." << std::endl;
        std::cout << "ScavTrap " << Name << " is dead" << std::endl;
        health = 0;
        return;
    }
    health-=amount;
    std::cout << "ScavTrap " << Name << " was attacked, causing "  << amount << " damage." << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (energy == 0)
    {
        std::cout << "ScavTrap " << Name << " ran out of energy and can't repair itself." << std::endl;
        return;
    }
    energy--;
    health+=amount;
    std::cout << "ScavTrap " << Name << " is repairing itself. Health is now: " << health << std::endl;
}

void ScavTrap::setAttDamage( unsigned int amount )
{
    std::cout << "ScavTrap " << Name << " has picked a new weapon. The attacking damage is now: " << amount << std::endl; 
    this->attDamage = amount;
}

void ScavTrap::blow(ScavTrap &attacked)
{
    this->attack(attacked.getName());
    attacked.takeDamage(this->attDamage);

    std::cout << attacked.getName() << " Health: " << attacked.getHealth() << std::endl; 
    std::cout << Name << " Energy: " << energy << std::endl; 
}