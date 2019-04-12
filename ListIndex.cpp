#include "ListIndex.h"

ListIndex::ListIndex() : List_base("index.txt")
{
    //ctor
}

void ListIndex::displayMenu(string msg)
{
    system("clear");
    if(msg != "") {
        cout << msg << "\n" << endl;
    }
    cout << "Main Menu\n" << endl;
    cout << "c. Create a playlist" << endl;
    cout << "x. Exit the program" << endl;
    printList("Select Playlist #\n");
    cout << "\nYour choice: ";
}

ListIndex::~ListIndex()
{
    //dtor
}
