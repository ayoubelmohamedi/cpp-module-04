/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:39:21 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/05 10:39:22 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(Ice const & src) : AMateria(src) {
}

Ice::~Ice() {
}

Ice & Ice::operator=(Ice const & rhs) {
    if (this != &rhs) {
        AMateria::operator=(rhs);
    }
    return *this;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}