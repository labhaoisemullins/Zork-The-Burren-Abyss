/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: item.h
*/

/* Header guards to prevent header files being included numerous times */
#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <map>
#include <string>

using namespace std;  // namespace

class Item{
/* access specifier: accessible only within the class */
private:
    string description;
    int weightGrams;
    float value;
    string longDescription;

/* access specifier: accessible from outside the class */
public:
    Item(string inDescription, int inWeightGrams, float inValue);
    Item(string inDescription); // copy constructor
    bool operator==(Item &i);   // operator overloading
    void setWeight(int inWeightGrams);
    void setValue(float inValue);
    int getWeight();
    float getValue();
    string getShortDescription();
    string getLongDescription();
};

#endif /* ITEM_H_ */
