#include "TrackParser.h"

TrackParser::TrackParser()
{
    //ctor
}

string TrackParser::trim(string anystring)
{
    string retVal = anystring;
    unsigned long lastPos = retVal.length() - 1;
    bool found = true;
    while(found == true && lastPos >= 0)
    {
        if(retVal.substr(lastPos, 1) == " ")
        {
            retVal = retVal.erase(lastPos, 1);
        }
        else if(retVal.substr(0, 1) == " ")
        {
            retVal = retVal.erase(0, 1);
        }
        else
        {
            found = false;
        }
        lastPos = retVal.length() - 1;
    }
    return retVal;
}

string TrackParser::parse(string str)
{
    string anystring = trim(str);
    string artist = "";
    string title = "";
    size_t found = anystring.find(":");
    if(found != string::npos)
    {
        artist = trim(anystring.substr(0, found));
        title = trim(anystring.substr(found + 1, anystring.length() - found));
    }
    else
    {
        found = anystring.find("-");
        if(found != string::npos)
        {
            title = trim(anystring.substr(0, found - 1));
            artist = trim(anystring.substr(found + 1, anystring.length() - found - 1));
        }
        else
        {
            int pos = -1;
            found = anystring.find("by");
            // Looping until the last occurrence of 'by'
            while(found != string::npos)
            {
                if(anystring.at(found - 1) == ' ' && anystring.at(found + 2) == ' ')
                {
                    pos = found;
                }
                found = anystring.find("by", found + 2);
            }
            if(pos != -1)
            {
                title = trim(anystring.substr(0, pos - 1));
                artist = trim(anystring.substr(pos + 2, anystring.length() - pos - 1));
            }
            else
            { // Deals with all other options
                return "";
            }
        }
    }
    return artist+": "+title;
}

TrackParser::~TrackParser()
{
    //dtor
}
