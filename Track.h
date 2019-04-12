#ifndef TRACK_H
#define TRACK_H

#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Track
{
    public:
        /** Default constructor */
        Track();
        Track(string tName, string plName);
        string getName();
        string getPlName();
        void setName(string s);
        void setPlName(string p);
        void setPlAndName(string s, string p);
        void displayMenu(string msg);
        /** Default destructor */
        virtual ~Track();
    protected:
    private:
        string playlistName;
        string trName;
};

#endif // TRACK_H
