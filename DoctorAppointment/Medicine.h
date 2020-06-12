#include <string>
using namespace std;
#pragma once
class Medicine
{
	private:
		int ID;
		string Name;
		string Description;
		double Price;
		int DailyTakenTimes;

	public:
		Medicine();
		Medicine(int id, string name, string description, double price, int timesPerDay);
		int getID();
		string getName();
		double getPrice();
		int getTimesPerDay();
};

