#pragma once
#ifndef DOMAIN_H
#define DOMAIN_H
#include <iostream>
#include <string>
using namespace std;
class carte {
private:
	std::string title;
	std::string autor;
	std::string genre;
	int year;
public:
	carte(const string t, const string a, const string g, const int i) :title{ t }, autor{ a }, genre{ g }, year{ i }{}
	carte(const carte&c2) {
		title = c2.title;autor = c2.autor;genre = c2.genre;year = c2.year;
		cout << "copy!!!";
	}

	carte() = default;
	string get_title()const {
		return title;
	}
	string get_autor()const {
		return autor;
	}
	string get_genre()const {
		return genre;
	}
	int get_year() const {
		return year;
	}

};
void interschimbare(carte &c1, carte &c2);
bool compare_title(const carte &c1, const carte &c2);
bool compare_autor(const carte &c1, const carte &c2);
bool compare_genre(const carte&c1, const carte&c2);
bool compare_year(const carte&c1, const carte&c2);
inline bool operator==(const carte& lhs, const carte& rhs)
{
	return ((lhs.get_autor() == rhs.get_autor()) && (lhs.get_genre() == rhs.get_genre()) && (lhs.get_title() == rhs.get_title()) && (lhs.get_year() == rhs.get_year()));
}
#endif // !DOMAIN_H


