#include "Track.h"

Track::Track()
{
    this->playlistName = "";
    this->trName = "";
}

Track::Track(string tName, string plName)
{
    this->playlistName = plName;
    this->trName = tName;
}

string Track::getName()
{
    return this->trName;
}

string Track::getPlName()
{
    return this->playlistName;
}

void Track::setName(string s)
{
    this->trName = s;
}

void Track::setPlName(string p)
{
    this->playlistName = p;
}

void Track::setPlAndName(string s, string p)
{
    setName(s);
    setPlName(p);
}

void Track::displayMenu(string msg)
{
    system("clear");
    if(msg != "")
    {
        cout << msg << "\n" << endl;
    }
    cout << "Playlist '" << this->playlistName << "' " << endl;
    cout << "Track '" << this->trName << "' Menu:\n" << endl;
    cout << "d. Delete this track" << endl;
    cout << "x. Exit to playlist menu\n" << endl;
    cout << "Your choice: ";
}

Track::~Track()
{
    //dtor
}
