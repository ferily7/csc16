#ifndef STACK_H
#define STACK_H


class Stack
{
private:
    struct Node{
        double data;
        Node*  next;
        Node(double pdata, Node* pnext){
            data = pdata;
            next = pnext;
        }
    };
    Node* head;
    int   numNodes;
public:
    Stack();
    void push(double item);
    double pop();
    int size();
};

#endif // STACK_H
