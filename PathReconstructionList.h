//
// Created by Kacper on 30.04.2023.
//

#ifndef JAKDOJADEHASHSET_PATHRECONSTRUCTIONLIST_H
#define JAKDOJADEHASHSET_PATHRECONSTRUCTIONLIST_H
#include "String.h"

class PathReconstructionList {
public:
    struct PathReconstructionNode{
        String name;
        PathReconstructionNode* next;

        PathReconstructionNode(const String& city){
            name = city;
            next = nullptr;

        }
    };
    PathReconstructionNode* head;

    PathReconstructionList();

    ~PathReconstructionList();

    void reverseOrderPathAdding(const String& name);
};


#endif //JAKDOJADEHASHSET_PATHRECONSTRUCTIONLIST_H
