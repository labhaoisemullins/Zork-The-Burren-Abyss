/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: main.cpp
*/

#include "mainwindow.h"        // include mainwindow header file

#include <QDialog>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QVBoxLayout>

int main(int argc, char **argv){
    QApplication app(argc, argv);

    QDialog initialwindow;  // QDialog object called initialwindow
   
/* using qt signal and slots , connect(object1,signal,object2,slot) */
    QPushButton *start = new QPushButton{"start"};  // start button, starts game and opens mainwindow
    QObject::connect(start, &QPushButton::clicked, &initialwindow, &QDialog::accept);
    QPushButton *quit = new QPushButton{"quit"};    // quit button, exits screen
    QObject::connect(quit, &QPushButton::clicked, &initialwindow, &QDialog::reject);

    QVBoxLayout *dialog_layout = new QVBoxLayout{&initialwindow};  // box for start and quit button
        dialog_layout->addWidget(new QLabel{"          The Burren Abyss          "});
        dialog_layout->addWidget(start);    // add start button to box
        dialog_layout->addWidget(quit);     // add quit button to box

    mainwindow window;    // mainwindow object called window

    if (initialwindow.exec() == QDialog::Accepted){
            qDebug() << "Accepted";
            window.show();  // start game if start button is clicked
        }else
            qDebug() << "Rejected";   // end game if quit button is clicked

        return app.exec();   // start application/game
    }
