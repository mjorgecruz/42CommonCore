/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:26:04 by masoares          #+#    #+#             */
/*   Updated: 2024/06/06 11:41:27 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "AAnimal.hpp"
// #include "Cat.hpp"
// #include "Dog.hpp"

class Brain
{
    private:
        std::string *ideas;

    public:
        Brain( void );
        ~Brain( void );
        Brain (Brain &src);
        Brain &operator= (Brain &src);
        void printIdeas( void );
        void setIdea(std::string idea, int pos);
        std::string getIdea (int pos);
};


#endif