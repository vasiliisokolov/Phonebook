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

void insert_data(std::map<std::string, std::map<std::string, int>>&, std::map<std::string, std::map<std::string, int>>&);
void find_surname(std::map<std::string, std::map<std::string, int>>&, std::vector<std::string>&);
void find_number(std::map<std::string, std::map<std::string, int>>&, std::vector<std::string>&);

int main()
{
    int operation;
    std::cout << "Phonebook!" << std::endl;
    std::map<std::string, std::map<std::string, int>> phoneBook;
    std::map<std::string, std::map<std::string, int>> phoneBookR;
    
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
                insert_data(phoneBook, phoneBookR);
                break;
            case command::find_surName:
                {
                    std::vector<std::string> res;
                }
                find_surname(phoneBook, res);
                for (int i = 0; i < res.size(); i++)
                {
                    std::cout << res[i] << " ";
                }
                std::cout << std::endl;
                break;
            case command::find_telNumber:
                {
                    std::vector<std::string> res; 
                }
                find_number(phoneBookR, res);
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

void insert_data(std::map<std::string, std::map<std::string, int>>& phoneBook, std::map<std::string, 
    std::map<std::string, int>>& phoneBookR)
{
    
    std::string number;
    std::string surname;
    std::cout << "Enter the telephone number: ";
    std::cin >> number;
    std::cout << "Enter the surname: ";
    std::cin >> surname;
    
    
    if (phoneBook.count(number) == 0)
    {
        std::map<std::string, int> list;
        list.insert(std::pair <std::string, int> (surname, 1));
        
        phoneBook.insert(std::pair<std::string, std::map<std::string, int>> (number, list));
    }
    else
    {
        std::map<std::string, std::map<std::string, int>> :: iterator it = phoneBook.find(number);
        it->second.insert(std::pair< std::string, int> (surname, 2));
    }

    if (phoneBookR.count(surname) == 0)
    {
        std::map<std::string, int> list;
        list.insert(std::pair <std::string, int>(number, 1));

        phoneBook.insert(std::pair<std::string, std::map<std::string, int>>(surname, list));
    }
    else
    {
        std::map<std::string, std::map<std::string, int>> ::iterator it = phoneBookR.find(surname);
        it->second.insert(std::pair< std::string, int>(number, 2));
    }
}


void find_surname(std::map<std::string, std::map<std::string, int>>& phoneBook, std::vector<std::string>& res)
{
    std::string insert;
    std::cout << "Enter the telephone number: ";
    std::cin >> insert;
    std::map<std::string, std::map<std::string, int>> ::iterator it = phoneBook.find(insert);
    
    if (it == phoneBook.end())
    {
        res.push_back("Abonent is not find!");
    }
    else
    {
        for (std::map<std::string, int > ::iterator itn = it->second.begin(); itn != it->second.end(); ++it)
        {
            res.push_back(itn->first);
           
        }
    }
}

void find_number(std::map<std::string, std::map<std::string, int>>& phoneBook, std::vector<std::string>& res)
{
    //std::map<std::string, std::string> ::iterator it = phoneBook.begin();
    std::string insert;
    std::cout << "Enter the surname: ";
    std::cin >> insert;
    std::map<std::string, std::map<std::string, int>> ::iterator it = phoneBook.find(insert);

    if (it == phoneBook.end())
    {
        res.push_back("Abonent is not find!");
    }
    else
    {
        for (std::map<std::string, int > ::iterator itn = it->second.begin(); itn != it->second.end(); ++it)
        {
            res.push_back(itn->first);

        }
    }
}