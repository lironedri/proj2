#include "MatrixProblemSolver.h"

string server_side::MatrixProblemSolver::solve(SearchableMatrix* problem) {
    string ans = m_algoType->search(problem);
    return ans;
}
