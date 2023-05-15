//
// Created by user on 10.05.2023.
//

#include "Animal.h"
#include <iostream>

std::string Animal::species;

Animal::Animal(const std::string& name, uint age, const std::string& breed) {
    this->name = name;
    this->age = age;
    this->breed = breed;
}

std::string Animal::getSpecies(){
    return Animal::species;
}

std::ostream& operator<<(std::ostream& out, const Animal& animal) {
    out << "______________________\n" << animal.say() << "\n" << animal.play() <<
    "\n\tAnimal: " << animal.name << "\n\tAge: " << animal.age <<
    "\n\tSpecies: " << Animal::getSpecies() << "\n\tBreed: " << animal.breed <<
    "\n______________________" << std::endl;
    return out;
}

bool Animal::operator==(const Animal& other) const {
    return this->name == other.name && this->age == other.age &&
    this->breed == other.breed && getSpecies() == Animal::getSpecies();
}

Cat::Cat(const std::string& name, uint age, const std::string& breed):
    Animal(name, age, breed){
    Animal::species = "Cat";
}

std::string Cat::say() const {
    return "Meow!";
}

std::string Cat::play() const {
    return "I'm playing with a ball of yarn!";
}

Dog::Dog(const std::string& name, uint age, const std::string& breed):
    Animal(name, age, breed){
    Animal::species = "Dog";
}

std::string Dog::say() const {
    return "Woof!";
}

std::string Dog::play() const{
    return "I'm playing with a stick!";
}