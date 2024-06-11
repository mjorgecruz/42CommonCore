/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:56:43 by masoares          #+#    #+#             */
/*   Updated: 2024/06/05 15:00:43 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "Character.hpp"
#include <string>

class Ice : public AMateria
{
    public:
        Ice();
        ~Ice();
        Ice(Ice &src);
        Ice &operator=(Ice &str);
        
        void use(ICharacter& target);
        AMateria* clone() const;
};

#endif