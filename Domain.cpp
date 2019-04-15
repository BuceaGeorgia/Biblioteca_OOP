#include "Domain.h"
#include <string.h>
#include <vector>
using namespace std;
/*void interschimbare(carte & c1, carte & c2)
{
	carte c3{ c1 };
	c1 = c2;
	c2 = c3;
}*/
bool compare_title(const carte &c1, const carte &c2) {
	return c1.get_title() < c2.get_title();
}
/*bool compare_autor(const carte &c1, const carte &c2) {
	if (c1.get_autor() <= c2.get_autor()) {
		return true;
	}
	return false;
}*/
bool compare_genre(const carte &c1, const carte &c2) {
	if (c1.get_genre() <= c2.get_genre()) {
		return true;
	}
	return false;
}

/*bool compare_year(const carte& c1, const carte& c2) {
	if (c1.get_year() <= c2.get_year()) {
		return true;
	}
	return false;
}*/
