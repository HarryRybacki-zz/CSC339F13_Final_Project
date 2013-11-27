// function definitions for employee-related classes

#include "employee.h"

// Employee class function definitions
Employee::Employee(string _name,
                   float _wage)
{
    name = _name;
    wage = _wage;
}
Employee::~Employee(){}
void Employee::setWage(float _wage)
{
    wage = _wage;
    hours = 0;
}
int Employee::getPay() {
    return int(wage) * hours;
}
void Employee::addHours(int _hours) {
    hours += _hours;
}
int Employee::getHours() const {
    return hours;
}
float Employee::getWage() const {
    return wage;
}
string Employee::getName() const {
    return name;
}

// Curator class function definitions
Curator::Curator(string _name,
                 float _wage,
                 char _spec,
                 int _exp)
: Employee(_name, _wage)
{
    speciality = _spec;
    experience = _exp;
    hours = 0;
}
Curator::~Curator(){}
void Curator::print() {
    cout << "Name: " << name << endl;
    cout << "Wage: " << wage << endl;
    cout << "Hours: " << getHours() << endl;
    cout << "Speciality:" << speciality << endl;
    cout << "Experience:" << experience << endl;
    cout << "Pay: " << getPay() << endl;
}
char Curator::getSpeciality() const {
    return speciality;
}
int Curator::getExperience() const {
    return experience;
}

void Curator::setSpeciality(char _spec) {
    speciality = _spec;
}
void Curator::setExperience(int _exp) {
    experience = _exp;
}

// Docent class function definitions
Docent::Docent(string _name,
               float _wage,
               char _shift)
: Employee(_name, _wage)
{
    shift = _shift;
    hours = 0;
}
Docent::~Docent(){}
char Docent::getShift() const {
    return shift;
}
void Docent::print() {
    cout << "Name: " << name << endl;
    cout << "Wage: " << wage << endl;
    cout << "Hours: " << getHours() << endl;
    cout << "Shift: " << shift << endl;
    cout << "Pay: " << getPay() << endl;
}
void Docent::setShift(char _shift) {
    shift = _shift;
}

// SeniorDocent class function definitions
SeniorDocent::SeniorDocent(string _name,
                           float _wage,
                           char _shift,
                           int _vac)
: Docent(_name, _wage, _shift)
{
    vacation = _vac;
}
SeniorDocent::~SeniorDocent(){}
void SeniorDocent::print()
{
    Docent::print();
    cout << "Vacation: " << vacation << endl;
}
int SeniorDocent::getVacation() const {
    return vacation;
}
void SeniorDocent::useVacation(int _amt) {
    vacation -= _amt;
}