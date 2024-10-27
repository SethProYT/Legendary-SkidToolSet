#include <iostream>
#include <string>
#include "include/DDos.hpp"
#include "include/Displayer.hpp"

void display()  {
    std::cout << "Current set of features: " << std::endl;
    std::cout << "1. DDos" << std::endl;
    
    char answer;
    std::cin >> answer;

    switch(answer) {
        case '1':
            DDosInit(false);
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            break;
    }
}
