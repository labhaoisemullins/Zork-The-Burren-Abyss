/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: main.cpp
*/

//#include "initialwindow.cpp"    // include initialwindow source file
//#include "initialwindow.h"      // include initialwindow header file
//#include "ui_initialwindow.h"   // include initialwindow ui header file
#include "mainwindow.h"        // include mainwindow header file
//#include "ui_mainwindow.h"      // include mainwindow ui header file

#include <QDialog>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QVBoxLayout>

int main(int argc, char **argv){
    QApplication app(argc, argv);

  //  QDialog initialwindow;
  //  initialwindow.show();
  //  initialwindow start;
  //  initialwindow quit;

    QDialog initialwindow;
    QPushButton *start = new QPushButton{"start"};
    QObject::connect(start, &QPushButton::clicked, &initialwindow, &QDialog::accept);
    QPushButton *quit = new QPushButton{"quit"};
    QObject::connect(quit, &QPushButton::clicked, &initialwindow, &QDialog::reject);

    QVBoxLayout *dialog_layout = new QVBoxLayout{&initialwindow};
        dialog_layout->addWidget(new QLabel{"          start game        "});
        dialog_layout->addWidget(start);
        dialog_layout->addWidget(quit);

    mainwindow window;

    if (initialwindow.exec() == QDialog::Accepted){
            qDebug() << "Accepted";
            window.show();
        }else
            qDebug() << "Rejected";

        return app.exec();
    }
