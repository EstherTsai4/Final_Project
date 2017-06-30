#pragma once
#include <string>
using namespace std;


class Hotel
{
private:
	string filename;
	string finalHotel, finalCity;
	double finalStars, finalCost;

	vector <string> FoundHotels;
	vector <string> FoundCity;
	vector <double> FoundStars;
	vector <double> FoundCost;

public:
	Hotel();

	//set filename based on destination
	void setFilename(string destination);

	//gets the final choice based on the number the user picks
	void setFinal(int index);

	//searches for hotel choices under the user's budget
	void Search();

	//prints hotel information
	void printHotel();

	//gets the cost
	double getCost();
};