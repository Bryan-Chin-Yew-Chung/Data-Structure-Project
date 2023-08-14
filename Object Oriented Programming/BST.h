#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include <iostream>
#include <fstream>

class BST {
    friend class Read;
    int data;
    BST *left, *right;

  public:
    BST();
    BST(int);
    BST* insert(BST* , int);
    BST* pop(BST* , int);
    BST* minValueNode(BST*);
    void inOrder(BST* );

};

#endif