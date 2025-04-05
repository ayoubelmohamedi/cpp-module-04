/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:27:29 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/05 09:51:47 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog default constructor called" << std::endl;
    this->brain = new Brain(); // Allocate Brain
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain); // Deep copy Brain
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other); // Call base class assignment operator
        delete this->brain; // Delete old Brain
        this->brain = new Brain(*other.brain); // Deep copy new Brain
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain; // Deallocate Brain
}

void Dog::makeSound() const {
    std::cout << "Woof Woof" << std::endl;
}