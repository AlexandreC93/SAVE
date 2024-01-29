#include "Utils.hpp"

int main (int ac, char **av)
{
    if (ac != 4) {
        std::cerr << "./Sed <filename> <to_find> <replace>." << std::endl;
        return EXIT_FAILURE;
    } else {
        Utils   sed2(av[1]);
        sed2.replace(av[2], av[3]);
    }
    return EXIT_SUCCESS;
}
