/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: item.cpp
*/

#include "item.h"   // include item header file

/* initializer list */
Item::Item(string inDescription, int inWeightGrams, float inValue){
    this->description = inDescription;
    this->weightGrams = inWeightGrams;
    this->value = inValue;
}

/* Initializer list ,  copy constructor */
Item::Item(string inDescription){
    this->description = inDescription;
    this->weightGrams = 1;
    this->value = 1;
}

/* Operator Overloading */
bool Item::operator==(Item &i){
    int t = 0;
    if(this->getShortDescription() == i.getShortDescription()){
        t = 1;
    }
    return t;
}

/* set the weight */
void Item::setWeight(int inWeightGrams){
    if (inWeightGrams > 9999 || inWeightGrams < 0)
       cout << "weight invalid, must be 0 < weight < 9999." ;
       else
        weightGrams = inWeightGrams;
}

/* set the value */
void Item::setValue(float inValue){
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0 < value < 9999." ;
    else
       value = inValue;
}

/* get weight function */
int Item::getWeight(){
    return weightGrams;
}

/* get the value */
float Item::getValue(){
    return value;
}

/* return the short description */
string Item::getShortDescription(){
    return description;
}

/* return the long description */
string Item::getLongDescription(){
    return description;
}
