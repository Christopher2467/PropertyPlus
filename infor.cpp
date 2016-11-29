#include "infor.h"
#include "ui_infor.h"

Infor::Infor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Infor)
{
    ui->setupUi(this);
}

Infor::~Infor()
{
    delete ui;
}
