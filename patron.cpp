// Header file for component two patron-related classes
#include "patron.h"

// Begin Patron class functions declarations
Patron::Patron() {
	id = 0;
	name = "";
	donations = 0;
};
Patron::~Patron() {
}
// set default total donation amount
int Patron::totalDonations=0;

void Patron::setName(string _name) {
	name = _name;
}
void Patron::setId(int _id) {
	id = _id;
}
void Patron::updateDonations(int amount) {
	donations += amount;
	totalDonations += amount;
}
int Patron::getId() {
	return id;
}
int Patron::getDonations() {
	return donations;
}
int Patron::getTotalDonations() {
	return totalDonations;
}
string Patron::getName() {
	return name;
}
// Overloading the equality operator for searching
bool operator==(const Patron &pt1, const Patron &pt2) {
	return pt1.id == pt2.id;
}
// Overloading the less than operator for sorting
bool operator<(const Patron &pt1, const Patron &pt2) {
	return pt1.donations < pt2.donations;
}
// End Patron Class function declarations

// Begin Patrons class function declarations
int Patrons::findPatron(int id, Patrons& pt) {
	int i;
	for (i = 0; i < pt.size(); i++) {
		if (pt[i].getId() == id)
			return i;
	}
	return -1;
}
// Overloading the insertion operator for the Patron class
ostream& operator<<(ostream& os, Patrons& pt)
{
	int i;
	for(i = 0; i < pt.size(); i++) {
		os << pt[i].getName();
		os << " donated $";
		os << pt[i].getDonations();
		os << "\n";
	}
    return os;
}
// End Patrons Class function declarations