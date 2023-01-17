#include <iostream>
#include <map>
#include <string>
#include <vector>

enum command
{
    add = 1,
    find_surname = 2,
    find_telNumber = 3

};

int main()
{
    int operation;
    std::cout << "Phonebook!" << std::endl;
    std::map<std::string, std::string> phoneBook;
    std::cout << "Choose the operation:" << std::endl;
    std::cout << "To add the abonent - press 1" << std::endl;
    std::cout << "To find abonent's surname - press 2" << std::endl;
    std::cout << "To find abonent' telefonnumber - press 3" << std::endl;

    switch (operation)
    {
    case command::add:
        break;
    case command::find_surname:
        break;
    case command::find_telNumber:
        break;
    }
}

