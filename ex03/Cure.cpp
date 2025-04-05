/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:39:16 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/05 10:39:17 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(Cure const & src) : AMateria(src) {
}

Cure::~Cure() {
}

Cure & Cure::operator=(Cure const & rhs) {
    if (this != &rhs) {
        AMateria::operator=(rhs);
    }
    return *this;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}