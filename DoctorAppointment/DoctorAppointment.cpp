// DoctorAppointment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <ctime>
#include <iterator> 
#include <algorithm>
#include "Patient.h";
#include "Message.h";
#include "Medicine.h";
#include "Doctor.h";
using namespace std;


int main()
{
	int login;

   cout << "Hey, Welcome to Doctor Appointment Management System \n";
   cout << "Please following the instructions and entering numbers for what you want \n";
   cout << "---------------------------------------------------------------------------- \n";
   WrongChoice:
   cout << "1- Login as a Doctor \n";
   cout << "2- Login as a Patient \n";
   cin >> login;
   
   Doctor dr1(1, "mohamed", "abdelrahman", "mohamed@yahoo.com", "01154321101");

   switch (login)
   {
	   case 1:
		   back:
		   int choice;
		   cout << "Welcome Doctor "+ dr1.getFristName() + " to your clinic "+ "\n";
		   cout << "Please choice What you want to do \n";
		   cout << "1- Register New Patient \n";
		   cout << "2- List all patient \n";
		   cout << "3- Manage a specific Patient \n";
		   cout << "4- List all messages coming from patients \n";
		   cin >> choice;

		   switch (choice)
		   {
			   case 1: {
				   cout << "----------------------Please Enter Patients Info and his username and password ---------------------- \n";
				   int userId, choice2;
				   string userFirstName, userLastName, userAddress, Username, userPassword, DateOfHisReservation;
				   cout << "enter username "; cin>> Username;
				   cout << "enter password "; cin>> userPassword;
				   cout << "enter Reservation date "; cin>> DateOfHisReservation;
				   cout << "From some additional info ..... \n ";
				   cout << "enter user ID "; cin>>userId;
				   cout << "enter First Name "; cin>> userFirstName;
				   cout << "enter Last Name "; cin>> userLastName;
				   cout << "enter Address "; cin>> userAddress;
				   
				   Patient p(userId, userFirstName, userLastName, userAddress, Username, userPassword, DateOfHisReservation);
				   dr1.registerPatient(p);

				   cout << ".........................\n";
				   cout << "Patient has register Successfully \n";
				   cout << "Choice from following \n";
				   cout << "1- Write Medicines for this Patient \n";
				   cout << "2- List All Patients \n";
				   cout << "3- back \n";
				   cin >> choice2;

				   switch (choice2)
				   {
					   case 1: {
						   anotherMedicine:
						   int medicineId, timesPerDay, choice3;
						   double price;
						   string medicineName, medicineDescription;
						   cout << "------------Adding Medicine for Patient "+ p.getFristName() +"\n";
						   cout << "enter Medicine Id: "; cin >> medicineId;
						   cout << "enter Medicine Name: "; cin >> medicineName;
						   cout << "enter Medicine Description: "; cin >> medicineDescription;
						   cout << "enter Medicine Price: "; cin >> price;
						   cout << "enter Medicine Taken Times Per Day: "; cin >> timesPerDay;
						   
						   Medicine m(medicineId, medicineName, medicineDescription, price, timesPerDay);
						   p.addMedicineToList(m);
						   cout << "Medicine has been added \n";
						   cout << "1- add another medicine \n";
						   cout << "2- back \n";
						   cin >> choice3;
						   switch (choice3)
						   {
								case 1:
									goto anotherMedicine;
									break;
								case 2:
									goto back;
									break;
								default:
									goto back;
								   break;
						   }
						   break;
					   }
					   case 2: {
							   list<Patient>::iterator it;
							   for (it = dr1.getAllPatients().begin(); it != dr1.getAllPatients().end(); ++it)
							   {
								   cout << "-------------- Patient Number " << (*it).getId() << "------------------ \n";
								   cout << "Patient First Name: " << (*it).getFristName() << "\n";
								   cout << "Patient Last Name: " << (*it).getLastName() << "\n";
								   cout << "Patient Address: " << (*it).getAddress() << "\n";
								   cout << "Patient username: " << (*it).getUsername() << "\n";
								   cout << "His Reservation Date:  " << (*it).getDateOfHisReservation() << "\n";
							   }
							   break;
							}
					   case 3:
						   goto back;
						   break;
					   default:
						   goto back;
						   break;
				   }

				   break;
			   }
			   case 2: {
				    list<Patient>::iterator it;
					   for (it = dr1.getAllPatients().begin(); it != dr1.getAllPatients().end(); ++it)
					   {
						   cout << "-------------- Patient Number " << (*it).getId() << "------------------ \n";
						   cout << "Patient First Name: " + (*it).getFristName() << "\n";
						   cout << "Patient Last Name: " + (*it).getLastName() << "\n";
						   cout << "Patient Address: " + (*it).getAddress() << "\n";
						   cout << "Patient username: " + (*it).getUsername() << "\n";
						   cout << "His Reservation Date:  " + (*it).getDateOfHisReservation() << "\n";
					   }

					break;
				}
			   case 3: {
				   int patientId, choice4;
				   cout << "Enter the Patient ID: ";cin >> patientId;
				   Patient searchedPatient = dr1.searchWithPatientId(patientId);
				   if (searchedPatient.getId() != 0)
				   {
					   cout << "Patient Found and his name = " << searchedPatient.getFristName() << endl;
					   cout << "Chose What you want from this patient "<< endl;
					   cout << "1- Set Username and Password "<< endl;
					   cout << "2- reverse a date "<< endl;
					   cout << "3- add a Medicine to him "<< endl;
					   cin >> choice4;
					   if (choice4 == 1)
					   {
						   string username, password;
						   cout << "enter username: ";cin >> username;
						   cout << "enter password: ";cin >> password;
						   searchedPatient.setUsernameAndPassword(username, password);
						   dr1.getAllPatients().push_back(searchedPatient);
					   }
					   else if (choice4 == 2)
					   {
						   int day,month,year;
						   cout << "enter day of reservation: ";cin >> day;
						   cout << "enter month of reservation: ";cin >> month;
						   cout << "enter year of reservation: ";cin >> year;
						   searchedPatient.reverseDate(day, month, year);
					   }
					   else if (choice4 == 2)
					   {
						   int medicineId, timesPerDay, choice3;
						   double price;
						   string medicineName, medicineDescription;
						   cout << "enter Medicine Id: "; cin >> medicineId;
						   cout << "enter Medicine Name: "; cin >> medicineName;
						   cout << "enter Medicine Description: "; cin >> medicineDescription;
						   cout << "enter Medicine Price: "; cin >> price;
						   cout << "enter Medicine Taken Times Per Day: "; cin >> timesPerDay;

						   Medicine m(medicineId, medicineName, medicineDescription, price, timesPerDay);
						   searchedPatient.addMedicineToList(m);
					   }
					  
				   }
				   else
				   {
					   cout << "Sorry, Patient Not Found \n";
				   }
				   break;
			   }
			   case 4: {
				   cout << "Here are your unread Messages -------------------- \n";

				   list<Message> messages = dr1.getAllMessages();
				   list<Message>::iterator it;
				   for (it = messages.begin(); it != messages.end(); ++it)
				   {
					   cout << "-------------- Message Number " << (*it).getID() << "------------------ \n";
					   cout << "Message: " << (*it).getContent() << "\n";
					   cout << "at : " << (*it).getTimeSend() << "\n";
					   cout << "From:  " << (*it).getPatientName() << "\n";
				   }
				   break;
				}
				default:
					break;
		   }

		   break;
	   case 2: {
		   string username, password;
		   cout << "enter your username: ";cin >> username;
		   cout << "enter your password: ";cin >> password;

		   Patient searchedPatient = dr1.searchWithUsernameAndPassword(username,password);
		   if (searchedPatient.getId() != 0)
		   {
			   int choice5;
			   cout << "----------------------------------------------------------" << endl;
			   cout << "Login Successfully"<<endl;
			   cout << "Welcome Patient " << searchedPatient.getUsername()<<endl;
			   cout << "Your Reservation Date at " << searchedPatient.getDateOfHisReservation()<<endl;
			   cout << "choice from the following what you want ?" << endl;
			   cout << "1- Show my list of medicine" << endl;
			   cout << "2- send a message to the doctor" << endl;
			   cin >> choice5;
			   switch (choice5)
			   {
				   case 1: {
					   list<Medicine> myMedicinces = searchedPatient.getListOfMedicine();
					   list<Medicine>::iterator it;
					   for (it = myMedicinces.begin(); it != myMedicinces.end(); ++it)
					   {
						   cout << "-------------- Medicine Number " << (*it).getID() << "------------------ \n";
						   cout << "Medicine Name: " << (*it).getName() << "\n";
						   cout << "Medicine Price: " << (*it).getPrice() << "\n";
						   cout << "Taken " << (*it).getTimesPerDay() <<" Times Per day" <<"\n";
					   }
					   break;
				   }
				   case 2: {
					   int messageId;
					   string content;
					   cout << "------------Sending Messages To doctor \n";
					   cout << "enter Message Id: "; cin >> messageId;
					   cout << "enter The Message: "; cin >> content;

					   time_t rawtime;
					   struct tm* timeinfo;
					   char buffer[80];
					   time(&rawtime);
					   timeinfo = localtime(&rawtime);
					   strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
					   std::string str(buffer);


					   Message m(messageId, content, searchedPatient, str);
					   dr1.recieveMessage(m);
					   cout << "Message sent Successfully \n";
					   break;
					}
				   default:
					   break;
			   }
		   }
		   else
		   {
			   cout << "Login Not Successfully" << endl;
			   cout << "wrong username or password" << endl;
		   }

		   break;
	   }
	   default:
		   if (typeid(login).name() == "int")
		   {
			   cout << "Sorry wrong choice, please enter the range for above available choices \n";
			   cout << "choice from that \n";
			   goto WrongChoice;
		   }
		   else
		   {
			   cout <<"please enter only numbers and try again";
			   break;
		   }
		   
   }
}
