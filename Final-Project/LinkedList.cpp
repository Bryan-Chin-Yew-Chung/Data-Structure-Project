#include "LinkedList.h"


// Push data into Linked List
void LinkedList ::push(int data){
    Node *nNode = new Node(data);
    if (tail == nullptr)
    {
        head = nNode;
        tail = nNode;
    }
    else
    {
        tail->next = nNode;
        tail = nNode;
    }
    size++;
}

// Delete data from linkedlist based on key
bool LinkedList :: pop(int key){
    Node *prev = nullptr;
    Node *current = head;
    bool found = false;

    while (current != nullptr)
    {
        if (current->data == key)
        {
            if (current == head)
            {
                head = head->next;
                delete current;
                current = head;
                found = true;
                return found;
            }
            else
            {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

// Find Maximum Number
int LinkedList :: findMax(){
    int max = INT_MIN;
    Node *ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->data > max)
            {
                max = ptr->data;
            }
        ptr = ptr->next; 
        }
    return max;
    }

// Find Minimum Number
int LinkedList :: findMin(){
    int min = INT_MAX;
    Node *ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->data < min)
            {
                min = ptr->data;
            }
        ptr = ptr->next; 
        }
    return min;
    }

// Function to search age 
bool LinkedList :: search(int key){
    Node *ptr = head;
    bool found = false;
    while (ptr != nullptr){
        if (ptr->data == key){
            found = true;
            break;
        }
        ptr = ptr->next;
    }
    return found;
}


    

