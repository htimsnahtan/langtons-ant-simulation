/*********************************************************************
** Program name: menu.hpp
** Author: Nathan Smith
** Date: 7-7-18
** Description: Header declaration file for menu function
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
    
    #include<string>

    int menu(int &,int &,int &,int &,int &, bool);
    bool intInRange(int,int,int);
    int getValidNumber(std::string consoleOutput, std::string errorMessage, int lowerBound = 0, int upperBound = 2147483647);

#endif