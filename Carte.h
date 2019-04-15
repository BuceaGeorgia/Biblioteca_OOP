#pragma once
#include <string>
#include <iostream>

//clasa cu obiecte de tip pet, folosita doar pentru teste
class Pet
{
public:
	
	Pet() = default;
	Pet(std::string t, std::string s, double p) :type{ t }, species{ s }, price{ p } {
	}
	//constructor de copiere
	Pet(const Pet& ot) :type{ ot.type }, species{ ot.species }, price{ ot.price } {
		std::cout << "copy\n";
	}
	double getPrice() const noexcept {
		return price;
	}
	std::string getType() const {
		return type;
	}
private:
	
	std::string type;
	std::string species;
	double price = -1.0;

};


