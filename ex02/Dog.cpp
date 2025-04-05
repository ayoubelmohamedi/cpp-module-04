#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = other; // Ensure type is copied if base assignment doesn't handle it fully
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other); // Call base class assignment
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}
