#include "Doctor.h"
#include "Medicine.h"
#include <list>
#include <ctime>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
Doctor::Doctor() : Email("No Email"), Phone("00000000000000"), Person(0,"No Name", "No Name")
{
}

Doctor::Doctor(int id, string firstName, string lastName,string email,string phone): 
	Email(email),Phone(phone), Person(id, firstName, lastName)
{
	// initial patients data
	Patient p1(1, "Mohamed", "Abdo", "Beni suef", "aboelkassem", "123456789", "21/6/2020");
	p1.addMedicineToList(Medicine(1, "Acetaminophen", "testing description", 12.5, 1));
	p1.addMedicineToList(Medicine(2, "Adderall", "testing description", 12.5, 2));
	p1.addMedicineToList(Medicine(3, "Amitriptyline", "testing description", 12.5, 3));
	p1.addMedicineToList(Medicine(4, "Amlodipine", "testing description", 12.5, 4));
	p1.addMedicineToList(Medicine(5, "Lisinopril", "testing description", 12.5, 2));

	Patient p2(2, "ahmed", "mohamed", "Cairo", "ahmed000", "123456789", "1/6/2020");
	p2.addMedicineToList(Medicine(6, "Levothyroxine", "testing description", 12.5, 2));
	p2.addMedicineToList(Medicine(7, "Amlodipine", "testing description", 12.5, 2));
	p2.addMedicineToList(Medicine(8, "Metformin Hydrochloride", "testing description", 12.5, 2));
	p2.addMedicineToList(Medicine(9, "Simvastatin", "testing description", 12.5, 2));
	p2.addMedicineToList(Medicine(10, "Gabapentin", "testing description", 12.5, 2));

	Patient p3(3, "ali", "ahmed", "Naser", "ali011", "123456789", "3/6/2020");
	p3.addMedicineToList(Medicine(11, "Hydrochlorothiazide", "testing description", 12.5, 2));
	p3.addMedicineToList(Medicine(12, "Sertraline Hydrochloride", "testing description", 12.5, 2));
	p3.addMedicineToList(Medicine(13, "Montelukast", "testing description", 12.5, 2));
	p3.addMedicineToList(Medicine(14, "Prednisone", "testing description", 12.5, 2));
	p3.addMedicineToList(Medicine(15, "Pravastatin Sodium", "testing description", 12.5, 2));

	Patient p4(4, "sara", "Abdo", "Alex", "sara", "123456789", "5/6/2020");
	p4.addMedicineToList(Medicine(1, "Acetaminophen", "testing description", 12.5, 2));
	p4.addMedicineToList(Medicine(2, "Carvedilol", "testing description", 12.5, 2));
	p4.addMedicineToList(Medicine(3, "Pravastatin Sodium", "testing description", 12.5, 2));
	p4.addMedicineToList(Medicine(4, "Tramadol Hydrochloride", "testing description", 12.5, 2));
	p4.addMedicineToList(Medicine(5, "Clonazepam", "testing description", 12.5, 2));

	Patient p5(5, "esraa", "mahmoud", "mansoura", "esraa", "123456789", "16/6/2020");
	p5.addMedicineToList(Medicine(1, "Clopidogrel Bisulfate", "testing description", 12.5, 2));
	p5.addMedicineToList(Medicine(2, "Aspirin", "testing description", 12.5, 2));
	p5.addMedicineToList(Medicine(3, "Cyclobenzaprine", "testing description", 12.5, 2));
	p5.addMedicineToList(Medicine(4, "Glipizide", "testing description", 12.5, 2));
	p5.addMedicineToList(Medicine(5, "Hydrochlorothiazide; Lisinopril", "testing description", 12.5, 2));

	Patient p6(6, "hussien", "hassan", "ashmant", "hhsan", "123456789", "4/6/2020");
	p6.addMedicineToList(Medicine(1, "Acetaminophen", "testing description", 12.5, 2));
	p6.addMedicineToList(Medicine(2, "Acetaminophen", "testing description", 12.5, 2));
	p6.addMedicineToList(Medicine(3, "Acetaminophen", "testing description", 12.5, 2));
	p6.addMedicineToList(Medicine(4, "Acetaminophen", "testing description", 12.5, 2));
	p6.addMedicineToList(Medicine(5, "Acetaminophen", "testing description", 12.5, 2));

	Patient p7(7, "mahmoud", "ali", "Beni suef", "mahmoudali", "123456789", "10/6/2020");
	p7.addMedicineToList(Medicine(1, "Acetaminophen", "testing description", 12.5, 2));
	p7.addMedicineToList(Medicine(2, "Acetaminophen", "testing description", 12.5, 2));
	p7.addMedicineToList(Medicine(3, "Acetaminophen", "testing description", 12.5, 2));
	p7.addMedicineToList(Medicine(4, "Acetaminophen", "testing description", 12.5, 2));
	p7.addMedicineToList(Medicine(5, "Acetaminophen", "testing description", 12.5, 2));

	Patient p8(8, "shimaa", "mohamed", "banha", "shosho", "123456789", "9/6/2020");
	p8.addMedicineToList(Medicine(1, "Acetaminophen", "testing description", 12.5, 2));
	p8.addMedicineToList(Medicine(2, "Acetaminophen", "testing description", 12.5, 2));
	p8.addMedicineToList(Medicine(3, "Acetaminophen", "testing description", 12.5, 2));
	p8.addMedicineToList(Medicine(4, "Acetaminophen", "testing description", 12.5, 2));
	p8.addMedicineToList(Medicine(5, "Acetaminophen", "testing description", 12.5, 2));

	this->Patients.push_back(p1);
	this->Patients.push_back(p2);
	this->Patients.push_back(p3);
	this->Patients.push_back(p4);
	this->Patients.push_back(p5);
	this->Patients.push_back(p6);
	this->Patients.push_back(p7);
	this->Patients.push_back(p8);

	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
	std::string str(buffer);


	Message m1(1, "Hello my doctor i have a good health now thank your", p1, str);
	Message m2(2, "Hello my doctor i love you ", p2, str);
	Message m3(3, "oh thanks god you are in my life", p3, str);
	Message m4(4, "thanks a lot for time ", p4, str);
	Message m5(5, "i really appreciate your efforts", p5, str);
	Message m6(6, "i cannot wait to meet your", p6, str);
	Message m7(7, "i hope you are in a good health", p7, str);
	Message m8(8, "Hello my doctor i have a good health now thank your", p8, str);
	Message m9(9, "oh help me i'm dying", p6, str);
	Message m10(10, "sorry for your time", p1, str);

	this->Messages.push_back(m1);
	this->Messages.push_back(m2);
	this->Messages.push_back(m3);
	this->Messages.push_back(m4);
	this->Messages.push_back(m5);
	this->Messages.push_back(m6);
	this->Messages.push_back(m7);
	this->Messages.push_back(m8);
	this->Messages.push_back(m9);
	this->Messages.push_back(m10);

}

string Doctor::getEmail()
{
	return this->Email;
}

string Doctor::getPhone()
{
	return this->Phone;
}

list<Patient>& Doctor::getAllPatients()
{
	return this->Patients;
}

Patient Doctor::searchWithPatientId(int id)
{
	list<Patient>::iterator it;
	for (it = this->Patients.begin(); it != this->Patients.end(); ++it)
	{
		if (id == (*it).getId())
		{
			return (*it);
		}
	}

	return Patient();
}

Patient Doctor::searchWithUsernameAndPassword(string username, string password)
{
	list<Patient>::iterator it;
	for (it = this->Patients.begin(); it != this->Patients.end(); ++it)
	{
		if (username == (*it).getUsername() && password == (*it).getPassword())
		{
			return (*it);
		}
	}

	return Patient();
}

void Doctor::setPatients(list<Patient> patiens)
{
	this->Patients = patiens;
}

void Doctor::registerPatient(Patient patient)
{
	this->Patients.push_front(patient);
}

list<Message> Doctor::getAllMessages()
{
	return this->Messages;
}

void Doctor::recieveMessage(Message msg)
{
	return this->Messages.push_back(msg);
}
