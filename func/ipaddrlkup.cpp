#include "include/ipaddrlkup.hpp"

int ipaddrget(const std::string &ipaddr) {
    auto response = cpr::Get(cpr::Url{"https://ipinfo.io/" + ipaddr + "/json"});

    if (response.status_code == 200) {
        std::cout << "IP Lookup Result:\n" << response.text << std::endl;
    } else {
        std::cerr << "Failed to retrieve information. Status code: " << response.status_code << std::endl;
    }

    std::cout << response.text << std::endl;

    return 0;
}


void ipaddrinit() {
    std::string ipaddr;
    std::cout << "Enter IP Address: ";
    std::cin >> ipaddr;
    ipaddrget(ipaddr);
}