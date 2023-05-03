//
// Created by Kacper on 30.04.2023.
//

#include "PathReconstructionList.h"

PathReconstructionList::PathReconstructionList() {
    head = nullptr;
}

PathReconstructionList::~PathReconstructionList() {
    while(head){
        PathReconstructionNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void PathReconstructionList::reverseOrderPathAdding(const String& name) {
    PathReconstructionNode* newNode = new PathReconstructionNode(name);
    if(head == nullptr){
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }

}