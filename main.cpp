#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> queue;
    int x = 1;
    queue.enqueue(&x);
    x += 5;
    std::cout << *queue.dequeue();
}