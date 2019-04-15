#include "Validator.h"
#include "Domain.h"
void CarteValidator::validate(const carte& p) {
	vector<string> msgs;
	if (p.get_year() < 0) msgs.push_back("An negativ!!!");
	if (p.get_title().size() == 0) msgs.push_back("titlu vid!!!");
	if (p.get_genre().size() == 0) msgs.push_back("gen vid!!!");
	if (p.get_autor().size() == 0) msgs.push_back("Autor vid!!!");
	if (msgs.size() > 0) {
		throw ValidateException(msgs);
	}
}
ostream& operator<<(ostream& out, const ValidateException& ex) {
	for (const auto& msg : ex.msgs) {
		out << msg << " ";
	}
	return out;
}