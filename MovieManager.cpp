/*
    Name: Ryan Tang
    ID: 38859342
    Partner Name: Suraj Sajos
    Partner ID: 89963984
*/

#include "MovieManager.h"

MovieManager::MovieManager(){
}

// runs main loop of program. Displays menu, accepts user input, and handles each of user commands
void MovieManager::run(){
    bool running = true;
    
    while(running){
        UI.printMenu();
        string command = UI.getCommand();
        if(command == "am"){
            try{
            string MovieName = UI.getMovieName();
            string MovieCode = UI.getMovieCode();
            this->addMovie(Movies(MovieCode, MovieName));
            }
            catch(MovieLimitException){
                cout << "Max number of movies." << endl;
            }
            catch(EmptyMovieInfoException){
                cout << "Movie code and/or movie name is empty." << endl;
            }
            catch(DuplicateMovieException){
                cout << "Movies already exists." << endl;
            }
        }
        if(command == "dm"){
            try{
            string MovieCode = UI.getMovieCode();
            this->discontinueMovie(MovieCode);
            }
            catch(MovieNotFoundException){
                cout << "Movies does not exist." << endl;
            }
            catch(EmptyMovieListException){
                cout << "No movie in the inventory list." << endl;
            }
            catch(RentedMovieException){
                cout << "Copies are currently rented out." << endl;
            }
        }
        if(command == "rm"){
            try{
                string MovieCode = UI.getMovieCode();
                int ID = UI.getRenterID();
                string FirstName = UI.getRenterFirstName();
                string LastName = UI.getRenterLastName();
                this->rentMovie(MovieCode, Renter(ID, UI.toUpper(FirstName), UI.toUpper(LastName)));
            }
            /*
               MovieNotFoundException: Thrown when a movie that does not exist.
            */
            catch(MovieNotFoundException){
                cout << "Movies does not exist." << endl;
            }
        }
        if(command == "rr"){
            try{
            string MovieCode = UI.getMovieCode();
            int ID = UI.getRenterID();
            this->returnRental(ID, MovieCode);
            }
            /*
               MovieNotFoundException: Thrown when a movie that does not exist.
            */
            catch(MovieNotFoundException){
                cout << "Movies does not exist." << endl;
            }
        }
        if(command == "p"){
            this->printInventory();
        }
        if(command == "q"){
            running = false;
        }
    };
}

// adds movie to array of movies
void MovieManager::addMovie(Movies m){
    if(this->NumOfMovies == 20){
        throw MovieLimitException();
    }
    
    if(m.getMovieCode() == "" or m.getMovieName() == ""){
        throw EmptyMovieInfoException();
    }
    
    for(int i = 0; i < this->NumOfMovies;i++){
        if(Movie[i].getMovieCode() == m.getMovieCode()){
            throw DuplicateMovieException();
        }
    }
    
    Movie[NumOfMovies] = m;
    NumOfMovies += 1;
}

// removes movie from array of Movies
void MovieManager::discontinueMovie(string code){
     if(this->NumOfMovies == 0){
        throw EmptyMovieInfoException();
     }
     
     bool notcorrect = true;
     for(int i = 0; i < this->NumOfMovies;i++){
        if(Movie[i].getMovieCode() == code){
            notcorrect = false;
        }
     }
     if(notcorrect){
        throw MovieNotFoundException();
     }
     
     for(int i = 0; i < this->NumOfMovies;i++){
        if(Movie[i].getMovieCode() == code){
            if(Movie[i].getRentedCopies() > 0){
                throw RentedMovieException();
            }
             break;
        }
     }
     
    for(int i = 0; i<this->NumOfMovies;i++){
        if(this->Movie[i].getMovieCode() == code){
            for(int j=i;j < this->NumOfMovies - 1;j++){
                Movie[j] = Movie[j + 1];
            }
            this->NumOfMovies -= 1;
            break;
        }
    }
}

// adds a renter to an already existing movie
void MovieManager::rentMovie(string code, Renter renter){
     bool notcorrect = true;
     for(int i = 0; i < this->NumOfMovies;i++){
        if(Movie[i].getMovieCode() == code){
            notcorrect = false;
        }
     }
     if(notcorrect){
        throw MovieNotFoundException();
     }
     
    try{
    for(int i = 0; i < this->NumOfMovies; i++){
        if(this->Movie[i].getMovieCode() == code){
            Movie[i].rentMovie(renter);
            break;
        }
    }
    }
    catch(RenterLimitException){
        cout << "There are no avaliable copies." << endl;
    }
    catch(DuplicateMovieException){
        cout << "That renter ID already exist." << endl;
    }
    catch(InvalidRenterIDException){
        cout << "Invalid Renter ID." << endl;
    }
    catch(EmptyRenterNameException){
        cout << "The first and/or last name for the renter is empty." << endl;
    }
}

// removes a renter from an already existing movie
void MovieManager::returnRental(int ID, string code){
    bool notcorrect = true;
    for(int i = 0; i < this->NumOfMovies;i++){
       if(Movie[i].getMovieCode() == code){
           notcorrect = false;
       }
    }
    if(notcorrect){
       throw MovieNotFoundException();
    }
    
    try{
    for(int i = 0; i < this->NumOfMovies; i++){
        if(this->Movie[i].getMovieCode() == code){
            Movie[i].returnRental(ID);
            break;
        }
    }
    }
    catch(EmptyRenterListException){
        cout << "No copies currently being rented." << endl;
    }
    catch(RenterNotFoundException){
        cout << "Renter not found." << endl;
    }
    catch(InvalidRenterIDException){
        cout << "Invalid Renter ID." << endl;
    }
}

// prints information for all movies and their renters
void MovieManager::printInventory(){
    Renter copy[10];
    for(int i = 0; i < this->NumOfMovies;i++){
        cout << Movie[i];
    }
}
