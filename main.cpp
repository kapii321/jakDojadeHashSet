#include <iostream>
#include <cstdio>
#include "String.h"
#include "DoubleLinkedList.h"
#include "HashSet.h"
using namespace std;
class String;
int main() {
    int w,h;
    String wInput= "";
    String hInput = "";
    char whInput;
    while((whInput = (char)getchar()) != ' '){
        wInput.addCharacter(whInput);
    }
    w = wInput.stringToIntConv();
    while((whInput = (char)getchar()) != '\n'){
        hInput.addCharacter(whInput);
    }
    h = hInput.stringToIntConv();
    char **input = new char*[h];
    for (int i = 0; i < h; i++) {
        input[i] = new char[w];
        for(int j = 0; j < w; j++){
            int c = getchar();
            if(c < 33){
                j--;
                continue;
            }
            input[i][j] = (char)c;
        }
    }
    HashSet* Cities = new HashSet;
    for (int i=0; i<h;i++){
        for(int j=0; j<w;j++){
            if(input[i][j]=='*'){
                String name;
                name.findCityName(input,i,j,h,w,name);
                Cities->insert(name,i,j);
            }
        }
    }

    Cities->BFSfindNeighbours(Cities,input,h,w);

    String flightsInput="";
    String source = "";
    String destination = "";
    String distInput="";
    int flights,flightDistance,currentString =0;
    char c;
    int enterCounter =0;
    while(enterCounter<2){
        c = (char)getchar();
        if(c == '\n'){
            enterCounter++;
            continue;
        }
        flightsInput.addCharacter(c);
    }
    flights = flightsInput.stringToIntConv();
    while(flights>0){
        c=(char)getchar();
        while(c != ' ' && c!= '\n'){
            if(currentString ==0){
                source.addCharacter(c);
            }
            if(currentString ==1){
                destination.addCharacter(c);
            }
            if(currentString ==2){
                distInput.addCharacter(c);
            }
            c=(char)getchar();
        }
        if(currentString ==2){
            flightDistance=distInput.stringToIntConv();
        }
        currentString++;
        if(currentString ==3) currentString=0;
        if(c == '\n'){
            flights--;
            Cities->updateNeighboursFlights(source,destination,flightDistance);
            source = "";
            destination = "";
            distInput="";
            continue;
        }

    }

    String operationsInput="";
    int operations;
    int operationType;
    int startId, endId;
    while((c = (char)getchar()) != '\n' ){
        operationsInput.addCharacter(c);
    }
    operations = operationsInput.stringToIntConv();
    while(operations>0){
        c = (char)getchar();
        while(c != ' ' && c!= '\n'){
            if(currentString ==0){
                source.addCharacter(c);
            }
            if(currentString ==1){
                destination.addCharacter(c);
            }
            if(currentString ==2){
                distInput.addCharacter(c);
            }
            c=(char)getchar();
        }
        if(currentString ==2){
            operationType=distInput.stringToIntConv();
        }
        currentString++;
        if(currentString ==3) currentString=0;
        if(c == '\n'){
            operations--;
           unsigned int hash = Cities->hashFunction(source);
           DoubleLinkedList* sourceList = Cities->find(hash);
           for(DoubleLinkedList::DllNode* sourceNode = sourceList->head;sourceNode!= nullptr;sourceNode=sourceNode->next){
               if(strcmp(sourceNode->cityName.getString(),source.getString())==0){
                   startId = sourceNode->id;
                   break;
               }
           }
           hash = Cities->hashFunction(destination);
           DoubleLinkedList* destinationList = Cities->find(hash);
           for(DoubleLinkedList::DllNode* destinationNode = destinationList->head;destinationNode!= nullptr;destinationNode=destinationNode->next){
               if(strcmp(destinationNode->cityName.getString(),destination.getString())==0){
                   endId = destinationNode->id;
                   break;
               }
           }


            Cities->dijkstra(startId,endId,operationType,source);
            cout << endl;
            source = "";
            destination = "";
            distInput="";
            continue;
        }
    }



    for (int i = 0; i < h; i++) {
        delete[] input[i];
    }
    delete[] input;
    delete Cities;


    return 0;
}




