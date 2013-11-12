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

#include "art.h"

using namespace std;

int main() {
	// compontent one
	cout << "BEGIN COMPONENT ONE:" << endl;

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

	return 0;
}