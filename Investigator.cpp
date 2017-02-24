/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    Investigator.cpp
 ** Project: CMSC 202 Project 1, Spring 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    2/21/2017
 ** Section: 05
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the definition for the Investigator class.
 ** This defines the initializer for the Investigator class.
 ** The Investigator class stores information on where the investigator is.
 ** 
 ** 
 *********************************************/


#include <iostream>
#include "Investigator.h"

using namespace std;

Investigator::Investigator() {
}

//  Investigator
//  Given x and y coordinates, create an investigator

Investigator::Investigator(int x, int y) : m_x(x), m_y(y) {
};


// GetY
// getter function for m_Y

int* Investigator::GetY() {
    int* y = &m_y;
    return y;
}


// GetX
// getter function for m_X

int* Investigator::GetX() {
    int * x = &m_x;
    return x;
}


// MoveWest
// Move the investigator over west

bool Investigator::MoveWest() {
    m_x--;
}

// MoveEast
// Move the investigator over east

bool Investigator::MoveEast() {
    m_x++;
}

// MoveSouth
// Move the investigator over south

bool Investigator::MoveSouth() {
    m_y++;
}

// MoveNorth
// Move the investigator over north

bool Investigator::MoveNorth() {
    m_y--;
}

ostream& operator<<(ostream& os, const Investigator& I) {
    return os << "x: " << I.m_x << "\n" << "y: " << I.m_y;
}


