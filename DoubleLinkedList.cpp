//
// Created by Kacper on 27.04.2023.
//

#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
    numberOfCities = 0;
}

DoubleLinkedList::~DoubleLinkedList() {
    while(head){
        DllNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void DoubleLinkedList::addNodeToEnd(const String &name, int x, int y, int id) {
    auto* newNode = new DllNode(name, x, y,id);
    if(!head){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    numberOfCities++;
}








