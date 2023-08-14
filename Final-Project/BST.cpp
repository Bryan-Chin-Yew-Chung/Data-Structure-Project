#include "BST.h"

BST :: BST() : data(0) , left(nullptr) , right(nullptr){}

BST :: BST(int value){ data = value; left = right = nullptr;}

// Insert Node
BST * BST :: insert(BST* root , int value) {
    if (!root) 
    {
        return new BST(value);
    }

    if(value > root->data) 
    {
        root->right = insert(root->right , value);
    }

    else if (value < root->data)
    {
        root->left = insert(root->left , value);
    }

    return root;
}

// Find minimum value node
BST * BST :: minValueNode(BST* value)
{
    BST* current = value;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != nullptr)
        current = current->left;
 
    return current;
}
 
 // Delete Node
BST * BST :: pop(BST* root , int value) {
    if (root == nullptr)
    {
        return root;
    }
    if (value < root->data) {
        root->left = pop(root->left , value);
    }
    else if (value > root->data) 
    {
        root->right = pop(root->right , value);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return nullptr;
        }
        else if (root->left == nullptr)
        {
            BST* temp = root->right;
            delete(root);
            return temp;
        }        
        else if (root->right == nullptr)
        {
            BST* temp = root->left;
            delete(root);
            return temp;
        }
    
    BST * temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = pop(root->right , temp->data);
    }
    return root;
}

void BST :: inOrder(BST * root ) {
    int data;
    if (!root)
    {
        return;
    }
    inOrder(root->left);
        fileOut << root->data << " ";
    inOrder(root->right);
}
