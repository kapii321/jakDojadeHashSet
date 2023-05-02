//
// Created by Kacper on 27.04.2023.
//

#include "NeighboursList.h"

NeighboursList::NeighboursList() {
    head = nullptr;
    tail = nullptr;
}

NeighboursList::~NeighboursList() {
    while(head){
        NeighbourNode* tmp= head;
        head=head->next;
        delete tmp;
    }
}

void NeighboursList::addNeighbourToEnd(String name,int cityID, int distance) {
    auto newNode = new NeighbourNode(name,cityID,distance);
    if(!head){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next=newNode;
        newNode->prev=tail;
        tail = newNode;
    }
    numberOfNeighbours++;
}

/*void NeighboursList::addNeighbourToEnd(String *name, int distance) {
    auto newNode = new NeighbourNode(*name,distance);
    if(!head){
        head = newNode;
    }
    else{
        NeighbourNode* tmp = head;       SingleLinkedList imp.
        while(tmp->next){
            tmp= tmp->next;
        }
        tmp->next=newNode;
    }
    numberOfNeighbours++;
} */