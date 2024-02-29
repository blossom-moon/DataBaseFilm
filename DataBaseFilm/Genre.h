#ifndef GENRE_H
#define GENRE_H

#include <iostream>
#include <string>

using namespace std;

class Genre {
private:
    string name;

public:
    Genre(string n);
    Genre();
    Genre(const Genre& other); 
    Genre(Genre&& other) noexcept; 
    //~Genre();

    string getName() const;
    void displayInfo() const;
};

#endif


