#ifndef PROJ2_MYPRIORITYQUEUE_H
#define PROJ2_MYPRIORITYQUEUE_H

#include <queue>
#include "State.h"
#include "MyPriorityQueueComperator.h"

using namespace std;

template <class T>
class MyPriorityQueue{
    priority_queue<State<T>*, vector<State<T>*>, MyPriorityQueueComperator<T>> m_myPriorityQueue;

public:
    State<T>* myTop(){
        return m_myPriorityQueue.top();
    }

    void myPop(){
        return m_myPriorityQueue.pop();
    }

    void myPush(State<T>* toPush){
        m_myPriorityQueue.push(toPush);
    }

    bool myEmpty(){
        m_myPriorityQueue.empty();
    }

    size_t mySize(){
        return m_myPriorityQueue.size();
    }

    priority_queue<State<T>*> copyPriorityQueue(){
        priority_queue<State<T>*> tempPriorityQueue;
        priority_queue<State<T>*> tempPriorityQueue2;
        size_t sizeOfPQ = this->mySize();
        for(size_t i = 0; i < sizeOfPQ; ++i){
            tempPriorityQueue.push(this->myTop());
            tempPriorityQueue2.push(this->myTop());
            this->myPop();
        }
        for(size_t i = 0; i < sizeOfPQ; ++i){
            this->m_myPriorityQueue.push(tempPriorityQueue.top());
            tempPriorityQueue.pop();
        }
        return tempPriorityQueue2;
    }

    /**
     * the function gets a pointer to a State, and returns a pointer to this state in the priority queue ,
     * null pointer otherwise
     * @param state
     * @return
     */
    State<T>* myFind(State<T>* state){
        priority_queue<State<T>*> tempPriorityQueue = copyPriorityQueue();
        State<T>* temp;
        while(!(tempPriorityQueue.empty())){
            temp = tempPriorityQueue.top();
            tempPriorityQueue.pop();
            if(*temp == *state){
                return temp;
            }
        }
        return nullptr;
    }

    bool myIsExist(State<T>* state){
        priority_queue<State<T>*> tempPriorityQueue = copyPriorityQueue();
        State<T>* temp;
        while(!(tempPriorityQueue.empty())){
            temp = tempPriorityQueue.top();
            tempPriorityQueue.pop();
            if(*temp == *state){
                return true;
            }
        }
        return false;
    }

    void myCut(State<T>* state){
        if(this->myIsExist(state)) {
            priority_queue<State<T> *> tempPriorityQueue;
            State<T> *temp;
            while (!(m_myPriorityQueue.empty())) {
                temp = m_myPriorityQueue.top();
                m_myPriorityQueue.pop();
                if (*temp == *state) {
                    break;
                }
                tempPriorityQueue.push(temp);
            }
            while(!(tempPriorityQueue.empty())){
                m_myPriorityQueue.push(tempPriorityQueue.top());
                tempPriorityQueue.pop();
            }
        }
        return;
    }

};

#endif //PROJ2_MYPRIORITYQUEUE_H
