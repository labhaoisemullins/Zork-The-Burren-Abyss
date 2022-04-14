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

/* initializer list ,  copy constructor */
Item::Item(string inDescription){
    this->description = inDescription;
    this->weightGrams = 1;
    this->value = 1;
}

/*Operator Overloading */
bool Item::operator==(Item &i){
    int test = 0;

    if(this->getShortDescription() == i.getShortDescription()){
        test = 1;
    }
    return test;
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

string Item::getShortDescription(){
    return description;
}

string Item::getLongDescription(){
    return description;
}
