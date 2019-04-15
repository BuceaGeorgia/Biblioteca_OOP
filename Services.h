#pragma once
#ifndef SERVICES_H
#define SERVICES_H
#include "Repository.h"
#include "Domain.h"
#include "Validator.h"
#include <vector>
#include <string>
#include "Validator.h"
#include <functional>
#include "Lista.h"

using namespace std;
typedef bool(*comp)(const carte&, const carte&);
class Service {
private:
	repository&all;
	CarteValidator &valid;
	lista<carte> generalsort(comp comp);
	lista<carte> filtreaza(function<bool(const carte&)> fct) const;
public:
	//friend class iterator_lista<carte>;
	Service(repository&r, CarteValidator &val) noexcept :all{ r }, valid{ val }{
	}
	Service(repository&ot) = delete;

	const lista<carte>& getAll() const noexcept {
		return all.getAll();
	}
	void Add(const string& autor, const string& genre, const string& title, const int& year);
	void modify_service(const string& autor, const string& genre, const string& title, const int& year, const string& autor2, const string& genre2, const string& title2, const int& year2);
	void delete_service(const string& autor, const string& genre, const string& title, const int& year);
	lista<carte> sortByTitle();
	lista<carte> sortByGenre();
	lista<carte> filtrareAn(int an)const;
	lista<carte> filtrareAn2(int AnMin, int AnMax)const;
	lista<carte> filtrareTitlu(string titlu) const;
};



#endif // !SERVICES_H
