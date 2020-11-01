/*
    Name: Ryan Tang
    ID: 38859342
    Partner Name: Suraj Sajos
    Partner ID: 89963984
*/

#ifndef MOVIEMANAGERUI_H_
#define MOVIEMANAGERUI_H_

#include "Movies.h"

class MovieManagerUI{
    public:
        void printMenu();
        string getCommand();
        string getMovieName();
        string getMovieCode();
        int getRenterID();
        string getRenterFirstName();
        string getRenterLastName();
        string toUpper(string);
};

#endif
