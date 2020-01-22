//
// Created by Hadar on 18-Jan-20.
//

#ifndef DSA_PROJECT_2_LISTITEM_H
#define DSA_PROJECT_2_LISTITEM_H

#include <cstddef>

template <typename T> class ListItem
{
private:
    T * _data;
    ListItem<T> * _next;
    ListItem<T> * _prev;

public:
    ListItem(T *data, ListItem<T> *next=NULL, ListItem<T> *prev=NULL) :
    _data(data), _next(next), _prev(prev) {}

    //TODO check whether these two are necessary
    ListItem(const ListItem &listItem);

    ListItem<T> &operator = (const ListItem &listItem);

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

template<typename T>
ListItem<T>::ListItem(const ListItem &listItem)
{
    this->_prev = listItem._prev;
    this->_next = listItem._next;
    this->_data = listItem._data;
}

template<typename T>
ListItem<T> &ListItem<T>::operator=(const ListItem &listItem)
{
    this->_prev = listItem._prev;
    this->_next = listItem._next;
    this->_data = listItem._data;
    return *this;
}

#endif //DSA_PROJECT_2_LISTITEM_H
