/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/*****************************************
 ** File:    Investigator.h
 ** Project: CMSC 202 Project 1, Spring 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    2/21/2017
 ** Section: 05
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the header for the Investigator class.
 ** The Investigator class stores information on where the investigator is.
 ** 
 ** 
 ** 
 *********************************************/

#ifndef INVESTIGATOR_H
#define INVESTIGATOR_H

class Investigator {
public:
    
    
    Investigator();

    //--------------------------------------------------------------------------
    //  Name: Investigator
    //  PreCondition:   x and y are between 0 and the MAP_WIDTH and MAP_HEIGHT, respectively
    //  PostCondition: Initializes an Investigator object
    //-------------------------------------------------------------------------
    Investigator(int, int);


    //------------------------------------------------
    //  Name: GetX
    //  PreCondition:   None
    //  PostConiditon  Return m_x's pointer
    //------------------------------------------------
    int* GetX();


    //------------------------------------------------
    //  Name: GetY
    //  PreCondition:   None
    //  PostConiditon  Return m_y's pointer
    //------------------------------------------------
    int* GetY();


    //------------------------------------------------
    // Name: MoveWest
    // PreCondition:    nonzero x value
    // PostCondition:  Moves the investigator over west
    //------------------------------------------------
    bool MoveWest();

    //------------------------------------------------
    // Name: MoveNorth
    // PreCondition:    nonzero y value
    // PostCondition:  Moves the investigator north
    //------------------------------------------------
    bool MoveNorth();

    //------------------------------------------------
    // Name: MoveEast
    // PreCondition:    x is not equal to the width
    // PostCondition:  Moves the investigator over east
    //------------------------------------------------
    bool MoveEast();

    //------------------------------------------------
    // Name: MoveSouth
    // PreCondition:    y is not equal to the height
    // PostCondition:  Moves the investigator over south
    //------------------------------------------------
    bool MoveSouth();



    friend std::ostream& operator<<(std::ostream&, const Investigator&);


private:
    int m_x, m_y;
};




#endif /* INVESTIGATOR_H */

