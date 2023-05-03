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

void NeighboursList::addNeighbourToEnd(const String& name,int cityID, int distance) {
    auto newNode = new NeighbourNode(name,cityID,distance);
    if(!head){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next=newNode;
        tail = newNode;
    }
    numberOfNeighbours++;
}

