#pragma once
#include <string>
#include <vector>

using namespace std;

class ThingsToDo
{
private:
	string filename;

	string FinalName, FinalCity, FinalCost;

	vector<string> FoundNames;
	vector <string> FoundCity;
	vector <string> FoundCost;

public:
	//constructor without argument
	ThingsToDo();

	//sets file name
	void setFilename(string destination);

	//searchs for activities based on budget
	void Search();

	//sets final activity choice based on the number user chose
	void setFinal(int choice);

	//returns the string cost
	string getCost();

	//prints out the information on each acitivity
	void printActivities();
};