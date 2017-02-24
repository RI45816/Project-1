/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    Map.cpp
 ** Project: CMSC 202 Project 1, Spring 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    02/23/2017
 ** Section: 05
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the definition for the Map class.
 ** This stores the map information and carries out many of the functions
 ** It stores the positions of the investigator and target
 ** 
 ** 
 *********************************************/

#include <iostream>
#include <fstream>
#include "Map.h"
#include "Investigator.h"
#include "Target.h"

using namespace std;


// Map
// Initializes Map object with width, height by loading from file

Map::Map(const int w, const int h, string filename) : m_width(w), m_height(h), m_mapGrid(new char*[w]) {
    ifstream saveFile(filename.c_str());
    int investigatorX, investigatorY, targetX, targetY;
    if (saveFile.is_open())
        saveFile >> investigatorX >> investigatorY >> targetX >> targetY;
    Investigator investigator(investigatorX, investigatorY);
    Target target(targetX, targetY);
    m_investigator = investigator;
    m_target = target;
    for (int i = 0; i < w; i++)
        m_mapGrid[i] = new char[h];
    SetUpMap(m_mapGrid, w, h);
    m_x = m_investigator.GetX();
    m_y = m_investigator.GetY();
    m_mapGrid[*m_x][*m_y] = INVESTIGATOR;
    m_mapGrid[target.GetX()][target.GetY()] = TARGET;
}

// Map
// Initializes Map object with width, height, and investigator and target

Map::Map(const int w, const int h, Investigator i, Target t) : m_width(w), m_height(h), m_investigator(i), m_target(t), m_mapGrid(new char*[w]) {
    for (int i = 0; i < w; i++)
        m_mapGrid[i] = new char[h];
    SetUpMap(m_mapGrid, w, h);
    m_x = m_investigator.GetX();
    m_y = m_investigator.GetY();
    m_mapGrid[*m_x][*m_y] = INVESTIGATOR;
    m_mapGrid[t.GetX()][t.GetY()] = TARGET;
};

// SetUpMap
// Populates the array with UNSEARCHED_AREA characters

void Map::SetUpMap(char** map, int width, int height) {
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            map[i][j] = UNSEARCHED_AREA;
}

// DisplayMap
// Outputs the map in a user friendly way

void Map::DisplayMap() {
    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_height; j++)
            cout << (m_mapGrid[j][i] != TARGET ? m_mapGrid[j][i] : UNSEARCHED_AREA) << " ";
        cout << endl;
    }
}

// TargetApprehended
// Determines whether or not the investigator has caught the target

bool Map::TargetApprehended() {
    if (m_target.GetX() < *m_x)
        cout << "Try Searching West" << endl;
    else if (m_target.GetX() > *m_x)
        cout << "Try Searching East" << endl;
    else if (m_target.GetY() < *m_y)
        cout << "Try Searching North" << endl;
    else if (m_target.GetY() > *m_y)
        cout << "Try Searching South" << endl;
    else {
        cout << "You found the target." << endl;
        return true;
    }
    DisplayMap();
    return false;
}
// UpdateMap
// Update the map

bool Map::UpdateMap(int direction) {
    m_mapGrid[*m_x][*m_y] = SEARCHED_AREA;
    switch (direction) {
        case 1:
            m_investigator.MoveNorth();
            break;
        case 2:
            m_investigator.MoveEast();
            break;
        case 3:
            m_investigator.MoveSouth();
            break;
        case 4:
            m_investigator.MoveWest();
            break;
    }
    m_mapGrid[*m_x][*m_y] = INVESTIGATOR;
    return TargetApprehended();
}

// CheckSearch
// Check to see whether or not the request move is possible

bool Map::CheckSearch(int direction) {
    switch (direction) {
        case 1:
            return *m_y != 0;
            break;
        case 2:
            return *m_x != m_width;
            break;
        case 3:
            return *m_y != m_height;
            break;
        case 4:
            return *m_x != 0;
            break;
    }
}

ostream& operator<<(ostream& os, const Map& M) {
    os << "Width: " << M.m_width << "\n" << "Height: " << M.m_height << "\n" << "Investigator: " << M.m_investigator << "\n" << "Target: " << M.m_target << endl;
}