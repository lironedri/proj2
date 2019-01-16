#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <string>
#include <map>
#include <fstream>

using namespace std;
template <class P, class S>

class FileCacheManager : public CacheManager<string, string>{
    map<string, string> m_problemSolutionMap;
    string m_fileName;
public:
    FileCacheManager (string fileName){
        this->m_fileName = fileName;
        string problem = "";
        string solution = "";
        ifstream myFile(fileName);
        if (myFile.is_open()) {
            while (!myFile.eof()) {
                getline(myFile, problem, ',');
                getline(myFile, solution);
                if (problem != "") {
                    m_problemSolutionMap[problem] = solution;
                }
            }
            myFile.close();
        }
    }

    /**
 * the function get a problem and return true if a solution for this problem saved in the cache,
 * false otherwise.
 * @param problem - the problem that we look for a solution that solve it.
 * @return boolean value
 */
    virtual bool isSolutionSaved(P problem) {
        if (m_problemSolutionMap.count(problem)){
            return true;
        }
        return false;
    }

    /**
     * the function returns a solution for the given problem
     * @param problem
     * @return
     */
    virtual S getSolution(P problem) {
        if (isSolutionSaved(problem)){
            return m_problemSolutionMap.at(problem);
        } else {
            perror("saved solution doe's not exist");
        }
    }

    /**
     * the function save the given solution in the cache
     * @param solution
     */
    virtual void saveSolution(P problem, S solution) {
        m_problemSolutionMap[problem] = solution;
        ofstream myFile(m_fileName, ios::app);
        if (myFile.is_open()) {
            myFile << problem + "," + solution + "\n";
            myFile.close();
        }
    }
};


#endif //PROJ2_FILECACHEMANAGER_H



