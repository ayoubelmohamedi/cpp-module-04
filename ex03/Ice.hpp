/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:40:01 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/05 10:40:02 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(Ice const & src);
    virtual ~Ice();
    
    Ice & operator=(Ice const & rhs);
    
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif