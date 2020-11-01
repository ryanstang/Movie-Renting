
#ifndef MOVIEMANAGER_H_
#define MOVIEMANAGER_H_

#include "MovieManagerUI.h"

class MovieManager{
    private:
        Movies Movie[20];
        int NumOfMovies = 0;
        MovieManagerUI UI;
    public:
        MovieManager();
        void run();
        void addMovie(Movies);
        void discontinueMovie(string);
        void rentMovie(string, Renter);
        void returnRental(int, string);
        void printInventory();
};

#endif
