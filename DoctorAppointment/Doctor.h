#include "Person.h"
#include "Patient.h"
#include "Message.h"
#include <string>
#include <list>
using namespace std;

#pragma once
class Doctor : public Person
{
	private:
		string Phone;
		string Email;
		list<Patient> Patients;
		list<Message> Messages;

	public:
		Doctor();
		Doctor(int id, string firstName, string lastName,string email, string phone);
		string getEmail();
		string getPhone();
		list<Patient>& getAllPatients();
		Patient searchWithPatientId(int id);
		Patient searchWithUsernameAndPassword(string username, string password);
		void setPatients(list<Patient> patiens);
		void registerPatient(Patient patient);
		list<Message> getAllMessages();
		void recieveMessage(Message msg);
};

