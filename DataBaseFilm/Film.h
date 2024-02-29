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
    static int filmCount; // �������� ����
public:
    Film(string t, int y, string �);
    Film();
    Film(const Film& other); // ����������� ���������
    Film(Film&& other) noexcept; // ����������� ����������
    //~Film();

    int getYear() const;
    void displayInfo() const;
    void setTitle(string t); //����� ���� ����� 
    void setYear(const int& y); //����� ���� ���� 
    static int getFilmCount(); // ��������� ����� 

    // �������������� �������� ��������� ++
    Film& operator++();


    // �������������� �������� ��������� +
    Film operator+(const Film& other) const;

    // �������������� ��������� ������ <<
    friend ostream& operator<<(ostream& os, const Film& film);

    // �������������� ��������� �������� >>
    friend istream& operator>>(istream& is, Film& film);

};

#endif
