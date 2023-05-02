//
// Created by Kacper on 01.05.2023.
//

#ifndef JAKDOJADEHASHSET_HASHSET_H
#define JAKDOJADEHASHSET_HASHSET_H
#include "String.h"
#include "DoubleLinkedList.h"
#define HASHMAPSIZE 50000

class HashSet {
public:
    struct hashNode {
        unsigned int key = -1;
        DoubleLinkedList values;
    };

    hashNode* hashMap[HASHMAPSIZE] = { nullptr };
    int size;

    HashSet();

    ~HashSet() = default;


    unsigned int hashFunction(const String &strKey);

    void insert(const String &strKey, int x, int y);

    DoubleLinkedList *find(unsigned int key);

    void BFSfindNeighbours(HashSet *listOfCities, char **map, int h, int w);
    void dijkstra(HashSet *listOfCities, int startId, int endId, int operationType, String source, String destination);
    void updateNeighboursFlights(String source, String destination, int dist);

};


#endif //JAKDOJADEHASHSET_HASHSET_H
