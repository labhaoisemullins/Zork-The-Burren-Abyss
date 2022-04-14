/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: mainwindow.h
*/

/* Header guards to prevent header files being included numerous times */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QDialog>
#include <vector>
using std::string;
#include <string>

//#include "initialwindow.h"
#include "zorkul.h"     // include zorkul header file
#include "character.h"  // include character header file

namespace Ui {          // namespace
class mainwindow;
}

/* Inheritance */
class mainwindow : public QMainWindow{
    Q_OBJECT

    friend class Room;       // friend- allows room to access private members of mainwindow
    friend class Character;  // friends- allows character to access private members of mainwindow
  //  friend class initialwindow;

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();  // Destructor

    void overloadedCheck();
    void allRoomItemsCollectedTest();
    void disableAllButtons();
    void addItemsToListWidget(vector<Item> item);   // vector
    string displayResilience();
    string displayHealth();
    void printCharacterStats();
    void endGameState(string m1, string m2);

/* access specifier: accessible only within the class, room class and the character class */
private:
    Ui::mainwindow *ui;

    ZorkUL *zork = new ZorkUL();
    Character character = *new Character("Caveman");
    bool putInInventory;
    void goRoom(string direction);
    void listItems(vector<Item> items, QString description);

private slots:
    void on_pushButton_clicked();       // down
    void on_pushButton_2_clicked();     // left
    void on_pushButton_3_clicked();     // up
    void on_pushButton_4_clicked();     // right
    void on_pushButton_5_clicked();     // teleport
    void on_pushButton_6_clicked();     // character information
    void on_pushButton_7_clicked();     // help
    void on_pushButton_8_clicked();     // map
    void on_pushButton_9_clicked();     // room items
    void on_pushButton_10_clicked();    // character items
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);  // displays items
};

#endif /* MAINWINDOW_H */
