#ifndef STACK
#define STACK

#include <iostream>

struct StackNode{
    int data;
    StackNode *link;

    StackNode(int x){
        data = x;
    }
    
};


class stack{
    friend class Read;
    StackNode* top;

public:
    stack() {top = nullptr;}

    bool isEmpty();
    int peek();
    void push(int);
    bool pop();

};

#endif