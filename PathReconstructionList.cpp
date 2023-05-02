//
// Created by Kacper on 30.04.2023.
//

#include "PathReconstructionList.h"

PathReconstructionList::PathReconstructionList() {
    head = nullptr;
    tail = nullptr;
}

PathReconstructionList::~PathReconstructionList() {
    while(head){
        PathReconstructionNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void PathReconstructionList::reverseOrderPathAdding(String name) {
    PathReconstructionNode* newNode = new PathReconstructionNode(name);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }

}