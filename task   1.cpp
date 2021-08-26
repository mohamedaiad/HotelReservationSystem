#include <iostream>
#include "humans.h"
#include "monsters.h"
#include<string>
#include <vector>
#include<map>

using namespace std;


struct info {
	string name;
	string type;
	int numOfRooms;
	int numOfNights;
	int totalCost;
};

map<int, info> guests;


int main()
{
	humans h;
	monsters m;
	auto itr = guests.end();
	while (1) {
		cout << "\t\t\t\t\t\tWelome to our hotel\n\t\t\t\t**Please enter the number of the option you want**\n";
		cout << "Are you new guest or old guest or receptionist? (1-new  2-old  3-receptionist)\n";
		int op=0;
		string s,type;
		cin >> op;
		if (op == 3) {
		cout << "ID\tName\tType\tNum Of Rooms\tNum Of Nights\tCost\n";
		for (auto i = guests.begin(); i != guests.end(); i++) {
			cout << i->first << "\t" << i->second.name << "\t" << i->second.type << "\t" << i->second.numOfRooms << "\t\t" << i->second.numOfNights << "\t\t" << i->second.totalCost << "\n";
		}
		cout << "\n\n\n\n";
		continue;
		}
		if (op == 1) {
				cout << "Are you human or monster? (1-human  2-monster)\n";
				cin >> op;
				string name;
				int id = guests.size() + 1;
				if (op == 1) {
					type = "human";
					cout << "what is your name? ";
					getline(cin, name);
					getline(cin, name);
					cout << "Welome " << name << " Your ID is " << id << "\n";
				}
				else if (op == 2) {
					type = "monster";
					cout << "what is your name? ";
					getline(cin, name);
					getline(cin, name);
					cout << "Welome " << name << " Your ID is " << id << "\n";
				}
				else {
					cout << "Sorry this is not option, Please try again later\n\n\n\n";
					continue;
				}
				guests.insert({ id, {name,type,0,0,0} });
				itr = guests.find(id);
			}
			else if (op == 2) {
				cout << "please enter your id : ";
				int n;
				cin >> n;
				getline(cin, s);
				itr = guests.find(n);
				cout << "welcome back " << itr->second.name << "\n";
				type = itr->second.type;
			}
			else {
				cout << "Sorry this is not option, please try again later\n\n\n\n";
				continue;
			}

			cout << "what service are you want? (1- new reservation 2- extend reservation 3- additional services 4- cancel reservation)\n";
			cin >> op;
			if (op == 1) {
				cout << "how many rooms do you want?\n";
				int rooms, freeRooms = 0;
				cin >> rooms;
				if (type == "human") freeRooms = h.getRooms();
				else freeRooms = m.getRooms();
				if (rooms > freeRooms) cout << "Sorry this number of rooms is not avalible\nHope we see you again,Sir!\n\n\n\n";
				else {
					itr->second.numOfRooms = rooms;
					if (type == "human") h.setRooms(rooms);
					else m.setRooms(rooms);
					cout << "how many nights would you stay?\n";
					int nights;
					cin >> nights;
					itr->second.numOfNights = nights;
					int cost = 0;
					if (type == "huamn") cost = h.getCost(rooms, nights);
					else cost = m.getCost(rooms, nights);
					itr->second.totalCost = cost;
					cout << "the total cost is " << cost << "$\nThank you!\n\n\n\n";
				}
			}
			else if (op == 2) {
				cout << "how many additional nights you want to stay? ";
				int nights;
				cin >> nights;
				itr->second.numOfNights += nights;
				int rooms = itr->second.numOfRooms;
				int cost = 0;
				if (type == "human") cost = h.getCost(rooms,nights);
				else cost = m.getCost(rooms, nights);
				itr->second.totalCost += cost;
				cout << "the cost of the extend reservation is " << cost << "$\nthee total cost now is " << itr->second.totalCost <<"$\nThank you!\n\n\n\n";
				getline(cin, s);
			}
			else if (op == 3) {
				cout << "1-dry clean  2-spa?";
				cin >> op;
				if (op == 1 && type == "human") { itr->second.totalCost += h.drycleanCost(); cout << "the cost for dry clena service is " << h.drycleanCost() << "$\nthe total cost now is " << itr->second.totalCost <<"$\nThank you!\n\n\n\n"; }
				else if (op == 1 && type == "monster") { itr->second.totalCost += m.drycleanCost();  cout << "the cost for dry clean service is " << m.drycleanCost() << "$\nthe total cost now is " << itr->second.totalCost << "$\nThank you!\n\n\n\n"; }
				else if (op == 2 && type == "human") { itr->second.totalCost += h.spaCost(); cout << "the cost for spa service is " << h.spaCost() << "$\nthe total cost now is " << itr->second.totalCost << "$\nThank you!\n\n\n\n"; }
				else if (op == 2 && type == "monster") { itr->second.totalCost += m.spaCost();  cout << "the cost for spa service is " << m.spaCost() << "$\nthe total cost now is " << itr->second.totalCost << "$\nThank you!\n\n\n\n";  }
			}
			else if (op == 4) {
				cout << "Are you sure you want to cancel the whole reservation? (1-yes 2-no) ";
				cin >> op;
				if (op == 1) {
					if (type == "human") {
						h.makeAvilable(itr->second.numOfRooms);
					}
					else {
						m.makeAvilable(itr->second.numOfRooms);
					}
					cout << "\n\n\n\n";
				}
				else {
					cout << "\n\n\n\n";
					continue;
				}


			}
			else {
				cout << "\n\n\n\n";
				continue;
			}
	}
	
	return 0;
}

