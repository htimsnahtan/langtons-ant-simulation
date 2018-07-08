/*********************************************************************
** Program name: menu.cpp
** Author: Nathan Smith
** Date: 7-7-18
** Description: menu function implimentation file
*********************************************************************/
#include "menu.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// menu function that accepts several passed by reference values
// runs 2 different sets of options depending on if it's users first time
// playing simulation
int menu(int &numRows, int &numCols, int &startingRow, int &startingCol, int &numSteps, bool firstTimeRunIn)
{
    int menuIn;
    int returnValue;
    int firstTimeRun = firstTimeRunIn;
    int randomStartingLocation;
    
    if (firstTimeRun)
    {
    std::cout   << "Please choose an option:\n"
                << "1. Start Langton's Ant simulation\n"
                << "2. Quit\n"; 
    }
    else
    {
    std::cout   << "Please choose an option:\n"
                << "1. Play again\n"
                << "2. Quit\n"; 
    }

    std::cin >> menuIn;
    
    while(!(menuIn == 1 || menuIn == 2))
    {
        std::cout << "Not a valid option. Please enter 1 or 2." << std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cin >> menuIn;
    }
    
    if (menuIn == 2)
    {
        std::cout << "Goodbye!" << std::endl;
        returnValue = 0;
    }
    else
    {
        numRows = getValidNumber("Please enter the number (decimals ignored) of rows for the board:",
            "Please enter a valid number of rows.");
        numCols = getValidNumber("Please enter the number(decimals ignored) of columns for the board:",
            "Please enter a valid number of columns.");
        randomStartingLocation = getValidNumber("Would you like a random starting location?\n1=Yes\t0=No\t(decimals ignored)",
            "Please enter a valid option.",-1,2);
        if (randomStartingLocation)
        {
            srand(time(NULL));
            startingRow = rand() % numRows+1;
            startingCol = rand() % numCols+1;
            
            std::cout << "Starting Row: " << startingRow << std::endl;
            std::cout << "Starting Column: " << startingCol << std::endl;
        }
        else
        {
            startingRow = getValidNumber("Please enter the starting row of the ant(decimals ignored):",
                "Please enter a valid starting row for the ant", 0, numRows+1);
            startingCol = getValidNumber("Please enter the starting column of the ant(decimals ignored):",
                "Please enter a valid starting column for the ant", 0, numCols+1);
        }
        numSteps = getValidNumber("Please enter the number of steps in simulation(decimals ignored):",
            "Please enter a valid number of steps.");

        returnValue = 1;
    }
    
    return returnValue;
}

// checks if integer is in range between lower and upper bounds; accepts 3 inputs:
// input, lowerbound, and upperbound
bool intInRange(int input, int lowerBound, int upperBound)
{
    bool returnValue = false;
    if (input > lowerBound && input < upperBound)
    {
        returnValue = true;
    }
    return returnValue;
}

// gets valid # from user by printing to console. accepts: prompt to get number, 
// error prompt, lower bound, and upper bound
// returns user input
int getValidNumber(std::string consoleOutput, std::string errorMessage, int lowerBound , int upperBound)
{
    int userInput;
    bool firstTimeShown = true;
    do
    {
        
        if (!firstTimeShown)
        {
            std::cout << errorMessage << std::endl;
        }
        std::cout << consoleOutput << std::endl;
        
        std::cin >> userInput;
        
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            userInput = lowerBound;//sets this so while condition will fail
        }
        
        else
        {
            std::cin.ignore(10000,'\n');
        }
        
        firstTimeShown = false;
    }
    while (!intInRange(userInput, lowerBound, upperBound));
    
    return userInput;
}
