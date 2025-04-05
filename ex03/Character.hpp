/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:39:14 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/05 10:39:15 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria* _inventory[4];
    
    // Private methods
    void _clearInventory();
    
public:
    Character(std::string const & name);
    Character(Character const & src);
    virtual ~Character();
    
    Character & operator=(Character const & rhs);
    
    // ICharacter implementation
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

#endif