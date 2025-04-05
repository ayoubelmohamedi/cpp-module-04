/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:39:18 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/05 10:39:19 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(Cure const & src);
    virtual ~Cure();
    
    Cure & operator=(Cure const & rhs);
    
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif