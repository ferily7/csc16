#ifndef QUEUE_H
#define QUEUE_H

#include "location.h"

class Queue{ //A queue of Location objects

private:
    struct Node{
            Location data;
            Node* next;
            Node(Location pdata, Node* pnext) {
                    data = pdata;
                    next = pnext;
            }
    };

    Node* head;
    Node* tail;
    int numNodes;

public:
    Queue();
    void enqueue(Location item);  //Adds an item to the rear of the queue
    Location dequeue(); //Removes and returns the item at the front of the queue
    int size(); //The number of items in the queue
    void clear(); //Remove all the items in the queue
};

#endif // QUEUE_H
