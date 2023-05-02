//
// Created by Kacper on 27.04.2023.
//

#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
    numberOfCities = 0;
}

DoubleLinkedList::~DoubleLinkedList() {
    while(head){
        DllNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void DoubleLinkedList::addNodeToEnd(const String *name, int x, int y, int id) {
    auto* newNode = new DllNode(name, x, y,id);
    if(!head){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    numberOfCities++;
}

void DoubleLinkedList::removeNode(String name) {
    DllNode** current = &head;
    while(*current){
        if(strcmp((*current)->cityName.getString(), name.getString())==0){
            DllNode* tmp = *current;
            if(tmp == head){
                head = tmp->next;
                if(head){
                    head->prev = nullptr;
                }
            }
            else if(tmp == tail){
                tail = tmp->prev;
                if(tail){
                    tail->next = nullptr;
                }
            }
            else{
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
            }
            delete tmp;
            numberOfCities--;
            return;
        }
        current = &(*current)->next;
    }
}
/*
void DoubleLinkedList::dijkstra(DoubleLinkedList *listOfCities, int numberOfNodes, int startId, int endId, int operationType) {
    int size = numberOfNodes;
    if(size<=0){
        return;
    }
    bool *visited= new bool[size];
    int* prev= new int[size];
    int* dist= new int[size];
    for(int i=0; i<size;i++){
        visited[i] = false;
        prev[i] = -2;
        dist[i] = INT_MAX;
    }
    dist[startId] = 0;
    PriorityQueue pq;
    pq.enqueue(startId,0);
    int getId, getDistance,newDistance;
    int sizeOfPath=0;
    while(!pq.isEmpty()){
        PriorityQueue::priorityQueueNode tmp = pq.dequeue();
        getId = tmp.cityId;
        getDistance = tmp.priority;
        visited[getId] =true;
        if(dist[getId]<getDistance) continue;
        DllNode* currentNode = listOfCities->head;
        while(currentNode->id!=getId){
            currentNode = currentNode->next;
        }
        for(NeighboursList::NeighbourNode* currentNeighbour = currentNode->neighbours.head; currentNeighbour!= nullptr; currentNeighbour=currentNeighbour->next ){
            if(visited[currentNeighbour->id]) continue;
            newDistance = dist[getId] + currentNeighbour->distance;
            if(newDistance < dist[currentNeighbour->id]){
                prev[currentNeighbour->id] = getId;
                sizeOfPath++;
                dist[currentNeighbour->id] = newDistance;
                pq.enqueue(currentNeighbour->id, newDistance);
            }
        }
        if(getId == endId){
            int output = dist[endId];
            std::cout<< output;
            if(operationType==1){
                PathReconstructionList citiesCrossed;
                for(int i= endId; i!=-2; i = prev[i]){
                    for(DllNode* currentcity = head;currentcity!=nullptr;currentcity=currentcity->next) {
                        if (i == currentcity->id) {
                            citiesCrossed.reverseOrderPathAdding(
                                    currentcity->cityName);
                            break;
                        }
                    }
                }
                for(PathReconstructionList:: PathReconstructionNode* first= citiesCrossed.head; first!=nullptr; first=first->next){
                    if(first == citiesCrossed.head || first == citiesCrossed.tail) continue;
                    std::cout<<' '<< first->name.getString();
                }
            }
            delete[] visited;
            delete[] dist;
            delete[] prev;
            return;
        }
    }
    delete[] visited;
    delete[] dist;
    delete[] prev;
}
*/
int DoubleLinkedList::getNumberOfCities() {
    return numberOfCities;
}

void DoubleLinkedList::updateNeighboursFlights(String source, String destination, int dist) {
    int id=-1;
    DllNode* sourceNode = nullptr;
    for(DllNode* currNode = head;currNode!=nullptr;currNode=currNode->next){
        if(strcmp(currNode->cityName.getString(),destination.getString())==0){
            id=currNode->id;
            if(sourceNode!= nullptr) break;
        }
        if(strcmp(currNode->cityName.getString(),source.getString())==0){
            sourceNode = currNode;
            if(id != -1) break;
        }
    }
    if(sourceNode!= nullptr && id !=-1) {
        sourceNode->neighbours.addNeighbourToEnd(destination, id, dist);
    }
}



