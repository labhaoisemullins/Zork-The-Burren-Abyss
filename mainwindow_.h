/**
Student ID: 20266928
Filename: mainwindow.h
*/

/** Header guards to prevent header files being included numerous times */
#ifndef MAINWINDOW__H  
#define MAINWINDOW__H  

#include <QDialog>
#include <QMainWindow>
#include <QListWidget>

#include <vector>
using std::string;
#include <string>

#include "zorkul.h"    // include zorkul header file
#include "character.h" // include character header file
//#include "mainwindow.cpp"
#include "initialwindow.h" // include initialwindow header file
//using namespace std;

namespace Ui {
    class mainwindow;
}

class mainwindow : public QMainWindow{
    Q_OBJECT

    friend class Character;  // friend class
    friend class Room;       // friend class

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();
    void overencumberedTest();
    void allRoomItemsCollectedTest();
    void disableAllButtons();
    void addItemsToListWidget(vector<Item> item);
    string displayResilience();
    string displayHealth();
    void printCharacterStats();
    void endGameState(string message1, string message2);

private:
    Ui::mainwindow *ui;
    ZorkUL *zork = new ZorkUL();
    Character character = *new Character("Caveman");
    bool putInInventory;
    void goRoom(string direction);
    void listItems(vector<Item> items, QString description);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
};

#endif /* MAINWINDOW__H */
