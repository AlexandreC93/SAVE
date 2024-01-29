#include "Zombie.hpp"

int main( void ) {
    std::string name;

    std::cout << "Creating a zombie" << std::endl;
    std::cout << "name: " << std::flush;
    std::cin >> name;
    Zombie aZombie(name);
    std::cout << "Creating The Zombie" << std::endl;
    std::cout << "name: " << std::flush;
    std::cin >> name;
    Zombie *theZombie = newZombie(name);
    theZombie->announce();
    delete theZombie;

    std::cout << "Calling randomChump()." << std::endl;
    randomChump("Carlos the random zombie");
    return 0;
}