#include "include/doxcreator.hpp"

void doxcreator() {
    // Information variables
    std::string name;
    std::string DOB;
    std::vector<std::string> addresses;
    std::vector<std::string> emails;
    std::vector<std::string> phones;
    std::vector<std::string> socials;
    std::vector<std::string> misc;


    bool toggle = false;

    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Date of Birth: ";
    std::cin >> DOB;


    collectData(addresses, "Addresses");
    collectData(emails, "Emails");
    collectData(phones, "Phones");
    collectData(socials, "Socials");
    collectData(misc, "Misc");


    std::cout << "NAME: " << name << std::endl;
    std::cout << "DOB: " << DOB << std::endl;

    std::cout << "[+] ---------- Addresses -------------- [+]" << std::endl;

    for (int i = 0; i < addresses.size(); i++) {
        std::cout << addresses[i] << std::endl;
    }

    std::cout << "[+] ---------- Emails -------------- [+]" << std::endl;

    for (int i = 0; i < emails.size(); i++) {
        std::cout << emails[i] << std::endl;
    }

    std::cout << "[+] ---------- Phones -------------- [+]" << std::endl;

    for (int i = 0; i < phones.size(); i++) {
        std::cout << phones[i] << std::endl;
    }

    std::cout << "[+] ---------- Socials -------------- [+]" << std::endl;

    for (int i = 0; i < socials.size(); i++) {
        std::cout << socials[i] << std::endl;
    }

    std::cout << "[+] ---------- Misc -------------- [+]" << std::endl;

    for (int i = 0; i < misc.size(); i++) {
        std::cout << misc[i] << std::endl;
    }
}

void collectData(std::vector<std::string>& data, const std::string& prompt) {
    bool toggle = false;
    while (toggle == false) {
        std::cout << prompt << ": ";
        std::string item;
        std::getline(std::cin, item);
        data.push_back(item);
        std::cout << "More " << prompt << "? y/n: ";
        std::string answer;
        std::getline(std::cin, answer);
        if (answer == "n") {
            toggle = true;
        }
    }
}