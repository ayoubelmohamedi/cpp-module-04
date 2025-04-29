/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:19:20 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/29 18:16:19 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const std::string& name) : type(name) {
    std::cout << "Animal Name constructor called for " << this->type << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal Destructor called for " << this->type << std::endl;
}

const std::string Animal::getType() const {
    return (this->type);
}