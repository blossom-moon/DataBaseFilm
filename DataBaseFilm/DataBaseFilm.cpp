#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "Film.h"
#include "Genre.h"
#include "Rating.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Film movie("Всесвітня війна Z", 2013, "США");
    Genre genre("Бойовик");
    Rating rating(7.0);

    movie.displayInfo();
    genre.displayInfo();
    rating.displayInfo();

    cout << endl;

    //(1)копіювання
    Film movieCopy = movie;
    Genre genreCopy = genre;
    Rating ratingCopy = rating;

    movieCopy.displayInfo();

    cout << endl;

    //(2)переміщення
    Genre genreMoved = move(genre);

    genreMoved.displayInfo();
    movie.displayInfo();
    genre.displayInfo();
    rating.displayInfo();

    cout << endl;

    //(3)this
    // Створюємо об'єкт 
    Film movie1("Рембо", 1982, "США");
    cout << "Інформація про фільм перед зміною назви:" << endl;
    movie1.displayInfo();
    //метод setTitle, вказівник this
    movie1.setTitle("Зоряні війни: Епізод IV - Нова надія");
    
    //(4) const
    movie.setYear(2005);

    cout << "\nІнформація про фільм після зміни назви:" << endl;
    movie.displayInfo();

    cout << endl;
    //(5)
    cout << "Кількість фільмів: " << Film::getFilmCount() << endl;
    // ще один об'єкт 
    Film movie2("Втеча з Шоушенка", 1994, "США");
    cout << "Кількість фільмів після створення третього фільму: " << Film::getFilmCount() << endl;

    cout << endl;

    //(6)
    cout << "Інформація про перший фільм:" << endl;
    movie1.displayInfo();

    cout << "\nІнформація про другий фільм:" << endl;
    movie2.displayInfo();

    //унарний оператор ++
    ++movie1;

    cout << "\nРік випуску першого фільму після використання оператора ++: " << movie1.getYear() << endl;

    //бінарний оператор
    Film combinedMovie = movie1 + movie2;
    //cout << "\nІнформація про комбінований фільм:" << endl;
    combinedMovie.displayInfo();

    cout << endl;

    //(7)
    Film movie3;
    // Введення даних >>
    cout << "Введіть дані про фільм:" << endl;
    cin >> movie3;
    // Виведення даних <<
    cout << "\nІнформація про фільм:" << endl;
    cout << movie3 << endl;


    return 0;
}
