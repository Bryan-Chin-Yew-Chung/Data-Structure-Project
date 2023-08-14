#include "SortedLinkedList.h"

// Push Into Sorted LinkedList
void SortedLinkedList :: push(int data){
        SortedNode *nNode = new SortedNode(data);
        SortedNode *ptr = head;
        SortedNode *current;
        if (ptr == nullptr || ptr->data >= nNode->data)
        {
            nNode->next = head;
            head = nNode;
        }
        else 
        {   
            current = head;
            while (current->next != nullptr && current->next->data < nNode->data)
            {
                current = current->next;
            }
            nNode->next = current->next;
            current->next = nNode;
        }
    }

// Function to delete data by key
bool SortedLinkedList :: pop(int key) {
        SortedNode *prev = nullptr;
        SortedNode *current = head;
        bool found = false;
        while(current != nullptr)
        {
            if (current->data == key)
            {
                if (current == head)
                {
                    head = head->next;
                    delete current;
                    current = head;

                }
                else
                {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                    
                }
                found = true;
                return found;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        
    }
        


