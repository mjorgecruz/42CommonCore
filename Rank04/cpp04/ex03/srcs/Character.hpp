/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:17:29 by masoares          #+#    #+#             */
/*   Updated: 2024/06/06 14:07:05 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter
{
    private:
        AMateria *_inventory[4];
        AMateria *_ground[4];
        std::string _name;
        int _x;
        
    public:
        Character();
        ~Character();
        Character(Character &src);
        Character &operator=(Character &src);
        
        Character(std::string const & str);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

        AMateria *getInventory(int i);
        AMateria *getGround(int i);
};

#endif