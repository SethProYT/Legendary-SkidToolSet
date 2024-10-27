#include <iostream>
#include <string>
#include "include/DDos.hpp"
#include "include/Displayer.hpp"
#include "include/ipaddrlkup.hpp"

void display()  {
    std::cout << "Current set of features: " << std::endl;
    std::cout << "1. DDos" << std::endl;
    std::cout << "2. IP Address Lookup" << std::endl;
    std::cout << "3. Exit" << std::endl;
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
            return;
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            break;
    }
}
