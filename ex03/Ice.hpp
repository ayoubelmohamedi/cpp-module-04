/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:40:01 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/29 18:22:48 by ael-moha         ###   ########.fr       */
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