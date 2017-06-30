#include <iostream>
#include <string>
#include <string>
#include <vector>
#include "TripPlanner.h"
#include "Food.h"
#include "Airline.h"
#include "Hotel.h"
#include "ThingsToDo.h"
using namespace std;


TripPlanner::TripPlanner()
{
	destination = " ";
	budget = 0;
	EstCost = 0;
	numberOfDays = 0;
}

//constructor with argument
TripPlanner::TripPlanner(Airline ticket, Hotel hotel, Food restaurant, ThingsToDo activities, string destination, double budget, int numberOfDays)
{
	EstCost = calcCost();
	this->destination = destination;
	this->budget = budget;
	this->airplaneTicket = ticket;
	this->hotel = hotel;
	this->restaurant.push_back(restaurant);
	this->activities.push_back(activities);
	this->numberOfDays = numberOfDays;
}

//set the number of days
void TripPlanner::setDays(int numberOfDays)
{
	this->numberOfDays = numberOfDays;
}

//returns the number of days
int TripPlanner::getDays()
{
	return numberOfDays;
}

//set the budget
void TripPlanner::setBudget(double budget)
{
	this->budget = budget;
}

//returns budget
double TripPlanner::getbudget()
{
	return budget;
}

//sets the cost
void TripPlanner::setTotal(double estCost)
{
	EstCost = estCost;
}

//returns the cost
double TripPlanner::getTotal()
{
	return EstCost;
}

//sets the user destination choice
void TripPlanner::setDestination(string destination)
{
	this->destination = destination;
}

//returns the user destination choice
string TripPlanner::getDestination()
{
	return destination;
}

//lets user choose destination
void TripPlanner::DestinationMenu()
{
	int destination;

	//ask user what continent they would like to go to
	cout << "Which continent would you like to go to? " << endl;
	cout << "1) Asia" << endl;
	cout << "2) Europe" << endl;
	cout << "3) Africa" << endl;
	cout << "4) North America" << endl;
	cout << "5) South America" << endl;
	cout << "6) Australia" << endl;
	cin >> destination;

	//based on continent choice, ask what country they would like to go to
	switch (destination)
	{
	case 1:
		cout << "Which country would you like to go to? " << endl;
		cout << "1) Korea" << endl;
		cout << "2) Taiwan" << endl;
		cin >> destination;
		if (destination == 1)
		{
			setDestination("Korea");
		}
		else
		{
			setDestination("Taiwan");
		}
		break;
	case 2:
		cout << "Which country would you like to go to? " << endl;
		cout << "1) France" << endl;
		cout << "2) UK" << endl;
		cin >> destination;
		if (destination == 1)
		{
			setDestination("France");
		}
		else
		{
			setDestination("UK");
		}
		break;
	case 3:
		cout << "Which country would you like to go to? " << endl;
		cout << "1) Nigeria" << endl;
		cout << "2) Morocco" << endl;
		cin >> destination;
		if (destination == 1)
		{
			setDestination("Nigeria");
		}
		else
		{
			setDestination("Morocco");
		}
		break;
	case 4:
		cout << "Which country would you like to go to? " << endl;
		cout << "1) Canada" << endl;
		cout << "2) Mexico" << endl;
		cin >> destination;
		if (destination == 1)
		{
			setDestination("Canada");
		}
		else
		{
			setDestination("Mexico");
		}
		break;
	case 5:
		cout << "Which country would you like to go to? " << endl;
		cout << "1) Brazil" << endl;
		cout << "2) Paraguay" << endl;
		cin >> destination;
		if (destination == 1)
		{
			setDestination("Brazil");
		}
		else
		{
			setDestination("Paraguay");
		}
		break;
	case 6:
		setDestination("Australia");
		break;
	}
}

//sets airline, hotel, food, and thingstodo
void TripPlanner::setAirline(Airline ticket)
{
	this->airplaneTicket = ticket;
}

void TripPlanner::setHotel(Hotel hotel)
{
	this->hotel = hotel;
}

void TripPlanner::setFood(Food restaurant)
{
	this->restaurant.push_back(restaurant);
}

void TripPlanner::setActivities(ThingsToDo activities)
{
	this->activities.push_back(activities);
}

//print out the trip summary
void TripPlanner::printSummary()
{
	cout << "Your trip to " << destination << endl;
	cout << "Your budget is: $" << budget << endl;
	cout << string(2, '\n');

	//get airline ticket info
	cout << "Airplane ticket information: " << endl;
	airplaneTicket.printTicket();
	cout << string(2, '\n');

	//get hotel info
	cout << "Hotel information: " << endl;
	hotel.printHotel();
	cout << string(2, '\n');

	//get restaurants info
	cout << "Picked restaurants: " << endl;
	cout << endl;
	for (int i = 0; i < restaurant.size(); i++)
	{
		restaurant[i].printRestaurants();
		cout << endl;
	}
	cout << string(2, '\n');

	//get activity info
	cout << "Picked activities: " << endl;
	cout << endl;
	for (int i = 0; i < activities.size(); i++)
	{
		activities[i].printActivities();
		cout << endl;
	}
	cout << string(2, '\n');

	//display the estimate cost
	cout << "The estimated trip cost is: $" << calcCost() << endl;
	cout << string(2, '\n');

	//compare the total cost with the budget
	compareCost();
}

//calculate the estimated cost
double TripPlanner::calcCost()
{
	double estCost;
	int numberOfDays = activities.size();

	//add the costs of ticket and hotel
	estCost = airplaneTicket.getCost() + (hotel.getCost() * numberOfDays);

	//convert the cost of restaurant and activities from string to double using operator
	for (int i = 0; i < restaurant.size(); i++)
	{
		estCost + restaurant[i].getCost();
		estCost + activities[i].getCost();
	}
	setTotal(estCost);

	return estCost;
}

//compares the estimated total cost with the budget
bool TripPlanner::compareCost()
{
	if (budget < EstCost)
	{
		return false;
	}
	else if (budget >= EstCost)
	{
		return true;
	}

}

//lets user choose which object they would like to reset
void TripPlanner::underBudget(int index)
{
	if (index == 1)
	{
		resetAirplane();
	}
	else if (index == 2)
	{
		resetHotel();
	}
	else if (index == 3)
	{
		resetFood();
	}
	else if (index == 4)
	{
		resetActivities();
	}

	printSummary();
	compareCost();
}

//allows user to reset the airplane ticket
void TripPlanner::resetAirplane()
{
	Airline temp;
	temp.setFilename(getDestination());
	temp.Search();
	setAirline(temp);
}

//allows user to reset the hotel choice
void TripPlanner::resetHotel()
{
	Hotel temp;
	temp.setFilename(getDestination());
	temp.Search();
	setHotel(hotel);
}

//allows user to reset the food choices
void TripPlanner::resetFood()
{
	//clears the vector with food choices and creates temp object to store choices
	restaurant.clear();
	Food temp;
	temp.setFilename(getDestination());

	for (int i = 0; i < numberOfDays; i++)
	{
		temp.Search();
		setFood(temp);
	}
}

//allows user to reset the activities
void TripPlanner::resetActivities()
{
	//clears the vector with activity choices and creates temp object to store choices
	activities.clear();
	ThingsToDo temp;
	temp.setFilename(getDestination());

	for (int i = 0; i < numberOfDays; i++)
	{
		temp.Search();
		setActivities(temp);
	}

}


//compares the string costs with a double budget
bool operator>=(const double budget, string cost)
{
	int estCost = 0;

	//sets the estimated cost based on the number of dollar signs (size of the string)
	if (cost.size() == 1)
	{
		estCost = 5;
	}
	else if (cost.size() == 2)
	{
		estCost = 15;
	}
	else if (cost.size() == 3)
	{
		estCost = 25;
	}
	else if (cost.size() == 4 && cost == "$$$$")
	{
		estCost = 75;
	}
	else
	{
		estCost = 0;
	}

	//compare the numerical cost
	if (budget >= estCost)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//adds the string costs to a double total
void operator+ (double& total, string cost)
{
	if (cost == "$")
	{
		total += 5;
	}
	else if (cost == "$$")
	{
		total += 15;
	}
	else if (cost == "$$$")
	{
		total += 25;
	}
	else if (cost == "$$$$")
	{
		total += 75;
	}
	else
	{
		total += 0;
	}
}

//clears the screen by scrolling
void clearScreen()
{
	cout << string(50, '\n');
}
