#include "Domain.h"
#include "Repository.h"
#include "Validator.h"
#include "Services.h"
#include <functional>
#include <algorithm>
#include "Lista.h"
#include <iostream>
using namespace std;
void Service::Add(const string& autor, const string& genre, const string& title, const int& year) {
	carte c{ autor,title,genre,year };
	valid.validate(c);
	all.store_repo(c);
}
lista<carte> Service::generalsort(comp comp) {
	lista<carte>copie{ all.getAll() };
	vector<carte> ve;
	iterator_lista<carte> l = copie.begin();
	while (l.valid()) {
		ve.push_back(l.element());
		l.next();
	}
	sort(ve.begin(), ve.end(), comp);

	iterator_lista<carte> l2 = all.getAll().begin();

	all.getAll().~lista();
	for (int i = 0;i < ve.size();i++)
	{
		all.getAll().add(ve[i]);
	}
	return all.getAll();
}
lista<carte> Service::sortByTitle() {
	return generalsort(compare_title);
}
lista<carte> Service::sortByGenre() {
	return generalsort(compare_genre);
}

void Service::modify_service(const string& autor, const string& genre, const string& title, const int& year, const string& autor2, const string& genre2, const string& title2, const int& year2) {
	carte c1(autor, genre, title, year);
	carte c2(autor2, genre2, title2, year2);
	valid.validate(c1);
	valid.validate(c2);
	all.modify_repo(c1, c2);
}
void Service::delete_service(const string& autor, const string& genre, const string& title, const int& year) {
	carte c1(autor, genre, title, year);
	valid.validate(c1);
	all.delete_repo(c1);
}

lista<carte> Service::filtreaza(function<bool(const carte&)> fct) const {
	lista<carte> rez;
	iterator_lista<carte> l = all.getAll().begin();
	while (l.valid()) {
		if (fct(l.element()))
		{
			rez.add(l.element());
		}
		l.next();
	}
	return rez;
}
lista<carte> Service::filtrareAn(int an) const {
	return filtreaza([an](const carte& p)noexcept {
		return p.get_year() < an;
	});
}

lista<carte> Service::filtrareAn2(int AnMin, int AnMax)const {

	return filtreaza([=](const carte& p) noexcept {
		return p.get_year() >= AnMin && p.get_year() <= AnMax;
	});
}

lista<carte> Service::filtrareTitlu(string titlu) const {
	return filtreaza([titlu](const carte& p)noexcept {
		return p.get_title() == titlu;
	});
}