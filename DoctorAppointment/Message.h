#include <string>
#include "Patient.h";
using namespace std;

#pragma once
class Message
{
	private:
		int ID;
		string Content;
		Patient Sender;
		string SentAt;

	public:
		Message();
		Message(int id, string content, Patient snder, string sentAt);

		int getID();
		string getContent();
		string getPatientName();
		string getTimeSend();
};

