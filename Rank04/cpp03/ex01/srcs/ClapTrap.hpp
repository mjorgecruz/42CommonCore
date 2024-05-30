#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string Name;
        unsigned int health;
        unsigned int energy;
        unsigned int attDamage;
    public:
        ClapTrap( void );
        ClapTrap(ClapTrap &src);
        ~ClapTrap( void );
        ClapTrap &operator= (ClapTrap &src);
        ClapTrap(std::string name);

        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void setAttDamage( unsigned int amount);
        unsigned int getAttDamage( void );
        std::string getName( void );
        unsigned int getHealth( void );
        unsigned int getEnergy( void );

        void blow( ClapTrap & attacked );

};

#endif