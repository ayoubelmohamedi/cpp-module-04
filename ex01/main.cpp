/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:19:23 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/29 18:16:08 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    const int arraySize = 10;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize / 2; ++i) {
        std::cout << "Creating Dog " << i << std::endl;
        animals[i] = new Dog();
        std::cout << std::endl;
    }

    for (int i = arraySize / 2; i < arraySize; ++i) {
        std::cout << "Creating Cat " << i << std::endl;
        animals[i] = new Cat();
        std::cout << std::endl;
    }

    std::cout << "\n--- Deleting Animals ---" << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Deleting Animal " << i << " (" << animals[i]->getType() << ")" << std::endl;
        delete animals[i];
        std::cout << std::endl;
    }

    std::cout << "\n--- Testing Deep Copy ---" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
        std::cout << "tmp Dog going out of scope" << std::endl;
    }
    std::cout << "basic Dog still exists" << std::endl;

    return 0;
}