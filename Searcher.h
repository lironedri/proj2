#ifndef PROJ2_SEARCHER_H
#define PROJ2_SEARCHER_H

#include "Searchable.h"

template <class Solution>
class Searcher {
protected:
    int m_numOfNodesEvaluated = 0;
public:
    virtual Solution search(Searchable searchable) = 0;
    virtual int getNumOfNodesEvaluated(){
        return this->m_numOfNodesEvaluated;
    }
};

#endif //PROJ2_SEARCHER_H
