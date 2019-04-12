#include "Playlist.h"

Playlist::Playlist() : List_base("")
{
    //ctor
}

Playlist::Playlist(string name) : List_base(name)
{
    //ctor
}

void Playlist::displayMenu(string msg)
{
    system("clear");
    if(msg != "")
    {
        cout << msg << "\n" << endl;
    }
    cout << "Playlist '" << this->getName() << "' Menu\n" << endl;
    cout << "a. Add track(s) to the playlist." << endl;
    cout << "d. Delete this playlist." << endl;
    cout << "x. Exit to main menu" << endl;
    printList("Select Track #\n");
    cout << "\nYour choice: ";
}

Playlist::~Playlist()
{
    //dtor
}
