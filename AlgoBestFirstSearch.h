#ifndef PROJ2_ALGOBESTFIRSTSEARCH_H
#define PROJ2_ALGOBESTFIRSTSEARCH_H

#include <string>
#include "Searcher.h"
#include "vector"
#include "MyPriorityQueue.h"

template <class T>

class AlgoBestFirstSearch : public Searcher<vector<State<T>*>, T>{
    MyPriorityQueue<T> m_openList;
    MyPriorityQueue<T> m_closedList;

public:
    virtual vector<State<T>*> search(Searchable<T> *searchable) {
        this->numOfNodesEvaluated = 0;
        //adding the initalState to the open list.
        State<T> *init = searchable->getInitialState();
        State<T> *goal = searchable->getGoalState();
        m_openList.push(init);
        while (!m_openList.empty()) {
            //start develop the node
            State<T> *minState = m_openList.pop();
            this->numOfNodesEvaluated++;
            m_closedList.push(minState);
            //if we got to the goal
            if (*minState == *goal) {
                vector<State<T> *> output = backTrace(init, minState);
                clearAll(output);
                return output;
            }


            vector<State<T> *> successors = searchable->getAllPossibleState(minState);
            for (int i = 0; i < successors.size(); ++i) {
                if (!m_openList.isExist(successors[i]) && !m_closedList.isExist(successors[i])) {
                    m_openList.push(successors[i]);
                } else if (!m_closedList.isExist(successors[i])) {
                    State<T> *item = m_openList.find(successors[i]);
                    if (successors[i]->getCost() < item->getCost()) {
                        m_openList.erase(item);
                        m_openList.push(successors[i]);
                    }else{
                        delete (successors[i]);
                    }
                } else {
                    delete (successors[i]);
                }
            }
        }

        vector<State<T> *> emptyVector;
        clearAll(emptyVector);
        return emptyVector;
    }

    vector<State<T> *> backTrace(State<T> *init, State<T> *goal) {
        vector<State<T> *> trace;
        vector<State<T> *> output;
        State<T> *tempState = goal;

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


    void clearAll(vector<State<T> *> output) {
        State<T> *temp;
        while (!m_openList.empty()) {
            delete (m_openList.pop());
        }
        while (!m_closedList.empty()) {

            temp = m_closedList.pop();

            for (int i = 0; i < output.size(); i++) {
                if (output[i] == temp) {
                    break;
                }
                if (i == output.size() - 1) {
                    delete (temp);
                }
            }

        }
    }

    AlgoBestFirstSearch(){

    }
};


#endif //PROJ2_ALGOBESTFIRSTSEARCH_H
