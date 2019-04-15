#pragma once
#include "Domain.h"
#include "Services.h"
#include "Repository.h"
class ConsoleUI {
	Service& srv;

	/*
		Citeste datele de la tastatura si le salveaza
		Se arunca exceptie daca datele nu sunt valide
	*/
	void AdaugaUI();

	/*
		Sterge carti
	*/
	void Sterge();

	/*
		Filtrare dupa titlu
	*/
	void Filtrare();

	/*
		Cauta carte
	*/
	void Find();

	/*
		Tipareste lista cartilor pe consola
	*/
	void tipareste(const lista<carte>& c);
public:
	ConsoleUI(Service& srv) noexcept : srv{ srv } {}
	//Nu se permite copierea
	ConsoleUI(const ConsoleUI& ot) = delete;

	void start();
};