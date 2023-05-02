//
// Created by Kacper on 01.05.2023.
//

#ifndef JAKDOJADEHASHSET_QUEUE_H
#define JAKDOJADEHASHSET_QUEUE_H
#include "String.h"
#include "DoubleLinkedList.h"

class Queue {
private:
    struct QueueNode{
        int cord;
        QueueNode* next;
        QueueNode(int x){
            cord = x;
            next = nullptr;
        }
    };
    QueueNode* head;
    QueueNode* tail;

public:
    Queue();

    ~Queue();

    void enqueue(int p);


    int dequeue();

    bool isEmpty();
};

#endif //JAKDOJADEHASHSET_QUEUE_H
