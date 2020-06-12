#include "Patient.h";
#include "Person.h";
#include "Medicine.h";
#include <string>
#include <list>

Patient::Patient():
	Address("No Address"), Person(0, "No Name", "No Name")
{
}

Patient::Patient(int id, string firstName, string lastName, string address):
	Address(address), Person(id, firstName, lastName)
{
}

Patient::Patient(int id, string firstName, string lastName, string address, string username, string password) :
	Address(address), Person(id, firstName, lastName), Username(username), Password(password)
{
}

Patient::Patient(int id, string firstName, string lastName, string address, string username, string password, string dateOfHisReservation) :
	Address(address), Person(id, firstName, lastName), Username(username), Password(password), DateOfHisReservation(dateOfHisReservation)
{
}

string Patient::getAddress()
{
	return this->Address;
}

string Patient::getUsername()
{
	return this->Username;
}

string Patient::getPassword()
{
	return this->Password;
}

string Patient::getDateOfHisReservation()
{
	return this->DateOfHisReservation;
}

list<Medicine>& Patient::getListOfMedicine()
{
	return this->Medicines;
}


void Patient::setUsernameAndPassword(string username, string password)
{
	this->Username = username;
	this->Password = password;
}


void Patient::reverseDate(int day, int month,int year)
{
	string date = to_string(day) + '/' + to_string(month) + '/' + to_string(year);
	this->DateOfHisReservation = date;
}

void Patient::setListOfMedicine(list<Medicine> list)
{
	this->Medicines = list;
}

void Patient::addMedicineToList(Medicine medicine)
{
	this->Medicines.push_front(medicine);
}

