#include "testService.h"
#include "Services.h"
#include "Repository.h"
#include <assert.h>
#include "Domain.h"

#include "Lista.h"
#include <vector>
#include "Validator.h"
#include<sstream>
void teste_service() {
	repository rep;
	CarteValidator val;
	Service se(rep, val);
	se.Add("la", "la2", "la3", 1999);

	//assert(se.getAll().get_size()== 1);

	repository rep2;
	CarteValidator val2;
	Service ctr2{ rep2,val2 };
	ctr2.Add("z", "z", "z", 6);
	ctr2.Add("b", "a", "b", 60);
	ctr2.Add("c", "l", "a", 600);
	
	try {
		ctr2.Add("", "", "", -1);
		assert(false);
	}
	catch (ValidateException&ex) {
		streambuf *old = cout.rdbuf();
		stringstream ss;
		cout.rdbuf(ss.rdbuf());
		std::cout << ex << '\n';
		cout.rdbuf(old);
		assert(true);
	}
	carte firstP = ctr2.sortByTitle().begin().element();
	assert(firstP.get_title() == "b");
	firstP = ctr2.sortByGenre().begin().element();
	assert(firstP.get_genre() == "a");
	ctr2.modify_service("z", "z", "z", 6, "b", "a", "b", 60);
	firstP = ctr2.getAll().begin().element();
	assert(firstP.get_title() == "b");
	ctr2.delete_service("b", "a", "b", 60);
	assert(ctr2.getAll().size() == 2);
}
void testFiltrare() {
	repository rep2;
	CarteValidator val2;
	Service ctr2{ rep2,val2 };
	ctr2.Add("z", "z", "z", 6);
	ctr2.Add("b", "a", "b", 60);
	ctr2.Add("c", "l", "a", 600);
	assert(ctr2.filtrareAn(60).size() == 1);
	assert(ctr2.filtrareAn2(6, 70).size() == 2);
	assert(ctr2.filtrareTitlu("b").size() == 1);

}