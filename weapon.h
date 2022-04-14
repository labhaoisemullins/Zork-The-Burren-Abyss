/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: weapon.h
*/

/* Header guards to prevent header files being included numerous times */
#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"   // include item header file

/* Inheritance */
class Weapon : public Item {

/* access specifier: accessible only within the class and item class */
private:
    float damage;
    int durability;

/* access specifier: accessible from outside the class */
public:
    Weapon(string description, int weightGrams, float value, float damage, int durability);
};

#endif /* WEAPON_H */
