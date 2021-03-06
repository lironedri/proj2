#include "Matrix.h"
#define OUT_OF_RANGE -2

int Matrix::calculateNumOfRows(){
    return (int)this->m_matrix->size();
}

int Matrix::calculateNumOfColumns(){
    if (this->calculateNumOfRows() > 0){
        return (int)this->m_matrix->at(0).size();
    }
}

double Matrix::getXCoordinate(State<Point>* state){
    return state->getState().getX();
}

double Matrix::getYCoordinate(State<Point>* state){
    return state->getState().getY();
}

State<Point>* Matrix::getLeftNeighbor(State<Point>* state){
    if(state->getState().getY() > 0) {
        double leftNeighborYCoordinate = this->getYCoordinate(state) - 1;
        State<Point>* leftNeighbor = new State<Point>(this->m_matrix->at(getXCoordinate(state)).at(leftNeighborYCoordinate));
        return leftNeighbor;
    }
    State<Point>* outOfRange = new State<Point>(Point (OUT_OF_RANGE, OUT_OF_RANGE));
    return outOfRange;
}

State<Point>* Matrix::getRightNeighbor(State<Point>* state){
    if(state->getState().getY() != calculateNumOfColumns() - 1) {
        double rightNeighborYCoordinate = this->getYCoordinate(state) + 1;
        State<Point>* rightNeighbor = new State<Point>(this->m_matrix->at(getXCoordinate(state)).at(rightNeighborYCoordinate));
        return rightNeighbor;
    }
    State<Point>* outOfRange = new State<Point>(Point (OUT_OF_RANGE, OUT_OF_RANGE));
    return outOfRange;
}

State<Point>* Matrix::getUpNeighbor(State<Point>* state){
    if(state->getState().getX() > 0) {
        double upNeighborXCoordinate = this->getXCoordinate(state) - 1;
        State<Point>* upNeighbor = new State<Point>(this->m_matrix->at(upNeighborXCoordinate).at(getYCoordinate(state)));
        return upNeighbor;
    }
    State<Point>* outOfRange = new State<Point>(Point (OUT_OF_RANGE, OUT_OF_RANGE));
    return outOfRange;
}

State<Point>* Matrix::getDownNeighbor(State<Point>* state){
    if(state->getState().getX() != calculateNumOfRows() - 1) {
        double downNeighborXCoordinate = this->getXCoordinate(state) + 1;
        State<Point>* downNeighbor = new State<Point>(this->m_matrix->at(downNeighborXCoordinate).at(getYCoordinate(state)));
        return downNeighbor;
    }
    State<Point>* outOfRange = new State<Point>(Point (OUT_OF_RANGE, OUT_OF_RANGE));
    return outOfRange;
}

vector<State<Point>*> Matrix::getAllNeighbors(State<Point>* state){
    vector<State<Point>*> neighbors;
    neighbors.push_back(this->getLeftNeighbor(state));
    neighbors.push_back(this->getRightNeighbor(state));
    neighbors.push_back(this->getUpNeighbor(state));
    neighbors.push_back(this->getDownNeighbor(state));
    return neighbors;
}



