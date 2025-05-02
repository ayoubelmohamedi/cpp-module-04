/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:40:09 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/29 18:22:54 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

class Metal : public AMateria
{
    public:
        Metal() : AMateria("Metal") {}
        Metal(Metal const & src) : AMateria(src) {}
        virtual ~Metal() {}

        Metal & operator=(Metal const & rhs)
        {
            if (this != &rhs)
                this->_type = rhs._type;
            return *this;
        }

        virtual AMateria* clone() const
        {
            return new Metal(*this);
        }

        virtual void use(ICharacter& target)
        {
            std::cout << "* shoots a metal projectile at " << target.getName() << " *" << std::endl;
        }
};

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Metal());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("Iron");
    me->equip(tmp);
    tmp = src->createMateria("Metal");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    Character* me2((Character*)me);
    me2->use(0, *me);
    me2->equip(src->createMateria("Metal"));
    me2->equip(src->createMateria("ice"));
    me2->equip(src->createMateria("Iron"));
    me2->equip(src->createMateria("cure"));
    for (int i = 0; i < 4; i++)
    { 
        me->unequip(i);
    }
    me->unequip(0);
    std::cout << "me2 name: " << me2->getName() << std::endl;
    me2->use(0, *bob);
    me2->use(1, *me);
    delete bob;
    delete me;
    delete src;
    return 0;
}