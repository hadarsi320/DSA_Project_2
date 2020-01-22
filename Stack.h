//
// Created by eldar.a on 22/01/2020.
//

#ifndef DSA_PROJECT_2_STACK_H
#define DSA_PROJECT_2_STACK_H

#include "List.h"

template <typename T> class Stack {
private:
    List<T> _list;

public:
    Stack() : _list() {}

    void push(T *data);

    T * pop();

    T * top();

    bool isEmpty();
};

template<typename T>
void Stack<T>::push(T *data) {
    _list.insert(data);
}

template<typename T>
T *Stack<T>::pop() {
    T * data = _list.getHead()->getData();
    _list.remove(_list.getHead());
    return data;
}

template<typename T>
T *Stack<T>::top() {
    return _list.getHead()->getData();
}

template<typename T>
bool Stack<T>::isEmpty() {
    return _list.isEmpty();
}


#endif //DSA_PROJECT_2_STACK_H
