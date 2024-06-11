/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 08:44:15 by masoares          #+#    #+#             */
/*   Updated: 2024/06/06 11:43:47 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main (void)
{
    AAnimal *various[10];
    for (int i = 0; i < 5; i++)
        various[i] = new Cat;
    for (int i = 5; i < 10; i++)
        various[i] = new Dog;
    for (int i = 0; i < 10; i++)    
        delete various[i];

    Dog K9;
    //AAnimal YoungMoney;
    AAnimal *Mega_K9 = new Dog;
    AAnimal *Ultra_K9 = new Dog; 
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