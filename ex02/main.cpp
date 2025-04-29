/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:16:50 by ael-moha          #+#    #+#             */
/*   Updated: 2025/04/29 18:17:50 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;
    std::cout << "Dog Type: " << j->getType() << " " << std::endl;
    std::cout << "Cat Type: " << i->getType() << " " << std::endl;
    std::cout << std::endl;
    std::cout << "Cat Sound: ";
    i->makeSound();
    std::cout << "Dog Sound: ";
    j->makeSound();
    std::cout << std::endl;

    delete j;
    delete i;
    std::cout << std::endl;

    const int arraySize = 4;
    Animal* animals[arraySize];

    std::cout << "--- Creating animals array ---" << std::endl;
    for (int k = 0; k < arraySize / 2; ++k) {
        animals[k] = new Dog();
    }
    for (int k = arraySize / 2; k < arraySize; ++k) {
        animals[k] = new Cat();
    }
    std::cout << std::endl;

    std::cout << "--- Making sounds ---" << std::endl;
    for (int k = 0; k < arraySize; ++k) {
        std::cout << animals[k]->getType() << " says: ";
        animals[k]->makeSound();
    }
    std::cout << std::endl;

    std::cout << "--- Deleting animals array ---" << std::endl;
    for (int k = 0; k < arraySize; ++k) {
        delete animals[k];
    }
    std::cout << std::endl;

    std::cout << "--- Testing Copy/Assignment ---" << std::endl;
    Dog basic_dog;
    {
        Dog tmp_dog = basic_dog;
        std::cout << "Inside scope, tmp_dog type: " << tmp_dog.getType() << std::endl;
    }

    Cat basic_cat;
    Cat assigned_cat;
    assigned_cat = basic_cat;
    std::cout << "Assigned cat type: " << assigned_cat.getType() << std::endl;
    std::cout << "--- End Testing Copy/Assignment ---" << std::endl;

    return 0;
}
