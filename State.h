#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H

using namespace std;

template <class T>
class State {
    T m_state;
    double m_cost;
    State<T>* m_cameFrom;

public:
    State<T>(T state) {
        this->m_state = state;
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
};




#endif //PROJ2_STATE_H
