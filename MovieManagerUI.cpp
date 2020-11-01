

#include "MovieManagerUI.h"

// prints menu options
void MovieManagerUI::printMenu(){
cout << "Welcome to Movie Rental Kiosk!"<< endl <<
        "----------" << endl
        << "am: Add Movie" << endl
        <<"dm: Discontinue Movie" << endl
        <<"rm: Rent Movie" << endl
        <<"rr: Return Rental" << endl
        <<"p: Print Movie Inventory"
        << endl <<"q: Quit Program"
        << endl<< "----------" << endl
        << "Enter Command: ";
}

// gets command from the console
string MovieManagerUI::getCommand(){
    string result;
    getline (cin,result);
    while(result != "am" and result != "dm" and result != "rm" and result != "rr" and result != "p" and result != "q"){
        cout<<"Command is't valid. Enter correct command: ";
        getline (cin,result);;
    };
    
    return result;
}

// gets movie name
string MovieManagerUI::getMovieName(){
    string MovieName;
    cout << "What is movie name? ";
    getline (cin,MovieName);
    return MovieName;
}

// gets movie code
string MovieManagerUI::getMovieCode(){
    string MovieCode;
    cout << "What is movie code? ";
    getline (cin,MovieCode);
    return MovieCode;
}

// gets renter ID
int MovieManagerUI::getRenterID(){
    int RenterID;
    cout << "What is renter ID? ";
    cin >> RenterID;
    cin.ignore();
    return RenterID;
}

// gets Renters First Name
string MovieManagerUI::getRenterFirstName(){
    string RenterFirstName;
    cout << "What is renter first name? ";
    getline (cin,RenterFirstName);
    return RenterFirstName;
}

// gets Renter Last Name
string MovieManagerUI::getRenterLastName(){
    string RenterLastName;
    cout << "What is renter last name? ";
    getline (cin,RenterLastName);
    return RenterLastName;
}

// upper case the whole string
string MovieManagerUI::toUpper(string word){
    string result;
    for(int i = 0;i<word.size();i++){
        result += toupper(word[i]);
    }
    return result;
}
