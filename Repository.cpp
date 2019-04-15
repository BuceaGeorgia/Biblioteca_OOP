#include "Repository.h"
#include <vector>
#include <algorithm>
#include "Lista.h"
using namespace std;
bool repository::exist(const carte& c) {
	try {
		find_repo(c.get_autor(), c.get_genre(), c.get_title(), c.get_year());
		return true;
	}
	catch (repoException&) {
		return false;
	}
}


void repository::store_repo(const carte &c) {
	if (exist(c)) {
		throw repoException("Cartea exista deja!!");
	}
	repo.add(c);
}

carte& repository::find_repo(const string &autor, const string &genre, const string& title, const int& year)
{
	iterator_lista<carte> it = repo.begin();
	while (it.valid()) {
		if (it.element().get_autor() == autor && it.element().get_genre() == genre && it.element().get_title() == title && it.element().get_year() == year)
		{
			return it.element();
		}
		it.next();
	}
	throw repoException("Nu exista cartea cu titlul:" + title + "genul" + genre + "din acel an");

}

lista<carte>& repository::getAll()  noexcept {
	return repo;
}

void repository::modify_repo(carte&c, carte&c2) {
	int ok = 0;
	try {
		nod<carte>*elem = repo.gaseste(c);
		elem->el = c2;

	}
	catch (int)
	{

		throw repoException("Nu exista cartea cu titlul:" + c.get_title() + "genul" + c.get_genre() + "din acel an");
	}

}
void repository::delete_repo(const carte &c) {
	try {

		repo.sterge(c);
	}
	catch (int) {
		throw repoException("Nu exista cartea cu titlul:" + c.get_title() + "genul" + c.get_genre() + "din acel an");

	}
}
ostream& operator<<(ostream& out, const repoException& ex) {
	out << ex.msg;
	return out;
}