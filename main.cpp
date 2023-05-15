#include "Zoo.h"
#include <iostream>
int main() {
    Zoo zoo1 = Zoo("Moscow Zoo", 5);
    Cat *cat1 = new Cat("Kitty", 2, "Persian");
    Dog *dog1 = new Dog("Balkan", 3, "German Shepherd");
    zoo1 << cat1 << dog1;
    std::cout << *zoo1[0] << std::endl;
    zoo1();
    Zoo zoo2 = Zoo("Moscow Zoo", 5);
    zoo2 << cat1 << dog1;
    std::cout << ((zoo1 == zoo2) ? "true" : "false") << std::endl;
    zoo2();
    return 0;
}
