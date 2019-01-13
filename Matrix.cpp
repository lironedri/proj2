#include "Matrix.h"

int Matrix::calculateNumOfRows(){
    return (int)this->m_matrix.size();
}

int Matrix::calculateNumOfColumns(){
    if (this->calculateNumOfRows() > 0){
        return (int)this->m_matrix.at(0).size();
    }
}

double Matrix::getXCoordinate(State<Point> state){
    return state.getState().getX();
}

double Matrix::getYCoordinate(State<Point> state){
    return state.getState().getY();
}


State<Point> Matrix::getLeftNeighbor(State<Point> state){
    if(state.getState().getX() > 0) {
        double leftNeighborXCoordinate = this->getXCoordinate(state) - 1;
        Point *neighbor = new Point(leftNeighborXCoordinate, this->getYCoordinate(state));
       // State<Point> leftNeighbor = new State<Point>(neighbor);
    }
}


