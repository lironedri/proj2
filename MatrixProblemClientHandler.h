#ifndef PROJ2_MATRIXPROBLEMCLIENTHANDLER_H
#define PROJ2_MATRIXPROBLEMCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include <string>
#include "SearchableMatrix.h"

using namespace std;
using namespace server_side;

class MatrixProblemClientHandler : public ClientHandler {
    Solver<SearchableMatrix, string> *m_solver;
    CacheManager<string, string> *m_cacheManager;
public:
    MatrixProblemClientHandler(Solver<SearchableMatrix, string> *solver, CacheManager<string, string> *cacheManager){
        this->m_solver = solver;
        this->m_cacheManager = cacheManager;
    }

    void handleClient(int socketID);
};

#endif //PROJ2_MATRIXPROBLEMCLIENTHANDLER_H
