#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

class Airline
{
private:
	string filename;
	string finalCompany, finalClass;
	int finalStops;
	double finalCost;

	vector <string> Foundcompany;
	vector <string> FoundseatClass;
	vector <int> FoundnumberOfStops;
	vector <double> Foundcost;

public:
	//constructor without argument
	Airline();

	//Constructor with argument
	void setFinal(int index);

	//get the filename based on the destination
	void setFilename(string destination);
	string getFilename();

	//gets the index of the choice the user wants and stores the 
	void Search();

	//prints info
	void printTicket();

	//gets the cost
	double getCost();
};