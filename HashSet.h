//
// Created by Kacper on 01.05.2023.
//

#ifndef JAKDOJADEHASHSET_HASHSET_H
#define JAKDOJADEHASHSET_HASHSET_H
#include "String.h"
#include "DoubleLinkedList.h"
#define HASHMAPSIZE 87531

class HashSet {
public:
    struct hashNode {
        unsigned int key = -1;
        DoubleLinkedList values;
    };

    hashNode* hashMap[HASHMAPSIZE] = { nullptr };
    int size;

    HashSet();

    ~HashSet();


    unsigned int hashFunction(const String &strKey);

    void insert(const String &strKey, int x, int y);

    DoubleLinkedList *find(unsigned int key);

    void BFSfindNeighbours(HashSet *listOfCities, char **map, int h, int w);
    void dijkstra( int startId, int endId, int operationType, const String& source);
    void updateNeighboursFlights(const String& source, const String& destination, int dist);

};


#endif //JAKDOJADEHASHSET_HASHSET_H
