/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:39:12 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/29 18:22:36 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : _name(name) {
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
}

Character::Character(Character const & src) : _name(src._name) {
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
    *this = src;
}

Character::~Character() {
    this->_clearInventory();
    this->_clearDroppedMaterias();
}

void Character::_clearInventory() {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i]) {
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
    }
}

void Character::_clearDroppedMaterias() {
    for (size_t i = 0; i < this->_droppedMaterias.size(); i++) {
        delete this->_droppedMaterias[i];
    }
    this->_droppedMaterias.clear();
}

Character & Character::operator=(Character const & rhs) {
    if (this != &rhs) {
        this->_name = rhs._name;
        
        this->_clearInventory();
        this->_clearDroppedMaterias();
        
        for (int i = 0; i < 4; i++) {
            if (rhs._inventory[i]) {
                this->_inventory[i] = rhs._inventory[i]->clone();
            } else {
                this->_inventory[i] = NULL;
            }
        }
    }
    return *this;
}

std::string const & Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria* m) {
    if (!m) {
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] == NULL) {
            this->_inventory[i] = m;
            return;
        }
    }
    // if the inventory is full, dont do anything and prevent memory leak.
    _droppedMaterias.push_back(m);
}

//unequip() member function must NOT delete the Materia!
void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && this->_inventory[idx]) {
        _droppedMaterias.push_back(this->_inventory[idx]);
        this->_inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->_inventory[idx]) {
        this->_inventory[idx]->use(target);
    }
}