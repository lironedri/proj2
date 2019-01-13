#ifndef PROJ2_SEARCHABLEMATRIX_H
#define PROJ2_SEARCHABLEMATRIX_H

#include "Searchable.h"
#include "Point.h"
#include "Matrix.h"

class SearchableMatrix : public Searchable<Point>, Matrix{
public:
    SearchableMatrix(State<Point>* init, State<Point>* goal, vector<State<Point>>* states,
            vector<vector<State<Point>>> matrix): Searchable(init, goal, states), Matrix(matrix){
    }

    virtual State<Point>* getInitialState();
    virtual State<Point>* getGoalState();
    virtual vector<State<Point>>* getAllPossibleState(State<Point>* state);

};


#endif //PROJ2_SEARCHABLEMATRIX_H
