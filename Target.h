/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/*****************************************
 ** File:    Target.h
 ** Project: CMSC 202 Project 1, Spring 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    2/21/2017
 ** Section: 05
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the header for the Target class.
 ** The Target class stores information on where the target is.
 ** 
 ** 
 ** 
 *********************************************/



#ifndef TARGET_H
#define TARGET_H

class Target {
public:

    Target();

    //--------------------------------------------------------------------------
    //  Name: Target
    //  PreCondition:   x and y are between 0 and the MAP_WIDTH and MAP_HEIGHT, respectively
    //  PostCondition: Initializes a Target object
    //-------------------------------------------------------------------------
    Target(int, int);

    //------------------------------------------------
    //  Name: GetX
    //  PreCondition:   None
    //  PostConiditon  Returns m_x
    //------------------------------------------------
    int GetX() const;


    //------------------------------------------------
    //  Name: GetY
    //  PreCondition:   None
    //  PostConiditon  Returns m_y
    //------------------------------------------------
    int GetY() const;


    friend std::ostream& operator<<(std::ostream&, const Target&);

private:
    int m_x;
    int m_y;
};

#endif /* TARGET_H */

