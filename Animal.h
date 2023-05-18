//
// Created by user on 10.05.2023.
//
#ifndef ZOO_ANIMAL_H
#define ZOO_ANIMAL_H

#include <string>

typedef unsigned int uint;

class Animal {
protected:
    uint age;
    //static std::string species;
    std::string breed;
    std::string name;
public:
    Animal(const std::string& name, uint age, const std::string& breed);
    virtual std::string say() const = 0;
    virtual std::string play() const = 0;
    virtual std::string getSpecies() const = 0;
    friend std::ostream& operator<<(std::ostream& out, const Animal& animal);
    bool operator==(const Animal& other) const;
};

class Cat: public Animal {
private:
    static const std::string species;
public:
    Cat(const std::string& name, uint age, const std::string& breed);
    std::string getSpecies() const override;
    std::string say() const override;
    std::string play() const override;
};

class Dog: public Animal {
private:
    static const std::string species;
public:
    Dog(const std::string& name, uint age, const std::string& breed);
    std::string getSpecies() const override;
    std::string say() const override;
    std::string play() const override;
};

#endif //ZOO_ANIMAL_H
