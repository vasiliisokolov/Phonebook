#include <iostream>
#include <map>
#include <string>
#include <vector>

enum command
{
    add = 1,
    find_surName = 2,
    find_telNumber = 3,
    out = 4

};

void insert_data(std::map<std::string, std::string>&);
std::string find_surname(std::map<std::string, std::string>&);
void find_number(std::map<std::string, std::string>&, std::vector<std::string>&);

int main()
{
    int operation;
    std::cout << "Phonebook!" << std::endl;
    std::map<std::string, std::string> phoneBook;
    while (true)
    {
        std::cout << "Choose the operation:" << std::endl;
        std::cout << "To add the abonent - press 1" << std::endl;
        std::cout << "To find abonent's surname - press 2" << std::endl;
        std::cout << "To find abonent' telefonnumber - press 3" << std::endl;
        std::cout << "To exit - press 4" << std::endl;
        std::cin >> operation;
        if (operation > 0 && operation < 5)
        {
            std::vector<std::string> res;
            switch (operation)
            {
            case command::add:
                insert_data(phoneBook);
                break;
            case command::find_surName:
                std::cout << find_surname(phoneBook) << std::endl;
                break;
            case command::find_telNumber:
                {
                    std::vector<std::string> res; 
                }
                find_number(phoneBook, res);
                for (int i = 0; i < res.size(); i++)
                {
                    std::cout << res[i] << " ";
                }
                std::cout << std::endl;
                break;
            case command::out:
                return 0;
            }
        }
        else
        {
            std::cerr << "Error! Invalid command!" << std::endl;
            
        }
    }
}

void insert_data(std::map<std::string, std::string>& phoneBook)
{
    std::pair<std::string, std::string> insert;
    std::cout << "Enter the telephone number: ";
    std::cin >> insert.first;
    std::cout << "Enter the surname: ";
    std::cin >> insert.second;
    phoneBook.insert(insert);
}

std::string find_surname(std::map<std::string, std::string>& phoneBook)
{
    std::string insert;
    std::cout << "Enter the telephone number: ";
    std::cin >> insert;
    std::map<std::string, std::string> ::iterator it;
    it = phoneBook.find(insert);
    if (it == phoneBook.end())
    {
        return "Abonent is not find!";
    }
    else
    {
        return it->second;
    }
}

void find_number(std::map<std::string, std::string>& phoneBook, std::vector<std::string>& res)
{
    std::map<std::string, std::string> ::iterator it = phoneBook.begin();
    std::string insert;
    std::cout << "Enter the surname: ";
    std::cin >> insert;
    for (std::map<std::string, std::string> ::iterator it = phoneBook.begin(); it != phoneBook.end(); ++it)
    {
        if (it->second == insert)
        {
            res.push_back(it->first);
        }
    }
}