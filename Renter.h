

#ifndef RENTER_H_
#define RENTER_H_

#include "Exceptions.cpp"
class Renter{
    private:
        int RenterID;
        string RenterFirstName;
        string RenterLastName;
    public:
        Renter();
        Renter(int, string, string);
        void setRenterID(int);
        int getRenterID();
        void setRenterFirstName(string);
        string getRenterFirstName();
        void setRenterLastName(string);
        string getRenterLastName();
};
#endif
