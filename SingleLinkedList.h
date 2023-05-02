//
// Created by Kacper on 01.05.2023.
//

#ifndef JAKDOJADEHASHSET_SINGLELINKEDLIST_H
#define JAKDOJADEHASHSET_SINGLELINKEDLIST_H


#include "String.h"
struct Position{
    int x=0;
    int y=0;
};

class SingleLinkedList {
private:
    struct SllNode{
        String cityName;
        // data for cities
        Position coordinates;
        SllNode* next;
        SingleLinkedList* neighbours;
        SllNode(String name, int x, int y){
            cityName = name;
            coordinates.x= x;
            coordinates.y =y;
            next = nullptr;
            neighbours = nullptr;
        }
    };
    SllNode* head;
    int numberOfCities;

public:
    SingleLinkedList();

    ~SingleLinkedList();

    void addNodeToEnd(String *name, int x, int y);

    void removeNode(String name);

    //void BFS

};


#endif //JAKDOJADEHASHSET_SINGLELINKEDLIST_H
