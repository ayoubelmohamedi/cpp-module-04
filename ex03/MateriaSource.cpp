/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:40:15 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/05 10:40:16 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    // Initialize templates array
    for (int i = 0; i < 4; i++) {
        this->_templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const & src) {
    // Initialize templates array
    for (int i = 0; i < 4; i++) {
        this->_templates[i] = NULL;
    }
    
    // Deep copy
    *this = src;
}

MateriaSource::~MateriaSource() {
    this->_clearTemplates();
}

void MateriaSource::_clearTemplates() {
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i]) {
            delete this->_templates[i];
            this->_templates[i] = NULL;
        }
    }
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
    if (this != &rhs) {
        // Clear current templates
        this->_clearTemplates();
        
        // Deep copy of templates
        for (int i = 0; i < 4; i++) {
            if (rhs._templates[i]) {
                this->_templates[i] = rhs._templates[i]->clone();
            }
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) {
        return; // Don't learn NULL
    }
    
    // Find first empty slot
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i] == NULL) {
            this->_templates[i] = m;
            return;
        }
    }
    
    // If templates is full, do nothing 
    // (or could delete the materia to avoid memory leak, but subject is unclear)
    delete m; // Prevent memory leak if we can't store it
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    // Find materia template with matching type
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i] && this->_templates[i]->getType() == type) {
            return this->_templates[i]->clone(); // Return a copy
        }
    }
    
    // If type not found, return 0 (NULL) as specified in the subject
    return NULL;
}