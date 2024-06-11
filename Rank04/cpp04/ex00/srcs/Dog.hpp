#pragma once
#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog( void );
		~Dog( void );
		Dog (Dog &src);
		Dog &operator= (Dog &src);
		
		void makeSound() const;

};

#endif