/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:39:12 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/05 10:39:13 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : _name(name) {
    // Initialize inventory slots to NULL
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
}

Character::Character(Character const & src) : _name(src._name) {
    // Initialize inventory slots to NULL
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
    
    // Deep copy of the inventory
    *this = src;
}

Character::~Character() {
    this->_clearInventory();
}

void Character::_clearInventory() {
    // Delete all Materias in the inventory
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i]) {
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
    }
}

Character & Character::operator=(Character const & rhs) {
    if (this != &rhs) {
        this->_name = rhs._name;
        
        // Clear current inventory
        this->_clearInventory();
        
        // Deep copy of inventory
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
        return; // Don't equip NULL
    }
    
    // Find first empty slot
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] == NULL) {
            this->_inventory[i] = m;
            return;
        }
    }
    
    // If inventory is full, do nothing (as per subject)
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && this->_inventory[idx]) {
        // The unequip function must NOT delete the Materia!
        this->_inventory[idx] = NULL;
    }
    // If idx is invalid or the slot is empty, do nothing
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->_inventory[idx]) {
        this->_inventory[idx]->use(target);
    }
    // If idx is invalid or the slot is empty, do nothing
}