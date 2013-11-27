// Header file for component three employee-related classes

#include <iostream>
#include <string>

using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

// class defining an employee
class Employee {
protected:
    string name;
    float wage;
    int hours;
public:
    // constructor
    Employee(string _name, float _wage);
    // destructor
    ~Employee();
    // accessor methods
    virtual void print() = 0;
    virtual int getPay();
    int getHours() const;
    float getWage() const;
    string getName() const;
    // mutator methods
    void setWage(float _wage);
    void addHours(int _hours);
};
// class representing a Curator
class Curator : public Employee {
protected:
    char speciality;
    int experience;
public:
    // constructor
    Curator(string _name, float _wage, char _spec, int _exp);
    // destructor
    ~Curator();
    // accessors
    char getSpeciality() const;
    int getExperience() const;
    void print();
    // mutators
    void setSpeciality(char _spec);
    void setExperience(int _exp);
};
// class representing a docent
class Docent : public Employee {
protected:
    char shift;
public:
    // constructor
    Docent(string _name, float _wage, char _shift);
    // destructor
    ~Docent();
    // accessors
    char getShift() const;
    void print();
    // mutators
    void setShift(char _shift);
};
// class representing a senior docent
class SeniorDocent : public Docent {
protected:
    int vacation;
public:
    // constructor
    SeniorDocent(string _name, float _wage, char _shift, int _vac);
    // destructor
    ~SeniorDocent();
    // accessors
    int getVacation() const;
    void print();
    // mutators
    void useVacation(int _amt);
};

#endif