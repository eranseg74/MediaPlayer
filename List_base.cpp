#include "List_base.h"

List_base::List_base(string iName)
{
    this->name = iName;
    ofstream myfile;
    string fName = (iName == "index.txt") ? iName : iName + ".playlist";
    myfile.open(fName.c_str());
    myfile.close();
}

string List_base::getName()
{
    return this->name;
}

void List_base::setName(string iName)
{
    this->name = iName;
}

void List_base::addItem(string item)
{
    this->items.push_back(item);
    saveToFile();

}

void List_base::deleteItem(string item)
{
    vector<string>::iterator itName = items.begin();
    while(itName != items.end())
    {
        if(*itName == item)
        {
            items.erase(itName);
            remove((item+".playlist").c_str());
            saveToFile();
            break;
        }
        itName++;
    }
}

bool List_base::exists(string item)
{
    vector<string>::iterator itName = items.begin();
    while(itName != items.end())
    {
        if(*itName == item)
        {
            return true;
        }
        itName++;
    }
    return false;
}

int List_base::numOfItems()
{
    return this->items.size();
}

void List_base::saveToFile()
{
    ofstream myfile;
    string fName = (this->name == "index.txt") ? this->name : this->name + ".playlist";
    myfile.open(fName.c_str());
    if(!items.empty())
    {
        sort(items.begin(), items.end());
        int index = 1;
        vector<string>::iterator itName = items.begin();
        while(itName != items.end())
        {
            myfile << index << " - " << *itName << endl;
            itName++;
            index++;
        }
    }
    myfile.close();
}

void List_base::printList(string msg)
{
    if(!items.empty())
    {
        sort(items.begin(), items.end());
        int index = 1;
        vector<string>::iterator itName = items.begin();
        cout << "\n" << msg << endl;
        while(itName != items.end())
        {
            cout << index << " - " << *itName << endl;
            itName++;
            index++;
        }
    }
}

List_base::~List_base()
{
    //dtor
}
