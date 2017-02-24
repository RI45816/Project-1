/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    Map.h
 ** Project: CMSC 202 Project 1, Spring 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    02/23/2017
 ** Section: 05
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the header for the Map class.
 ** This 
 ** 
 ** 
 ** 
 *********************************************/

#ifndef MAP_H
#define MAP_H

#include "Investigator.h"
#include "Target.h"

const char UNSEARCHED_AREA = '_';
const char INVESTIGATOR = 'I';
const char TARGET = 'T';
const char SEARCHED_AREA = '*';

class Map {
public:

    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    //  Map
    // PreCondition:    width and height are greater than 0, valid filename
    // PostCondition:  initializes a map object with the specified width and height
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    Map(int, int, std::string);


    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    //  Map
    // PreCondition:    width and height are greater than 0, valid Investigator and Target
    // PostCondition:  initializes a map object with the specified width and height and places the Investigator and Target in the grid
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    Map(const int, const int, Investigator, Target);

    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    // SetUpMap
    // PreCondition:    Already initialized map array, and the dimensions
    // PostCondition:  The map array is iniitalized, filled with the requisite character
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    void SetUpMap(char**,int,int);

    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    // DisplayMap
    // PreCondition:    Already set up map
    // PostCondiition:  Outputs the map in a user friendly way
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    void DisplayMap();


    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Name: CheckSearch
    // PreCondition:    direction is an integer from 1 to 4: 1 - North, 2 - East, 3 - South, 4 - West
    // PostCondition:  Returns true if the move is possible, false if its not
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    bool CheckSearch(int);


    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Name: TargetApprehended
    // PreCondition:    Target and Investigator
    // PostCondition:  Returns whether or not the investigator has found the target
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    bool TargetApprehended();


    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Name: UpdateMap
    // PreCondition:    Same direction is in CheckSearch
    // PostCondition:  Update the map
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    bool UpdateMap(int);

    


    friend std::ostream& operator<<(std::ostream&, const Map&);

private:
    int m_width, m_height;
    Investigator m_investigator;
    Target m_target;
    int* m_x;
    int* m_y;
    char** m_mapGrid;
};

#endif /* MAP_H */

