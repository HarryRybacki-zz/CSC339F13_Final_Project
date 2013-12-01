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
	int component;
    // component demo loop
    do { 
    	cout << "Chose component to demo:" << endl;
    	cout << "(1) - Component One" << endl;
    	cout << "(2) - Component Two" << endl;
    	cout << "(3) - Component Three" << endl;
    	cout << "(4) - Exit" << endl;
    	cin >> component;

    	// component demo menu
    	switch(component) {
    		case 1: { // MARK BEGINNING OF COMPONENT ONE
				cout << endl << "#####BEGIN COMPONENT ONE:#####" << endl << endl;

				list<ArtCollection*> collections;

				// start collection one
				ArtCollection *collection1 = new ArtCollection();
				collection1->setName("Roman Stuff");
				collection1->setDescription("This is an awesome collection of Roman-esque things");
				// add it to list of collections
				collections.push_back(collection1);

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
				collection1->addArt(artwork1);
				collection1->addArt(artwork2);

				// start collection two
				ArtCollection *collection2 = new ArtCollection(
					"Modern Art",
					"A bizarre assortment of art"
					);

				// add it to list of collections
				collections.push_back(collection2);

				// create artwork for collection 2
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
				collection2->addArt(artwork3);
				collection2->addArt(artwork4);

				// demonstrate list manipulation
				cout << "Initial list of collections:" << endl << endl;

				for (list<ArtCollection*>::iterator it = collections.begin(); it != collections.end(); it++)
					cout << (*it)->prettyPrint() << endl;

				collections.pop_front();

				cout << "List of collections after reduction:" <<  endl << endl;

				for (list<ArtCollection*>::iterator it = collections.begin(); it != collections.end(); it++)
					cout << (*it)->prettyPrint() << endl;
    			break;
    		} // MARK END OF COMPONENT ONE

    		case 2: { // MARK BEGINNING OF COMPONENT TWO
    			

				cout << endl << endl << "#####BEGIN COMPONENT TWO:#####" << endl;

				// Create our Patros vector
				Patrons patrons;

				/*
				Text file in which fields are separated by tabs “\t” and patrons by “\n”. 
				For example, the first patron (the fields are all in the following order: id, name) could be 1234, "Timmy"
				*/

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

				/*
				Text file in which fields are separated by tabs “\t” and donations by “\n”. 
				For example, the first patron (the fields are all in the following order: id, donation) could be 1234, 1000
				*/

				// Create temp vars for data and open donations file
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

  				break;
    		} // MARK END OF COMPONENT TWO

    		case 3: { //MARK BEGINNING OF COMPONENT THREE
    			
				cout << endl << endl << "#####BEGIN COMPONENT THREE:#####" << endl;

			    // create vector of employees and choice for employee menu
			    vector<Employee*> employees;
			    int choice;
			    int choice2;
			    string fullname;
			    float wage;
			    char shift;
			    do {
			    	cout << "Component Three Menu:" << endl;
			    	cout << "(1) - Add an Employee" << endl;
			    	cout << "(2) - Calculate Employee Pay" << endl;
			    	cout << "(3) - Display Employees" << endl;
			    	cout << "(4) - Exit" << endl;
			    	cin >> choice;

			    		// main menu decision tree
			    		switch(choice) {
			    			// add employee loop
			    			case 1: 
			    				do {
				    				cout << "Choose the type of employee:" << endl;
				    				cout << "(1) Curator" << endl;
				    				cout << "(2) Docent" << endl;
				    				cout << "(3) Senior Docent" << endl;
				    				cout << "(4) Exit" << endl;
				    				cin >> choice2;    
			    					
			    					// employee addition decsion tree
			    					switch(choice2) {
			    						// adding a curator
			    						case 1: {
			    							char speciality;
			    							int experience;
			    							cout << "Enter employee's name (string): ";
			    							cin >> fullname;
			    							cout << endl;
			    							cout << "Enter employee's wage (float): ";
			    							cin >> wage;
			    							cout << endl;
			    							cout << "Enter employee's speciality (char): ";
			    							cin >> speciality;
			    							cout << endl;
			    							cout << "Enter employee's experience (int): ";
			    							cin >> experience;
			    							cout << endl;
			    							cout << "Adding curator name: " << fullname << ", with wage: "
			    							<< wage << ", specaility: " << speciality 
			    							<< ", experience: " << experience << endl;
			    							Curator *temp = new Curator(fullname, wage, speciality, wage);
			    							employees.push_back(temp);
			    							break;
			    						}
			    						// adding a docent
			    						case 2: {
			    							char shift;
			    							cout << "Enter employee's name (string): ";
			    							cin >> fullname;
			    							cout << endl;
			    							cout << "Enter employee's wage (float): ";
			    							cin >> wage;
			    							cout << endl;
			    							cout << "Enter employee's shift (char): ";
			    							cin >> shift;
			    							cout << endl;
			    							cout << "Adding docent name: " << fullname << ", with wage: "
			    							<< wage << ", shift: " << shift << endl;
			    							Docent *temp = new Docent(fullname, wage, shift);
			    							employees.push_back(temp);
			    							cout << "Adding a docent." << endl;
			    							break;
			    						}
			    						// adding a senior docent
			    						case 3: {
			    							char shift;
			    							int vacation;
			    							cout << "Enter employee's name (string): ";
			    							cin >> fullname;
			    							cout << endl;
			    							cout << "Enter employee's wage (float): ";
			    							cin >> wage;
			    							cout << endl;
			    							cout << "Enter employee's shift (char): ";
			    							cin >> shift;
			    							cout << endl;
			    							cout << "Enter employee's vacation days (int): ";
			    							cin >> vacation;
			    							cout << endl;
			    							cout << "Adding  senior docent name: " << fullname << ", with wage: "
			    							<< wage << ", shift: " << shift << ", vacation days: "
			    							<< vacation << endl;
			    							SeniorDocent *temp = new SeniorDocent(fullname, wage, shift, vacation);
			    							employees.push_back(temp);
			    							break;
			    						}
			    						// leaving this submenu
			    						case 4:
			    							break;
			    					}
			    				
			    				} while (choice2 != 4);
			    				break;
			    			case 2:
			    				// for every employee in employees
				    			for (int i = 0; i < employees.size(); i++) {
			    					// print wage data
			    					cout << "Employee: "
			    					<< employees[i]->getName() << " made $"
			    					<< employees[i]->getPay() << endl;
			    				}
			    				cout << endl;
				    			break;
			    			case 3:
			    				// for every employee in employees
			    				for (int i = 0; i < employees.size(); i++) {
			    					// print respective data
			    					cout << "Employee #" << i << endl;
			    					employees[i]->print();
			    					cout << endl;
			    				}
			    				cout << endl;
			    				break;
			    			case 4:
			    				break;
			    			default:
			    				break;
			    		}
			    } while(choice != 4);
			    
    			break;
    		} // MARK END OF COMPONENT THREE

    		case 4:
    			break;

    		default:
    			break;
    	};

    } while (component != 4);

	return 0;
}


    
/*
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
    SeniorDocent *tim = new SeniorDocent(john, money, shift, vacation);
    
    // seniordocent accessor method tests
    cout << "Initial Senior Docent:" << endl;
    tim->print(); cout << endl;
    
    // senior docent mutator method tests
    tim->useVacation(100);
    tim->addHours(100);
    
    cout << "Final Senior Docent:" << endl;
    tim->print(); cout << endl;
*/
    //employees.push_back(tim);
    //cout << "###########" << endl;
    //employees[0]->print();
