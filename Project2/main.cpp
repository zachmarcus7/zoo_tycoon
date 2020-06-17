/****************************************************************
* File name:   main.cpp
* Assignment:  Project 2
* Author:      Zach Marcus
* Date:        7/13/2019
* Description: Main file for Zoo Tycoon game. Player starts with 
*              100,000 in bank and chooses 1 or 2 of each animals.
*              Extra credit added for adding a user-specified animal.
*              Extra credit also added for choosing feed type.
*              A random event then occurs, and end of day stats are shown
*              before user chooses to move on to next day or quit.
*****************************************************************/

#include "animal.hpp"
#include "penguin.hpp"
#include "tiger.hpp"
#include "turtle.hpp"
#include "newAnimal.hpp"
#include "zoo.hpp"
#include <ctime>
#include <climits>
#include <cstdlib>


int main()
{
	//start the srand seed for functions that return a random number
	//citation: formula provided in cs 161 for finding a random number
	srand(static_cast<unsigned int>(time(NULL)));

	//initiate zoo object
	Zoo zoo1;

	//flag to end game
	bool gameOver = false;

	zoo1.startGame();

	while (gameOver == false)
	{
		zoo1.startDay();
		zoo1.selectRandomEvent();
		zoo1.calculateProfit();
		gameOver = zoo1.endPrompt();
	}
}