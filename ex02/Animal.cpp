/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:19:20 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/05 10:05:07 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {}

Animal::Animal(const std::string& name) : type(name) {}

Animal::Animal(const Animal& other) {
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {}

const std::string Animal::getType() const {
    return (this->type);
}