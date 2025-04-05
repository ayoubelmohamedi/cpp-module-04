/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:39:05 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/05 10:39:06 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp" 

class ICharacter; // Forward declaration

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria(std::string const & type);
        AMateria(AMateria const & src); 
        virtual ~AMateria();

        AMateria & operator=(AMateria const & rhs); // (rule of three)

        std::string const & getType() const; //Returns the materia type

        virtual AMateria* clone() const = 0; // Pure virtual function
        virtual void use(ICharacter& target); // Virtual function
};

#endif