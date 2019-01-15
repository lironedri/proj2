#ifndef PROJ2_MYPRIORITYQUEUE_H
#define PROJ2_MYPRIORITYQUEUE_H

#include <queue>
#include "State.h"
#include "MyPriorityQueueComperator.h"

using namespace std;

template <class T>
class MyPriorityQueue{
    priority_queue<State<T>*, vector<State<T>*>, State<T>*->get
};

#endif //PROJ2_MYPRIORITYQUEUE_H
