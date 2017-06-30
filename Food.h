#pragma once
#include <string>
#include <cstdbool>
#include <sstream>
using namespace std;

class Food
{
private:
	string filename;
	string FinalName, FinalCity, FinalCost;

	vector <string> FoundNames;
	vector <string> FoundCity;
	vector <string> FoundCost;

public:
	//constructor without argument
	Food();

	//sets filename based on the destination of the user's choice
	void setFilename(string destination);

	//searches for food choices that matches the user's budget
	void Search();

	//sets the final choice of the user based on the user's choice
	void setFinal(int index);

	//returns the string cost of the 
	string getCost();

	//prints out the information of the restaurant
	void printRestaurants();
};
