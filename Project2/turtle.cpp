/****************************************************************
* File name:   penguin.cpp
* Assignment:  Project 2
* Author:      Zach Marcus
* Date:        7/13/2019
* Description: Implementation file for turtle class.
*****************************************************************/

#include "turtle.hpp"


/****************************************************************
* Default constructor for turtle object.
*****************************************************************/

Turtle::Turtle() : Animal()
{
	//set age to -1 as a placeholder
	//means animal hasn't been born yet
	this->age = -1;
	this->cost = 100.00;
	this->numberOfBabies = 10;
	this->baseFoodCost = BASE * .50;
	this->payoff = 5;
}