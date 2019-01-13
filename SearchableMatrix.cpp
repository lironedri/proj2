#include "SearchableMatrix.h"


State<Point> SearchableMatrix::getInitialState(){
    return this->m_init;
}

State<Point> SearchableMatrix::getGoalState(){
    return this->m_goal;
}

/**
 * returns all  successors of the given state.
 * @return
 */
vector<State<Point>> SearchableMatrix::getAllPossibleState(State<Point> state){
    vector<State<Point>> allNeighbors = this->getAllNeighbors(state);
    vector<State<Point>> allPossibleNeighbors;
    for (size_t i =0; i<allNeighbors.size(); i++){
        //in case the neighbor is not possible
        if (allNeighbors.at(i).getState().getX() != OUT_OF_RANGE){
            allPossibleNeighbors.push_back(allNeighbors.at(i));
        }
    }
    return allPossibleNeighbors;
}