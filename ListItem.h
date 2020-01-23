//
// Created by Hadar on 18-Jan-20.
//

#ifndef DSA_PROJECT_2_LISTITEM_H
#define DSA_PROJECT_2_LISTITEM_H

#include <cstddef>

template <typename T> class ListItem
{
private:
    T *_data;
    ListItem<T> * _next;
    ListItem<T> * _prev;

public:
    ListItem(T *data, ListItem<T> *next=NULL, ListItem<T> *prev=NULL) :
    _data(data), _next(next), _prev(prev) {}

    T *getData() const {
        return _data;
    }

    ListItem<T> *getNext() const {
        return _next;
    }

    void setNext(ListItem<T> *next) {
        _next = next;
    }

    ListItem<T> *getPrev() const {
        return _prev;
    }

    void setPrev(ListItem<T> *prev) {
        _prev = prev;
    }
};

#endif //DSA_PROJECT_2_LISTITEM_H
