#ifndef PROJ2_ALGOBESTFIRSTSEARCH_H
#define PROJ2_ALGOBESTFIRSTSEARCH_H

#include <string>
#include "Searcher.h"
#include "vector"
#include "MyPriorityQueue.h"
#include "Point.h"

using namespace std;

template <class Problem, class Solution>

class AlgoBestFirstSearch : public Searcher<Problem, Solution>{
    MyPriorityQueue<Problem> m_openList;
    MyPriorityQueue<Problem> m_closedList;

public:
    virtual Solution search(Searchable<Problem>* searchable) {
        this->m_numOfNodesEvaluated = 0;
        //adding the initalState to the open list.
        State<Problem>* init = searchable->getInitialState();
        State<Problem>* goal = searchable->getGoalState();
        m_openList.myPush(init);
        while (!m_openList.myEmpty()) {
            //start develop the node
            State<Problem> *minState = m_openList.myTop();
            m_openList.myPop();
            this->m_numOfNodesEvaluated++;
            m_closedList.myPush(minState);
            //if we got to the goal
            if (*minState == *goal) {
                vector<State<Problem> *> output = backTrace(init, minState);
                string sol = convertSolutionToString(output);
                return sol;
            }


            vector<State<Problem>*> successors = searchable->getAllPossibleState(minState);
            for (int i = 0; i < successors.size(); ++i) {
                if (!m_openList.myIsExist(successors[i]) && !m_closedList.myIsExist(successors[i])) {
                    m_openList.myPush(successors[i]);
                } else if (!m_closedList.myIsExist(successors[i])) {
                    State<Problem> *item = m_openList.myFind(successors[i]);
                    if (successors[i]->getCost() < item->getCost()) {
                        m_openList.myCut(item);
                        m_openList.myPush(successors[i]);
                    }else{
                        delete (successors[i]);
                    }
                } else {
                    delete (successors[i]);
                }
            }
        }

        string sol = "";
        return sol;
    }

    vector<State<Problem>*> backTrace(State<Problem> *init, State<Problem> *goal) {
        vector<State<Problem> *> trace;
        vector<State<Problem> *> output;
        State<Problem> *tempState = goal;

        while (!(*tempState == *init)) {
            trace.push_back(tempState);
            tempState = tempState->getCameFrom();
        }
        trace.push_back(init);

        for (int i = trace.size() - 1; i >= 0; i--) {
            output.push_back(trace[i]);
        }
        return output;
    }

    string convertSolutionToString(vector<State<Problem>*> vecSol){
        string sol;
        size_t vecSize = vecSol.size();
        for(size_t i = 0; i < vecSize - 1; i++){

            Point firstStatePoint = vecSol.at(i)->getState();
            Point secondStatePoint = vecSol.at(i + 1)->getState();

            if (firstStatePoint.getX() > secondStatePoint.getX()) {
                sol += "Up, ";
            } else if (firstStatePoint.getX() < secondStatePoint.getX()) {
                sol += "Down, ";
            } else if (firstStatePoint.getY() > secondStatePoint.getY()) {
                sol += "Left, ";
            } else if (firstStatePoint.getY() < secondStatePoint.getY()) {
                sol += "Right, ";
            }
        }
        return sol;
    }

    AlgoBestFirstSearch(){
    }
};


#endif //PROJ2_ALGOBESTFIRSTSEARCH_H
