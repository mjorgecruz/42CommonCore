/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 08:44:15 by masoares          #+#    #+#             */
/*   Updated: 2024/05/24 09:37:50 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp" 

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
    
}