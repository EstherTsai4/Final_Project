#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Airline.h"

using namespace std;

Airline::Airline()
{
	finalCompany = " ";
	finalClass = " ";
	finalStops = 0;
	finalCost = 0;
}

//sets the final characteristics of the airplane ticket based on the number the user chose
void Airline::setFinal(int index)
{
	this->finalCompany = Foundcompany[index];
	this->finalClass = FoundseatClass[index];
	this->finalStops = FoundnumberOfStops[index];
	this->finalCost = Foundcost[index];
}

//get the filename based on the destination
void Airline::setFilename(string destination)
{
	filename = destination.append("Airplane.txt");
}

//return filename
string Airline::getFilename()
{
	return filename;
}

double Airline::getCost()
{
	return finalCost;
}
//opens the final and searchs for the airplane object
void Airline::Search()
{
	double objectBudget;
	cout << "What is the budget for your ticket? ";
	cin >> objectBudget;


	while (Foundcompany.empty())
	{
		ifstream file(filename);
		string company, seat;
		int numberOfStops;
		double cost;

		//continues to read till end of the file
		while (!file.eof())
		{
			//makes sure not to get the enter at the beginning of the line
			//reads the words until reaches a tab
			getline(file, company, '\t');
			if (company[0] == '\n')
			{
				company = company.substr(1);
			}

			if (!file.eof())
			{
				getline(file, seat, '\t');
				if (!file.eof())
				{
					file >> numberOfStops >> cost;
					//if the cost is under the budget, store the characteristics in vectors
					if (objectBudget >= cost)
					{
						Foundcompany.push_back(company);
						FoundseatClass.push_back(seat);
						FoundnumberOfStops.push_back(numberOfStops);
						Foundcost.push_back(cost);
					}
				}
			}
		}
		if (Foundcompany.empty())
		{
			cout << "Object not found that meets budget requirements. Please try again: ";
			cin >> objectBudget;
		}
	}

	//ask user to choose from found results
	int choice;
	const int width = 35;
	const char separator = ' ';

	cout << "Choose from the following: " << endl;
	for (int i = 0; i < Foundcompany.size(); i++)
	{
		cout << i << ". " << left << setw(width) << setfill(separator) << Foundcompany[i] << left << setw(width) << setfill(separator)
			<< FoundseatClass[i] << left << setw(width) << setfill(separator) 
			<< FoundnumberOfStops[i] << left << setw(width) <<setfill(separator) << Foundcost[i] << endl;
	}
	cin >> choice;

	//set the final choice
	setFinal(choice);

	//clear the vectors for next search
	Foundcompany.clear();
	FoundseatClass.clear();
	FoundnumberOfStops.clear();
	Foundcost.clear();
}

//prints info
void Airline::printTicket()
{
	const int width = 20;
	const char separator = ' ';

	cout << left << setw(width) << setfill(separator) << finalCompany << left << setw(width) << setfill(separator)
		<< finalClass << finalStops << " stops"	<< left << setw(width) << setfill(separator) 
		<< " $"<< finalCost << endl;
}