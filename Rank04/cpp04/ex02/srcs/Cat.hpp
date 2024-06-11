#pragma once
#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    private:
		  Brain *ideas;

    public:
        Cat( void );
        ~Cat( void );
        Cat (Cat &src);
        Cat &operator= (Cat &src);
        
        void makeSound() const;
        virtual void thoughts( void );
		void setType( std::string type );
		std::string getType( void );
		void setIdea( std::string idea, int pos);
		std::string getIdea( int pos );
};

#endif