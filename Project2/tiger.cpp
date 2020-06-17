/****************************************************************
* File name:   tiger.cpp
* Assignment:  Project 2
* Author:      Zach Marcus
* Date:        7/13/2019
* Description: Implementation file for tiger class.
*****************************************************************/

#include "tiger.hpp"


/****************************************************************
* Default constructor for tiger object.
*****************************************************************/

Tiger::Tiger() : Animal()
{
	//set age to -1 as a placeholder
	//means animal hasn't been born yet
	this->age = -1;
	this->cost = 10000.00;
	this->numberOfBabies = 1;
	this->baseFoodCost = BASE * 5;
	this->payoff = 2000;
}