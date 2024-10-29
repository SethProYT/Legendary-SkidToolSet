#include "include/randipgen.hpp"
void randipgen() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 9);  // Changed to 0-9 for single digits
        
    std::string ipaddr;
        
    for (int i = 0; i < 4; ++i) {  // Generate 4 octets
        if (i > 0) ipaddr += ".";
        for (int j = 0; j < 3; ++j) {  // Each octet has up to 3 digits
            ipaddr += std::to_string(dis(gen));
        }
    }
        
    std::cout << ipaddr << std::endl;
}
