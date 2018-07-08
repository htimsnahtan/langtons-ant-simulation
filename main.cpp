/*********************************************************************
** Program name: main.cpp
** Author: Nathan Smith
** Date: 7-7-18
** Description: Runs Langton's Ant simulation. Gets several inputs from user 
* including number of rows, columns, steps, starting row, and starting column.
* Requires Ant & menu headers.
* Runs main menu first time and 2ndary menu after first gameplay. Allows
* user to quit function by returning 0. Program includes makefile and should be run
* with ./assignment2. 
*********************************************************************/
#include "Ant.hpp"
#include "menu.hpp"
#include <iostream>
#include <unistd.h>

int main() 
{
    int firstTimeRun = true;;
    
    while(true)
    {
        int numRows;
        int numCols;
        int numSteps;
        int startingRow;
        int startingCol;

        int gameState = menu(numRows, numCols, startingRow, startingCol, numSteps, firstTimeRun);
        
        if (gameState == 0) // end application 
        {
            return 0;
        }
        
        Ant ant0(numRows, numCols, startingRow, startingCol, numSteps);
        
        bool success = true; // runs simulation until moveAnt() returns false (out of steps)
        bool firstTimeInLoop = true; // added so simulation doesn't print cout first time
        
        while(success)
        {

            if (!firstTimeInLoop)
            {
                std::cout << "Press any key to continue" << std::endl;
                std::cin.get();
                
            }
            else
            {
                firstTimeInLoop = false;
            }
            std::cout << "\033[2J\033[1;1H";// clears screen
            ant0.printMatrix();
            success = ant0.moveAnt();
        }
        firstTimeRun = false;
    }
    
    return 0;
}