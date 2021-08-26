#include "humans.h"
using namespace std;
humans::humans() : rooms(5),night(500),dryclean(70),spa(100)
{
}




void humans::makeAvilable(int r)
{
	rooms += r;
}

int humans::drycleanCost()
{
	return dryclean;
}

int humans::spaCost()
{
	return spa;
}

int humans::getCost(int r, int n)
{
	return night*n*r;
}

void humans::setRooms(int r)
{
	rooms -= r;
}

int humans::getRooms()
{
	return rooms;
}

