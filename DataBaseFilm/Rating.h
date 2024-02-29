#ifndef RATING_H
#define RATING_H

#include <iostream>

class Rating {
private:
    double score;

public:
    Rating(double s);
    Rating();
    Rating(const Rating& other); 
    Rating(Rating&& other) noexcept; 
    //~Rating();

    double getScore() const;
    void displayInfo() const;
};

#endif
