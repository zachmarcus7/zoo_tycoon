/****************************************************************
* File name:   animal.hpp
* Assignment:  Project 2
* Author:      Zach Marcus
* Date:        7/13/2019
* Description: Specification file for animal class. It's the base
*              class that all the animals in the zoo are derived from.
*****************************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

//constant for base food cost
const double BASE = 10.00;

class Animal
{
	protected:
		int age;
		double cost;
		int numberOfBabies;
		double baseFoodCost;
		double payoff;

	public:
		Animal();
		int getAge() const;
		double getCost() const;
		int getNumberOfBabies() const;
		double getBaseFoodCost() const;
		double getPayoff() const;
		void addDay();

		void setAge(int);
		void setCost(double);
		void setBabies(int);
		void setBaseFood(double);
		void setPayoff(double);
};
#endif