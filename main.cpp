#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "TripPlanner.h"
#include "Airline.h"
#include "Food.h"
#include "Hotel.h"
#include "ThingsToDo.h"


using namespace std;

int main()
{
	//Ask user to enter in their name
	string name;
	cout << "Enter your name: ";
	cin >> name;

	cout << "Welcome to your TripPlanner, " << name << endl;
	
	//call up menu with available continents to have user to choose destination of choice
	TripPlanner trip;
	trip.DestinationMenu();
	
	//ask budget
	double budget;
	cout << "What is your budget? ";
	cin >> budget;
	trip.setBudget(budget);

	//ask how many days they would like to spend
	int numberOfDays;
	cout << "How many days are you staying? ";
	cin >> numberOfDays;
	trip.setDays(numberOfDays);

	//call function to set airline file based on destination
	Airline ticket;
	ticket.setFilename(trip.getDestination());

	//call function to search for airlines that meets budget and print out the choices
	ticket.Search();
	trip.setAirline(ticket);
	clearScreen();

	//call function to set hotel file based on destination
	Hotel hotel;
	hotel.setFilename(trip.getDestination());

	//call function to search for hotel that meets budget and print out the choices and ask user to enter choice
	hotel.Search();
	trip.setHotel(hotel);
	clearScreen();

	//call function to set food file based on destination
	Food food;
	food.setFilename(trip.getDestination());
	
	//call function to search for restaurants the meets budget and print out the choices and ask user to enter choice
	cout << "For each of the " << numberOfDays << " days you will stay, please choose a restaurant: " << endl;
	
	for (int i = 0; i < numberOfDays; i++)
	{
		food.Search();
		trip.setFood(food);
	}

	clearScreen();

	//call function to set activities file based on destination
	ThingsToDo activities;
	activities.setFilename(trip.getDestination());

	//call function to search for activities that meets budget and print out the choices and ask user to enter choice
	cout << "For each of the " << numberOfDays << " days that you will stay, please choose an activity: " << endl;

	for (int i = 0; i < numberOfDays; i++)
	{
		activities.Search();
		trip.setActivities(activities);
	}

	clearScreen();

	//get the total cost of the created trip as well as the comparison with the budget
	trip.printSummary();

	//while the total cost of the trip is greater than the budget, have the user choose the category they want to change
	while (!trip.compareCost())
	{
		int choice;

		cout << "Your planned trip is above your budget. What category would you like to change? " << endl;
		cout << "1) Airplane ticket" << endl;
		cout << "2) Hotel" << endl;
		cout << "3) Restaurants" << endl;
		cout << "4) Activities" << endl;
		cin >> choice;

		//call function to change an object
		trip.underBudget(choice);
	}

	return 0;
}