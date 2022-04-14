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
    string longDescription;
    int weightGrams;
    float value;

/* access specifier: accessible from outside the class */
public:
  //Item();
    Item(string description, int weightGrams, float value);
    Item(string description); // copy constructor
    string getShortDescription();
    string getLongDescription();
    bool operator==(Item &i);   // operator overloading
    int getWeight();
    void setWeight(int inWeightGrams);
    float getValue();
    void setValue(float inValue);
};

#endif /* ITEM_H_ */
