/*
Student Name:Muhammet Çavuş
Student Number:2018400306
Project Number: 2
Compile Status: [SUCCESS/FAIL] success
Running Status: [SUCCESS/FAIL] success
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include "RestaurantOrganizer.h"

using namespace std;

RestaurantOrganizer::RestaurantOrganizer(const vector<int>& tableCapacityInput){
    numberOfTables = tableCapacityInput.size();
    for(int i=0;i<numberOfTables;i++){
        tableCapacity[i] = tableCapacityInput[i];
        heap[i] = i;
        heapUp(i);
    }
}

void RestaurantOrganizer::addNewGroup(int groupSize, ofstream& outFile){
        if(tableCapacity[heap[0]]>=groupSize) {
            outFile<<heap[0]<<endl;
            tableCapacity[heap[0]]-=groupSize;
            heapDown(0);
        } else {
            outFile<<-1<<endl;
        }
    // IMPLEMENT ME!
}

void RestaurantOrganizer::heapUp(int index){
    int temp=move(heap[index]);
    for( ; index>0 && tableCapacity[temp] >= tableCapacity[ heap[(index-1) / 2] ] ; index =(index-1)/ 2 ) {
        if(tableCapacity[temp]==tableCapacity[heap[(index-1)/2]]) {
            if(temp<heap[(index-1)/2]) {
                heap[index]=move(heap[(index-1)/2]);
            } else
                break;
        } else
            heap[index]=move(heap[(index-1)/2]);

        if(index==0)
            break;
    }
    heap[index]=temp;

    // IMPLEMENT ME!
}

void RestaurantOrganizer::heapDown(int index){

    int temp=move(heap[index]);
    int child;
    while((index+1) * 2-1 < numberOfTables) {
        child=(index+1) * 2-1;
        if(child!=numberOfTables-1 && tableCapacity[heap[child+1]]>tableCapacity[heap[child]]) {
            child++;
        }
        else if(child!=numberOfTables-1 && tableCapacity[heap[child+1]]==tableCapacity[heap[child]]) {
            if(heap[child+1]<heap[child])
                child++;
        }
        if(tableCapacity[heap[child]]>tableCapacity[temp]){
                heap[index]=move(heap[child]);

        } else if(tableCapacity[heap[child]]==tableCapacity[temp]) {
            if(heap[child]<temp) {
                heap[index]=move(heap[child]);
            } else
                break;
        }
        else  {
            break;
        }
        index=child;
    }

    heap[index]=temp;
    // IMPLEMENT ME!
}

void RestaurantOrganizer::printSorted(ofstream& outFile){
    for(int i=0; i<numberOfTables; i++) {
        outFile<<tableCapacity[heap[0]]<<" ";
        tableCapacity[heap[0]]=-1;
        heapDown(0);
    }

    // IMPLEMENT ME!
}

// YOU CAN ADD YOUR HELPER FUNCTIONS

