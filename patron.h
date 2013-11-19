#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef PATRON_H
#define PATRON_H



class Patron {
private:
	int id, donations;
	string name;

public:
	static int totalDonations;

	Patron();
	~Patron();

	void setId(int);
	void setName(string);
	void updateDonations(int);

	int getId();
	int getDonations();
	int getTotalDonations();
	string getName();
	// overload equaltiy operator for searching
	bool friend operator==(const Patron& pt1, const Patron& pt2);
	// overload less than operator for sorting
	bool friend operator<(const Patron& pt1, const Patron& pt2);
};

class Patrons : public vector<Patron> {
	// overload the insertion operator for printing
	friend ostream& operator<<(ostream &os, Patrons &pt);
public:
	int findPatron(int, Patrons &pt);
};

#endif