#include <iostream>
#include <string>
#include "include/DDos.hpp"
#include "include/Displayer.hpp"

int main()  {
    std::cout << "hi would you like to go self mode y/n: ";
    std::string answer;
    std::cin >> answer;
    if (answer == "y") {
        std::cout << "Using IP Address: localhost" << std::endl;
        DDosInit(true);
    } else if (answer == "n") {
        DDosInit(false);
        std::cout << "Finished!" << std::endl;
        display();
    }

}