#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>

class LoadBalancer {
public:
    // Distribute clients across available servers
    static void distributeClients(const std::vector<int>& serverList);

    // Choose a server based on load balancing algorithm
    static int chooseServer(const std::vector<int>& serverList);
};

#endif // LOADBALANCER_H
