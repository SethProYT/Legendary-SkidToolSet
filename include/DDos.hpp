#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <cstdlib>
#include <mutex>

extern std::mutex threadguard;

void DDos(const std::string &ipaddr, int pings);
void ThreadHandler(int pings, const std::string &ipaddr, bool useThreads = false, const int amountofthreads = 1);
void DDosInit(bool self = false);
