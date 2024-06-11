/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 08:44:15 by masoares          #+#    #+#             */
/*   Updated: 2024/06/06 11:35:03 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main (void)
{
    Animal *various[10];
    for (int i = 0; i < 5; i++)
        various[i] = new Cat;
    for (int i = 5; i < 10; i++)
        various[i] = new Dog;
    various[0]->thoughts();
    for (int i = 0; i < 10; i++)    
        delete various[i];
    Dog K9;

    Animal *Mega_K9 = new Dog;
    Animal *Ultra_K9 = new Dog; 
    *Ultra_K9 = *Mega_K9;
    Ultra_K9->setType("girafa");
    K9.setIdea("virus", 0);
    Ultra_K9->setIdea("girafa", 0);
    
    std::cout << "ULTRA->" << Ultra_K9->getType() << std::endl;
    std::cout << "MEGA->" << Mega_K9->getType() << std::endl;
    std::cout << "K9->" << K9.getType() << std::endl;

    Mega_K9->thoughts();
    Ultra_K9->thoughts();
    K9.thoughts();
    
    delete Mega_K9;
    delete Ultra_K9;
    
}