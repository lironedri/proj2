#ifndef PROJ2_MATRIX_H
#define PROJ2_MATRIX_H

#include <vector>
#include "State.h"
#include "Point.h"


class Matrix {
    vector<vector<State<Point>>> m_matrix;

public:
    Matrix(vector<vector<State<Point>>> matrix){
        this->m_matrix = matrix;
    }

    int calculateNumOfRows();
    int calculateNumOfColumns();
    State<Point> getLeftNeighbor(State<Point> state);
    State<Point> getRightNeighbor(State<Point> state);
    State<Point> getUpNeighbor(State<Point> state);
    State<Point> getDownNeighbor(State<Point> state);
    double getXCoordinate(State<Point> state);
    double getYCoordinate(State<Point> state);

};



#endif //PROJ2_MATRIX_H
