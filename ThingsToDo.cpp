#include "ThingsToDo.h"
#include "TripPlanner.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

//constructor without argument
ThingsToDo::ThingsToDo()
{
	FinalName = " ";
	FinalCity = " ";
	FinalCost = " ";
}

//sets file name
void ThingsToDo::setFilename(string destination)
{
	filename = destination.append("ThingsToDo.txt");
}

void ThingsToDo::Search()
{
	double objectBudget;
	cout << "What is the budget for activity? ";
	cin >> objectBudget;

while (FoundNames.empty())
{	ifstream file(filename);
	string name, city, cost;

	//read file until the end
	while (!file.eof())
	{
		//read name until reaches tab and makes sure not to read the beginning enter 
		getline(file, name, '\t');
		if (name[0] == '\n')
		{
			name = name.substr(1);
		}

		if (!file.eof())
		{
			getline(file, city, '\t');
			file >> cost;

			//calls operator to compare the budget with the string
			if (objectBudget >= cost)
			{
				//stores choices in vectors if meets budget
				FoundNames.push_back(name);
				FoundCity.push_back(city);
				FoundCost.push_back(cost);
			}
		}
	}
	if (FoundNames.empty())
	{
		cout << "Object not found that meets budget requirements. Please try again: ";
		cin >> objectBudget;
	}
}
	//print out the choices for the user to choose
	int choice;
	const int width = 35;
	const char separator = ' ';

	cout << "Choose from the following: " << endl;
	for (int i = 0; i < FoundNames.size(); i++)
	{
		cout << i << ". " << left << setw(width) << setfill(separator) << FoundNames[i]
			<< left << setw(width) << setfill(separator) << FoundCity[i] 
			<< left << setw(width) << setfill(separator) << FoundCost[i] << endl;
	}

	cin >> choice;

	//set the final choice
	setFinal(choice);

	//clear the found vectors for next search
	FoundNames.clear();
	FoundCity.clear();
	FoundCost.clear();
}

void ThingsToDo::setFinal(int choice)
{
	FinalName = FoundNames[choice];
	FinalCity = FoundCity[choice];
	FinalCost = FoundCost[choice];
}

//returns the string cost
string ThingsToDo::getCost()
{
	return FinalCost;
}

//prints out activity information
void ThingsToDo::printActivities()
{
	const int width = 35;
	const char separator = ' ';

	cout << left << setw(width) << setfill(separator) << FinalName << left << setw(width) << setfill(separator) 
		<< FinalCity << left << setw(width) << setfill(separator) << FinalCost << endl;
}