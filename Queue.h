//
// Created by Hadar on 18-Jan-20.
//

#ifndef DSA_PROJECT_2_QUEUE_H
#define DSA_PROJECT_2_QUEUE_H

#include "List.h"

template <typename T> class Queue {
private:
    List<T> _list;
    ListItem<T>* _tail;

public:
    Queue() : _list(), _tail(NULL) {}

    void enqueue(T *data);

    T* dequeue();

    bool isEmpty() const;
};

template<typename T>
void Queue<T>::enqueue(T *data)
{
    _list.insert(data);
    if(_tail == NULL)
        _tail = _list.getHead();
}

template<typename T>
T *Queue<T>::dequeue()
{
    T* dataPtr = _tail->getData();
    ListItem<T> *itemPtr = _tail;
    _tail = _tail->getPrev();
    _list.remove(itemPtr);
    return dataPtr;
}

#endif //DSA_PROJECT_2_QUEUE_H
