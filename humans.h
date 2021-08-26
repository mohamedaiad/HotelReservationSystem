#pragma once
using namespace std;
class humans
{
private:
	int rooms;
	int night;
	int dryclean;
	int spa;
public :
	void makeAvilable(int r);
	int drycleanCost();
	int  spaCost();
	int getCost(int r, int n);
	void setRooms(int r);
	int getRooms();
	humans();
};

