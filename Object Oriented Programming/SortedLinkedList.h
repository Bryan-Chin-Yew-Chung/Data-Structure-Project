#ifndef SORTEDLINKEDLIST
#define SORTEDLINKEDLIST

#include <iostream>

using namespace std;

struct SortedNode{
    int data;
    SortedNode *next;
    SortedNode *link;

    SortedNode(int x){
        data = x;
        next = nullptr;
    }
    
};

class SortedLinkedList {
    friend class Read;
    SortedNode *head;

    public:

    SortedLinkedList(){
            head = nullptr;
        }

    SortedLinkedList(int x){
            SortedNode *nNode = new SortedNode(x);
            head = nNode;
        }

    void push(int);
    bool pop(int);
};

#endif