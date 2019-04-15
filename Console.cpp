#include "Console.h"
#include "Domain.h"
#include "Repository.h"
#include "Validator.h"
#include <iostream>
#include <string>
using namespace std;

void ConsoleUI::tipareste(const lista<carte>& carti) {
	cout << "----------------------------------\n";
	cout << "Cartile:\n";
	cout << "Carte	Autor	Genul	An\n";
	iterator_lista<carte>it = carti.begin();;
	while (it.valid()) {
		cout << it.element().get_title()<< "\t" << it.element().get_autor() << "\t" << it.element().get_genre() << "\t" << it.element().get_year() << ";\n";
		it.next();
		}
	cout << "----------------------------------\n" << endl;
}

void ConsoleUI::AdaugaUI() {
	string t, a, g;
	int y;
	cout << "Dati titlul: ";
	cin >> t;
	cout << "Dati autor: ";
	cin >> a;
	cout << "Dati gen: ";
	cin >> g;
	cout << "Dati anul: ";
	cin >> y;
	srv.Add(t, a, g, y);
	cout << "\nCarte adaugata cu succes!!! \n";
}

void ConsoleUI::Sterge() {
	string t1,t2,t3;
	int an;
	cout << "Dati autor: ";
	cin >> t1;
	cout << "Dati gen: ";
	cin >> t2;
	cout << "Dati titlul: ";
	cin >> t3;
	cout << "Dati an: ";
	cin >> an;
	srv.delete_service(t1,t2,t3,an);
	cout << "\nCarte stearsa cu succes!!!\n";
}

void ConsoleUI::Filtrare() {
	cout << "Dati titlu: ";
	string t;
	cin >> t;
	tipareste(srv.filtrareTitlu(t));
}





void ConsoleUI::start() {
	while (true) {
		cout << "Meniu: \n";
		cout << "1-Adauga\n2-Tipareste toate\n3-sorteaza dupa titlu\n4-sorteaza dupa gen\n5-filtreaza dupa titlu\n6-filtreaza dupa an\n7.Sterge\n0-iesire\n Dati comanda: ";
		int cmd;
		cin >> cmd;
		try {
			switch (cmd) {
			case 1:
				AdaugaUI();
				break;
			case 2:
				tipareste(srv.getAll());
				break;
			case 3:
				tipareste(srv.sortByTitle());
				break;
			case 4:
				tipareste(srv.sortByGenre());
				break;
			case 5:
				Filtrare();
				break;
			case 6:
				cout << "Dati an: ";
				int an;
				cin >> an;
				tipareste(srv.filtrareAn(an));
				break;
			case 7:
				Sterge();
				break;
			case 0:
				return;
			default:
				cout << "Comanda invalida!!!\n";
			}
		}
		catch (repoException&ex) {
			cout << ex << '\n';
		}
		catch (const ValidateException& ex) {
			cout << ex << '\n';
		}
	}
}
