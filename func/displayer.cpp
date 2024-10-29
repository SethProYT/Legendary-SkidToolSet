#include <iostream>
#include <string>
#include "include/DDos.hpp"
#include "helpers/Displayer.hpp"
#include "include/ipaddrlkup.hpp"
#include "include/doxcreator.hpp"

void display()  {
    std::cout << "Current set of features: " << std::endl;
    std::cout << "1. DDos" << std::endl;
    std::cout << "2. IP Address Lookup" << std::endl;
    std::cout << "3. Dox Creator" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Type here: ";
    char answer;
    std::cin >> answer;

    switch(answer) {
        case '1':
            DDosInit(false);
            break;
        case '2':
            ipaddrinit();
            break;
        case '3':
            doxcreator();
            break;
        case '4':
            return;
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            break;
    }
}
