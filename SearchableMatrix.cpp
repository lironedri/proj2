#include "SearchableMatrix.h"


State<Point>* SearchableMatrix::getInitialState(){
    return this->m_init;
}

State<Point>* SearchableMatrix::getGoalState(){
    return this->m_goal;
}

/**
 * returns all  successors of the given state.
 * @return
 */
vector<State<Point>>* SearchableMatrix::getAllPossibleState(State<Point>* state){
    int rowNum = state->getState().getX();
    int columnNum = state->getState().getY();
    int numOfRows = this->calculateNumOfColumns();
    int numOfColumns = this->calculateNumOfColumns();
    //State<Point> left =


}