/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 08:44:15 by masoares          #+#    #+#             */
/*   Updated: 2024/05/28 11:20:36 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp" 
#include "ScavTrap.hpp"

int main (void)
{
    ClapTrap A("Arthur");
    ClapTrap B("Becas");
    ClapTrap C("Chris");

    C.setAttDamage(2);
    B.setAttDamage(4);
    A.blow(B);
    B.blow(A);
    std::cout << A.getEnergy() << std::endl;
    B.blow(A);
    B.blow(A);
    B.blow(A);
    std::cout << A.getEnergy() << std::endl;
    A.beRepaired(3);
    A.beRepaired(3);
    A.blow(B);
    B.blow(A);
    
    ScavTrap E("Esteban");
    ScavTrap F(E);
    ScavTrap G("Guillaume");

    E.setAttDamage(2);
    F.setAttDamage(4);
    E.blow(F);
    F.blow(E);
    std::cout << E.getEnergy() << std::endl;
    F.blow(E);
    F.blow(E);
    F.blow(E);
    std::cout << E.getEnergy() << std::endl;
    E.beRepaired(3);
    E.beRepaired(3);
    E.blow(F);
    F.blow(E);
}