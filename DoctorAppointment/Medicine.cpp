#include "Medicine.h"
#include <string>

Medicine::Medicine() :
	ID(0),Name("No Name"),Description("No Description"), Price(0), DailyTakenTimes(0)
{
}

Medicine::Medicine(int id, string name, string description, double price, int timesPerDay) :
	ID(id), Name(name), Description(description), Price(price), DailyTakenTimes(timesPerDay)
{
}

string Medicine::getName()
{
	return this->Name;
}
int Medicine::getID()
{
	return this->ID;
}

double Medicine::getPrice()
{
	return this->Price;
}

int Medicine::getTimesPerDay()
{
	return this->DailyTakenTimes;
}
