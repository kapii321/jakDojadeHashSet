//
// Created by Kacper on 26.04.2023.
//

#include "Queue.h"
Queue::Queue() {
    head = nullptr;
    tail = nullptr;
}

Queue::~Queue() {
    while(head !=nullptr){
        QueueNode* tmp = head;
        head= head->next;
        delete tmp;
    }
    tail = nullptr;
}

void Queue::enqueue(int p) {
    QueueNode* newNode = new QueueNode(p);
    if(head==nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

int Queue::dequeue()  {
    if(head == nullptr){
        return 100;
    }
    else{
        QueueNode* tmp = head;
        head = head->next;
        int rCoord = tmp->cord;
        delete tmp;
        return rCoord;
    }
}

bool Queue::isEmpty() {
    return head ==nullptr;
}