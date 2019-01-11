#ifndef PROJ2_MATRIXPROBLEMCLIENTHANDLER_H
#define PROJ2_MATRIXPROBLEMCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include <string>

using namespace std;
using namespace server_side;

class MatrixProblemClientHandler : public ClientHandler {
    Solver<string,string>* m_solver;
    CacheManager<string,string>* m_cacheManager;
public:
    void handleClient(int socketID);

};

#endif //PROJ2_MATRIXPROBLEMCLIENTHANDLER_H
