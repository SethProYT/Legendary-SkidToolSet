#include <iostream>
#include <random>
#include <string>

void randipgen() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 9); 
        
    std::string ipaddr;
        
    for (int i = 0; i < 4; ++i) { 
        if (i > 0) ipaddr += ".";
        for (int j = 0; j < 3; ++j) { 
            ipaddr += std::to_string(dis(gen));
        }
    }
        
    std::cout << ipaddr << std::endl;
}
