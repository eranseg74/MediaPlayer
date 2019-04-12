#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <string>
#include <iostream>

#include "ListIndex.h"
#include "Playlist.h"
#include "Track.h"
#include "TrackParser.h"

using namespace std;

class App
{
    public:
        /** Default constructor */
        App();
        void run();
        /** Default destructor */
        virtual ~App();
    protected:
    private:
        bool mainFlag;
        bool plFlag;
        bool trFlag;
        bool display;
        bool cont;
        char ch;
        string plName;
        string trName;
        string msg;
        ListIndex playlists;
        vector<Playlist> plVec;
        vector<Track> tracks;
        void runPlaylistScenario(int pos);
        void runAddTrackScenario(int pos);
        void runTrackScenario(int pos);
        void validateScenario();
        int getPlFromVec(string s);
        int getTrFromVec(string s);
        void delElement(string elName);
        void delElement1(string elName);
        void delTracksFromVec(string pListName);
        static bool compFunc(Playlist &a, Playlist &b);
        static bool compFunc1(Track &a, Track &b);
};

#endif // APP_H
