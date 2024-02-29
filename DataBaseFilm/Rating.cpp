#include "Rating.h"
using namespace std;

Rating::Rating(const Rating& other) : score(other.score) {}

Rating::Rating(double s) : score(s) {}

Rating::Rating() : Rating(0.0) {}

Rating::Rating(Rating&& other) noexcept : score(move(other.score)) {}

//Rating::~Rating() {
//    cout << "������� �������: " << score << endl;
//}

double Rating::getScore() const {
    return score;
}

void Rating::displayInfo() const {
    cout << "�������: " << score << endl;
}