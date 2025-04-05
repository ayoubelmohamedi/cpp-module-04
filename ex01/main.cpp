/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:19:23 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/05 09:51:52 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    const int arraySize = 10; // Example size, can be any even number
    Animal* animals[arraySize];

    // Fill the first half with Dogs
    for (int i = 0; i < arraySize / 2; ++i) {
        std::cout << "Creating Dog " << i << std::endl;
        animals[i] = new Dog();
        std::cout << std::endl;
    }

    // Fill the second half with Cats
    for (int i = arraySize / 2; i < arraySize; ++i) {
        std::cout << "Creating Cat " << i << std::endl;
        animals[i] = new Cat();
        std::cout << std::endl;
    }

    std::cout << "\n--- Deleting Animals ---" << std::endl;
    // Delete all animals
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Deleting Animal " << i << " (" << animals[i]->getType() << ")" << std::endl;
        delete animals[i];
        std::cout << std::endl;
    }

    // Example to test deep copy (optional)
    std::cout << "\n--- Testing Deep Copy ---" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
        // tmp goes out of scope here, its destructor is called
        std::cout << "tmp Dog going out of scope" << std::endl;
    }
    std::cout << "basic Dog still exists" << std::endl;
    // basic goes out of scope here, its destructor is called

    return 0;
}