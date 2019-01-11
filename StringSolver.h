#ifndef PROJ2_STRINGSOLVER_H
#define PROJ2_STRINGSOLVER_H

#include "Solver.h"
#include <string>

using namespace std;

namespace server_side {

    class StringSolver : public Solver<string, string> {
    public:
        virtual string solve(string problem);

    };
}

#endif //PROJ2_STRINGSOLVER_H
