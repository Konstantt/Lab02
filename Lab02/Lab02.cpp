//Collin Schmucker
// 2/15/2018
// Lab02
// Vectors and Sorting Algorithms



#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

const int NUM_TEAMS = 4;
const int NUM_MEMBERS = 3; 

struct TeamS {
	int ID;
	string teamMembers[NUM_MEMBERS];
};

void Initialize(vector <TeamS> &TeamV, const int id[],	const string m[][NUM_MEMBERS], int arraySize);
void printList(const vector<TeamS> &TeamV);
void menu();
void add(vector<TeamS> &TeamV);
int search(const vector<TeamS> &TeamV, int id);

int main()
{
	vector<TeamS> TeamV;
	int isDone, searchID = 0;

	const int ID[NUM_TEAMS] = { 123, 321, 456, 789 };
	const string MEMBERS[NUM_TEAMS][NUM_MEMBERS] =
	{
		{ "Sarah", "Joe", "John" },
		{ "Chris", "Kevin", "James" },
		{ "Tom", "Kim", "Emily" },
		{ "Jill", "Jason", "Jim" }
	};
	
	Initialize(TeamV, ID, MEMBERS, NUM_TEAMS);
	printList(TeamV);
	menu();

	cout << "Enter Choice: " << endl;
	cin >> isDone;

	while ((isDone != 4) && (isDone > 4) && (isDone < 0)) {
		switch (isDone) {
		case 1: printList(TeamV); break;
		case 2: add(TeamV); break;
		case 3: cout << "Enter Team ID: ";
			cin >> searchID;
			if(search(TeamV, searchID) == -1) {
				cout << "No Team with the search ID " << searchID << " found in the list." << endl;
			}; break;
		case 4: return 0; break;
		default: cout << "Please Enter a value between 1 and 4";
		}
	}
	

	system("pause");
    return 0;
}

void Initialize(vector <TeamS> & TeamV, const int id[], const string m[][NUM_MEMBERS], int arraySize) {
	int i, j = 0;

	cout << "Starting Initialization" << endl;
	TeamV.resize(NUM_TEAMS);
	for (i = 0; i < arraySize; i++) {
		TeamV[i].ID = id[i];
		for (j = 0; j < NUM_MEMBERS; j++) {
			TeamV[i].teamMembers[j] = m[i][j];
		}
	}
	cout << "Ending Initialization" << endl;
}

void printList(const vector <TeamS> &TeamV) {
	int i, j = 0;

	cout << endl << "xxxxTeam Listxxxx" << endl << endl;

	for (i = 0; i < TeamV.size(); i++) {
		cout << "Information for Team " << (i + 1) << endl;
		cout << "ID:\t" << TeamV[i].ID << "\t";
		for (j = 0; j < NUM_MEMBERS; j++) {
			cout << TeamV[i].teamMembers[j] << "\t"; 
		}
		cout << endl;
	}

	cout << endl << "xxxxx" << endl;
}

void menu() {
	cout << "Enter 1 to see a list of teams" << endl;
	cout << "Enter 2 to add a team to the list" << endl;
	cout << "Enter 3 to search for a team using an ID" << endl;
	cout << "Enter 4 to end the program" << endl;
}

void add(vector<TeamS> &TeamV) {
	int i = 0;
	TeamV.resize(TeamV.size() + 1);
	
	TeamS tempTeam;

	cout << "Enter Team ID:";
	cin >> tempTeam.ID;
	cin.ignore();
	for (i = 0; i < NUM_MEMBERS; i++) {
		cout << " Enter member " << (i + 1) << ": ";
		getline(cin, tempTeam.teamMembers[i]);
	}

	TeamV.push_back(tempTeam);
}

int search(const vector<TeamS> &TeamV, int id) {
	int i, j = 0;

	for (i = 0; i < TeamV.size(); i++) {
		if (TeamV[i].ID == id) {
			cout << "ID: " << TeamV[i].ID;
			for (j = 0; j < NUM_MEMBERS; j++) {
				cout << "\t" << TeamV[i].teamMembers[j];
			}
		}
	}
	return -1;
}