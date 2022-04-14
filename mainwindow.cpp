/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: mainwindow.cpp
*/

#include "mainwindow.h"     // include mainwindow header file
#include "ui_mainwindow.h"  // include mainwindow ui header file
//#include "initialwindow.h"
//#include "initialwindow.h"

#include <algorithm>

/* Template */
template <typename T>
void addItem(vector<T> v, T t){     // vector
    v.push_back(t);
}

mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::mainwindow){
    ui->setupUi(this);

//    ui->textEdit_->setTextColor(QColor("purple"));   // set items color to purple
    ui->textEdit_3->setTextColor(QColor("orange")); // set health stats color to orange
    ui->textEdit_2->setTextColor(QColor("blue"));   // set resilience stats color blue
    ui->textEdit_->append(QString::fromStdString(zork->printWelcome() + "\n"));

    printCharacterStats();  // displays the current statistics of the character
}

/* Destructor */
mainwindow::~mainwindow(){ delete ui; }

/** push button 1: direction - down */
void mainwindow::on_pushButton_clicked(){
    goRoom("down");
}

/** push button 2: direction - left */
void mainwindow::on_pushButton_2_clicked(){
    goRoom("left");
}

/** push button 3: direction - up */
void mainwindow::on_pushButton_3_clicked(){
    goRoom("up");
}

/** push button 4: direction - right */
void mainwindow::on_pushButton_4_clicked(){
    goRoom("right");
}

/** push button 5: teleports to another room */
void mainwindow::on_pushButton_5_clicked(){
    goRoom("teleport");
}

/** push button 6: character information is displayed */
void mainwindow::on_pushButton_6_clicked(){
    ui->textEdit_->append(QString::fromStdString(character.longDescription()));
}

/** push button 7: help information is displayed */
void mainwindow::on_pushButton_7_clicked(){
    ui->textEdit_->append(QString::fromStdString(zork->printHelp()));
}

/** push button 8: map information is displayed */
void mainwindow::on_pushButton_8_clicked(){
    ui->textEdit_->append(QString::fromStdString(zork->map()));
}

/** push button 9: items in the current room are displayed */
void mainwindow::on_pushButton_9_clicked(){
    putInInventory = true;
    vector<Item> items = zork->getCurrentRoom().viewItems();
    listItems(items, "room");
}

/** push button 10: items belonging to the character in the current room are displayed */
void mainwindow::on_pushButton_10_clicked(){
    putInInventory = false;
    vector<Item> items = character.viewItems();  //vector
    listItems(items, "character");
}

/** list widget: displays the items (character/room) */
void mainwindow::on_listWidget_itemDoubleClicked(QListWidgetItem*item){  //
    string description = item->text().toStdString();
    Item i = *new Item(description);
    ui->listWidget->takeItem(ui->listWidget->row(item));

    if (putInInventory){
        Room r = zork->getCurrentRoom();
        Item m = r.findItem(i);
        //character.itemsInCharacter.push_back(m);
        addItem(character.itemsInCharacter, m);
        character.addItem(&m);
        r.removeItem(m);
        ui->textEdit_->append(QString::fromStdString(description + " has been added to the inventory.\n"));
        overloadedCheck();
    }else{
        Item m = character.findItem(i);
        Room r = zork->getCurrentRoom();
        addItem(r.itemsInRoom, m);
        character.removeItem(m);
        ui->textEdit_->append(QString::fromStdString(description + " has been removed from the inventory.\n"));
    }
}

void mainwindow::addItemsToListWidget(vector<Item> items){
    ui->listWidget->clear();

    if (putInInventory){
        if (!zork->getCurrentRoom().allItemsGathered()){
            for (unsigned int i = 0; (unsigned int)i < (unsigned int)zork->getCurrentRoom().numberOfItems(); i++){
                ui->listWidget->addItem(QString::fromStdString(items[i].getShortDescription()));
            }
        }else{
            ui->textEdit_->append(QString::fromStdString("no items in the room."));
        }
    }else{
        if (!character.itemsInCharacter.empty()){
            for (unsigned int i = 0; i < character.itemsInCharacter.size(); i++){
                ui->listWidget->addItem(QString::fromStdString(items[i].getShortDescription()));
            }
        }else{
            ui->textEdit_->append(QString::fromStdString("no items in " + character.shortDescription() + "'s inventory.\n"));
        }
    }
}

void mainwindow::endGameState(string m1, string m2){
    ui->pushButton_->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->listWidget->setEnabled(false);

    ui->textEdit_->setText(QString::fromStdString(character.description + " has " + m1 + ".\n" + character.description + " " + m2 + " the game.\n"));

    character.health = 0;
    character.resilience = 0;
    ui->textEdit_2->setText(QString::fromStdString(displayHealth()));
    ui->textEdit_3->setText(QString::fromStdString(displayResilience()));
}

void mainwindow::overloadedCheck(){
    if (character.isOverloaded(4.0)){
        endGameState("been overloaded with too much weight", "lost");
    }
}

void mainwindow::goRoom(string direction){
    if (character.health != 0 && character.resilience >= 0){
        character.decrementResilience();
        printCharacterStats();

        if (direction == "teleport"){
            ui->textEdit_->append(QString::fromStdString(zork->teleport() + "\n"));
        }else{
            ui->textEdit_->append(QString::fromStdString(zork->go(direction) + "\n"));

            if (zork->getCurrentRoom().description == "The Terminus"){
                endGameState("entered the winning room", "won");
            }
        }
    }else{
        endGameState("ran out of health", "lost");
    }
}

void mainwindow::listItems(vector<Item> items, QString description){
    if (!items.empty()){
        addItemsToListWidget(items);
    }else{
        ui->textEdit_->append("no " + description + " items found.\n");
    }
}

/* display the resilience statistics */
string mainwindow::displayResilience(){
    string resilience = "          Resilience:\n";

    for (int i = 0; i < character.resilience; i++){
        resilience += "   *   ";
    }
    return resilience;
}

/* display the health statistics */
string mainwindow::displayHealth(){
    string health = "             Health:\n";

    for (int i = 0; i < character.getHealth(); i++){
        health += "   +  ";
    }
    return health;
}

void mainwindow::printCharacterStats(){
    if (!(character.health > 0)){
        endGameState("ran out of health", "lost");
    }else{
        ui->textEdit_2->setText(QString::fromStdString(displayHealth()));   // health stats
        ui->textEdit_3->setText(QString::fromStdString(displayResilience()));  // resilience stats
    }
}
