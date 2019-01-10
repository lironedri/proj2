#ifndef PROJ2_SOLVER_H
#define PROJ2_SOLVER_H

template <class P, class S>
//The algorithm that solve the problem
class Solver{
public:
    virtual S solve(P problem) = 0;
};

#endif //PROJ2_SOLVER_H







