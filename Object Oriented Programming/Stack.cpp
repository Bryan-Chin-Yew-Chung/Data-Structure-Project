#include "Stack.h"

// Check stack is empty or not
bool stack :: isEmpty() {
    return top == nullptr;
}

// Return top element of the stack
int stack :: peek(){
    if (!isEmpty())
    {
        return top->data;
    }
}

// Push Data into the stack
void stack :: push(int data) {
    StackNode *temp = new StackNode(data);

    temp->data = data;
    temp->link = top;
    top = temp;
    }

bool stack :: pop() {
    StackNode *temp;
    bool empty = false;

    if (top == nullptr)
    {
        return empty;
    }
    else
    {
        temp = top;
        top = top->link;

        delete temp;

        empty = true;
        return empty;
    }
}
 