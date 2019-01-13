#ifndef PROJ2_SEARCHABLE_H
#define PROJ2_SEARCHABLE_H

#include <vector>
#include "State.h"

template <class T>

class Searchable {
protected:
    State<T>* m_init;
    State<T>* m_goal;
    vector<State<T>>* m_states;

public:
    Searchable(State<T>* init, State<T>* goal, vector<State<T>>* states){
        this->m_init = init;
        this->m_goal = goal;
        this->m_states = states;
    }
    virtual State<T>* getInitialState() = 0;
    virtual State<T>* getGoalState() = 0;
    virtual vector<State<T>>* getAllPossibleState(State<T> state) = 0;
};

#endif //PROJ2_SEARCHABLE_H
