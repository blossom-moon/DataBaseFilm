#include "Film.h"

using namespace std;

int Film::filmCount = 0;
//збільшення лічильників
Film::Film(const Film& other) : title(other.title), year(other.year), country(other.country) {
    filmCount++;
}

Film::Film(string t, int y, string с) : title(t), year(y), country(с) {
    filmCount++; 
}

Film::Film() : Film("Невідомо", 0, "Невідомо") {}

Film::Film(Film&& other) noexcept
    : title(move(other.title)), year(move(other.year)), country(move(other.country)) {
    filmCount++;
}

//Film::~Film() {
//    cout << "Фільм знищено: " << title << endl;
//    filmCount--; // Зменшуємо лічильник при знищенні об'єкта
//}

int Film::getYear() const {
    return year;
}

void Film::displayInfo() const {
    cout << "Назва: " << title << ", Рік: " << year << ", Країна: " << country << endl;
}

void Film::setTitle(string t) {
    //this (для доступу до поточного об'єкта)
    this->title = t;
}

void Film::setYear(const int& y) {
    year = y;
}

int Film::getFilmCount() {
    return filmCount;
}

// Реалізація перевантаження унарного оператора ++
Film& Film::operator++() {
    ++year;
    return *this;
}

// Реалізація перевантаження бінарного оператора +
Film Film::operator+(const Film& other) const {
    return Film(title + " і " + other.title, year + other.year, country + " і " + other.country);
}


// перевантаження оператора виводу <<
ostream& operator<<(ostream& os, const Film& film) {
    os << "Назва: " << film.title << ", Рік: " << film.year << ", Країна: " << film.country;
    return os;
}

//перевантаження оператора введення >>
istream& operator>>(istream& is, Film& film) {
    cout << "Введіть назву: ";
    getline(is, film.title);

    cout << "Введіть рік: ";
    is >> film.year;
    cin.ignore(); // Очищення буфера вводу

    cout << "Введіть країну: ";
    getline(is, film.country);

    return is;
}