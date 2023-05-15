//
// Created by user on 12.05.2023.
//
#include <iostream>
#include "Zoo.h"

Zoo::Zoo(const std::string &name, unsigned int cellsCount){
    this->name = name;
    this->cellsCount = cellsCount;
    animals = std::vector<Animal*>();
}

Zoo::Zoo(Zoo&& otherZoo) noexcept{
    this->name = otherZoo.name;
    this->cellsCount = otherZoo.cellsCount;
    animals = std::vector<Animal*>(cellsCount);
    for (int i = 0; i < cellsCount; ++i) {
        animals[i] = otherZoo.animals[i];
    }
}

void Zoo::put(Animal *animal){
    if(animals.size() == cellsCount){
        std::cout << "Zoo is full!" << std::endl;
    }
    animals.push_back(animal);
}

Animal* Zoo::get(){
    if(animals.empty()){
        std::cout << "Zoo is empty!" << std::endl;
    }
    Animal* animal = animals.back();
    animals.pop_back();
    return animal;
}

Animal* Zoo::operator[](unsigned int index){
    if(animals.size() <= index <= this->cellsCount){
        std::cout << "Cell is empty!" << std::endl;
    }
    if(index >= cellsCount){
        std::cout << "Index is out of range!" << std::endl;
    }
    return animals[index];
}

Zoo& Zoo::operator=(Zoo&& otherZoo) noexcept{
    if(this == &otherZoo){
        return *this;
    }
    this->name = otherZoo.name;
    this->cellsCount = otherZoo.cellsCount;
    animals = std::vector<Animal*>(cellsCount);
    for (int i = 0; i < cellsCount; i++) {
        animals[i] = otherZoo.animals[i];
    }
    return *this;
}

Zoo& Zoo::operator<<(Animal *animal) {
    put(animal);
    return *this;
}

bool Zoo::operator==(const Zoo& otherZoo){
    if(animals.size() != otherZoo.animals.size()){
        return false;
    }
    for (auto& i : animals) {
        bool flag = false;
        for(auto j : otherZoo.animals) {
            if(*i == *j){
                flag = true;
                break;
            }
        }
        if(!flag){
            return false;
        }
    }
    return true;
}

void Zoo::operator()(){
    std::cout << "_______________________________________________________" << std::endl;
    std::cout << "______________________ZOO______________________________" << std::endl;
    std::cout << "Zoo name: " << name << std::endl;
    std::cout << "Animals in the zoo: " << std::endl;
    for(auto animal : animals){
        std::cout << *animal << std::endl;
    }
    std::cout << "Free cells: " << cellsCount - animals.size() << std::endl;
    std::cout << "_______________________________________________________" << std::endl;
}