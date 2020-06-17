/****************************************************************
* File name:   zoo.cpp
* Assignment:  Project 2
* Author:      Zach Marcus
* Date:        7/13/2019
* Description: Implementation file for zoo class. It contains all the
* necessary functions for setting up the Zoo Tycoon game and also
* going through the events of the game. There's one main default 
* constructor and destructor. The rest of the functions are split into
* groups: bank functions, getters, adding animals, start of game functions,
* random event functions, end of day functions, and extra credit functions.
*****************************************************************/

#include "zoo.hpp"


/****************************************************************
* Default constructor for zoo object. Bank is set at 100,000. 
* Animal containers set to 10. Arrays initialized to 10 objects.
* Everything else set to 0.
*****************************************************************/

Zoo::Zoo()
{
	this->days = 0;
	this->bank = 100000;
	this->totalFeedingCost = 0;
	this->bonus = 0;
	this->profit = 0;
	this->tigers = 0;
	this->penguins = 0;
	this->turtles = 0;
	this->tigerContainer = 10;
	this->penguinContainer = 10;
	this->turtleContainer = 10;
	tigersInZoo = new Tiger[10];
	penguinsInZoo = new Penguin[10];
	turtlesInZoo = new Turtle[10];

	//extra credit variables
	newAnimalsInZoo = new NewAnimal[10];
	this->newAnimal = false;
	this->newAnimalContainer = 10;
	this->newAnimals = 0;
	this->newAnimalCost = 0.0;
	this->newAnimalBabies = 0;
	this->newAnimalBaseFood = 0.0;
	this->newAnimalPayoff = 0.0;
	this->newAnimalName = "None";
	this->feedType = 0;
}

/****************************************************************
* Destructor for zoo object.
*****************************************************************/

Zoo::~Zoo()
{
	delete[] tigersInZoo;
	delete[] penguinsInZoo;
	delete[] turtlesInZoo;
	delete[] newAnimalsInZoo;
}


/* bank functions */

/****************************************************************
* Function that returns the amount of money in bank.
*****************************************************************/

double Zoo::getBank() const
{
	return bank;
}

/****************************************************************
* Function that adds money to bank. Parameter is amount of money to 
* add as a double.
*****************************************************************/

void Zoo::addBank(double add)
{
	bank += add;
}

/****************************************************************
* Function that subtracts money from bank. Parameter is amount of money to
* subtract as a double.
*****************************************************************/

void Zoo::subtractBank(double subtract)
{
	bank -= subtract;
}


/* animal getters */

/****************************************************************
* Getter for amount of tigers in zoo.
*****************************************************************/

int Zoo::getTigers() const
{
	return tigers;
}

/****************************************************************
* Getter for amount of penguins in zoo.
*****************************************************************/

int Zoo::getPenguins() const
{
	return penguins;
}

/****************************************************************
* Getter for amount of turtles in zoo.
*****************************************************************/

int Zoo::getTurtles() const
{
	return turtles;
}


/* functions for adding animals */

/****************************************************************
* Function that adds a new tiger to the zoo.
*****************************************************************/

void Zoo::addTiger(int age)
{
	tigers++;
	
	//double array size if not enough room
	if (tigers > tigerContainer)
	{
		tigerContainer *= 2;

		//create a temp array to store current tigers in
		Tiger* temp = new Tiger[tigerContainer];

		for (int i = 0; i < (tigers - 1); i++)
			temp[i] = tigersInZoo[i];

		//deallocate original tiger array
		delete[] tigersInZoo;

		//assign temp array to original 
		//for (int i = 0; i < tigerContainer; i++)
			tigersInZoo = temp;

		//delete the temp array
		//delete[] temp;
	}

	//set the new tiger's age
	tigersInZoo[getTigers() - 1].setAge(age);

	//subtract the cost of the tiger from the bank
	subtractBank(10000.00);

	//increment the feeding cost
	totalFeedingCost += tigersInZoo[getTigers() - 1].getBaseFoodCost();
}

/****************************************************************
* Function that adds a new penguin to the zoo.
*****************************************************************/

void Zoo::addPenguin(int age)
{                                                                              
	penguins++;                                                               

	//double array size if not enough room                                    
	if (penguins > penguinContainer)
	{
		penguinContainer *= 2;

		//create a temp array to store current penguins in
		Penguin* temp = new Penguin[penguinContainer];                         

		for (int i = 0; i < (penguins - 1); i++)                                  
			temp[i] = penguinsInZoo[i];                                           

		//deallocate original tiger array
		delete[] penguinsInZoo;

		//assign temp array to original 
		//for (int i = 0; i < penguinContainer; i++)
			penguinsInZoo= temp;

		//delete the temp array
		//delete[] temp;
	}

	//set the new penguin's age
	penguinsInZoo[getPenguins() - 1].setAge(age);                                

	//subtract the cost of the penguin from the bank
	subtractBank(1000.00);

	//increment the feeding cost
	totalFeedingCost += penguinsInZoo[getPenguins() - 1].getBaseFoodCost();
}

/****************************************************************
* Function that adds a new turtle to the zoo.
*****************************************************************/

void Zoo::addTurtle(int age)
{
	turtles++;

	//double array size if not enough room
	if (turtles > turtleContainer)
	{
		turtleContainer *= 2;

		//create a temp array to store current turtles in
		Turtle* temp = new Turtle[turtleContainer];

		for (int i = 0; i < (turtles - 1); i++)
			temp[i] = turtlesInZoo[i];

		//deallocate original turtle array
		delete[] turtlesInZoo;

		//assign temp array to original 
		//for (int i = 0; i < turtleContainer; i++)
			turtlesInZoo = temp;

		//delete the temp array
		//delete[] temp;
	}

	//set the new turtle's age
	turtlesInZoo[getTurtles() - 1].setAge(age);

	//subtract the cost of the turtle from the bank
	subtractBank(100.00);

	//increment the feeding cost
	totalFeedingCost += turtlesInZoo[getTurtles() - 1].getBaseFoodCost();
}


/* start of game functions */

/****************************************************************
* Function that executes at start of game. Asks user to buy
* animals until they have 1 or 2 of each type.
*****************************************************************/

void Zoo::startGame()
{
	//temp int for selection
	int answer;

	std::cout << "::: Zoo Tycoon :::" << std::endl;
	std::cout << "Starting money in bank: " << getBank() << std::endl;

	std::cout << "How many tigers would you like to buy?" << std::endl;
	std::cout << "(1) for one" << std::endl;
	std::cout << "(2) for two" << std::endl;
	std::cout << "Enter Value:" << std::endl;

	//validate input
	answer = checkPrompt();

	if (answer == 1)
		addTiger(1);
	else
	{
		addTiger(1);
		addTiger(1);
	}

	std::cout << "How many penguins would you like to buy?" << std::endl;
	std::cout << "(1) for one" << std::endl;
	std::cout << "(2) for two" << std::endl;
	std::cout << "Enter Value:" << std::endl;

	//validate input
	answer = checkPrompt();

	if (answer == 1)
		addPenguin(1);
	else
	{
		addPenguin(1);
		addPenguin(1);
	}

	std::cout << "How many turtles would you like to buy?" << std::endl;
	std::cout << "(1) for one" << std::endl;
	std::cout << "(2) for two" << std::endl;
	std::cout << "Enter Value:" << std::endl;

	//validate input
	answer = checkPrompt();

	if (answer == 1)
		addTurtle(1);
	else
	{
		addTurtle(1);
		addTurtle(1);
	}

	//extra credit: ask if user would like to create a new animal to
	//add to the zoo

	std::cout << "extra credit: Would like to add a new animal to the zoo?" << std::endl;
	std::cout << "(1) for yes" << std::endl;
	std::cout << "(2) for no" << std::endl;
	std::cout << "Enter Value:" << std::endl;

	//validate input
	answer = checkPrompt();

	if (answer == 1)
	{
		newAnimal = true;

		//make sure user only enters characters for name
		bool nameCheck = false;
		std::string tempName = " ";
		while (nameCheck == false)
		{
			std::cout << "Enter name of animal:" << std::endl;
			std::cout << "Please enter only characters." << std::endl;
			std::getline(std::cin, tempName);
			nameCheck = checkName(tempName);
		}
		newAnimalName = tempName;

		std::cout << "Enter cost of animal:" << std::endl;
		newAnimalCost = static_cast<double>(checkPromptToo(0, INT_MAX));
		std::cout << "Enter the amount of babies the animal has:" << std::endl;
		newAnimalBabies = checkPromptToo(0, INT_MAX);
		std::cout << "Enter base food cost of animal:" << std::endl;
		newAnimalBaseFood = static_cast<double>(checkPromptToo(0, INT_MAX));
		std::cout << "Enter payoff of animal:" << std::endl;
		newAnimalPayoff = static_cast<double>(checkPromptToo(0, INT_MAX));

		int answerTwo = 0;

		std::cout << "How many " << newAnimalName << "s would you like to buy?" << std::endl;
		std::cout << "(1) for one" << std::endl;
		std::cout << "(2) for two" << std::endl;
		std::cout << "Enter Value:" << std::endl;

		answerTwo = checkPrompt();

		if (answerTwo == 1)
			addNewAnimal(1);
		else
		{
			addNewAnimal(1);
			addNewAnimal(1);
		}
	}
	else
	{
		newAnimal = false;
		std::cout << "No new animal added to zoo." << std::endl;
	}

}

/****************************************************************
* Function that checks if the user entered a 1 or a 2.
*****************************************************************/

int Zoo::checkPrompt()
{
	int answer = 0;

	std::cin >> std::setw(1) >> answer;

	while ((!std::cin.good()) || ((!(answer == 1)) && (!(answer == 2))))
	{
		std::cout << "Invalid value entered." << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Enter correct value:" << std::endl;
		//make sure only one integer is accepted
		std::cin >> std::setw(1) >> answer;
	}

	//clear the buffer
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');

	return answer;
}

/****************************************************************
* Function that checks if the user entered a number between min and max.
*****************************************************************/

int Zoo::checkPromptToo(int min, int max)
{
	int answer = 0;

	std::cin >> std::setw(1) >> answer;

	while ((!std::cin.good()) || (!(answer >= min)) || (!(answer <= max)))
	{
		std::cout << "Invalid value entered." << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Enter correct value:" << std::endl;
		//make sure only one integer is accepted
		std::cin >> std::setw(1) >> answer;
	}

	//clear the buffer
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');

	return answer;
}

/****************************************************************
* Function that executes at start of day.
*****************************************************************/

void Zoo::startDay()
{
	days++;
	std::cout << "::: Day " << days << " :::" << std::endl;
	increaseAge();
	std::cout << "All animals are now one day older." << std::endl;

	//extra credit: see which feed type user wants to purchase for the day
	std::cout << "extra credit: which type of feed would you like to purchase for the day?" << std::endl;
	std::cout << "(1) to buy cheap" << std::endl;
	std::cout << "(2) to buy generic" << std::endl;
	std::cout << "(3) to buy premium" << std::endl;
	std::cout << "Enter option: " << std::endl;
	feedType = checkPromptToo(1, 3);

	payFeedingCost();
}

/****************************************************************
* Function that increases the age of each animal by a day. Executed
* at the start of each day.
*****************************************************************/

void Zoo::increaseAge()
{
	//increase the age of all the tigers
	for (int i = 0; i < tigers; i++)
		tigersInZoo[i].addDay();

	//increase the age of all the penguins
	for (int i = 0; i < penguins; i++)
		penguinsInZoo[i].addDay();

	//increase the age of all the turtles
	for (int i = 0; i < turtles; i++)
		turtlesInZoo[i].addDay();
}

/****************************************************************
* Function that pays the total feeding cost for all the animals.
*****************************************************************/

void Zoo::payFeedingCost()
{
	
	if (feedType == 1)
		subtractBank(totalFeedingCost / 2); //cheap
	else if (feedType == 2)
		subtractBank(totalFeedingCost);     //generic
	else 
		subtractBank(totalFeedingCost * 2); //premium

	std::cout << "Feeding cost paid for the day: " << totalFeedingCost << std::endl;
	
}


/* random event functions */

/****************************************************************
* Function for generating a random number.
*****************************************************************/

int Zoo::randomNumber(int max, int min)
{
	//return a random integer between max and min
	//citation: formula provided in cs 161 for finding a random number
	return (rand() % max + min);
}

/****************************************************************
* Function that removes one animal object from the zoo.
*****************************************************************/

void Zoo::sickness()
{

	if (newAnimal == false)
	{
		int random = randomNumber(3, 1);

		if (random == 1)
		{
			if (tigers > 0)
			{
				std::cout << "One of the tigers became sick and died." << std::endl;

				//remove the tiger from the array
				//by resetting that object's age back to 0
				tigersInZoo[tigers - 1].setAge(0);

				tigers--;

				std::cout << "There are now " << getTigers() << " tigers in the zoo." << std::endl;
			}
			else
				std::cout << "All the tigers have already died from sickness." << std::endl;
		}
		else if (random == 2)
		{
			if (penguins > 0)
			{
				std::cout << "One of the penguins became sick and died." << std::endl;

				//remove the penguin from the array
				//by resetting that object's age back to 0
				penguinsInZoo[penguins - 1].setAge(0);

				penguins--;

				std::cout << "There are now " << getPenguins() << " penguins in the zoo." << std::endl;
			}
			else
				std::cout << "All the penguins have already died from sickness." << std::endl;

		}
		else
		{
			if (turtles > 0)
			{
				std::cout << "One of the turtles became sick and died." << std::endl;

				//remove the turtle from the array
				//by resetting that object's age back to 0
				turtlesInZoo[turtles - 1].setAge(0);

				turtles--;

				std::cout << "There are now " << getTurtles() << " turtles in the zoo." << std::endl;
			}
			else
				std::cout << "All the turtles have already died from sickness." << std::endl;
		}
	}
	else //if the user selected to input a new animal
	{
		int random = randomNumber(4, 1);

		if (random == 1)
		{
			if (tigers > 0)
			{
				std::cout << "One of the tigers became sick and died." << std::endl;

				//remove the tiger from the array
				//by resetting that object's age back to 0
				tigersInZoo[tigers - 1].setAge(0);

				tigers--;

				std::cout << "There are now " << getTigers() << " tigers in the zoo." << std::endl;
			}
			else
				std::cout << "All the tigers have already died from sickness." << std::endl;
		}
		else if (random == 2)
		{
			if (penguins > 0)
			{
				std::cout << "One of the penguins became sick and died." << std::endl;

				//remove the penguin from the array
				//by resetting that object's age back to 0
				penguinsInZoo[penguins - 1].setAge(0);

				penguins--;

				std::cout << "There are now " << getPenguins() << " penguins in the zoo." << std::endl;
			}
			else
				std::cout << "All the penguins have already died from sickness." << std::endl;

		}
		else if (random == 3)
		{
			if (turtles > 0)
			{
				std::cout << "One of the turtles became sick and died." << std::endl;

				//remove the turtle from the array
				//by resetting that object's age back to 0
				turtlesInZoo[turtles - 1].setAge(0);

				turtles--;

				std::cout << "There are now " << getTurtles() << " turtles in the zoo." << std::endl;
			}
			else
				std::cout << "All the turtles have already died from sickness." << std::endl;
		}
		else 
		{
			if (newAnimals > 0)
			{
				std::cout << "One of the " << newAnimalName << "s became sick and died." << std::endl;

				//remove the newAnimal from the array
				//by resetting that object's age back to 0
				newAnimalsInZoo[newAnimals - 1].setAge(0);

				newAnimals--;

				std::cout << "There are now " << newAnimals << " " << newAnimalName << "s in the zoo." << std::endl;
			}
			else
				std::cout << "All the" << newAnimalName << "s have already died from sickness." << std::endl;
		}
	}
}

/****************************************************************
* Function that generates a random bonus between 250 and 500 dollars
* for each tiger in the zoo. Gets added to the total payoff of the day
* as a reward.
*****************************************************************/

void Zoo::boom()
{
	int boomBonus = 0;

	//generate random bonus for each tiger in zoo
	for (int i = 0; i < tigers; i++)
		boomBonus += ((rand() % (500 - 250 + 1)) + 250);

	std::cout << "There was a boom in ticket sales for tigers." << std::endl;
	std::cout << boomBonus  << " added to total payoff for the day." << std::endl;

	bonus += boomBonus;
}

/****************************************************************
* Function that picks an animal at random to have a baby. If no 
* animal of selected type is old enough, a new animal is chosen. 
*****************************************************************/

int Zoo::birth()
{
	if (newAnimal == false)
	{
		int random = randomNumber(3, 1);

		//checker to see if one of the animals is old enough 
		bool checker = false;

		if (random == 1)
		{
			//check if any tigers are old enough
			for (int i = 0; i < tigers; i++)
			{
				if (tigersInZoo[i].getAge() >= 3)
				{
					checker = true;
					break;
				}
			}

			if (checker == true)
			{
				addTiger(0);
				std::cout << "A baby tiger was born." << std::endl;
				std::cout << "There are now " << tigers << " tigers in the zoo." << std::endl;
				return 0;
			}
		}
		else if (random == 2)
		{
			//check if any penguins are old enough
			for (int i = 0; i < penguins; i++)
			{
				if (penguinsInZoo[i].getAge() >= 3)
				{
					checker = true;
					break;
				}
			}

			if (checker == true)
			{
				for (int i = 0; i < 5; i++)
					addPenguin(0);

				std::cout << "Five baby penguins were born." << std::endl;
				std::cout << "There are now " << penguins << " penguins in the zoo." << std::endl;
				return 0;
			}
		}
		else
		{
			//check if any turtles are old enough
			for (int i = 0; i < turtles; i++)
			{
				if (turtlesInZoo[i].getAge() >= 3)
				{
					checker = true;
					break;
				}
			}

			if (checker == true)
			{
				for (int i = 0; i < 10; i++)
					addTurtle(0);

				std::cout << "Ten baby turtles were born." << std::endl;
				std::cout << "There are now " << turtles << " turtles in the zoo." << std::endl;
				return 0;
			}
		}

		//check to see if the randomly selected animal gave birth
		if (checker == false)
		{
			//second checker
			bool checkerToo = false;

			//check if any tigers are old enough
			for (int i = 0; i < tigers; i++)
			{
				if (tigersInZoo[i].getAge() >= 3)
				{
					checkerToo = true;
					break;
				}
			}

			if (checkerToo == true)
			{
				addTiger(0);
				std::cout << "A baby tiger was born." << std::endl;
				std::cout << "There are now " << tigers << " tigers in the zoo." << std::endl;
				return 0;
			}

			//check if any penguins are old enough
			for (int i = 0; i < penguins; i++)
			{
				if (penguinsInZoo[i].getAge() >= 3)
				{
					checkerToo = true;
					break;
				}
			}

			if (checkerToo == true)
			{
				for (int i = 0; i <= 5; i++)
					addPenguin(0);

				std::cout << "Five baby penguins were born." << std::endl;
				std::cout << "There are now " << penguins << " penguins in the zoo." << std::endl;
				return 0;
			}

			//check if any turtles are old enough
			for (int i = 0; i < turtles; i++)
			{
				if (turtlesInZoo[i].getAge() >= 3)
				{
					checkerToo = true;
					break;
				}
			}

			if (checkerToo == true)
			{
				for (int i = 0; i <= 10; i++)
					addTurtle(0);

				std::cout << "Ten baby turtles were born." << std::endl;
				std::cout << "There are now " << turtles << " turtles in the zoo." << std::endl;
				return 0;
			}
		}
		std::cout << "None of the animals are old enough to give birth." << std::endl;
		return 0;
	}
	else
	{
		int random = randomNumber(4, 1);

		//checker to see if one of the animals is old enough 
		bool checker = false;

		if (random == 1)
		{
			//check if any tigers are old enough
			for (int i = 0; i < tigers; i++)
			{
				if (tigersInZoo[i].getAge() >= 3)
				{
					checker = true;
					break;
				}
			}

			if (checker == true)
			{
				addTiger(0);
				std::cout << "A baby tiger was born." << std::endl;
				std::cout << "There are now " << tigers << " tigers in the zoo." << std::endl;
				return 0;
			}
		}
		else if (random == 2)
		{
			//check if any penguins are old enough
			for (int i = 0; i < penguins; i++)
			{
				if (penguinsInZoo[i].getAge() >= 3)
				{
					checker = true;
					break;
				}
			}

			if (checker == true)
			{
				for (int i = 0; i < 5; i++)
					addPenguin(0);

				std::cout << "Five baby penguins were born." << std::endl;
				std::cout << "There are now " << penguins << " penguins in the zoo." << std::endl;
				return 0;
			}
		}
		else if (random == 3)
		{
			//check if any turtles are old enough
			for (int i = 0; i < turtles; i++)
			{
				if (turtlesInZoo[i].getAge() >= 3)
				{
					checker = true;
					break;
				}
			}

			if (checker == true)
			{
				for (int i = 0; i < 10; i++)
					addTurtle(0);

				std::cout << "Ten baby turtles were born." << std::endl;
				std::cout << "There are now " << turtles << " turtles in the zoo." << std::endl;
				return 0;
			}
		}
		else
		{
			//check if any newAnimals are old enough
			for (int i = 0; i < newAnimals; i++)
			{
				if (newAnimalsInZoo[i].getAge() >= 3)
				{
					checker = true;
					break;
				}
			}

			if (checker == true)
			{
				for (int i = 0; i < 10; i++)
					addNewAnimal(0);

				std::cout << newAnimalsInZoo[0].getNumberOfBabies() << " baby " << newAnimals << " were born." << std::endl;
				std::cout << "There are now " << newAnimals << " " << newAnimalName << " in the zoo." << std::endl;
				return 0;
			}
		}

		//check to see if the randomly selected animal gave birth
		if (checker == false)
		{
			//second checker
			bool checkerToo = false;

			//check if any tigers are old enough
			for (int i = 0; i < tigers; i++)
			{
				if (tigersInZoo[i].getAge() >= 3)
				{
					checkerToo = true;
					break;
				}
			}

			if (checkerToo == true)
			{
				addTiger(0);
				std::cout << "A baby tiger was born." << std::endl;
				std::cout << "There are now " << tigers << " tigers in the zoo." << std::endl;
				return 0;
			}

			//check if any penguins are old enough
			for (int i = 0; i < penguins; i++)
			{
				if (penguinsInZoo[i].getAge() >= 3)
				{
					checkerToo = true;
					break;
				}
			}

			if (checkerToo == true)
			{
				for (int i = 0; i < 5; i++)
					addPenguin(0);

				std::cout << "Five baby penguins were born." << std::endl;
				std::cout << "There are now " << penguins << " penguins in the zoo." << std::endl;
				return 0;
			}

			//check if any turtles are old enough
			for (int i = 0; i < turtles; i++)
			{
				if (turtlesInZoo[i].getAge() >= 3)
				{
					checkerToo = true;
					break;
				}
			}

			if (checkerToo == true)
			{
				for (int i = 0; i < 10; i++)
					addTurtle(0);

				std::cout << "Ten baby turtles were born." << std::endl;
				std::cout << "There are now " << turtles << " turtles in the zoo." << std::endl;
				return 0;
			}

			//check if any newAnimals are old enough
			for (int i = 0; i < newAnimals; i++)
			{
				if (newAnimalsInZoo[i].getAge() >= 3)
				{
					checkerToo = true;
					break;
				}
			}

			if (checkerToo == true)
			{
				for (int i = 0; i < newAnimalsInZoo[0].getNumberOfBabies(); i++)
					addTurtle(0);

				std::cout << newAnimalsInZoo[0].getNumberOfBabies() << " baby " << newAnimals << " were born." << std::endl;
				std::cout << "There are now " << newAnimals << " " << newAnimalName << " in the zoo." << std::endl;
				return 0;
			}
		}

		std::cout << "None of the animals are old enough to give birth." << std::endl;
		return 0;
	}
}

/****************************************************************
* Function for selecting a random event to take place.
*****************************************************************/

void Zoo::selectRandomEvent()
{
	std::cout << "::: Random Event :::" << std::endl;
	
	
	if (feedType == 1) //cheap food type selected
	{
		//variable for selecting random event
		//since cheap food is selected, sickness will have a 50 percent chance to occur
		int random = randomNumber(100, 1);

		if ((random >= 1) && (random <= 50))
		{
			sickness();
		}
		else if ((random >= 51) && (random <= 67))
		{
			boom();
		}
		else if ((random >= 68) && (random <= 84))
		{
			birth();
		}
		else
		{
			std::cout << "No random event happened today." << std::endl;
		}
	}
	else if (feedType == 2) //generic food type selected
	{
		//variable for selecting random event
		//sickness will have a regular 25 percent chance to occur
		int random = randomNumber(4, 1);

		if (random == 1)
		{
			sickness();
		}
		else if (random == 2)
		{
			boom();
		}
		else if (random == 3)
		{
			birth();
		}
		else
		{
			std::cout << "No random event happened today." << std::endl;
		}
	}
	else //premium food type selected
	{
		//variable for selecting random event
		//since premium food is selected, sickness will half a 12.5 percent chance to occur
		int random = randomNumber(16, 1);

		if ((random >= 1) && (random <= 2))
		{
			sickness();
		}
		else if ((random >= 3) && (random <= 7))
		{
			boom();
		}
		else if ((random >= 8) && (random <= 12))
		{
			birth();
		}
		else
		{
			std::cout << "No random event happened today." << std::endl;
		}
	}
}


/* end of day functions */

/****************************************************************
* Function for calculating profit.
*****************************************************************/

void Zoo::calculateProfit()
{
	if (newAnimal == false)
	{
		std::cout << "::: End of Day :::" << std::endl;
		std::cout << "Tigers: " << tigers << std::endl;
		std::cout << "Penguins: " << penguins << std::endl;
		std::cout << "Turtles: " << turtles << std::endl;

		profit += (tigers * tigersInZoo[0].getPayoff());
		profit += (penguins * penguinsInZoo[0].getPayoff());
		profit += (turtles * turtlesInZoo[0].getPayoff());
		profit += bonus;
		bank += profit;

		std::cout << "Profit for day " << days << ": " << profit << std::endl;
		std::cout << "Total money in bank: " << bank << std::endl;

		//reset profit and bonus for next day
		profit = 0.00;
		bonus = 0.00;
	}
	else
	{
		std::cout << "::: End of Day :::" << std::endl;
		std::cout << "Tigers: " << tigers << std::endl;
		std::cout << "Penguins: " << penguins << std::endl;
		std::cout << "Turtles: " << turtles << std::endl;
		std::cout << newAnimalName << "s: " << newAnimals << std::endl;

		profit += (tigers * tigersInZoo[0].getPayoff());
		profit += (penguins * penguinsInZoo[0].getPayoff());
		profit += (turtles * turtlesInZoo[0].getPayoff());
		profit += (newAnimals * newAnimalsInZoo[0].getPayoff());
		profit += bonus;
		bank += profit;

		std::cout << "Profit for day " << days << ": " << profit << std::endl;
		std::cout << "Total money in bank: " << bank << std::endl;

		//reset profit and bonus for next day
		profit = 0.00;
		bonus = 0.00;

	}
}

/****************************************************************
* Function that asks the user what type of animal they want
* to purchase.
*****************************************************************/

bool Zoo::endPrompt()
{
	if (newAnimal == false)
	{
		int answer = 0;
		int answerTwo = 0;

		std::cout << "Would you like to buy an adult animal?" << std::endl;
		std::cout << "(1) for yes" << std::endl;
		std::cout << "(2) for no" << std::endl;
		std::cout << "Enter Value:" << std::endl;

		//validate input
		answer = checkPrompt();

		if (answer == 1)
		{
			std::cout << "Animal Selection: " << std::endl;
			std::cout << "(1) to buy a tiger" << std::endl;
			std::cout << "(2) to buy a penguin" << std::endl;
			std::cout << "(3) to buy a turtle" << std::endl;
			std::cout << "Enter option: " << std::endl;
			answerTwo = checkPromptToo(1,3);

			if (answerTwo == 1)
			{
				addTiger(3);
				std::cout << "A new adult tiger has been added to the zoo." << std::endl;
			}
			else if (answerTwo == 2)
			{
				addPenguin(3);
				std::cout << "A new adult penguin has been added to the zoo." << std::endl;
			}
			else if (answerTwo == 3)
			{
				addTurtle(3);
				std::cout << "A new adult turtle has been added to the zoo." << std::endl;
			}
		}
		else
			std::cout << "No new animals added." << std::endl;
	}
	else
	{
		int answer = 0;
		int answerTwo = 0;

		std::cout << "Would you like to buy an adult animal?" << std::endl;
		std::cout << "(1) for yes" << std::endl;
		std::cout << "(2) for no" << std::endl;
		std::cout << "Enter Value:" << std::endl;

		//validate input
		answer = checkPrompt();

		if (answer == 1)
		{
			std::cout << "Animal Selection: " << std::endl;
			std::cout << "(1) to buy a tiger" << std::endl;
			std::cout << "(2) to buy a penguin" << std::endl;
			std::cout << "(3) to buy a turtle" << std::endl;
			std::cout << "(4) to buy a " << newAnimalName << std::endl;
			std::cout << "Enter option: " << std::endl;
			answerTwo = checkPromptToo(1,4);

			if (answerTwo == 1)
			{
				addTiger(3);
				std::cout << "A new adult tiger has been added to the zoo." << std::endl;
			}
			else if (answerTwo == 2)
			{
				addPenguin(3);
				std::cout << "A new adult penguin has been added to the zoo." << std::endl;
			}
			else if (answerTwo == 3)
			{
				addTurtle(3);
				std::cout << "A new adult turtle has been added to the zoo." << std::endl;
			}
			else
			{
				addNewAnimal(3);
				std::cout << "A new adult " << newAnimalName << " has been added to the zoo." << std::endl;
			}
		}
		else
			std::cout << "No new animals added." << std::endl;
	}

	if (bank == 0.00)
	{
		std::cout << std::endl;
		std::cout << "You ran out of money." << std::endl;
		std::cout << "Ending game..." << std::endl;
		return true;
	}

	std::cout << "Continue to next day?" << std::endl;
	std::cout << "(1) for yes" << std::endl;
	std::cout << "(2) for no" << std::endl;
	std::cout << "Enter option: " << std::endl;

	int answerThree = checkPrompt();

	if (answerThree == 1)
	{
		std::cout << std::endl;
		return false;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Ending game..." << std::endl;
		return true;
	}
}

/****************************************************************
* Function that adds a day to the overall days member variable.
*****************************************************************/

void Zoo::addNewDay()
{
	this->days += 1;
}



/* extra credit functions*/

/****************************************************************
* Function that adds a new newAnimal to the zoo.
*****************************************************************/

void Zoo::addNewAnimal(int age)
{
	newAnimals++;

	//double array size if not enough room
	if (newAnimals > newAnimalContainer)
	{
		newAnimalContainer *= 2;

		//create a temp array to store current newAnimals in
		NewAnimal* temp = new NewAnimal[newAnimalContainer];

		for (int i = 0; i < (newAnimals - 1); i++)
			temp[i] = newAnimalsInZoo[i];

		//deallocate original newAnimal array
		delete[] newAnimalsInZoo;

		//assign temp array to original 
		//for (int i = 0; i < newAnimalContainer; i++)
			newAnimalsInZoo = temp;

		//delete the temp array
		//delete[] temp;
	}

	//set the new newAnimal's age
	newAnimalsInZoo[getNewAnimals() - 1].setAge(age);

	//set the new newAnimal's other variables
	newAnimalsInZoo[getNewAnimals() - 1].setName(newAnimalName);
	newAnimalsInZoo[getNewAnimals() - 1].setCost(newAnimalCost);
	newAnimalsInZoo[getNewAnimals() - 1].setBabies(newAnimalBabies);
	newAnimalsInZoo[getNewAnimals() - 1].setBaseFood(newAnimalBaseFood);
	newAnimalsInZoo[getNewAnimals() - 1].setPayoff(newAnimalPayoff);

	//subtract the cost of the newAnimal from the bank
	subtractBank(newAnimalsInZoo[0].getCost());

	//increment the feeding cost
	totalFeedingCost += newAnimalsInZoo[0].getBaseFoodCost();
}

/****************************************************************
* Getter for amount of new animals in zoo.
*****************************************************************/

int Zoo::getNewAnimals() const
{
	return newAnimals;
}

/****************************************************************
* Function that checks if a user entered a name correctly.
*****************************************************************/

bool Zoo::checkName(std::string name)
{
	for (unsigned i = 0; i < name.length(); i++)
	{
		if (((name[i] >= 65) && (name[i] <= 90)) || ((name[i] >= 97) && (name[i] <= 122)))
			return true;
	}
	return false;
}