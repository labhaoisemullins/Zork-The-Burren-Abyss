/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: zorkul.cpp
*/

#include "zorkul.h"  // include zorkul header file

#include <ctime>
#include <iostream>
#include <cstdlib>      // c standard general utilities library

using namespace std;    // namespace

/**int main(int argc, char *argv[]) {
    ZorkUL temp;
    temp.play();
    return 0;
} */

ZorkUL::ZorkUL() {
    createRooms();
    srand(time(0)); // generates random numbers by seeding rand with a starting value
}

/* creates the rooms (one to ten) */
void ZorkUL::createRooms() {
    Room *one, *two, *three, *four, *five, *six, *seven,       //pointers stores address of another variable
            *eight, *nine, *ten;

/* room one = "The Cavern", main room in the cave */
    one = new Room("The Cavern");
/* add an item (crinoid fossil), set the weight and value */
    one->addItem(new Item("crinoid", 1, 11));

/* room two = "Chamber 1", first chamber in the cave */
    two = new Room("Chamber 1");
/* add an item (brachiopod fossil), set the weight and value */
    two->addItem(new Item("brachiopod", 3, 33));

/* room three = "Chamber 2", second chamber in the cave */
    three = new Room("Chamber 2");

/* room four = "Chamber 3", third chamber in the cave */
    four = new Room("Chamber 3");
/* add an item (trace fossil), set the weight and value */
    four->addItem(new Item("trace", 2, 22));
/* add an item (coral fossil), set the weight and value */
    four->addItem(new Item("coral", 4, 44));

/* room five = "Chamber 4", fourth chamber in the cave */
       five = new Room("Chamber 4");

/* room six = "Chamber 5", fifth chamber in the cave */
       six = new Room("Chamber 5");
       six->addItem(new Weapon("arrow", 2, 15.0, 2.5, 3));

/* room seven = "Chamber 6", sixth chamber in the cave */
       seven = new Room("Chamber 6");
//     seven->addItem(new Weapon("spear", 360, 25.0, 6.0, 3));

/* room eight = "Chamber 7", seventh chamber in the cave */
       eight = new Room("Chamber 7");

/* room nine = "Chamber 8", eigth chamber in the cave */
       nine = new Room("Chamber 8");

/* room ten = "The Terminus", last room in the cave; player wins if they reach this room */
    ten = new Room("The Terminus");

/* set the exits for each room (one-ten)*/
    //             (up, right, down, left)
      one->setExits(six, two, four, three);
      two->setExits(NULL, NULL, NULL, one);
      three->setExits(NULL, one, NULL, ten);
      four->setExits(one, five, NULL, nine);
      five->setExits(NULL, NULL, NULL, four);
      six->setExits(NULL, seven, one, eight);
      seven->setExits(NULL, NULL, NULL, six);
      eight->setExits(NULL, six, NULL, NULL);
      nine->setExits(NULL, four, NULL, NULL);
      ten->setExits(NULL, ten, NULL, NULL);     // final room, you win if you enter it

/* push_back allows to add element to the vector, stores the room */
      rooms.push_back(*one);
      rooms.push_back(*two);
      rooms.push_back(*three);
      rooms.push_back(*four);
      rooms.push_back(*five);
      rooms.push_back(*six);
      rooms.push_back(*seven);
      rooms.push_back(*eight);
      rooms.push_back(*nine);
      rooms.push_back(*ten);

/* set the current room to the main room, The Cavern, (room one)*/
      currentRoom = one;
}

/*
// Main play routine.  Loops until end of play.
void ZorkUL::play() {
 printWelcome();

 // Enter the main command loop.  Here we repeatedly read commands and
 // execute them until the ZorkUL game is over.

 bool finished = false;
 while (!finished) {
     // Create pointer to command and give it a command.
     Command* command = parser.getCommand();
     // Pass dereferenced command and check for end of game.
     finished = processCommand(*command);
     // Free the memory allocated by "parser.getCommand()"
     //   with ("return new Command(...)")
     delete command;
 }
 cout << endl;
 cout << "end" << endl;
} */

/* print the welcome message */
string ZorkUL::printWelcome() {
    return "-- Welcome to The Burren Abyss --\n"
            + currentRoom->longDescription();
}

/* prints the end message */
string ZorkUL::printEnd() {
    return "\nend";
}

/** COMMANDS */
/* prints the help information */
string ZorkUL::printHelp() {
    return "\nhelp:\n\tyou must reach The Terminus to win the game  :)\n\tif you run out of health and/or resilience, you lose  :(\n\n\tthe valid inputs are the buttons on this screen.\n\tclick the buttons to carry out the action. \n\nbuttons:\n\tdirectional buttons: up, down, left, right\n\tteleport: from current room to another room\n\tcharacter info: displays the characters information\n\tmap: map of the rooms and their exits\n\troom items: displays the room items in that room\n\tcharacter items: displays the character items in that room";
}

/*void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
    }
} */

/* teleports you to another room */
string ZorkUL::teleport() {
    currentRoom = &rooms.at((int) rand() % rooms.size());

    if (currentRoom == nullptr) {
        return "there was an error teleporting";
    } else {
        return currentRoom->longDescription();
    }
}

/* the map of the cave */
string ZorkUL::map() {
    string map;
    string spaces = "                                 "; // spacing to align chambers in map
 // string s =      "                                                                                         ";
    string link = "\n                                                                          |                        ";

    map += "The Burren Abyss map:\n";
    map += "\n" + spaces + "[Chamber 7] --- [Chamber 5]  --- [Chamber 6]";
    map += link;    map += link; // links room to and from The Cavern
    map += "\n[The Terminus] --- [Chamber 2] --- [The Cavern] --- [Chamber 1]";
    map += link;    map += link;  // links room to and from The Cavern
    map += "\n" + spaces + "[Chamber 8] --- [Chamber 3]  --- [Chamber 4]";

    return map; // displays the map
}

/* go command to enter another room, if there is an exit in that direction */
string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL) {
        return "no exit that way.";
    } else {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}

/* shows the items that are in the current room */
string ZorkUL::viewItems() {
    return currentRoom->displayItems();
}

/* shows what the current room is */
Room ZorkUL::getCurrentRoom() {
    return *currentRoom;
}
