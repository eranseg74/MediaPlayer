#ifndef LISTINDEX_H
#define LISTINDEX_H

#include "List_base.h"


class ListIndex : public List_base
{
    public:
        /** Default constructor */
        ListIndex();
        void displayMenu(string msg);
        /** Default destructor */
        virtual ~ListIndex();
    protected:
    private:
};

#endif // LISTINDEX_H
