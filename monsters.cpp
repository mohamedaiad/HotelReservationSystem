#include "monsters.h"
using namespace std;
monsters::monsters() : rooms(15),night(200), dryclean(30), spa(50)
{
}

void monsters::makeAvilable(int r)
{
	rooms += r;
}

int monsters::drycleanCost()
{
	return dryclean;
}

int monsters::spaCost()
{
	return spa;
}

int monsters::getCost(int r, int n)
{
	return night*n*r;
}

void monsters::setRooms(int r)
{
	rooms -= r;
}

int monsters::getRooms()
{
	return rooms;
}


