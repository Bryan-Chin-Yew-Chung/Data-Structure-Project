#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node *link;

    Node(int x){
        data = x;
        next = nullptr;
    }
    
};

class LinkedList {
    friend class Read;
    friend class SortedLinkedList;
    Node *head;
    Node *tail;
    int size;

    public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    LinkedList(int x){
        Node *nNode = new Node(x);
        head = nNode;
        tail = nNode;
        size = 1;
    }
    
    void push(int);
    bool pop(int);
    int findMax();
    int findMin();
    bool search(int);
};

#endif