//
// Created by Kacper on 29.04.2023.
//

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    head = nullptr;
}

PriorityQueue::~PriorityQueue() {
    while(head!=nullptr){
        priorityQueueNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void PriorityQueue::enqueue( int id, int dist,  String name){
    priorityQueueNode* newNode = new priorityQueueNode( id,dist,name);
    if(head  ==nullptr){
        head = newNode;
    }
    else if (head->priority> dist){
        newNode->next = head;
        head = newNode;
    }
    else{
        priorityQueueNode* tmp = head;
        while(tmp->next != nullptr && tmp->next->priority< dist){
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}

PriorityQueue::priorityQueueNode PriorityQueue::dequeue() {
    priorityQueueNode* tmp = head;
    head= head->next;
    int rPriority = tmp->priority;
    int rId = tmp->cityId;
    String rName = tmp->cityName;
    delete tmp;
    return{ rId, rPriority,rName};
}

bool PriorityQueue::isEmpty() {
    return head==nullptr;
}

PriorityQueue::priorityQueueNode PriorityQueue::peek() {
    int rPriority = head->priority;
    int rId = head->cityId;
    String rName = head->cityName;
    return{ rId, rPriority,rName};
}