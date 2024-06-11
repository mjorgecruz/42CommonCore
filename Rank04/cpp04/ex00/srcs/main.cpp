/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 08:44:15 by masoares          #+#    #+#             */
/*   Updated: 2024/06/05 18:41:04 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// class WrongAnimal
// {
//     protected:
//         std::string type;

//     public:
// WrongAnimal( void )
// {
// 		this->type = "none";
// 		std::cout << "The WrongAnimal was created" << std::endl;

// }
		
// ~WrongAnimal( void )
// {
// 	std::cout << "The WrongAnimal was destroyed" << std::endl;
// }

// WrongAnimal (WrongAnimal &src)
// {
// 		type = src.type;
// 		std::cout << "The WrongAnimal was created" << std::endl;
// }

// WrongAnimal &operator= (WrongAnimal &src)
// {
// 		type = src.type;
// 		return (*this);
// }

// void makeSound() const
// 	{   std::cout << "The WrongAnimal made a weird sound" << std::endl;
// }

// std::string getType( void ) const
// {
// 		return (type);
// }
// };
// class WrongCat : public WrongAnimal
// {
// public:
// WrongCat( void )
// {
//     this->type = "none";
//     std::cout << "The WrongCat was created" << std::endl;

// }
    
// ~WrongCat( void )
// {
//   std::cout << "The WrongCat was destroyed" << std::endl;
// }

// WrongCat(WrongCat &src)
// {
//     type = src.type;
//     std::cout << "The WrongCat was created" << std::endl;
// }

// WrongCat & operator= (WrongCat &src)
// {
//     type = src.type;
//     return (*this);
// }

// void makeSound() const
// {
//     std::cout << "MEGAMIAUUUUUUU" << std::endl;
// }
// };

int main (void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    Animal Tone;
    Tone.makeSound();
    //WrongCat Catone;
    //Catone.makeSound();
    Dog Dogone;
    Dogone.makeSound();
    Animal* Mega_dogone = new Dog(Dogone);
    Animal* Mega_animal = new Animal(Tone);
    Mega_dogone->makeSound();
    Mega_animal->makeSound();
    
    delete j;
    delete meta;
    delete i;
    delete Mega_animal;
    delete Mega_dogone;
}