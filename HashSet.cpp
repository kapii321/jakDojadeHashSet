//
// Created by Kacper on 01.05.2023.
//

#include "HashSet.h"

HashSet::HashSet() {
   size =0;
 
}

HashSet::~HashSet() {
    for(int i=0;i<HASHMAPSIZE;i++){
        if(hashMap[i]!=nullptr){
            delete hashMap[i];
        }
    }
}


unsigned int HashSet::hashFunction(const String &strKey) {
    unsigned int hash = 0;
    const char* str = strKey.getString();
    int sizeH = strKey.length();
    for(int i=0;i<sizeH;i++){
        hash = str[i] +(hash<<6) + (hash <<16) - hash;
    }
    return hash% HASHMAPSIZE;
}


void HashSet::insert(const String &strKey, int x, int y) {
    unsigned int hash = hashFunction(strKey);
    if(hashMap[hash] == nullptr){
        hashNode* newNode = new hashNode;
        newNode->key = hash;
        hashMap[hash] = newNode;
    }
    DoubleLinkedList& list = hashMap[hash]->values;
    list.addNodeToEnd(strKey,x,y,size);
    size++;

}

DoubleLinkedList *HashSet::find(unsigned int key) {
    unsigned int hash = key % HASHMAPSIZE;
    hashNode* node = hashMap[hash];

    if(node->key == key && node->values.head!=nullptr){
        return &(node->values);
    }
    else{
        return nullptr;
    }
}

void HashSet::BFSfindNeighbours(HashSet *listOfCities, char **map, int h, int w) {
    bool *visited = new bool[h * w];
    int dx[4] = {-1, 1, 0, 0}; // neighbours coordinates
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < h * w; i++) {
        visited[i] = false;
    }

    for (int c = 0; c < HASHMAPSIZE; c++) {
        hashNode* currentCity = listOfCities->hashMap[c];
        if (currentCity == nullptr) continue;
        for (DoubleLinkedList::DllNode *currentNode = currentCity->values.head;
             currentNode != nullptr; currentNode = currentNode->next) {
            int sx = currentNode->coordinates.x;
            int sy = currentNode->coordinates.y;
            Queue xq, yq,visitedPoints;



            int distance = 0;
            int positionsLeftToCheckNow = 1;
            int positionsToCheckNext = 0;
            xq.enqueue(sx);
            yq.enqueue(sy);
            visited[sx * w + sy] = true;
            visitedPoints.enqueue(sx*w+sy);
            while (!xq.isEmpty()) {
                int x = xq.dequeue();
                int y = yq.dequeue();
                for (int i = 0; i < 4; i++) {
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    if (newX >= h || newY >= w) continue;
                    if (newX < 0 || newY < 0) continue;
                    if (visited[newX * w + newY]) continue;
                    if (map[newX][newY] != '#' && map[newX][newY] != '*') continue;
                    if (map[newX][newY] == '*') {
                        visited[newX * w + newY] = true;
                        visitedPoints.enqueue(newX*w+newY);
                        for (int a = 0; a < HASHMAPSIZE; a++) {
                            hashNode *currentCityNeighbour = listOfCities->hashMap[a];
                            if (currentCityNeighbour == nullptr) continue;
                            for (DoubleLinkedList::DllNode *findNeighbourNode = currentCityNeighbour->values.head;
                                 findNeighbourNode != nullptr; findNeighbourNode = findNeighbourNode->next) {
                                if (findNeighbourNode->coordinates.x == newX &&
                                    findNeighbourNode->coordinates.y == newY) {
                                    currentNode->neighbours.addNeighbourToEnd(findNeighbourNode->cityName,
                                                                              findNeighbourNode->id, distance + 1);
                                }
                            }
                        }
                        continue;
                    }

                    xq.enqueue(newX);
                    yq.enqueue(newY);
                    visited[newX * w + newY] = true;
                    visitedPoints.enqueue(newX*w+newY);
                    positionsToCheckNext++;
                }
                positionsLeftToCheckNow--;
                if (positionsLeftToCheckNow == 0) {
                    positionsLeftToCheckNow = positionsToCheckNext;
                    positionsToCheckNext = 0;
                    distance++;
                }
            }
            while(!visitedPoints.isEmpty()){
                visited[visitedPoints.dequeue()] = false;
            }
            currentNode->neighbours.addNeighbourToEnd(currentNode->cityName, currentNode->id, 0);
        }
    }
    delete[] visited;
}

void HashSet::dijkstra( int startId, int endId, int operationType,const String& source) {
    if(size<=0){
        return;
    }
    bool *visited= new bool[size];
    int* prev= new int[size];
    String* prevNames = new String[size];
    int* dist= new int[size];
    for(int i=0; i<size;i++){
        visited[i] = false;
        prev[i] = -2;
        dist[i] = INT_MAX;
    }
    dist[startId] = 0;
    PriorityQueue pq;
    pq.enqueue(startId,0,source);
    int getId, getDistance,newDistance;
    String getName;
    int sizeOfPath=0;
    while(!pq.isEmpty()){
        PriorityQueue::priorityQueueNode tmp = pq.dequeue();
        getName = tmp.cityName;
        getId = tmp.cityId;
        getDistance = tmp.priority;
        visited[getId] =true;
        if(dist[getId]<getDistance) continue;

        DoubleLinkedList* currentList = find(hashFunction(getName));
        DoubleLinkedList::DllNode* currentNode = currentList->head;
        while( currentNode->id!=getId){
            currentNode = currentNode->next;
        }
        for(NeighboursList::NeighbourNode* currentNeighbour = currentNode->neighbours.head; currentNeighbour!= nullptr; currentNeighbour=currentNeighbour->next ){
            if(visited[currentNeighbour->id]) continue;
            newDistance = dist[getId] + currentNeighbour->distance;
            if(newDistance < dist[currentNeighbour->id]){
                prev[currentNeighbour->id] = getId;
                prevNames[currentNeighbour->id] = getName;
                sizeOfPath++;
                dist[currentNeighbour->id] = newDistance;
                pq.enqueue(currentNeighbour->id, newDistance,currentNeighbour->cityName);
            }
        }

        if(getId == endId){
            int output = dist[endId];
            std::cout<< output;

            if(operationType==1){
               PathReconstructionList citiesCrossed;
               int a = endId;
                for(int i= endId; i!=-2; i = prev[i]){
                    if(hashMap[hashFunction(prevNames[a])]==nullptr) continue;
                    DoubleLinkedList* list = find(hashFunction(prevNames[a]));
                    for(DoubleLinkedList::DllNode* getNode = list->head; getNode!=nullptr; getNode=getNode->next){
                        if (i == getNode->id) {
                            citiesCrossed.reverseOrderPathAdding(
                                    getNode->cityName);
                            break;
                        }
                    }
                    a = i;
                }
                for(PathReconstructionList::PathReconstructionNode* first = citiesCrossed.head; first !=nullptr;first = first->next){
                    if(first == citiesCrossed.head ) continue;
                    std::cout << ' '<< first->name.getString();
                }
            }
            delete[] visited;
            delete[] dist;
            delete[] prev;
            delete[] prevNames;
            return;
        }
    }
    delete[] visited;
    delete[] dist;
    delete[] prev;
    delete[] prevNames;
}

void HashSet::updateNeighboursFlights(const String& source, const String& destination, int dist) {
    int id=-1;

   unsigned int keySource = hashFunction(source);
   unsigned int keyDestination = hashFunction(destination);
   DoubleLinkedList::DllNode* findSource = nullptr;

    DoubleLinkedList* sourceList = find(keySource);
    DoubleLinkedList* destinationList = find(keyDestination);

    for(DoubleLinkedList::DllNode* sourceNode = sourceList->head; sourceNode!=nullptr; sourceNode=sourceNode->next){
        if(strcmp(sourceNode->cityName.getString(),source.getString())==0){
            findSource = sourceNode;
            break;
        }
    }
    for(DoubleLinkedList::DllNode* destinationNode = destinationList->head;destinationNode!=nullptr;destinationNode=destinationNode->next){
        if(strcmp(destinationNode->cityName.getString(),destination.getString())==0){
            id = destinationNode->id;
            break;
        }
    }
    if(findSource!= nullptr && id !=-1) {
        findSource->neighbours.addNeighbourToEnd(destination, id, dist);
    }

}

