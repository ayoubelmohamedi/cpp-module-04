/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:39:14 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/29 18:26:58 by ael-moha         ###   ########.fr       */
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