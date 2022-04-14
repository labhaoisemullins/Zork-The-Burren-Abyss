/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: commandwords.h
*/

/* Header guards to prevent header files being included numerous times */
#ifndef COMMANDWORDS_H_
#define COMMANDWORDS_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;   // namespace

class CommandWords {
/* access specifier: accessible only within the class */
private:
// Define a static vector for our valid command words.
// We'll populate this in the class constructor
    static vector<string> validCommands;


/* access specifier: accessible from outside the class */
public:
    CommandWords();
    bool isCommand(string aString);
    void showAll();
};


#endif /* COMMANDWORDS_H_ */
