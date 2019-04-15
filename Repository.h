#pragma once
#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "Domain.h"
#include <vector>
#include <string>
#include "Lista.h"
using namespace std;

class repository {
private:
	lista<carte> repo;
	bool exist(const carte&c);
public:
	repository() = default;
	repository(const carte&ot) = delete;
	/*
	* stores a book to the library, trows exception if book
	*already in the library
	*/
	void store_repo(const carte &c);
	/*
	*deletes an element from the library, throws exception if
	*element not already in library
	*/
	void delete_repo(const carte &c);

	/*
	*finds an element in the list
	*throws exception if element not in list
	*/

	carte& find_repo(const string &autor, const string &genre, const string& title, const int& year);
	lista<carte>& getAll() noexcept;
	/*modifys a book in the library
	throws exception if book is not in libary
	*/
	void modify_repo(carte&c, carte&c2);
	/*deletes a book in the library
	throws exception if book is not in libary
	*/


};

class repoException {
	string msg;
public:
	repoException(string m) :msg{ m } {}
	friend ostream& operator<<(ostream & out, const repoException& ex);
};
ostream& operator<<(ostream& out, const repoException& ex);
#endif // !REPOSITORY_H

