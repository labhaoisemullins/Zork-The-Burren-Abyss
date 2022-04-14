/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: character.h
*/

/* Header guards to prevent header files being included numerous times */
#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "zorkul.h"  // include zorkul header file

#include <string>
using std::vector;
#include <vector>

using namespace std;  // namespace

class Character {
    friend class mainwindow;  // friends- allows mainwindow to access private members of character

/* access specifier: only within the class and mainwindow */
private:
    string description;
    vector< Item > itemsInCharacter;    // vector
    int health;
    int resilience;
    float carriedWeight;

/* access specifier: accessible from outside the class */
public:
  //Character();
    Character(string description);
    string shortDescription();
    string longDescription();
    vector<Item > viewItems();      // vector
    Item findItem(Item item);
    int findItemPos(Item item);
    void removeItem(Item item);
    bool isOverloaded(float maxWeight);
    string viewCharacterInfo();
    void addItem(string itemDescription);
    void addItem(Item *item);
    void addItem(Item &item);
    int getResilience();
    void setResilience(int resilience);
    void decrementResilience();
    int getHealth();
    void setHealth(int health);
    void decrementHealth();
};

#endif  /* CHARACTER_H_ */
