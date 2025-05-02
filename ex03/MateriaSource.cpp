/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:40:15 by macbookpro        #+#    #+#             */
/*   Updated: 2025/05/01 21:52:39 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        this->_templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const & src) {
    for (int i = 0; i < 4; i++) {
        this->_templates[i] = NULL;
    }
    
    *this = src;
}

MateriaSource::~MateriaSource() {
    this->_clearTemplates();
    this->_dropDroppedTemplates();
}

void MateriaSource::_clearTemplates() {
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i]) {
            delete this->_templates[i];
            this->_templates[i] = NULL;
        }
    }
}

void MateriaSource::_dropDroppedTemplates() {
    for (size_t i = 0; i < this->_droppedTemplates.size(); i++) {
        delete this->_droppedTemplates[i];
    }
    this->_droppedTemplates.clear();
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
    if (this != &rhs) {
    {
        this->_clearTemplates();
        this->_dropDroppedTemplates();
    }
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
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i] == NULL) {
            this->_templates[i] = m;
            return;
        }
    }
    this->_droppedTemplates.push_back(m);
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i] && this->_templates[i]->getType() == type) {
            return this->_templates[i]->clone(); 
        }
    } 
    return NULL; // Returns 0 if the type is unknown. 
}