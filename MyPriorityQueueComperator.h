#ifndef PROJ2_MYPRIORITYQUEUECOMPERATOR_H
#define PROJ2_MYPRIORITYQUEUECOMPERATOR_H

#include "State.h"

template <class T>
class MyPriorityQueueComperator{
public:
    bool operator()(State<T>* cmp1, State<T>* cmp2){
        return cmp1->getCost() > cmp2->getCost();
    }
};

#endif //PROJ2_MYPRIORITYQUEUECOMPERATOR_H
