#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <string>

using namespace std;

class Film {
private:
    string title;
    int year;
    string country;
    static int filmCount; // Статичне поле
public:
    Film(string t, int y, string с);
    Film();
    Film(const Film& other); // Конструктор копіювання
    Film(Film&& other) noexcept; // Конструктор переміщення
    //~Film();

    int getYear() const;
    void displayInfo() const;
    void setTitle(string t); //метод зміни назви 
    void setYear(const int& y); //метод зміни року 
    static int getFilmCount(); // Статичний метод 

    // Перевантаження унарного оператора ++
    Film& operator++();


    // Перевантаження бінарного оператора +
    Film operator+(const Film& other) const;

    // Перевантаження оператора виводу <<
    friend ostream& operator<<(ostream& os, const Film& film);

    // Перевантаження оператора введення >>
    friend istream& operator>>(istream& is, Film& film);

};

#endif
