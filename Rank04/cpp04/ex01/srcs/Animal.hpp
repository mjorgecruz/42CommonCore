#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;

    public:
        Animal( void );
        virtual ~Animal( void );
        Animal (Animal &src);
        Animal &operator= (Animal &src);
        
        virtual void makeSound() const;
        std::string getType( void ) const;
        virtual void thoughts( void ) = 0;
        virtual void setType( std::string type ) = 0;
        virtual void setIdea( std::string idea, int pos) = 0;
		virtual std::string getIdea( int pos ) = 0;

};

#endif