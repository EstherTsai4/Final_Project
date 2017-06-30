#include <iostream>
#include <vector>
#include <string>
#include "Food.h"
#include "TripPlanner.h"
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

Food::Food()
{
	filename = " ";
	FinalName = " ";
	FinalCity = " ";
	FinalCost = " ";

}

void Food::setFilename(string destination)
{
	filename = destination.append("Food.txt");
}

//searches file for restaurant under the budget
void Food::Search()
{
	double objectBudget;
	cout << "What is the budget for restaurant? ";
	cin >> objectBudget;

	while (FoundCity.empty())
	{
		ifstream file(filename);
		string restaurant, city, cost;

		//read file until the end
		while (!file.eof())
		{
			//read name until reaches tab and makes sure there isn't an enter in the front of the line
			getline(file, restaurant, '\t');
			if (restaurant[0] == '\n')
			{
				restaurant = restaurant.substr(1);
			}

			if (!file.eof())
			{
				getline(file, city, '\t');
				file >> cost;

				//calls operator to compare the budget with the string
				if (objectBudget >= cost)
				{
					//stores choices in vectors if meets budget
					FoundNames.push_back(restaurant);
					FoundCity.push_back(city);
					FoundCost.push_back(cost);
				}
			}
		}
		if (FoundCity.empty())
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
			<< left << setw(width) << setfill(separator) << FoundCity[i] << left << setw(width) << setfill(separator)
			<< FoundCost[i] << endl;
	}

	cin >> choice;

	setFinal(choice);

	//clear the vector for the next search
	FoundNames.clear();
	FoundCity.clear();
	FoundCost.clear();
}

void Food::setFinal(int index)
{
	FinalName = FoundNames[index];
	FinalCity = FoundCity[index];
	FinalCost = FoundCost[index];
}

string Food::getCost()
{
	return FinalCost;
}

void Food::printRestaurants()
{
	const int width = 35;
	const char separator = ' ';

	cout << left << setw(width) << setfill(separator) << FinalName 
		<< left << setw(width) << setfill(separator) << FinalCity 
		<< left << setw(width) << setfill(separator) << FinalCost << endl;
}