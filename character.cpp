/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: character.cpp
*/

#include "character.h"  // include character header file
#include <string>       // include string header

/* initializer list */
Character::Character(string description){
    itemsInCharacter.empty();
    this->description = description;
    resilience = 5;
    health = 5;
}

void Character::addItem(Item *item){    // points to variable item
    itemsInCharacter.push_back(*item);
    carriedWeight += item->getWeight();
}

void Character::addItem(Item &item){   // address of the variable item
    itemsInCharacter.push_back(item);
    carriedWeight += item.getWeight();
}

vector<Item> Character::viewItems(){
    return itemsInCharacter;
}

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

     character += "\nCharacter name: " + this->description + ".\n";

    if (itemsInCharacter.empty()){
        character += "\nyou're carrying no items.";
    }else{
        character += "\nitem(s):   ";

        for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++){
            character += (*i).getLongDescription() + "\n";
        }
    }
    return character;
}

Item Character::findItem(Item item){
    for (unsigned int i = 0; i < (unsigned int)itemsInCharacter.size(); i++){
        if (itemsInCharacter[i] == item){
            return itemsInCharacter[i];
        }
    }
}

int Character::findItemPos(Item item){
    for (unsigned int i = 0; i < (unsigned int)itemsInCharacter.size(); i++)    {
        if (itemsInCharacter[i] == item){
            return i;
        }
    }
}

string Character::viewCharacterInfo(){
    string output = "";
    output += longDescription();
    output += "\ncarried weight: " + to_string(carriedWeight) + "g.";
    return output;
}

void Character::removeItem(Item item) {
    itemsInCharacter.erase(itemsInCharacter.begin() + findItemPos(item));
}

bool Character::isOverloaded(float maxWeight){
    if (carriedWeight > maxWeight){
        return true;
    }else{
        return false;
    }
}

int Character::getResilience(){
    return resilience;
}

void Character::setResilience(int resilience){
    this->resilience = resilience;
}

void Character::decrementResilience(){
    resilience--;

    if (resilience < 0 && health > 1){
        setResilience(10);
        decrementHealth();
    }
}

int Character::getHealth(){
    return health;
}

void Character::setHealth(int health){
    this->health = health;
}

void Character::decrementHealth(){
    health--;
}
