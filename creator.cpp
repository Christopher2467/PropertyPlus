#include "creator.h"
#include "ui_creator.h"

creator::creator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::creator)
{
    ui->setupUi(this);
}

creator::~creator()
{
    delete ui;
}
