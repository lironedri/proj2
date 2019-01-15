#ifndef PROJ2_ALGOBESTFIRSTSEARCH_H
#define PROJ2_ALGOBESTFIRSTSEARCH_H

#include <string>
#include "Searcher.h"
#include "vector"

template <class T>

class AlgoBestFirstSearch : public Searcher<T, vector<State<T>*>>{
public:
    vector<State<T>*> search(Searchable<T>* searchable);
    virtual int getNumOfNodesEvaluated();
};


#endif //PROJ2_ALGOBESTFIRSTSEARCH_H
