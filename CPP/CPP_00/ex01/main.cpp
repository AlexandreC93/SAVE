#include "PhoneBook.hpp"

int main(int ac, char **av) {
	(void)av;
    PhoneBook book;
    std::string input = "";
	if (ac > 1)
	{
		std::cout << "Try again with no parameters" << std::endl;
		return 0;
	}
    book.init();
    do {
        std::cout << ">> " << std::flush;
        if (!std::getline(std::cin, input))
            break;
        if (input == "EXIT")
            break;
        else if (input == "ADD")
            book.addContact();
        else if (input == "SEARCH") {
            book.printContacts();
            book.search();
        }
        else if (input[0] == 0)
            continue;
        else
            std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
    std::cin.clear();
    } while (true);
    return 0;
}






