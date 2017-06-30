#pragma once
#include <iostream>
#include <string>
#include "Airline.h"
#include "Food.h"
#include "Hotel.h"
#include "ThingsToDo.h"

using namespace std;

class TripPlanner
{
private:
	string destination;
	double budget;
	double EstCost;
	int numberOfDays;

	//store chosen objects in vectors
	Airline airplaneTicket;
	vector <Food> restaurant;
	Hotel hotel;
	vector <ThingsToDo> activities;
public:

	TripPlanner();

	//tripPlanner constructor with argument
	TripPlanner(Airline ticket, Hotel hotel, Food restaurant, ThingsToDo activities, string destination, double budget, int numberOfDays);
	
	//set number of days
	void setDays(int numberOfDays);

	//get number of days
	int getDays();

	//set the budget
	void setBudget(double budget);

	//returns budget
	double getbudget();

	//sets the estimated cost total
	void setTotal(double cost);

	//returns the estimated cost total
	double getTotal();

	//sets the user destination choice
	void setDestination(string destination);

	//returns the user destination choice
	string getDestination();

	//lets user choose destination
	void DestinationMenu();
	
	//sets airline, hotel, food, and thingstodo
	void setAirline(Airline ticket);
	void setHotel(Hotel hotel);
	void setFood(Food restaurant);
	void setActivities(ThingsToDo activities);

	//calculate trip total cost
	double calcCost();

	//print out the trip summary
	void printSummary();

	//compare the budget with the estimated total cost
	bool compareCost();

	//change objects if over budget
	void underBudget(int index);
	
	//lets user rechoose certain objects
	void resetAirplane();
	void resetHotel();
	void resetFood();
	void resetActivities();

};

//compares the string cost values
bool operator>=(const double budget, string cost);

//create operator to add costs of objects to get total cost
void operator+(double& total, string cost);

//clears the screen
void clearScreen();