/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:03:16 by masoares          #+#    #+#             */
/*   Updated: 2024/05/28 14:35:59 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(),  HealthS(100), EnergyS(50), AttDamageS(20) 
{
    this->health = HealthS;
    this->energy = EnergyS;
    this->attDamage = AttDamageS;
    std::cout << "Hola from the constructor of the ScavTrap!" << std::endl;
}
ScavTrap::~ScavTrap()
{
    std::cout << "Hola from the destructor of ScavTrap!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) , HealthS(100), EnergyS(50), AttDamageS(20) 
{
    this->health = HealthS;
    this->energy = EnergyS;
    this->attDamage = AttDamageS;
    std::cout << "Hola from the constructor of the ScavTrap!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &src) : ClapTrap( src ),  HealthS(100), EnergyS(50), AttDamageS(20) 
{
    this->health = HealthS;
    this->energy = EnergyS;
    this->attDamage = AttDamageS;
    std::cout << "Hola from the constructor of the FragTrap!" << std::endl;
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
