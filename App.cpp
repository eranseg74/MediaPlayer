#include "App.h"

/*
The App class is the main class that holds all the logic of the program
and is invoked by the main function when the program starts
*/

/*
The class constructor
*/
App::App()
{
    mainFlag = true;
    plFlag = true;
    trFlag = true;
    display = true;
    cont = true;
    plName = "";
    trName = "";
    msg = "";
    playlists = ListIndex();
}

/*
The starting point on program start. Contains the main menu process.
*/
void App::run()
{
    do
    {
        cont = true;
        playlists.displayMenu(msg);
        cin >> ch;
        cin.ignore();
        switch (ch) //Main Menu process
        {
            case 'x':
                remove("index.txt");
                cout << "Farewell" << endl;
                mainFlag = false;
                break;
            case 'c':
                msg = "";
                validateScenario();
                break;
            default:
                int plIndex = ch - '1';
                if(plIndex >= 0 && plIndex < playlists.numOfItems())
                {
                    msg = "";
                    runPlaylistScenario(plIndex);
                }
                else
                {
                    msg = "Invalid track number. Please try again.";
                }
                break;
        }
    }
    while(mainFlag);
}

/*A utility function for validating the playlist name as given by the user*/
void App::validateScenario()
{
    do
    {
        playlists.displayMenu(msg);
        cout << "\n\nPlease enter a name for your new playlist:\n" << endl;
        getline(cin, plName);
        if(playlists.exists(plName))
        {
            msg = "Sorry. That playlist already exists. Please try again";
        }
        else
        {
            msg = "";
            playlists.addItem(plName);
            plVec.push_back(Playlist(plName));
            sort(plVec.begin(), plVec.end(), compFunc);
            runPlaylistScenario(getPlFromVec(plName));
            cont = false;
        }
    }
    while(cont);
}

/*
A function to control the interaction on the playlist menu
int pos - the position of the playlist in the playlists vector
*/
void App::runPlaylistScenario(int pos)
{
    string title;
    do
    {
        plFlag = true;
        plVec[pos].displayMenu(msg);
        cin >> ch;
        cin.ignore();
        switch (ch)
        {
            case 'x':
                plFlag = false;
                break;
            case 'd':
                title = plVec[pos].getName();
                playlists.deleteItem(title);
                delTracksFromVec(title);
                delElement(title);
                msg = "Playlist deleted.";
                plFlag = false;
                break;
            case 'a':
                runAddTrackScenario(pos);
                break;
            default:
                int plIndex = ch - '1';
                if(plIndex >= 0 && plIndex < plVec[pos].numOfItems()) {
                    msg = "";
                    runTrackScenario(plIndex);
                }
                else
                {
                    msg = "Invalid track number. Please try again.";
                }
                break;
        }
    }
    while(plFlag);
}

/*
A utility function for controlling the interaction with the user when adding a track
and validating the track name as given by the user
int pos - the position of the playlist in the playlists vector
*/
void App::runAddTrackScenario(int pos)
{
    do
    {
        trFlag = true;
        cout << "\nEnter a title and artist, or 'x' to exit." << endl;
        getline(cin, trName);
        if(trName == "x" || trName == "X")
        {
            trFlag = false;
        }
        else
        {
            string parsedTrack = TrackParser::parse(trName);
            if(plVec[pos].exists(parsedTrack) || parsedTrack == "")
            {
                string plMsg = (parsedTrack == "") ? "Unrecognized format. Please try again" :
                "that track already exists. Please try again.";
                cout << plMsg << endl;
            }
            else
            {
                plVec[pos].addItem(parsedTrack);
                Track track(parsedTrack, plVec[pos].getName());
                tracks.push_back(track);
                sort(tracks.begin(), tracks.end(), compFunc1);
            }
        }
    } while(trFlag);
}
/*
A function to control the interaction on the track menu
int pos - the position of the track in the tracks vector
*/
void App::runTrackScenario(int pos)
{
    string trackName;
    string playlistTitle;
    bool b = true;
    while(b)
    {
        tracks[pos].displayMenu(msg);
        cin >> ch;
        cin.ignore();
        switch (ch)
        {
            case 'x':
                b = false;
                break;
            case 'd':
                trackName = tracks[pos].getName();
                playlistTitle = tracks[pos].getPlName();
                plVec[getPlFromVec(playlistTitle)].deleteItem(trackName);
                delElement1(trackName);
                msg = "Track deleted.";
                b = false;
                break;
            default:
                msg = "Invalid track number. Please try again.";
                break;
        }
    }
}
/*
A function for getting a playlist from the playlists vector by a playlist name.
s - The playlist's name.
*/
int App::getPlFromVec(string s)
{
    if(!plVec.empty())
    {
        for(unsigned int i = 0; i < plVec.size(); i++)
        {
            if(plVec[i].getName() == s)
            {
                return i;
            }
        }
    }
    return -1;
}
/*
A function for getting a track from the tracks vector by a track name.
s - The track's name.
*/
int App::getTrFromVec(string s)
{
    if(!tracks.empty())
    {
        for(unsigned int i = 0; i < tracks.size(); i++)
        {
            if(tracks[i].getName() == s)
            {
                return i;
            }
        }
    }
    return -1;
}
/*
A function for deleting a given Playlist from the track s vector.
elName - The playlist name that is going to be erased.
*/
void App::delElement(string elName)
{
    if(!plVec.empty())
    {
        vector<Playlist>::iterator itName = plVec.begin();
        while(itName != plVec.end())
        {
            if(itName->getName() == elName)
            {
                plVec.erase(itName);
                break;
            }
            itName++;
        }
        sort(plVec.begin(), plVec.end(), compFunc);
    }
}
/*
A function for deleting a given Track from the track s vector.
elName - The track name that is going to be erased.
*/
void App::delElement1(string elName)
{
    if(!tracks.empty())
    {
        vector<Track>::iterator itName = tracks.begin();
        while(itName != tracks.end())
        {
            if(itName->getName() == elName)
            {
                tracks.erase(itName);
                break;
            }
            itName++;
        }
        sort(tracks.begin(), tracks.end(), compFunc1);
    }
}

void App::delTracksFromVec(string pListName)
{
    if(!tracks.empty())
    {
        vector<Track>::iterator itName = tracks.begin();
        ifstream myfile(pListName.c_str());
        if(myfile.is_open())
        {
            string line;
            while(getline(myfile, line)) {
                while(itName != tracks.end())
                {
                    if(itName->getName() == line)
                    {
                        tracks.erase(itName);
                        break;
                    }
                }
            }
            myfile.close();
        }
    }
}

bool App::compFunc(Playlist &a, Playlist &b)
{
    return a.getName() < b.getName();
}

bool App::compFunc1(Track &a, Track &b)
{
    return a.getName() < b.getName();
}

App::~App()
{
    //dtor
}
