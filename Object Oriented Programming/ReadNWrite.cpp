#include "ReadNWrite.h"
#include "LinkedList.h"
#include "SortedLinkedList.h"
#include "Stack.h"
#include "BST.h"

fstream& GotoLine(fstream& file, int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}

string Read :: get(int x) {

    fstream file("input.txt");
    string line;
    GotoLine(file , x);
    getline(file , line);
    return line;
}
     
int Read :: extractInt(string str)
    {
        stringstream ss;
        ss << str;

        string temp;
        int found;
        while (!ss.eof())
        {

            ss >> temp;

            if (stringstream(temp) >> found)
                return found;

            temp = "";
        }
    }

void Read :: write(){

    LinkedList l;
    SortedLinkedList s;
    stack st;
    BST b , *root = nullptr;
    inFile.open("Input.txt");
    fileOut.open("Output.txt");
    

    int count = 1;

    // Strings to change key fast
    string
    listMake    = "LinkedList list",
    listAdd     = "list add",
    listDel     = "list delete",
    listMin     = "list min",
    listMax     = "list max",
    listPrint   = "list print",
    listSearch  = "list search",
    sortMake    = "SortedLinkedList sortedList",
    sortAdd     = "sortedList add",
    sortDel     = "sortedList delete",
    sortPrint   = "sortList print",
    stackMake   = "LinkedStack stack",
    stackAdd    = "stack add",
    stackDel    = "stack delete",
    stackPrint  = "stack print",
    BSTMake     = "BinarySearchTree bst",
    BSTAdd      = "bst add",
    BSTDel      = "bst delete",
    BSTInor     = "bst inorder";

    for (int i = 0; i < count; i++){
        string current = get(count);


    
        // Create LinkedList if key found
            if (current == listMake)
            {
                fileOut << "list constructed\n";
            }
        // Push linked if key found
            else if (current.find(listAdd) != string::npos) 
            {             
                fileOut << "list added " << extractInt(current) << endl;
                l.push(extractInt(current));
                
            }
        // Delete linked if key found
            else if (current.find(listDel) != string::npos) 
            {  
                l.pop(extractInt(current)) ? 
                    fileOut << "not found "  << endl :
                    fileOut << "list deleted " << extractInt(current) << endl;    
            }
                    
        // Print linkedlist if key found
            else if (current == listPrint) 
            {     
                Node* ptr = l.head;
                if (l.head == nullptr) 
                    { 
                        fileOut << "empty\n";
                    }
                else {
                    while(ptr != nullptr)
                    {
                        fileOut << ptr->data  << " ";
                        ptr = ptr->next; 

                    }
                    fileOut << endl;
                }
            }
        // Find linked min if key found
            else if (current == listMin) 
            {       
                fileOut << l.findMin() << endl;           
            }
        // Find linked max key is found
            else if (current == listMax) 
            {       
                fileOut << l.findMax() << endl;           
            }
       // Search linked for key
            else if (current.find(listSearch) != string::npos) 
            {  
                l.search(extractInt(current)) ? 
                fileOut << "found\n" :
                fileOut << "not found\n";
            }
        // Sorted Linked List Creation
            else if (current == sortMake)
            {
                fileOut << "sortList constructed\n";
            }
        // Add Sortlist if key is found
            else if (current.find(sortAdd) != string::npos) 
            {  
                fileOut << "sortedList added " << extractInt(current) << endl;
                s.push(extractInt(current));
            }
        // Pop Sortlist if key is found
            else if (current.find(sortDel) != string::npos) 
            {  
                s.pop(extractInt(current)) ? 
                    fileOut << "list deleted " << extractInt(current) << endl :
                    fileOut << "not found "  << endl;
            }
        // Print Sortedlinkedlist if key found
            else if (current == sortPrint) 
            {     
                SortedNode* ptr = s.head;
                if (s.head == nullptr) 
                    { 
                        fileOut << "empty\n";
                    }
                else {
                    while(ptr != nullptr)
                    {
                        fileOut << ptr->data  << " ";
                        ptr = ptr->next; 

                    }
                    fileOut << endl;
                }
            }
        // Stack Creation
            else if (current == stackMake)
            {
                fileOut << "stack constructed\n";
            }
        // Push stack if command is found
            else if (current.find(stackAdd) != string::npos) 
            {             
                fileOut << "stack added " << extractInt(current) << endl;
                st.push(extractInt(current));
                
            }
        // Pop Stack if key is found
            else if (current.find(stackDel) != string::npos) 
            {  
                int deleted = st.peek();
                st.pop() ? 
                    fileOut << "stack deleted " << deleted << endl :
                    fileOut << "stack empty "  << endl;
            }
        // Print Stack if key found
            else if (current == stackPrint) 
            {     
                StackNode *temp;

                if (st.top == nullptr)
                {
                    fileOut << "stack empty\n";
                }
                else
                {
                    temp = st.top;     
                    while (temp != nullptr) {
                        fileOut << temp->data << " ";
                        temp = temp->link;
                    }
                    fileOut << endl;
                }
            }
        // BST Creation
            else if (current == BSTMake)
            {
                fileOut << "bst constructed\n";
            }
        // Push BST if command is found
            else if (current.find(BSTAdd) != string::npos) 
            {             
                fileOut << "bst added " << extractInt(current) << endl;
                root = b.insert(root , extractInt(current));  
            }
        // Pop BST if command is found
            else if (current.find(BSTDel) != string::npos) 
            {             
                fileOut << "bst deleted " << extractInt(current) << endl;
                root = b.pop(root , extractInt(current));  
            }
        // Print stack if command is found
            else if (current == BSTInor) 
            {
                b.inOrder(root);
                
            }
            
        // End Program If Line Is Empty
            else if (current == "")
            {
                break;
                fileOut.close();
            }         
        // Else Print Bad Input
            else
            {
                fileOut << "Bad Input\n";
            }
        count++;

    }
    }