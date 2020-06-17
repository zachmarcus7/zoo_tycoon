/****************************************************************
* File name:   newAnimal.cpp
* Assignment:  Project 2
* Author:      Zach Marcus
* Date:        7/15/2019
* Description: Implementation file for NewAnimal object. Unlike
*              other derived animal classes, constructor sets member
*              variables to zero, since it's user defined. A setter for
*              name is also added.
*****************************************************************/

#include "newAnimal.hpp"


/****************************************************************
* Default constructor for new animal object. Everything set to 0,
* since it's user-defined.
*****************************************************************/

NewAnimal::NewAnimal() : Animal()
{
	//set age to -1 as a placeholder
	//means animal hasn't been born yet
	this->age = 0;
	this->cost = 0;
	this->numberOfBabies = 0;
	this->baseFoodCost = 0;
	this->payoff = 0;
	this->name = "None.";
}


/****************************************************************
* Function that sets the name for a new animal object.
*****************************************************************/

void NewAnimal::setName(std::string name)
{
	this->name = name;
}
