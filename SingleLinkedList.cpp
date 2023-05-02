//
// Created by Kacper on 25.04.2023.
//

#include "SingleLinkedList.h"


SingleLinkedList::SingleLinkedList() {
    head = nullptr;
    numberOfCities = 0;
}

SingleLinkedList::~SingleLinkedList() {
    while(head){
        SllNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void SingleLinkedList::addNodeToEnd(String *name, int x, int y) {
    auto* newNode = new SllNode(*name, x,y);
    if(!head){
        head = newNode;
    }
    else{
        SllNode* tmp = head;
        while(tmp->next){
            tmp= tmp->next;
        }
        tmp->next = newNode;
    }
    numberOfCities++;
}

void SingleLinkedList::removeNode(String name) {
    SllNode** current = &head;
    while(*current){
        if(strcmp((*current)->cityName.getString(), name.getString())==0){
            SllNode* tmp = *current;
            *current = (*current)->next;
            delete tmp;
            return;
        }
        current = &(*current)->next;
    }
    numberOfCities--;
}
