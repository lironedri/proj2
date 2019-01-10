#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <string>

using namespace std;
template <class P, class S>

class FileCacheManager : public CacheManager<P, S>{
    string m_fileName;
public:
    FileCacheManager (string fileName){
        this->m_fileName = fileName;
    }

    /**
 * the function get a problem and return true if a solution for this problem saved in the cache,
 * false otherwise.
 * @param problem - the problem that we look for a solution that solve it.
 * @return boolean value
 */
    virtual bool isSolutionSaved(P problem) {
        return false;
    }

    /**
     * the function returns a solution for the given problem
     * @param problem
     * @return
     */
    //TODO: start the function with: if(isSolutionSaved(problem))
    virtual S getSolution(P problem) {}

    /**
     * the function save the given solution in the cache
     * @param solution
     */
    //TODO: check if we have to get a problem (maybe to save a solution-prob Map)
    virtual void saveSolution(S solution) {}
};


#endif //PROJ2_FILECACHEMANAGER_H



