#include "creatorwindow.h"
#include "ui_creatorwindow.h"
#include <QCoreApplication>

creatorwindow::creatorwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::creatorwindow)
{
    ui->setupUi(this);
}

creatorwindow::~creatorwindow()
{
    delete ui;
}
