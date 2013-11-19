// Header file for componentn one art-related classes

#include <iostream>
#include <string>

using namespace std;

#ifndef ART_H
#define ART_H

// class representing a piece of artwork
class Art {
private:
	// member variables
	string name, artist, description;

public:
	// default constructor
	Art();
	// overload constructor name, artist, description
	Art(string, string, string);
	// destructor
	~Art();

	// accessors
	string getName() const;
	string getArtist() const;
	string getDescription() const;

	// mutators
	void setName(string);
	void setArtist(string);
	void setDescription(string);

	// returns string of all variables
	string prettyPrint();
};

// class representing a list of art objects
struct node {
	Art artwork;
	node *next;
};

class ArtList {
private:
	node *head;
	node *tail;
public:
	// default constructor
	ArtList();
	// destructor
	~ArtList();

	// accessors
		// returns a string of all artworks in the artlist
		string printList();
		// returns true if artlist is empty
		bool isEmpty();

	// mutators
		// inserts a piece of art into the artlist
		void insert(Art);
		// removes one item from the artlist
		void remove();
		// removes all items from the artlist
		void removeAll();	
};

// class representing a collection of artwork
class ArtCollection {
private:
	string name, description;
	ArtList artworks;

public:
	// default constructor
	ArtCollection();
	// overload constructor name and description
	ArtCollection(string, string);
	// destructor
	~ArtCollection();

	// accessors
		string getName() const;
		string getDescription() const;
		// returns string of art collection
		string prettyPrint();

	// mutators
		void setName(string);
		void setDescription(string);
		// adds a piece of art to the artlist
		void addArt(Art);
		// removes a piece of art from the artlist
		void removeArtPiece();
		// removes all artwork from the collection
		void removeAllArt();
};

#endif