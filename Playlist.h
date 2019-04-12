#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "List_base.h"


class Playlist : public List_base
{
    public:
        /** Default constructor */
        Playlist();
        Playlist(string uName);
        void displayMenu(string msg);
        void displayTrackMenu(string msg, string trName);
        /** Default destructor */
        virtual ~Playlist();
    protected:
    private:
};

#endif // PLAYLIST_H
