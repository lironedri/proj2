#ifndef PROJ2_ALGOBESTFIRSTSEARCH_H
#define PROJ2_ALGOBESTFIRSTSEARCH_H

#include <string>
#include "Searcher.h"
#include "vector"


class AlgoBestFirstSearch : public Searcher<vector<string>>{
    virtual <vector<string>> search(Searchable searchable);
    virtual int getNumOfNodesEvaluated();
};


#endif //PROJ2_ALGOBESTFIRSTSEARCH_H
