#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "lista.h"
#include "Carte.h"
#include <assert.h>
#include <vector>
//#include "Domain.h"
//#include "Repository.h"
//#include "testeRepo.h"
//#include "testService.h"
//#include "Console.h"
using namespace std;
/*
  Functie folosit in teste
  primeste vector prin valoare -> copy constructor
  returneaza prin valoare -> copy constructor sau move constructor
*/
template <typename MyVector>
MyVector testCopyIterate(MyVector v) {
	double totalPrice = 0;
	for (auto el : v) {
		totalPrice += el.getPrice();
	}
	Pet p{ "total","tt",totalPrice };
	v.add(p);
	return v;
}

template <typename MyVector>
void addPets(MyVector& v, int cate) {
	for (int i = 0; i < cate; i++) {
		Pet p{ std::to_string(i) + "_type",std::to_string(i) + "_spec",i + 10.0 };
		v.add(p);
	}
}

/*
Testare constructori / assignment
E template pentru a refolosi la diferite variante de VectorDinamic din proiect
*/
template <typename MyVector>
void testCreateCopyAssign() {
	MyVector v;//default constructor
	MyVector v5{ v };//constructor de copiere
	addPets(v, 100);
	assert(v.size() == 100);
	cout << v.get(50).getType();
	assert(v.get(50).getType() == "50_type");

	MyVector v2{ v };//constructor de copiere
	assert(v2.size() == 100);
	assert(v2.get(50).getType() == "50_type");

	MyVector v3;//default constructor
	v3 = v;//operator=   assignment
	assert(v3.size() == 100);
	assert(v3.get(50).getType() == "50_type");

	auto v4 = testCopyIterate(v3);
	assert(v4.size() == 101);
	cout << v4.get(50).getType();
	assert(v4.get(50).getType() == "50_type");
	v4 = v4;
	v4 = v3;
}

/*
  Test pentru move constructor si move assgnment
*/

template <typename MyVector>
void testMoveConstrAssgnment() {
	std::vector<MyVector> v;
	//adaugam un vector care este o variabila temporara
	//se v-a apela move constructor
	v.push_back(MyVector{});

	//inseram, la fel se apeleaza move costructor de la vectorul nostru
	v.insert(v.begin(), MyVector{});

	assert(v.size() == 2);

	MyVector v2;
	addPets(v2, 50);

	v2 = MyVector{};//move assignment

	assert(v2.size() == 0);

}
template <typename MyVector>
void testAll() {
	testCreateCopyAssign<MyVector>();
	testMoveConstrAssgnment<MyVector>();
}

void Adauga(Service& srv) {
	srv.Add("haha", "eu", "ficti", 2010);
	srv.Add("asa", "el", "comedie", 2019);
	srv.Add("supi", "gigel", "actiune", 1999);
	srv.Add("ghita", "stratan", "drama", 2001);
	srv.Add("haha", "noi", "drama", 2010);
}

int main() {
	testAll<lista<Pet>>();
	teste_repo();
	teste_service();
	testFiltrare();
	repository rep;
	CarteValidator val;
	Service srv{ rep,val};
	Adauga(srv);
	ConsoleUI ui{ srv };
	ui.start();
	_CrtDumpMemoryLeaks();
	return 0;
}