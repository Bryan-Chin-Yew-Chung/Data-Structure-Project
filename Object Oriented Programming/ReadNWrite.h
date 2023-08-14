#ifndef READ
#define READ

#include <fstream>
#include <limits>
#include <sstream>
#include <iostream>

using namespace std;

ifstream inFile;
ofstream fileOut;

class Read
{
    public:
    Read(){ write(); }
    string get(int);
    int extractInt(string);
    void write();
};

#endif