#ifndef TRACKPARSER_H
#define TRACKPARSER_H

#include <string>
#include <iostream>

using namespace std;

class TrackParser
{
    public:
        /** Default constructor */
        TrackParser();
        static string parse(string anystring);
        /** Default destructor */
        virtual ~TrackParser();
    protected:
    private:
        static string trim(string str);
};

#endif // TRACKPARSER_H
