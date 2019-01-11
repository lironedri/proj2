#ifndef PROJ2_StringReverser_H
#define PROJ2_StringReverser_H

#include "Solver.h"
#include <string>

using namespace std;

namespace server_side {

    class StringReverser : public Solver<string, string> {
    public:
        virtual string solve(string problem);

    };
}

#endif //PROJ2_StringReverser_H
