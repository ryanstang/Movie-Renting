/*
    Name: Ryan Tang
    ID: 38859342
    Partner Name: Suraj Sajos
    Partner ID: 89963984
*/

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
