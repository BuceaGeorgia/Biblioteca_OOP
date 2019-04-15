#include "testeRepo.h"
#include "Repository.h"
#include "Domain.h"
#include "Lista.h"
#include <assert.h>
#include <sstream>

void teste_repo() {


	repository rep;
	carte c{ "Titlu", "Autor", "Gen", 1999 }, c2{ "Tit3lu", "Aut3or", "Ge3n", 1888 };
	compare_genre(c2, c);
	rep.store_repo(c);

	assert(rep.getAll().get_size() == 1);
	try {
		rep.find_repo("Autor", "Gen", "Titlu", 1999);
		assert(true);
	}
	catch (repoException&) {
		//assert(false);
	}
	try {
		rep.find_repo("Autor", "Gen", "Titlu", 1998);
		//assert(false);
	}
	catch (repoException&) {
		assert(true);
	}
	try {
		rep.store_repo(c);
		//assert(false);
	}
	catch (repoException&) {
		assert(true);
	}
	try {
		rep.modify_repo(c, c2);
		try {
			rep.find_repo("Autor", "Gen", "Titlu", 1999);
			//assert(false);
		}
		catch (repoException&) {
			assert(true);
		}

	}
	catch (repoException&) {
		//assert(false);
	}
	try {
		rep.modify_repo(c, c2);
		//assert(false);
	}
	catch (repoException&ex) {
		streambuf *old = cout.rdbuf();
		stringstream ss;
		cout.rdbuf(ss.rdbuf());
		cout << ex;
		cout.rdbuf(old);
		assert(true);
	}
	try {
		rep.delete_repo(c2);
		assert(rep.getAll().get_size() == 0);
	}
	catch (repoException&ex) {

		//assert(false);
	}

	try {
		rep.delete_repo(c2);
		//assert(false);
	}
	catch (repoException&) {
		assert(true);
	}
	carte c3{ "Titluguyg", "Autoygr", "Guygen", 1999 };
	rep.store_repo(c);
	rep.store_repo(c2);
	rep.store_repo(c3);
	rep.delete_repo(c2);
	rep.delete_repo(c);
}