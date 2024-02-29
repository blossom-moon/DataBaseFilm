#include "Film.h"

using namespace std;

int Film::filmCount = 0;
//��������� ���������
Film::Film(const Film& other) : title(other.title), year(other.year), country(other.country) {
    filmCount++;
}

Film::Film(string t, int y, string �) : title(t), year(y), country(�) {
    filmCount++; 
}

Film::Film() : Film("�������", 0, "�������") {}

Film::Film(Film&& other) noexcept
    : title(move(other.title)), year(move(other.year)), country(move(other.country)) {
    filmCount++;
}

//Film::~Film() {
//    cout << "Գ��� �������: " << title << endl;
//    filmCount--; // �������� �������� ��� ������� ��'����
//}

int Film::getYear() const {
    return year;
}

void Film::displayInfo() const {
    cout << "�����: " << title << ", г�: " << year << ", �����: " << country << endl;
}

void Film::setTitle(string t) {
    //this (��� ������� �� ��������� ��'����)
    this->title = t;
}

void Film::setYear(const int& y) {
    year = y;
}

int Film::getFilmCount() {
    return filmCount;
}

// ��������� �������������� �������� ��������� ++
Film& Film::operator++() {
    ++year;
    return *this;
}

// ��������� �������������� �������� ��������� +
Film Film::operator+(const Film& other) const {
    return Film(title + " � " + other.title, year + other.year, country + " � " + other.country);
}


// �������������� ��������� ������ <<
ostream& operator<<(ostream& os, const Film& film) {
    os << "�����: " << film.title << ", г�: " << film.year << ", �����: " << film.country;
    return os;
}

//�������������� ��������� �������� >>
istream& operator>>(istream& is, Film& film) {
    cout << "������ �����: ";
    getline(is, film.title);

    cout << "������ ��: ";
    is >> film.year;
    cin.ignore(); // �������� ������ �����

    cout << "������ �����: ";
    getline(is, film.country);

    return is;
}