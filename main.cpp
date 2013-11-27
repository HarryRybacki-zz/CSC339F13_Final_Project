/*
Author: Harry Rybacki

CSC339 - Fall 2013

This program mimics musem software and is broken down into three components:

1. Create two Art Collections consisting of lists of works. Add, delete, and display these collections.

2. Soon.

3. Soon.
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <list>

#include "art.h"
#include "patron.h"
#include "employee.h"

using namespace std;

int main() {
    
    // employee class construction test
    string john = "John";
    float money = 10.0;
    //Employee tim(john, money);
    
    // curator class construction test
    char sp = 'c';
    int exper = 1;
    Curator jim(john, money, sp, exper);

    // curator accesor method tests
    cout << "Initial curator:" << endl;
    jim.print(); cout << endl;
    
    // curator mutator method tests
    sp = 't';
    jim.setSpeciality(sp);
    exper = 2;
    jim.setExperience(exper);
    int hours = 10;
    jim.addHours(hours);
    cout << "After modifications:" << endl;
    jim.print(); cout << endl;
    
    // docent class construction test
    john = "James";
    money = 20.0;
    char shift = 'm';
    Docent james(john, money, shift);
    
    // docent access method tests
    cout << "Initial docent:" << endl;
    james.print(); cout << endl ;
    cout << james.getShift() << endl;
    james.setShift('p');
    cout << james.getShift() << endl;
    
    // seniordocent constructor test
    john = "Timmy";
    int vacation = 145;
    SeniorDocent tim(john, money, shift, vacation);
    
    // seniordocent accessor method tests
    cout << "Initial Senior Docent:" << endl;
    tim.print(); cout << endl;
    
    // senior docent mutator method tests
    tim.useVacation(100);
    tim.addHours(100);
    
    cout << "Final Senior Docent:" << endl;
    tim.print(); cout << endl;
    
/*
    
	// MARK BEGINNING OF COMPONENT TWO
	cout << endl << endl << "#####BEGIN COMPONENT ONE:#####" << endl << endl;

	// start collection one
	ArtCollection collection1;
	collection1.setName("Roman Stuff");
	collection1.setDescription("This is an awesome collection of Roman-esque things");

	// create artwork1 with overloaded constructor
	Art artwork1(
		"Statue of Dude", 
		"Ramon Roman", 
		"A statue of naked man"
		);

	// create artwork1 with default constructor and manually set fields
	Art artwork2;
	artwork2.setName("Bloody Spear");
	artwork2.setArtist("Unknown");
	artwork2.setDescription("A bloody spear");

	// insert artworks into collection1
	collection1.addArt(artwork1);
	collection1.addArt(artwork2);

	// display contents of collection1
	cout << "Collection One (initially):" << endl << collection1.prettyPrint() << endl;

	// remove a piece of art from collection1 and reprint
	collection1.removeArtPiece();
	cout << "Collection One (removing one piece):" << endl << collection1.prettyPrint() << endl;

	// remove all pieces of art from collection1 and reprint
	collection1.removeAllArt();
	cout << "Collection One (removing everything):" << endl << collection1.prettyPrint() << endl;

	// start collection two
	ArtCollection collection2(
		"Modern Art",
		"A bizarre assortment of art"
		);
	cout << endl << collection2.prettyPrint() << endl << endl;

	Art artwork3(
		"Paint", 
		"J. Clai", 
		"paint in a can (opened)"
		);

	Art artwork4(
		"Void", 
		"Jean-Marie Pierre", 
		"A mesmerizing view into the eternal"
		);

	// insert artworks into collection1
	collection2.addArt(artwork3);
	collection2.addArt(artwork4);

	// display contents of collection2
	cout << "Collection Two (initially):" << endl << collection2.prettyPrint() << endl;

	// remove a piece of art from collection2 and reprint
	collection2.removeArtPiece();
	cout << "Collection Two (removing one piece):" << endl << collection2.prettyPrint() << endl;

	// remove all pieces of art from collection2 and reprint
	collection2.removeAllArt();
	cout << "Collection Two (removing everything):" << endl << collection2.prettyPrint() << endl;

	// MARK END OF COMPONENT ONE	

	// MARK BEGINNING OF COMPONENT TWO
	cout << endl << endl << "#####BEGIN COMPONENT TWO:#####" << endl;

	// Create our Patros vector
	Patrons patrons;

*/
	/*
	Text file in which fields are separated by tabs “\t” and patrons by “\n”. 
	For example, the first patron (the fields are all in the following order: id, name) could be 1234, "Timmy"
	*/
/*
	// Create temp vars and open patrons file
	int id;
	string line, name;
	cout << endl << "Reading file \"patrons.txt\"" << endl << endl;
	ifstream infile("patrons.txt");

	// Read in patrons and add them to patrons vector
	while(getline(infile, line)) {
		// read data
		stringstream linestream(line);
		linestream >> id;
		linestream >> name;
		// create patron and insert into patrons vector
		Patron patron;
		patron.setId(id);
		patron.setName(name);
		patrons.push_back(patron);
		cout << "Adding id: " << id << ", name: " << name << endl;
	}
	// Close file
	infile.close();
*/
	/*
	Text file in which fields are separated by tabs “\t” and donations by “\n”. 
	For example, the first patron (the fields are all in the following order: id, donation) could be 1234, 1000
	*/

/*	// Create temp vars for data and open donations file
	int donation, patron_index;
	cout << endl << "Reading file \"donations.txt\"" << endl << endl;
	ifstream infile2("donations.txt");

	// Read in patrons and add them to patrons vector
	while(getline(infile2, line)) {
		// read data
		stringstream linestream(line);
		linestream >> id;
		linestream >> donation;
		// locate patron and update donations
		patron_index = patrons.findPatron(id, patrons);
		patrons[patron_index].updateDonations(donation);
		cout << "Adding id: " << id << ", donated: " << donation << endl;
	}
	// Close file
	infile2.close();

	// Demonstrate before/after sorting with overloaded operators
	cout << endl << "Before sorting:" << endl << patrons << endl;
	std::sort(patrons.begin(), patrons.end());
	cout << "After sorting:" << endl << patrons << endl;

	// MARK END OF COMPONENT ONE0
*/
	return 0;
}