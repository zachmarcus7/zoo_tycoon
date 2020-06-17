/****************************************************************
* File name:   penguin.cpp
* Assignment:  Project 2
* Author:      Zach Marcus
* Date:        7/13/2019
* Description: Implementation file for penguin class.
*****************************************************************/

#include "penguin.hpp"


/****************************************************************
* Default constructor for penguin object.
*****************************************************************/

Penguin::Penguin() : Animal()
{
	//set age to -1 as a placeholder
	//means animal hasn't been born yet
	this->age = -1;
	this->cost = 1000.00;
	this->numberOfBabies = 5;
	this->baseFoodCost = BASE;
	this->payoff = 100;
}