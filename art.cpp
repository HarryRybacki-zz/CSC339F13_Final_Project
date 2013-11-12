// function definitions

#include "art.h"

// Art class function definitions
Art::Art() {
	// kind of redundant -- C++ strings set to null upon instaniation
	name = "";
	artist = "";
	description = "";
}
Art::Art(string _name, string _artist, string _description) {
	name = _name;
	artist = _artist;
	description = _description;
}
Art::~Art() {

}
string Art::getName() const {
	return name;
}
string Art::getArtist() const {
	return artist;
}
string Art::getDescription() const {
	return description;
}
void Art::setName(string _name) {
	name = _name;
}
void Art::setArtist(string _artist) {
	artist = _artist;
}
void Art::setDescription(string _description) {
	description = _description;
}
string Art::prettyPrint() {
	string pretty = getName() + ", " + getArtist() + ", " + getDescription();
	return pretty;
}

// ArtList function definitions
ArtList::ArtList() {
	head = NULL;
	tail = NULL;
}
ArtList::~ArtList() {
}
bool ArtList::isEmpty() {
	if(head == NULL)
		return true;
	else
		return false;
}
void ArtList::insert(Art _artwork) {
	if(isEmpty()) {
		node *temp = new node;
		temp->artwork = _artwork;
		temp->next = NULL;
		*&head = temp;
		*&tail = temp;
	}
	else {
		node *temp = new node;
		temp->artwork = _artwork;
		temp->next = NULL;
		tail->next = temp;
		*&tail = temp;
	}
}
void ArtList::remove() {
	if(isEmpty()) {
		cout << "This list is already empty." << endl;
	}
	else {
		node *temp = head;
		head = head->next;
		delete temp;
	}
}
void ArtList::removeAll() {
	if(isEmpty()) {
		cout << "This list is already empty." << endl;
	}
	else {
		node *temp = head;
		while(temp != NULL) {
			temp = temp->next;
			delete head;
			head = temp;
		}
	}
}
string ArtList::printList() {
	if (isEmpty()) {
		return "";
	}
	else {
		string pretty;
		node *current = head;
		while (current != NULL) {
			pretty += current->artwork.prettyPrint();
			pretty += "\n";
			current = current->next;
		}
		return pretty;
	}
}

// ArtCollection function definitions
ArtCollection::ArtCollection() {
	name = "";
	description = "";
	ArtList artworks;
	}
ArtCollection::ArtCollection(string _name, string _description) {
	name = _name;
	description = _description;
}
ArtCollection::~ArtCollection() {

}
string ArtCollection::getName() const {
	return name;
}
string ArtCollection::getDescription() const {
	return description;
}
void ArtCollection::setName(string _name) {
	name = _name;
}
void ArtCollection::setDescription(string _description) {
	description = _description;
}
string ArtCollection::prettyPrint() {
	string pretty = getName() + ", " + getDescription() + "\n";
	if(artworks.isEmpty() != true) {
		pretty += artworks.printList();
	}
	else {
		pretty += "This collection currently has no art.";
	}
	return pretty;
}
void ArtCollection::addArt(Art artwork) {
	artworks.insert(artwork);
}
void ArtCollection::removeArtPiece() {
	if(!artworks.isEmpty())
		artworks.remove();
}
void ArtCollection::removeAllArt() {
	if(!artworks.isEmpty()) {
		artworks.removeAll();
	}
}