#include "Person.h";
#include "Medicine.h";
#include <string>
#include <list> 
using namespace std;

#pragma once
class Patient : public Person
{
	private:
		string Address;
		string Username;
		string Password;
		string DateOfHisReservation;
		list<Medicine> Medicines;

	public:
		Patient();
		Patient(int id, string firstName, string lastName, string adress);
		Patient(int id, string firstName, string lastName, string adress, string username, string password);
		Patient(int id, string firstName, string lastName, string adress, string username, string password, string dateOfHisReservation);
		
		string getAddress();
		string getUsername();
		string getPassword();
		string getDateOfHisReservation();
		list<Medicine>& getListOfMedicine();

		void setUsernameAndPassword(string username, string password);
		void reverseDate(int day, int month, int year);
		void setListOfMedicine(list<Medicine> list);
		void addMedicineToList(Medicine medicine);
};

