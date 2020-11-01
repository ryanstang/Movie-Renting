/*
    Name: Ryan Tang
    ID: 38859342
    Partner Name: Suraj Sajos
    Partner ID: 89963984
*/

#include "Renter.h"

// default constructor for Renter
Renter::Renter(){
}

// constructor for Renter
Renter::Renter(int ID, string FirstName, string LastName){
    this->RenterID = ID;
    this->RenterFirstName = FirstName;
    this->RenterLastName = LastName;
}

// set Renter ID
void Renter::setRenterID(int ID){
    this->RenterID = ID;
}

// get renter ID
int Renter::getRenterID(){
    return this->RenterID;
}

// set Renter First Name
void Renter::setRenterFirstName(string FirstName){
    this->RenterFirstName = FirstName;
}

// get Renter First Name
string Renter::getRenterFirstName(){
    return this->RenterFirstName;
}

// set Renter Last Name
void Renter::setRenterLastName(string LastName){
    this->RenterLastName = LastName;
}

// get Renters Last Name
string Renter::getRenterLastName(){
    return this->RenterLastName;
}

