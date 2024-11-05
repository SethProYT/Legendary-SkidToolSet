#pragma once

#include <iostream>
#include "DDos.hpp"
#include "doxcreator.hpp"
#include "ipaddrlkup.hpp"
#include "randipgen.hpp"


void display()  {
    std::cout << "Current set of features: " << std::endl;
    std::cout << "1. DDos" << std::endl;
    std::cout << "2. IP Address Lookup" << std::endl;
    std::cout << "3. Dox Creator" << std::endl;
    std::cout << "4. IP Address Generator" << std::endl;
    std::cout << "5. Exit" << std::endl;
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
            randipgen(); 
            break;
        case '5':
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            break;
    }
}
