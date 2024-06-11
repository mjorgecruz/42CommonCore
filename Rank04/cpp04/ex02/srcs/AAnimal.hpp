#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal
{
    protected:
        std::string type;
        AAnimal( void );

    public:
        virtual ~AAnimal( void );
        AAnimal (AAnimal &src);
        AAnimal &operator= (AAnimal &src);
        
        virtual void makeSound() const = 0;
        std::string getType( void ) const;
        virtual void thoughts( void ) = 0;
        virtual void setType( std::string type ) = 0;
        virtual void setIdea( std::string idea, int pos) = 0;
		virtual std::string getIdea( int pos ) = 0;

};

#endif