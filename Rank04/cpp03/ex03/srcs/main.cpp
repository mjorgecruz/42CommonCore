/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 08:44:15 by masoares          #+#    #+#             */
/*   Updated: 2024/05/30 10:27:27 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "DiamondTrap.hpp"

int main (void)
{
    // ClapTrap A("Arthur");
    // ClapTrap B("Becas");
    // ScavTrap E("Esteban");
    // ScavTrap F("Frances");
    // // ScavTrap G("Guillaume");

    // E.setAttDamage(2);
    // F.setAttDamage(4);
    
    // E.blow(F);
    // F.blow(E);
    // std::cout << E.getEnergy() << std::endl;
    // F.blow(E);
    // F.blow(E);
    // F.blow(E);
    // std::cout << E.getEnergy() << std::endl;
    // E.beRepaired(3);
    // E.beRepaired(3);
    // E.blow(F);
    // F.blow(E);

    DiamondTrap H;
    DiamondTrap I(H);
    FragTrap J("Jacques");

    std::cout << H.getHealth() << std::endl;
    std::cout << H.getEnergy() << std::endl;
    std::cout << H.getAttDamage() << std::endl;
    
    
    H.blow(I);
    H.blow(J);
    std::cout << H.getEnergy() << std::endl;
    H.whoAmI();
    I.whoAmI();

}