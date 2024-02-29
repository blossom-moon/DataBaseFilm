#include "Genre.h"
using namespace std;

Genre::Genre(const Genre& other) : name(other.name) {}

Genre::Genre(string n) : name(n) {}

Genre::Genre() : Genre("Невідомо") {}

Genre::Genre(Genre&& other) noexcept : name(move(other.name)) {}

//Genre::~Genre() {
//    cout << "Жанр знищено: " << name << endl;
//}

string Genre::getName() const {
    return name;
}

void Genre::displayInfo() const {
    cout << "Жанр: " << name << endl;
}