/****************************************************************
* File name:   animal.cpp
* Assignment:  Project 2
* Author:      Zach Marcus
* Date:        7/13/2019
* Description: Implementation file for the animal class. It has
*              a default constructor, setters, and getters for
*              animal objects.
*****************************************************************/

#include "animal.hpp"


/****************************************************************
* Default constructor for animal object. All the member variables
* are initialized to 0.
*****************************************************************/

Animal::Animal()
{
	this->age = 0;
	this->cost = 0;
	this->numberOfBabies = 0;
	this->baseFoodCost = 0;
	this->payoff = 0;
}


/****************************************************************
* Getter for an animal's age.
*****************************************************************/

int Animal::getAge() const
{
	return this->age;
}


/****************************************************************
* Getter for an animal's cost.
*****************************************************************/

double Animal::getCost() const
{
	return this->cost;
}


/****************************************************************
* Getter for an animal's number of babies.
*****************************************************************/

int Animal::getNumberOfBabies() const
{
	return this->numberOfBabies;
}


/****************************************************************
* Getter for an animal's base food cost.
*****************************************************************/

double Animal::getBaseFoodCost() const
{
	return this->baseFoodCost;
}


/****************************************************************
* Getter for an animal's payoff.
*****************************************************************/

double Animal::getPayoff() const
{
	return this->payoff;
}


/****************************************************************
* Function that adds a day to an animal's age.
*****************************************************************/

void Animal::addDay()
{
	this->age += 1;
}


/****************************************************************
* Setter for an animal's age.
*****************************************************************/

void Animal::setAge(int age)
{
	this->age = age;
}


/****************************************************************
* Setter for an animal's cost.
*****************************************************************/

void Animal::setCost(double cost)
{
	this->cost = cost;
}


/****************************************************************
* Setter for the amount of babies an animal has.
*****************************************************************/

void Animal::setBabies(int babies)
{
	this->numberOfBabies = babies;
}


/****************************************************************
* Setter for an animal's base food cost.
*****************************************************************/

void Animal::setBaseFood(double baseFoodCost)
{
	this->baseFoodCost = baseFoodCost;
}


/****************************************************************
* Setter for an animal's payoff.
*****************************************************************/

void Animal::setPayoff(double payoff)
{
	this->payoff = payoff;
}