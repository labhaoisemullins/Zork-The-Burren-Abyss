/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: weapon.cpp
*/

#include "weapon.h"      // include weapon header file

/* Inheritance */
/* Initializer list */
Weapon::Weapon(string description, int weightGrams, float value, float damage, int durability) : Item(description, weightGrams, value){
    this->damage = damage;
    this->durability = durability;
}
