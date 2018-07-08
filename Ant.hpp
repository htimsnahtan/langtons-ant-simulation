/*********************************************************************
** Program name: Ant.hpp
** Author: Nathan Smith
** Date: 7-7-18
** Description: Header declaration file for Ant Class
*********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
    private:
        bool gameInProgress;
        int xCoordinate;
        int yCoordinate;
        char orientation; // U,R,D,L
        int numRows;
        int numColumns;
        int** matrix;
        int numSteps;
    public:
        Ant(int, int, int, int, int);
        ~Ant();
        int setX(int);
        int setY(int);
        int getSteps();
        int getX();
        int getY();
        void printMatrix();
        bool moveAnt();
};
#endif

