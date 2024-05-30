/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:41:26 by masoares          #+#    #+#             */
/*   Updated: 2024/05/29 08:58:28 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
    protected:
        const unsigned int HealthS;
        const unsigned int EnergyS;
        const unsigned int AttDamageS;
    
    public:
        FragTrap();
        ~FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap &src);
        FragTrap &operator= (FragTrap &src);
        
        void highFivesGuys( void );

    //void attack(const std::string& target);
};

#endif