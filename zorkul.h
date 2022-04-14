/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: zorkul.h
*/

/* Header guards to prevent header files being included numerous times */
#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "command.h"  // include command header file
//#include "parser.h" // no parser file anymore
#include "room.h"     // include room header file
#include "item.h"     // include item header file
#include "weapon.h"   // include weapon header file

#include <string>
#include <iostream>
#include <vector>

using namespace std;   // namespace

class ZorkUL {
/* access specifier: only within the class */
private:
    //Parser parser;   // no parser file anymore
    vector<Room> rooms;
    Room *currentRoom;
    void createRooms();
    bool processCommand(Command command);
    void goRoom(Command command);
    void createItems();
    void displayItems();

/* access specifier: accessible from outside the class */
public:
    ZorkUL();
  //void play();
    string printWelcome();
    string printHelp();
    string printEnd();
    string go(string direction);
    string teleport();
    string map();
    string viewCharacterInfo();
    string viewItems();
    Room getCurrentRoom();
};

#endif /* ZORKUL_H_ */
