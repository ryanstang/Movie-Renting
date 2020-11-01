

#ifndef MOVIES_H_
#define MOVIES_H_

#include "Renter.h"


class Movies{
    private:
        string MovieCode;
        string MovieName;
        int RentedCopies;
        Renter Renters[10];
    public:
        Movies();
        Movies(string, string);
        string getMovieCode();
        string getMovieName();
        int getRentedCopies();
        void rentMovie(Renter);
        void returnRental(int);
        friend ostream& operator<<( ostream &os, Movies &);
};

#endif
