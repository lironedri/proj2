#ifndef PROJ2_MYTESTCLIENTHANDLER_H
#define PROJ2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include <string>
using namespace std;
namespace server_side {
    class MyTestClientHandler : public ClientHandler {
        Solver<string, string> *m_solver;
        CacheManager<string, string> *m_cacheManager;
    public:
        MyTestClientHandler(Solver<string, string> *solver, CacheManager<string, string> *cacheManager) {
            this->m_solver = solver;
            this->m_cacheManager = cacheManager;
        }

        void handleClient(int socketID);
    };
}

#endif //PROJ2_MYTESTCLIENTHANDLER_H










