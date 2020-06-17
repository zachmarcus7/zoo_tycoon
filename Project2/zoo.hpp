/****************************************************************
* File name:   zoo.hpp
* Assignment:  Project 2
* Author:      Zach Marcus
* Date:        7/13/2019
* Description: Specification file for zoo class. It's the main object
*              that's created when playing the Zoo Tycoon game. It has
*              all the required member variables and functions to set up
*              and play the game.
*****************************************************************/

#include <iostream>
#include <iomanip>
#include <climits>
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "newAnimal.hpp"

#ifndef Z00_H
#define ZOO_H

class Zoo
{
	private:
		int days;
		double bank;
		double totalFeedingCost;
		double profit;
		double bonus;
		int tigers;
		int penguins;
		int turtles;
		int tigerContainer;
		int penguinContainer;
		int turtleContainer;
		Tiger* tigersInZoo;
		Penguin* penguinsInZoo;
		Turtle* turtlesInZoo;

		//variables for extra credit
		NewAnimal* newAnimalsInZoo;
		bool newAnimal;
		int newAnimalContainer;
		int newAnimals;
		double newAnimalCost;
		int newAnimalBabies;
		double newAnimalBaseFood;
		double newAnimalPayoff;
		std::string newAnimalName;
		int feedType;


	public:
		Zoo();
		~Zoo();

		void addNewDay();

		double getBank() const;
		void addBank(double);
		void subtractBank(double);

		int getTigers() const;
		int getPenguins() const;
		int getTurtles() const;

		void addTiger(int);
		void addPenguin(int);
		void addTurtle(int);

		//prototypes for actual game simulation
		void startGame();
		int checkPrompt();
		int checkPromptToo(int, int);
		void startDay();
		void increaseAge();
		void payFeedingCost();
		void calculateProfit();
		bool endPrompt();

		//random event protoypes
		int randomNumber(int, int);
		void sickness();
		void boom();
		int birth();
		void selectRandomEvent();

		//extra credit function protoypes
		int getNewAnimals() const;
		void addNewAnimal(int);
		bool checkName(std::string);
};

#endif