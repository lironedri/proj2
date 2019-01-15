#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H

#define OUT_OF_RANGE -2

using namespace std;

template <class T>
class State {
    T m_state;
    double m_cost;
    State<T>* m_cameFrom;

public:
    State<T>(T state) {
        this->m_state = state;
        this->m_cost = OUT_OF_RANGE;
    }

    bool Equals(State<T> s) {
        return m_state->equal(s.m_state);
    }

    void setCost(double cost) {
        this->m_cost = cost;
    }

    void setCameFrom(State<T> s) {
        this->m_cameFrom = s;
    }

    T getState(){
        return this->m_state;
    }

    double getCost (){
        return this->m_cost;
    }

    bool operator== (State<T> s) {
        return (getState() == s.getState());
    }

//    bool operator<(State<T> leftState, State<T> rightState){
//        return leftState.getCost() < rightState.getCost() ? true: false;
//    }

    State(){}
};




#endif //PROJ2_STATE_H
