#include "LoadBalancer.h"
#include "Logger.h"
#include <iostream>
#include <vector>

void LoadBalancer::distributeClients(const std::vector<int>& serverList) {
    Logger::log("Distributing clients across servers...");
    // Placeholder logic for distributing clients to the least busy server
}

int LoadBalancer::chooseServer(const std::vector<int>& serverList) {
    // Basic round-robin load balancing (can replace with more complex algorithms)
    static size_t currentIndex = 0;
    int chosenServer = serverList[currentIndex % serverList.size()];
    currentIndex++;
    return chosenServer;
}
