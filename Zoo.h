//
// Created by user on 12.05.2023.
//

#ifndef ZOO_ZOO_H
#define ZOO_ZOO_H

#include <vector>
#include "Animal.h"
class Zoo {
private:
    std::string name;
    unsigned int cellsCount;
    std::vector<Animal*> animals;
public:
    Zoo(const std::string& name, unsigned int cellsCount);
    Zoo(Zoo&& otherZoo) noexcept;
    Zoo(const Zoo& otherZoo) = delete;
    void put(Animal* animal);
    Animal* get();
    Animal* operator[](unsigned int index);
    Zoo& operator=(Zoo&& otherZoo) noexcept;
    Zoo& operator=(const Zoo& otherZoo) = delete;
    Zoo& operator<<(Animal* animal);
    bool operator==(const Zoo& otherZoo);
    void operator()();
};


#endif //ZOO_ZOO_H
