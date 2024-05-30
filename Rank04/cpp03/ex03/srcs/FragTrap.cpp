/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:41:08 by masoares          #+#    #+#             */
/*   Updated: 2024/05/29 08:58:19 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(),  HealthS(100), EnergyS(100), AttDamageS(30) 
{
    this->health = HealthS;
    this->energy = EnergyS;
    this->attDamage = AttDamageS;
    std::cout << "Hola from the constructor of the FragTrap!" << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "Hola from the destructor of FragTrap!" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name),  HealthS(100), EnergyS(100), AttDamageS(30) 
{
    this->health = HealthS;
    this->energy = EnergyS;
    this->attDamage = AttDamageS;
    std::cout << "Hola from the constructor of the FragTrap!" << std::endl;
}

FragTrap::FragTrap(FragTrap &src) : ClapTrap( src ),  HealthS(100), EnergyS(100), AttDamageS(30) 
{
    this->health = HealthS;
    this->energy = EnergyS;
    this->attDamage = AttDamageS;
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

// void FragTrap::attack(const std::string& target)
// {
//     if (energy == 0)
//     {
//         std::cout << "FragTrap " << Name << " ran out of energy and can't attack.";
//         return;
//     }
//     energy--;
//     std::cout << "FragTrap " << Name << " attacks " << target <<", causing " << attDamage << " points of damage!" << std::endl;
// }
