/*
    Name: Ryan Tang
    ID: 38859342
    Partner Name: Suraj Sajos
    Partner ID: 89963984
*/

#include "Movies.h"

// default constructor for movies
Movies::Movies(){
}

// one structor for Movie
Movies::Movies(string Code, string Name){
    this->MovieCode = Code;
    this->MovieName = Name;
    this->RentedCopies = 0;
}

// gets Movie Code
string Movies::getMovieCode(){
    return this->MovieCode;
}

// gets Movie Name
string Movies::getMovieName(){
    return this->MovieName;
}

// gets Rented Copies
int Movies::getRentedCopies(){
    return this->RentedCopies;
}

// adds renter to renters array
void Movies::rentMovie(Renter renter){
     if(renter.getRenterID() < 0){
         throw InvalidRenterIDException();
     }
     
    if(this->RentedCopies == 10){
        throw RenterLimitException();
    }
    
    for(int i = 0; i < this->RentedCopies; i++){
        if(Renters[i].getRenterID() == renter.getRenterID())
        {
            throw DuplicateMovieException();
        }
    }
    
    if(renter.getRenterFirstName() == "" or renter.getRenterLastName() == ""){
        throw EmptyRenterNameException();
    }
    
    this->Renters[RentedCopies] = renter;
    
    this->RentedCopies += 1;
    
    Renter copyR[this->getRentedCopies()];
    for(int i = 0; i < this->getRentedCopies(); i++){
        int x = 0;
        for(int j = 0; j < this->getRentedCopies(); j++){
            if(Renters[i].getRenterFirstName() > Renters[j].getRenterFirstName()){
                x += 1;
            }else{
                if(Renters[i].getRenterFirstName() == Renters[j].getRenterFirstName()){
                    if(Renters[i].getRenterLastName() > Renters[j].getRenterLastName()){
                        x += 1;
                    }else{
                        if(Renters[i].getRenterLastName() > Renters[j].getRenterLastName()){
                            if(Renters[i].getRenterID() > Renters[j].getRenterID()){
                                x += 1;
                            }
                        }
                    }
                }
            }
        }
        copyR[x] = Renters[i];
    }
    
    for(int i = 0; i < this->getRentedCopies(); i++){
        Renters[i] = copyR[i];
    }
    
}

// removes a renter from movie based on their renters ID
void Movies::returnRental(int ID){
     if(ID < 0){
         throw InvalidRenterIDException();
     }
    
    if(this->RentedCopies == 0){
        throw EmptyRenterListException();
    }
    
    bool notcorrect = true;
    for(int i = 0; i < this->RentedCopies; i++){
        if(Renters[i].getRenterID() == ID){
            notcorrect = false;
        }
    }
    if(notcorrect){
        throw RenterNotFoundException();
    }
    
    
    for(int i = 0; i<this->RentedCopies;i++){
        if(this->Renters[i].getRenterID() == ID){
            for(int j=i;j < this->RentedCopies - 1;j++){
                Renters[j] = Renters[j + 1];
            }
            this->RentedCopies -= 1;
            break;
        }
    }
}


// overload << operator
ostream &operator<<(ostream& os, Movies &Movie){
    string result = "";
    result += "Movie Name : ";
    result += Movie.MovieName;
    result += " Code : ";
    result += Movie.MovieCode;
    result += " Number of Renter(s): ";
    result += to_string(Movie.RentedCopies);
    result += "\n";
    if(Movie.RentedCopies > 0){
        for(int i = 0; i < Movie.RentedCopies; i++){
            result += Movie.Renters[i].getRenterFirstName();
            result += " ";
            result += Movie.Renters[i].getRenterLastName();
            result += ", ";
            result += to_string(Movie.Renters[i].getRenterID());
            result += "\n";
        }
    }
    os << result;
    return os;
}
