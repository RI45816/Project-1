/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    Target.cpp
 ** Project: CMSC 202 Project 1, Spring 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    2/21/2017
 ** Section: 05
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the definition for the Target class.
 ** This defines the initializer for the Target class.
 ** The Target class stores information on where the target is.
 ** 
 ** 
 *********************************************/
#include <iostream>
#include "Target.h"

using namespace std;

Target::Target() {

}

//  Target
//  Given x and y coordinates, create a target

Target::Target(int x, int y) : m_x(x), m_y(y) {
}

// GetY
// getter function for m_Y

int Target::GetY() const {
    return m_y;
}

// GetX
// getter function for m_X

int Target::GetX() const {
    return m_x;
};

ostream& operator<<(ostream& os, const Target& T) {
    return os << "x: " << T.m_x << "\n" << "y: " << T.m_y;
}
