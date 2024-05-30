/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:53:55 by masoares          #+#    #+#             */
/*   Updated: 2024/05/28 14:38:14 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : FragTrap() , ScavTrap()
{ 
    Name = "NoName";
    ClapTrap::Name = Name +"_clap_name";
    health = FragTrap::HealthS;
    energy = ScavTrap::EnergyS;
    attDamage = FragTrap::AttDamageS;
    std::cout << "DiamondTrap " << Name << " is ready to fight!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &src) : FragTrap(src), ScavTrap(src)
{
    *this = src;
    std::cout << "DiamondTrap " << Name << " is ready to fight!" << std::endl;
}

DiamondTrap::~DiamondTrap( void ) 
{
    std::cout << "DiamondTrap " << Name << " has perished..." << std::endl;
}

DiamondTrap &DiamondTrap::operator= (DiamondTrap &src)
{
    Name = src.Name;
    health = src.health;
    energy = src.energy;
    attDamage = src.attDamage;
    ClapTrap::Name = src.ClapTrap::Name;
    return (*this);
}

DiamondTrap::DiamondTrap(std::string name) :  FragTrap(name) , ScavTrap(name)
{
    Name = name;
    ClapTrap::Name = name+"_clap_name";
    health = FragTrap::HealthS;
    energy = ScavTrap::EnergyS;
    attDamage = FragTrap::AttDamageS;
    std::cout << "DiamondTrap " << Name << " is ready to fight!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "Diamond Trap Name : " << DiamondTrap::Name << std::endl;
    std::cout << "ClapTrap Name : " << ClapTrap::Name << std::endl;
}
void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}
