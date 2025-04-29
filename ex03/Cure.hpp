/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:39:18 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/29 18:22:44 by ael-moha         ###   ########.fr       */
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