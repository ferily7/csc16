#include "stack.h"

Stack::Stack(){
    head = 0;
    numNodes = 0;
}

/**
  The push function should insert the given item at the front of the list.
 * @brief Stack::push
 * @param item
 */
void Stack::push(double item){
    //Complete this function.
    //Steps:
    //1. Create a temp pointer
    Node* temp;
    //2. Point temp at a new Node object with 'item' in it.
    temp = new Node(item, 0);
    //3. Create a link from the new Node to the current head Node of the list
    temp->next = head;
    //4. Make head point to the new Node
    head = temp;
    //5. Increment numNodes
    numNodes++;
}

double Stack::pop(){
    //Complete this function
    //Steps:
    //1. Create a temp pointer
    Node* temp;
    //2. Point temp at the head Node
    temp = head;
    //3. Copy the data value from the head Node into a variable called "saved"
    double saved;
    saved = head->data;
    //4. Move the head pointer forward.
    head = head->next;
    //5. Delete the temp Node
    delete temp;
    //6. Decrement numNodes
    numNodes--;
    //7. Return "saved"
    return saved;
}

int Stack::size(){
    return numNodes;
}
