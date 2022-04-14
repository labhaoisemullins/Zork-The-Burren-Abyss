/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: command.h
*/

/* Header guards to prevent header files being included numerous times */
#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>

using namespace std;   // namespace

class Command {
/* access specifier: accessible only within the class */
private:
    string commandWord;
    string secondWord;

/* access specifier: accessible from outside the class */
public:
    Command(string firstWord, string secondWord);
    string getCommandWord();
    string getSecondWord();
    bool isUnknown();
    bool hasSecondWord();
};

#endif  /* COMMAND_H_ */
