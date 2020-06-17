/****************************************************************
* File name:   newAnimal.hpp
* Assignment:  Project 2
* Author:      Zach Marcus
* Date:        7/15/2019
* Description: Specification file for a new animal object that's 
*              user-defined. Unlike other derived animal classes,
*              it has a variable for name, and a function to set name.
*****************************************************************/

#include "animal.hpp"
#include <string>

#ifndef NEW_ANIMAL_H
#define NEW_ANIMAL_H

class NewAnimal : public Animal
{
private:
	std::string name;
public:
	NewAnimal();
	void setName(std::string);
};
#endif
