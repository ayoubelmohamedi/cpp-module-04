#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    // Animal meta; // This should cause a compile-time error because Animal is abstract
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;
    std::cout << "Dog Type: " << j->getType() << " " << std::endl;
    std::cout << "Cat Type: " << i->getType() << " " << std::endl;
    std::cout << std::endl;
    std::cout << "Cat Sound: ";
    i->makeSound(); // will output the cat sound!
    std::cout << "Dog Sound: ";
    j->makeSound(); // will output the dog sound!
    std::cout << std::endl;

    delete j; // Should call Dog destructor then Animal destructor
    delete i; // Should call Cat destructor then Animal destructor
    std::cout << std::endl;

    // Test array of Animals
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

    // Test copy constructor and assignment operator
    std::cout << "--- Testing Copy/Assignment ---" << std::endl;
    Dog basic_dog;
    {
        Dog tmp_dog = basic_dog; // Copy constructor
        std::cout << "Inside scope, tmp_dog type: " << tmp_dog.getType() << std::endl;
    } // tmp_dog goes out of scope here, destructor called

    Cat basic_cat;
    Cat assigned_cat;
    assigned_cat = basic_cat; // Assignment operator
    std::cout << "Assigned cat type: " << assigned_cat.getType() << std::endl;
    std::cout << "--- End Testing Copy/Assignment ---" << std::endl;


    return 0;
}
