/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: character.cpp
*/

#include "character.h"  // include character header file
#include <string>       // include string header

/* Initializer list */
Character::Character(string description){
    itemsInCharacter.empty();
    this->description = description;
    resilience = 5;   // set resilience stats to 5 at start of game
    health = 3;      // set health stats to 3 at start of game
}

void Character::addItem(Item *item){    // points to variable item
    itemsInCharacter.push_back(*item);
    carriedWeight += item->getWeight();
}

void Character::addItem(Item &item){   // address of the variable item
    itemsInCharacter.push_back(item);
    carriedWeight += item.getWeight();
}

/* view the character items */
vector<Item> Character::viewItems(){
    return itemsInCharacter;
}

/* return the short description */
string Character::shortDescription(){
    return this->description;
}

/* string image of caveman */
string Character::longDescription(){
    string character = "";

     character += "\n     |^^^^| ";
     character += "\n     |  o  o  |";
     character += "\n     |    r     |";
     character += "\n     |  ----  |";
     character += "\n+_____|______+";
     character += "\n           |";
     character += "\n           |";
     character += "\n        __|__   ";
     character += "\n      |       |";
     character += "\n      |       |";
     character += "\n      |       |";
     character += "\n      |       |\n";

     character += "\ncharacter name: " + this->description + ".\n";

     string output = "";
     output += "\ncarried weight: " + to_string(carriedWeight) + "g.\n";  // carried weight in grams

    if (itemsInCharacter.empty()){
        character += "\nyou're carrying no items.";
    }else{
        character += "\nitem(s):   ";

        for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++){
            character += (*i).getLongDescription() + "\n";
        }
    }
    return character + output;
}

/* find the item */
Item Character::findItem(Item item){
    for (unsigned int i = 0; i < (unsigned int)itemsInCharacter.size(); i++){
        if (itemsInCharacter[i] == item){
            return itemsInCharacter[i];
        }
    }
}

/* find the position of the item */
int Character::findItemPos(Item item){
    for (unsigned int i = 0; i < (unsigned int)itemsInCharacter.size(); i++){
        if (itemsInCharacter[i] == item){
            return i;
        }
    }
}

/* remove the item */
void Character::removeItem(Item item) {
    itemsInCharacter.erase(itemsInCharacter.begin() + findItemPos(item));
}

/* check if the caveman is carrying too much weight */
bool Character::isOverloaded(float maxWeight){
    if (carriedWeight > maxWeight){
        return true;   /* character is carrying too much weight */
    }else{
        return false;  /* character is carrying an okay weight */
    }
}

/* return resilience amount (*) */
int Character::getResilience(){
    return resilience;
}

/* set the resilience */
void Character::setResilience(int resilience){
    this->resilience = resilience;
}

/* decrement resilience */
void Character::decrementResilience(){
    resilience--;
    
/* increase resilience to 6(*) if health has more than one (+) */
    if (resilience < 0 && health > 1){
        setResilience(6);  // 6 *
        decrementHealth();
    }
}

/* return health amount (+) */
int Character::getHealth(){
    return health;
}

/* set the health */
void Character::setHealth(int health){
    this->health = health;
}

/* decrement health */
void Character::decrementHealth(){
    health--;
}
