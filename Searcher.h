#ifndef PROJ2_SEARCHER_H
#define PROJ2_SEARCHER_H

#include "Searchable.h"

template <class Solution>
class Searcher {
public:
    virtual Solution search(Searchable searchable) = 0;
    virtual int getNumOfNodesEvaluated() = 0;
};

#endif //PROJ2_SEARCHER_H
