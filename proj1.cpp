/*****************************************
 ** File:   proj1.cpp
 ** Project: CMSC 202 Project 1, Spring 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    2/21/2017
 ** Section: 05
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the main driver program for Project 1.
 * 


 */

#include <cstdlib>
#include <iostream>

#include "Investigator.h"
#include "Target.h"
#include "Map.h"

using namespace std;

/*
 * 
 */

const int MAP_HEIGHT = 10;
const int MAP_WIDTH = 10;

int main(int argc, char** argv) {

    // Start Menu
    cout << "Manhunt" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Load a simulation from file" << endl;
    cout << "2. Start a new simulation" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter 1 - 3:" << endl;
    int startMenu;

    Investigator *investigator;
    Target *target;


    bool exit = true;
    string filename;


    // Loop start menu until user picks an available choice
    do {
        exit = true;
        cin >> startMenu;
        switch (startMenu) {

                // Load a new simulation
            case 1:
                cout << "What is the name of the file?:" << endl;
                cin >> filename;
                break;


                // Create a new simulation
            case 2:

                // Create the investigator
                int x, y;
                cout << "What is the X axis of the investigator?:" << endl;
                cin >> x;
                while (x < 0 || x > MAP_WIDTH) {
                    cout << "Please input a number between 0 and " << MAP_WIDTH << endl;
                    cin >> x;
                };
                cout << "What is the Y axis of the investigator?:" << endl;
                cin >> y;
                while (y < 0 || y > MAP_HEIGHT) {
                    cout << "Please input a number between 0 and " << MAP_HEIGHT << endl;
                    cin >> y;
                }
                investigator = new Investigator(x, y);

                // Create the target
                cout << "What is the X axis of the target?:" << endl;
                cin >> x;
                while (x < 0 || x > MAP_WIDTH) {
                    cout << "Please input a number between 0 and " << MAP_WIDTH << endl;
                    cin >> x;
                };
                cout << "What is the Y axis of the target?:" << endl;
                cin >> y;
                while (y < 0 || y > MAP_HEIGHT) {
                    cout << "Please input a number between 0 and " << MAP_HEIGHT << endl;
                    cin >> y;
                }
                target = new Target(x, y);
                break;
            case 3:
                cout << "Giving up so soon?" << endl;
                cout << "Good-bye" << endl;
                return 0;
            default:
                cout << "Not a valid choice, please choose an option from 1-3" << endl;
                exit = false;
                break;
        }
    } while (!exit);


    //     Create the map
    //    if (startMenu == 1)
    //         newMap = new Map(MAP_WIDTH, MAP_HEIGHT,filename);
    //    else
    //        newMap = new Map(MAP_WIDTH, MAP_HEIGHT, *investigator, *target);
    Map map = (startMenu == 2 ? Map(MAP_WIDTH, MAP_HEIGHT, *investigator, *target) : Map(MAP_WIDTH, MAP_HEIGHT, filename));
    cout << map;
    map.DisplayMap();

    int mainMenu;


    // Main Menu sequence
    do {
        // Create the main menu
        cout << "What would you like to do?" << endl;
        cout << "1. Search North" << endl;
        cout << "2. Search East" << endl;
        cout << "3. Search South" << endl;
        cout << "4. Search West" << endl;
        cout << "5. See Map" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter 1-6" << endl;

        // Get menu input

        cin >> mainMenu;

        // Process menu input
        switch (mainMenu) {
            case 1:
            case 2:
            case 3:
            case 4:
                if (map.CheckSearch(mainMenu))
                    exit = map.UpdateMap(mainMenu);
                else
                    cout << "I'm sorry, this direction is not available" << endl;
                break;
            case 5:
                map.DisplayMap();
                break;
            case 6:
                cout << "Giving up so soon?" << endl;
                cout << "Good-bye" << endl;
                exit = true;
                break;
            default:
                cout << "Not a valid choice, please choose an option from 1-6" << endl;
                break;
        }
    } while (!exit);

    return 0;
    delete investigator;
    delete target;
}

