#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Hotel.h"

using namespace std;

//constructor without argument
Hotel::Hotel()
{
	finalHotel = " ";
	finalCity = " ";
	finalStars = 0;
	finalCost = 0;
}

//sets the filename based on the destination of the user's choice
void Hotel::setFilename(string destination)
{
	filename = destination.append("Hotel.txt");
}

//set the chosen hotel based on the user's choice
void Hotel::setFinal(int index)
{
	finalHotel = FoundHotels[index];
	finalCity = FoundCity[index];
	finalStars = FoundStars[index];
	finalCost = FoundCost[index];
}

//search for hotel based on budget
void Hotel::Search()
{
	double objectBudget;
	cout << "What is the budget for hotel (price per night)? ";
	cin >> objectBudget;

	while (FoundCity.empty())
	{
		ifstream file(filename);
		string hotel, city;
		double stars, cost;

		while (!file.eof())
		{
			//reads the hotel name until gets to a tab and makes sure enter is not read at the beginning of the line
			getline(file, hotel, '\t');
			if (hotel[0] == '\n')
			{
				hotel = hotel.substr(1);
			}

			//if not end of the file, continue to read the rest of the file until the end
			if (!file.eof())
			{
				getline(file, city, '\t');
				if (!file.eof())
				{
					file >> stars >> cost;
					if (objectBudget >= cost)
					{
						//store found objects as a hotel vector (must be below the budget)
						FoundHotels.push_back(hotel);
						FoundCity.push_back(city);
						FoundStars.push_back(stars);
						FoundCost.push_back(cost);
					}
				}
			}
		}
		if (FoundCity.empty())
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
	for (int i = 0; i < FoundHotels.size(); i++)
	{
		cout << i << ". " << left << setw(width) << setfill(separator) << FoundHotels[i] 
			<< left << setw(width) << setfill (separator) << FoundCity[i] 
			<< left << setw(width) << setfill(separator) << FoundStars[i] 
			<<left << setw(width) << setfill(separator) << FoundCost[i] << endl;
	}
	cin >> choice;

	//set the final choice
	setFinal(choice);

	//clear the found vectors for next search
	FoundCity.clear();
	FoundCost.clear();
	FoundHotels.clear();
	FoundStars.clear();

}

//returns the cost of the object
double Hotel::getCost()
{
	return finalCost;
}

//prints the hotel information
void Hotel::printHotel()
{
	const int width = 35;
	const char separator = ' ';
	cout << left << setw(width) << setfill(separator) << finalHotel << left << setw(width) << setfill(separator)
		<< finalCity <<  finalStars << " stars"	<< setw(width) <<setfill(separator) << "$" << finalCost << left << setw(width) << setfill(separator) << endl;
}