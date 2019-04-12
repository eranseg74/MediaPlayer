#ifndef LIST_BASE_H
#define LIST_BASE_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class List_base
{
    public:
        /** Default constructor */
        List_base(string iName);
        string getName();
        void setName(string iName);
        bool exists(string item);
        void addItem(string item);
        void deleteItem(string item);
        int numOfItems();
        /** Default destructor */
        virtual ~List_base();
    protected:
        void saveToFile();
        void printList(string msg);
    private:
        string name;
        vector<string> items;
};

#endif // LIST_BASE_H
