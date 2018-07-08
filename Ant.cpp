/*********************************************************************
** Program name: Ant.cpp
** Author: Nathan Smith
** Date: 7-7-18
** Description: Ant class implimentation file. Includes constructor, destructor,
* setter and getter functions for x and y coordinates, a print function, and a
* move ant function. Currently move ant function is verbose and should eventually
* be broken up into several, smaller functions to improve readability and
* future modification.
*********************************************************************/

#include "Ant.hpp"
#include <iostream>

// White square = 0
// Black square = 1
// Ant on White = 2
// Ant on Black = 3

// constructor
// accepts information to build matrix (see variables below) then builds dynamic 2d matrix
Ant::Ant(int numRowsIn, int numColumnsIn, int xCoordinateIn, int yCoordinateIn, int numStepsIn)
{
    numRows = numRowsIn;
    numColumns = numColumnsIn;
    xCoordinate = xCoordinateIn -1;
    yCoordinate = yCoordinateIn -1;
    numSteps = numStepsIn;
    
    // dynamically allocates memory for matrix
    matrix = new int*[numRows];
    for(int i = 0; i < numRows; ++i)
    {
        matrix[i] = new int[numColumns];
    }
    
    // fill matrix w/ white squares aka 0
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numColumns; ++j)
        {
            matrix[i][j] = 0;
        }
    }
    
    //set ant's initial orientation to Up
    orientation = 'L';
    
    // position ant
    setX(xCoordinate);
    setY(yCoordinate);
    matrix[xCoordinate][yCoordinate] = 2;
    
}

// destructor
Ant::~Ant()
{
    //free memory
    for (int i = 0; i < numRows; ++i)
    {
        delete [] matrix[i];
    }
    delete [] matrix;

}

//returns 0 if too far up, 1 if too far down, 2 if in range
int Ant::setX(int xIn)
{
    if (xIn < 0)
    {
        return 0;
    }
    else if (xIn > numRows -1)
    {
        return 1;
    }
    xCoordinate = xIn;
    return 2;
}
//returns 0 if too far left, 1 if too far right, 2 if in range
int Ant::setY(int yIn)
{
    if (yIn < 0)
    {
        return 0;
    }
    else if (yIn > numColumns -1)
    {
        return 1;
    }
    yCoordinate = yIn;
    return 2;
}

int Ant::getX()
{
    return xCoordinate;
}

int Ant::getY()
{
    return yCoordinate;
}

int Ant::getSteps()
{
    return numSteps;
}

//prints matrix with "|" at end of each line
void Ant::printMatrix()
{
    //prints matrix
    bool firstLine = true;
    for (int i = 0; i < numRows; ++i)
    {
        if (firstLine == true)
        {
            std::cout << "\n";
            firstLine = false;
        }
        else
        {
            std::cout << '|' << "\n";
        }
        
        for (int j = 0; j < numColumns; ++j)
            {
            int temp = matrix[i][j];
            if (temp == 0)
            {
                std::cout << ' ' << ' ';
            }
            if (temp == 1)
            {
                std::cout << '#' << ' ';
            }
            if (temp == 2 || temp == 3)
            {
                std::cout << '*' << ' ';
            }
            }
    }
    std::cout << '|' << std::endl;
    
}

// moves ant  to new location and returns true if successful and false if not
// if on white, turns 90 degrees right, moves forward 1, and changes space to black
// if on black, turns 90 degrees left, moves forward 1, and chanegs space to white
// after moving decriments numsteps by 1
// if ant will hit wall, rotate ant to a direction not facing wall and decriment 
// numsteps by 1
bool Ant::moveAnt()
{
    if (numSteps > 0)
    {
        int currentX = getX();
        int currentY = getY();
        
        //Note: Following section quite verbose. Keeping as is for now,
        //      however, may update in future to make cleaner
        if (matrix[currentX][currentY] == 2)//if on white
        {
            if (orientation == 'U')
            {
                int setYResults = setY(currentY + 1);
                //move ant right 1 column
                if ( setYResults == 2)
                {
                    //change current square from white to black
                    matrix[currentX][currentY] = 1;
                
                    //turn right 90 degrees
                    orientation = 'R';
                    
                    //get color of new spot then put ant there
                    if (matrix[getX()][getY()] == 0)// if black
                    {
                        matrix[getX()][getY()] = 2;
                    }
                    else// if white
                    {
                        matrix[getX()][getY()] = 3;
                    }
                    
                    numSteps--;
                    return true;
                }
                else if (setYResults == 1)//too far right
                {
                    orientation = 'L';
                    numSteps--;
                    return true;
                }
                else if (setYResults == 0)//for non-square grids
                {
                    orientation = 'U';
                    numSteps--;
                    return true;
                }
                else
                {
                    std::cout << "error" << std::endl;
                    return false;
                }
                

                
            }
            if (orientation == 'R')
            {
                int setXResults = setX(currentX + 1);
                if (setXResults == 2)
                {
                    //change current square from white to black
                    matrix[currentX][currentY] = 1;
                    
                    //move ant down 1 column
                    
                    
                    //turn right 90 degrees
                    orientation = 'D';
    
                    //get color of new spot then put ant there
                    if (matrix[getX()][getY()] == 0)// if black
                    {
                        matrix[getX()][getY()] = 2;
                    }
                    else// if white
                    {
                        matrix[getX()][getY()] = 3;
                    }
                    numSteps--;
                    return true;
                }
                else if (setXResults == 1)
                {
                    orientation = 'U';
                    numSteps--;
                    return true;
                }
                else if (setXResults == 0)// for non square grids
                {
                    orientation = 'L';
                    numSteps--;
                    return true;
                }
                else
                {
                    std::cout << "error" << std::endl;
                    return false;
                }

                
            }
            if (orientation == 'D')
            {
                int setYResults = setY(currentY - 1);
                if ( setYResults == 2)
                {
                    //change current square from white to black
                    matrix[currentX][currentY] = 1;
                    
                    //move ant left 1 column
                    
                    //turn right 90 degrees
                    orientation = 'L';
                    
                    //get color of new spot then put ant there
                    if (matrix[getX()][getY()] == 0)// if black
                    {
                        matrix[getX()][getY()] = 2;
                    }
                    else// if white
                    {
                        matrix[getX()][getY()] = 3;
                    }
                    numSteps--;
                    return true;
                }
                else if (setYResults == 1)// for non-square grids
                {
                    orientation = 'U';
                    numSteps--;
                    return true;
                }
                else if (setYResults == 0)
                {
                    orientation = 'R';
                    numSteps--;
                    return true;
                }
                else
                {
                    std::cout << "error" << std::endl;
                    return false;
                }

                
            }
            if (orientation == 'L')
            {
                int setXResults = setX(currentX - 1);
                if ( setXResults == 2)
                {
                    //change current square from white to black
                    matrix[currentX][currentY] = 1;
                    
                    //move ant up 1 row
                    
                    
                    //turn left 90 degrees
                    orientation = 'U';
    
                    //get color of new spot then put ant there
                    if (matrix[getX()][getY()] == 0)// if white
                    {
                        matrix[getX()][getY()] = 2;// move ant to white
                    }
                    else// if white
                    {
                        matrix[getX()][getY()] = 3;
                    }
                    numSteps--;
                    return true;        
                }
                else if (setXResults == 0)
                {
                    orientation = 'D';
                    numSteps--;
                    return true;
                }
                else if (setXResults == 0)// for non-square grids
                {
                    orientation = 'L';
                    numSteps--;
                    return true;
                }
                else
                {
                    std::cout << "error" << std::endl;
                    return false;
                }

                
            }
        }
        if (matrix[currentX][currentY] == 3)// if on black
        {
            if (orientation == 'U')
            {
                int setYResults = setY(currentY - 1);
                if ( setYResults == 2)
                {
                    //change current square from black to white
                    matrix[currentX][currentY] = 0;
                    
                    //move ant left 1 column
                    
                    
                    //turn left 90 degrees
                    orientation = 'L';
                    
                    //get color of new spot then put ant there
                    if (matrix[getX()][getY()] == 0)// if black
                    {
                        matrix[getX()][getY()] = 2;
                    }
                    else// if white
                    {
                        matrix[getX()][getY()] = 3;
                    }
                    numSteps--;
                    return true; 
                }
                else if (setYResults == 0)
                {
                    orientation = 'R';
                    numSteps--;
                    return true;
                }
                else if (setYResults == 1)// for non-square grids
                {
                    orientation = 'D';
                    numSteps--;
                    return true;
                }
                else
                {
                    std::cout << "error" << std::endl;
                    return false;
                }

                
            }
            if (orientation == 'R')
            {
                int setXResults = setX(currentX - 1);
                if ( setXResults == 2)
                {
                    //change current square from black to white
                    matrix[currentX][currentY] = 0;
                    
                    //move ant up 1 row
                    
                    
                    //turn left 90 degrees
                    orientation = 'U';
                    
                    //get color of new spot then put ant there
                    if (matrix[getX()][getY()] == 0)// if black
                    {
                        matrix[getX()][getY()] = 2;
                    }
                    else// if white
                    {
                        matrix[getX()][getY()] = 3;
                    }
                    numSteps--;
                    return true;
                }
                else if (setXResults == 0)
                {
                    orientation = 'D';
                    numSteps--;
                    return true;
                }
                else if (setXResults == 1)//in case of non-square grids
                {
                    orientation = 'R';
                    numSteps--;
                    return true;
                }
                else
                {
                    std::cout << "error" << std::endl;
                    return false;
                }

                
            }
            if (orientation == 'D')
            {
                int setYResults = setY(currentY + 1);
                if ( setYResults== 2)
                {
                    //change current square from black to white
                    matrix[currentX][currentY] = 0;
                    
                    //move ant right 1 row
                    setY(currentY + 1);
                    
                    //turn left 90 degrees
                    orientation = 'R';
                    
                    //get color of new spot then put ant there
                    if (matrix[getX()][getY()] == 0)// if black
                    {
                        matrix[getX()][getY()] = 2;
                    }
                    else// if white
                    {
                        matrix[getX()][getY()] = 3;
                    }
                    numSteps--;
                    return true;
                }
                else if (setYResults == 1)
                {
                    orientation = 'L';
                    numSteps--;
                    return true;
                }
                else if (setYResults == 0)// in case of non-square grids
                {
                    orientation = 'R';
                    numSteps--;
                    return true;
                }
                else
                {
                    std::cout << "error" << std::endl;
                    return false;
                }

                
            }
            if (orientation == 'L')
            {
                int setXResults = setX(currentX + 1);
                if (setXResults==2)
                {
                    //change current square from black to white
                    matrix[currentX][currentY] = 0;
                    
                    //move ant down 1 column
                    ;
                    
                    //turn left 90 degrees
                    orientation = 'D';
                    
                    //get color of new spot then put ant there
                    if (matrix[getX()][getY()] == 0)// if black
                    {
                        matrix[getX()][getY()] = 2;
                    }
                    else// if white
                    {
                        matrix[getX()][getY()] = 3;
                    }
                    numSteps--;
                    return true;
                }
                else if (setXResults == 1)
                {
                    orientation = 'U';
                    numSteps--;
                    return true;
                }
                else if (setXResults == 0)// in case of non-square grids
                {
                    orientation = 'D';
                    numSteps--;
                    return true;
                }
                else
                {
                    std::cout << "error" << std::endl;
                    return false;
                    
                }
            }
        }
        else //if current square not black or white print error
        {
            std::cout << "error: " << matrix[currentX][currentY] << std::endl;
            return false;
        }
    }
    else
    {
        return false;// out of steps
    }
}