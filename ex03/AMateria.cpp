/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:39:02 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/05 10:39:03 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

// Constructor
AMateria::AMateria(std::string const & type) : _type(type) {
    // std::cout << "AMateria constructor called for type: " << _type << std::endl;
}

// Copy Constructor
AMateria::AMateria(AMateria const & src) {
    // std::cout << "AMateria copy constructor called" << std::endl;
    // The subject notes: "While assigning a Materia to another, copying the type doesn't make sense."
    // This likely refers to the assignment operator, not the copy constructor.
    // For a copy constructor, copying the type is appropriate.
    this->_type = src._type;
}

// Destructor
AMateria::~AMateria() {
    // std::cout << "AMateria destructor called for type: " << _type << std::endl;
}

// Assignment Operator
AMateria & AMateria::operator=(AMateria const & rhs) {
    // std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &rhs) {
        // The subject says: "While assigning a Materia to another, copying the type doesn’t make sense."
        // This means we should NOT copy the _type member.
        // this->_type = rhs._type; // Explicitly forbidden by the subject's note.
    }
    return *this;
}

// getType Method
std::string const & AMateria::getType() const {
    return this->_type;
}

// use Method (Default implementation, might be overridden)
// Note: The subject asks to implement use in concrete classes Ice and Cure.
// This base class version could be empty or provide a default message.
// Let's make it do nothing by default, as specific behavior is in derived classes.
void AMateria::use(ICharacter& target) {
    // Default implementation: does nothing or prints a generic message.
    // Since Ice and Cure have specific messages, let's print a generic one here
    // or leave it empty as derived classes MUST implement their specific behavior.
    // Let's leave it empty to avoid confusion.
    (void)target; // Avoid unused parameter warning
    // std::cout << "AMateria of type " << _type << " used on " << target.getName() << " (generic use)" << std::endl;
}