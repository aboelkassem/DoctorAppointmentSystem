#include "Person.h"

Person::Person() {
	ID = 0;
	FristName = "No Name";
	LastName = "No Name";
};

Person::Person(int id, string firstName, string lastName) : 
	ID(id), FristName(firstName), LastName(lastName) 
{ 
};

int Person::getId() {
	return this->ID;
};

string Person::getFristName() {
	return this->FristName;
};

string Person::getLastName() {
	return this->LastName;
};