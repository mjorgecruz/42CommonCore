#pragma once
#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *ideas;

	public:
		Dog( void );
		~Dog( void );
		Dog (Dog &src);
		Dog &operator= (Dog &src);
		
		void makeSound() const;
		virtual void thoughts( void );
		void setType( std::string type );
		std::string getType( void );
		void setIdea( std::string idea, int pos);
		std::string getIdea( int pos );
};

#endif