//
// Created by Kacper on 27.04.2023.
//

#ifndef JAKDOJADEHASHSET_NEIGHBOURSLIST_H
#define JAKDOJADEHASHSET_NEIGHBOURSLIST_H
#include "String.h"

class NeighboursList {
    friend class DoubleLinkedList;
    friend class HashSet;
private:
    struct NeighbourNode{
        String cityName;
        int id;
        int distance;
        NeighbourNode * next;
        NeighbourNode * prev;
        NeighbourNode(String name, int cityID,int dist){
            cityName= name;
            id=cityID;
            distance= dist;
            next = nullptr;
            prev = nullptr;
        }
    };
    NeighbourNode* head;
    NeighbourNode* tail;
    int numberOfNeighbours;
public:
    NeighboursList();

    ~NeighboursList();

    void addNeighbourToEnd(String name,int cityID, int distance);

    //void removeNeighbour(String name);
};


#endif //JAKDOJADEHASHSET_NEIGHBOURSLIST_H
