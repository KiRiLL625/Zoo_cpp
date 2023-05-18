//
// Created by user on 10.05.2023.
//

#include "Animal.h"
#include <iostream>

Animal::Animal(const std::string& name, uint age, const std::string& breed) {
    this->name = name;
    this->age = age;
    this->breed = breed;
}

std::ostream& operator<<(std::ostream& out, const Animal& animal) {
    out << "_____________________________________\n" << animal.say() << "\n" << animal.play() <<
    "\n\tAnimal: " << animal.name << "\n\tAge: " << animal.age <<
    "\n\tSpecies: " << animal.getSpecies() << "\n\tBreed: " << animal.breed <<
    "\n_____________________________________" << std::endl;
    return out;
}

bool Animal::operator==(const Animal& other) const {
    return this->name == other.name && this->age == other.age &&
    this->breed == other.breed && this->getSpecies() == other.getSpecies();
}

const std::string Cat::species = "Cat";

Cat::Cat(const std::string& name, uint age, const std::string& breed):
    Animal(name, age, breed){
    //Cat::species = "Cat";
}

std::string Cat::getSpecies() const{
    return species;
}

std::string Cat::say() const {
    return "Meow!";
}

std::string Cat::play() const {
    return "I'm playing with a ball of yarn!";
}

const std::string Dog::species = "Dog";

Dog::Dog(const std::string& name, uint age, const std::string& breed):
    Animal(name, age, breed){
    //Dog::species = "Dog";
}

std::string Dog::getSpecies() const{
    return species;
}

std::string Dog::say() const{
    return "Woof!";
}

std::string Dog::play() const{
    return "I'm playing with a stick!";
}
