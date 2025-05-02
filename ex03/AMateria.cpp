/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:39:02 by macbookpro        #+#    #+#             */
/*   Updated: 2025/05/02 20:13:49 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : _type(type) {
}

AMateria::AMateria(AMateria const & src) {
    this->_type = src._type;
}

AMateria::~AMateria() {
}

AMateria & AMateria::operator=(AMateria const & rhs) {
    if (this != &rhs)
        this->_type = rhs._type;
    return *this;
}

std::string const & AMateria::getType() const {
    return this->_type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
}