//
// Created by Kacper on 01.05.2023.
//

#ifndef JAKDOJADEHASHSET_PRIORITYQUEUE_H
#define JAKDOJADEHASHSET_PRIORITYQUEUE_H


#include "String.h"


class PriorityQueue {
    friend class DoubleLinkedList;
    friend class HashSet;
private:
    struct priorityQueueNode{
        int cityId;
        int priority;
        String cityName;
        struct priorityQueueNode* next;
        priorityQueueNode( int id, int dist,  const String&  name){
            cityId = id;
            priority = dist;
            cityName = name;
            next = nullptr;
        }
    };
    priorityQueueNode* head;

public:
    PriorityQueue();
    ~PriorityQueue();
    void enqueue( int id, int dist, const String& name);
    priorityQueueNode dequeue();
    bool isEmpty();
};

#endif //JAKDOJADEHASHSET_PRIORITYQUEUE_H
