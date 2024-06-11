/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:16:55 by masoares          #+#    #+#             */
/*   Updated: 2024/06/06 15:08:37 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Character.hpp"

Character::Character(): _name("No Name"), _x(0) 
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 4; i++)
		_ground[i] = NULL;
}

Character::~Character() 
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
		if (_ground[i] != NULL)
			delete _ground[i];
	}
}

Character::Character(Character &src): _name(src.getName()), _x(0) 
{
	for (int i = 0; i < 4; i++)
	{
		if (src.getInventory(i))
			_inventory[i] = src.getInventory(i)->clone();
		if (src.getGround(i))
			_ground[i] = src.getGround(i)->clone();
			
	}
}

Character &Character::operator=(Character &src)
{
	AMateria *ptr;
	
	_name = src.getName();
	_x = src._x;
	
	for (int i = 0; i < 4; i++)
	{
		ptr = _inventory[i];
		if (ptr != NULL)
			delete ptr;
		if (src.getInventory(i))
			_inventory[i] = src.getInventory(i)->clone();
	}
	return *this;
}

std::string const & Character::getName() const
{
	return(_name);
}

Character::Character(std::string const & str):  _name(str), _x(0)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
		_ground[i] = NULL;
	}
}

void Character::equip(AMateria* m)
{
	int i = 0;
	if (m == NULL)
		return;
	while (i < 4)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
		i++;
	}
	delete m;
}
void Character::unequip(int idx)
{
	AMateria *ptr = NULL;
	int i;

	i = 0;
	if (idx < 4 && idx >= 0 && _inventory[idx] != NULL)
	{
		ptr = _inventory[idx];
		_inventory[idx] = NULL;
		while (i < 4)
		{
			if (_ground[i] == NULL)
			{
				_ground[i] = ptr;
				break;
			}
			i++;
		}
	}
}
void Character::use(int idx, ICharacter& target)
{
	if (idx > -1 && idx < 4)
	{
		if (_inventory[idx])
			_inventory[idx]->use(target);
	}
}

AMateria *Character::getInventory(int i)
{
	return(_inventory[i]);
}

AMateria *Character::getGround(int i)
{
	return(_ground[i]);
}