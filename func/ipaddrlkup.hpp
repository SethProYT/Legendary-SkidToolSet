#include <cpr/cpr.h>
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>

int ipaddressget(const std::string &ipaddr) {
    auto response = cpr::Get(cpr::Url{"https://ipinfo.io/" + ipaddr + "/json"});

    if (response.status_code == 200) {

    nlohmann::json json = nlohmann::json::parse(response.text);
    int i = 0;

    // beatifier
    for (auto& [key, value] : json.items()) {
        if (i == 0)  {std::cout << "IP Results: \n";}
        i++;
        std::cout << key << ": " << value << std::endl;
    }

    } else {
        std::cerr << "Failed to retrieve information. Status code: " << response.status_code << std::endl;
    }



    return 0;
}

void ipaddrinit() {
    std::string ipaddress;
    std::cout << "Enter IP Address: ";
    std::cin >> ipaddress;
    ipaddressget(ipaddress);
}