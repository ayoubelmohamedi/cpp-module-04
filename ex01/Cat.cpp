/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:22:54 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/05 09:51:42 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat default constructor called" << std::endl;
    this->brain = new Brain(); // Allocate Brain
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain); // Deep copy Brain
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other); // Call base class assignment operator
        delete this->brain; // Delete old Brain
        this->brain = new Brain(*other.brain); // Deep copy new Brain
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain; // Deallocate Brain
}

void Cat::makeSound() const {
    std::cout << "Meow Meow" << std::endl;
}
