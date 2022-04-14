/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: room.h
*/

/* Header guards to prevent header files being included numerous times */
#ifndef ROOM_H_
#define ROOM_H_

#include "item.h"  // include item header file

#include <map>
#include <string>
#include <vector>
using std::vector;

using namespace std;   // namespace

class Room {
    friend class mainwindow;    // friend- allows mainwindow to access private members of room

/* access specifier: only within the class and mainwindow class */
private:
    string description;
    map<string, Room*> exits;
    string exitString();
    vector<Item> itemsInRoom;

/* access specifier: accessible from outside the class */
public:
    int numberOfItems();
    Room(string description);
    void setExits(Room *up, Room *right, Room *down, Room *left);
    string shortDescription();
    string longDescription();
    Room* nextRoom(string direction);
    void addItem(Item *inItem);
    void addItem(Item &inItem);
    string displayItems();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    void removeItem(Item item);
    vector<Item> viewItems();
    Item findItem(Item item);
    bool allItemsGathered();
    bool containsExit(string exit);
};

#endif /* ROOM_H_ */
