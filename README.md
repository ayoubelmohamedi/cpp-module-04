# C++ Module 04 - Subtype Polymorphism, Abstract Classes, and Interfaces

## Description
This repository contains exercises that demonstrate the concepts of subtype polymorphism, abstract classes, and interfaces in C++. These are key features of object-oriented programming that enhance code flexibility and reusability.

## Table of Contents
- [Description](#description)
- [Core concepts](#core-concepts)
- [Exercise 1 - Subtype Polymorphism](#exercise-1---subtype-polymorphism)
- [Exercise 2 - Abstract Classes](#exercise-2---abstract-classes)
- [Exercise 3 - Interfaces](#exercise-3---interfaces)
- [Installation](#installation)

## Core concepts
  *Abstract Classes*: Can have both regular and pure virtual functions. Cannot be instantiated.
  *Interfaces*: A type of abstract class with only pure virtual functions. Defines a contract for derived classes.
  *Virtual Keyword*: Enables polymorphism by allowing functions to be overridden in derived classes. Pure virtual functions make a class abstract.

## Exercise 1 - Subtype Polymorphism
In this exercise, we explore subtype polymorphism, which allows a function to process objects differently based on their data type or class. We demonstrate how a base class pointer or reference can be used to call methods of derived classes.

### Concepts Covered
- Defining a base class
- Creating derived classes
- Using base class pointers and references to achieve polymorphism
- Implementing virtual functions

## Exercise 2 - Abstract Classes
This exercise focuses on abstract classes, which cannot be instantiated and are designed to be subclassed. Abstract classes often contain pure virtual functions that must be implemented by derived classes.

### Concepts Covered
- Defining an abstract class
- Creating pure virtual functions
- Inheriting from abstract classes
- Implementing pure virtual functions in derived classes

## Exercise 3 - Interfaces
In C++, interfaces can be implemented using abstract classes with only pure virtual functions. This exercise demonstrates how to define and use interfaces to ensure that derived classes implement specific methods.

### Concepts Covered
- Defining an interface using an abstract class
- Implementing interfaces in derived classes
- Using interface pointers and references

## Installation
To compile and run the exercises in this repository, you will need a C++ compiler. You can use g++ which is part of the GNU Compiler Collection.

On Ubuntu, you can install g++ with:
```bash
sudo apt-get update
sudo apt-get install g++
