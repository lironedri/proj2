#ifndef PROJ2_MATRIXPROBLEMSOLVER_H
#define PROJ2_MATRIXPROBLEMSOLVER_H

#include "Solver.h"
#include "SearchableMatrix.h"
#include <string>
#include "AlgoBestFirstSearch.h"
#include "Searcher.h"

namespace server_side {

    class MatrixProblemSolver : public Solver<SearchableMatrix, string>{
        Searcher<SearchableMatrix, string>* m_algoType;
    public:
        MatrixProblemSolver(Searcher<SearchableMatrix, string>* algoType){
            this->m_algoType = algoType;
        }
        virtual string solve(SearchableMatrix problem);
    };
}


#endif //PROJ2_MATRIXPROBLEMSOLVER_H
