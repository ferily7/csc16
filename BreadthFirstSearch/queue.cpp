#include "queue.h"

Queue::Queue(){
    head = 0;
    tail = 0;
    numNodes = 0;
}

void Queue::enqueue(Location item){
    Node* temp;
    temp = new Node(item,0);
    if ( tail == 0 )
    {
        tail = temp;
        head = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
    numNodes++;
}

Location Queue::dequeue(){
    Location saved;
    saved = head->data;
    head = head->next;
    if(head == 0)
        tail = 0;
    numNodes--;
    return saved;
}

int Queue::size(){
    return numNodes;
}

void Queue::clear(){
    while(size() > 0)
        dequeue();
}
