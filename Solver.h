#ifndef PROJ2_SOLVER_H
#define PROJ2_SOLVER_H

//The algorithm that solve the problem
namespace server_side {
    template <class P, class S>

    class Solver {
    public:
        virtual S solve(P problem) = 0;
    };
}

#endif //PROJ2_SOLVER_H







