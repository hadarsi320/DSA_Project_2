//
// Created by Hadar on 18-Jan-20.
//

#ifndef DSA_PROJECT_2_LIST_H
#define DSA_PROJECT_2_LIST_H

#include "ListItem.h"

template <typename T> class List
{
private:
    ListItem<T> * _head;

public:
    List(): _head(NULL) {}

    virtual ~List();

    ListItem<T> *getHead() const;

    bool isEmpty() const;

    size_t length() const;

    void insert(T *data);

    void insert(ListItem<T> *item);

    void remove(ListItem<T> *item);

};

template<typename T>
List<T>::~List()
{
    ListItem<T> ptr = _head, next;
    while(ptr != NULL)
    {
        next = ptr.getNext();
        delete ptr;
        ptr = next;
    }
}

template<typename T>
ListItem<T> *List<T>::getHead() const {
    return _head;
}

template<typename T>
bool List<T>::isEmpty() const {
    return _head == NULL;
}

template<typename T>
size_t List<T>::length() const {
    size_t len = 0;
    ListItem<T> * ptr = _head;
    while (ptr != NULL)
    {
        len += 1;
        ptr = ptr->getNext();
    }
    return len;
}

template<typename T>
void List<T>::insert(T *data)
{
    ListItem<T> *ptr = new ListItem<T>(data);
    if (isEmpty())
        _head = ptr;
    else
    {
        ptr->setNext(_head);
        _head->setPrev(ptr);
        _head = ptr;
    }
}

template<typename T>
void List<T>::insert(ListItem<T> *item)
//Assuming item is a valid element, i.e it has no previous and no next items
{
    if (isEmpty())
        _head = item;
    else
    {
        item->setNext(_head);
        _head->setPrev(item);
        _head = item;
    }
}

//TODO consider delete item?
template<typename T>
void List<T>::remove(ListItem<T> *item)
{
    if(item == _head)
        _head = item->getNext();

    if(item->getNext() != NULL)
        item->getNext()->setPrev(item->getPrev());

    if(item->getPrev() != NULL)
        item->getPrev()->setNext(item->getNext());
}

#endif //DSA_PROJECT_2_LIST_H