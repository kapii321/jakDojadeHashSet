//
// Created by Kacper on 27.04.2023.
//

#ifndef JAKDOJADEHASHSET_DOUBLELINKEDLIST_H
#define JAKDOJADEHASHSET_DOUBLELINKEDLIST_H
#include "String.h"
#include "NeighboursList.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "PathReconstructionList.h"
#include <climits>
struct Position{
    int x=0;
    int y=0;
};

/*struct DijkstraReturnStruct{
    int * distance;
    String * names;
};*/

class DoubleLinkedList {
    friend class Queue;
public:
    struct DllNode{
        int id;
        String cityName;
        // data for cities
        Position coordinates;
        DllNode* prev;
        DllNode* next;
        NeighboursList neighbours;// lista miasto + odleglosc
        DllNode(const String *name, int x, int y, int pID){
            id = pID;
            cityName = *name;
            coordinates.x= x;
            coordinates.y =y;
            prev = nullptr;
            next = nullptr;
        }
    };
    DllNode* head;
    DllNode* tail;
    int numberOfCities;

public:
    DoubleLinkedList();

    ~DoubleLinkedList();

    void addNodeToEnd(const String *name, int x, int y, int id);

    void removeNode(String name);

    //  DllNode* getNodeByName(String name);

    void BFSfindNeighbours(DoubleLinkedList* listOfCities, char ** map, int h ,int w);

    void dijkstra(DoubleLinkedList* listOfCities, int numberOfNodes, int startId, int endId, int operationType);

    int getNumberOfCities();

    void updateNeighboursFlights(String source, String destination, int dist);


    //String* citiesCrossedOnPath(DoubleLinkedList* cities, int numbOfCities, int sId, int eId, String sName);
};


#endif //JAKDOJADEHASHSET_DOUBLELINKEDLIST_H
