#include "mainwindow.h"
#include "ui_creatorwindow.h"		

creatorWindow::creatorWindow(QWidget *parent) :		
QMainWindow(parent),		
 ui(new Ui::MainWindow)		
 {		
 ui->setupUi(this);		
 }		
 		
 creatorWindow::~creatorWindow()		
 {		
 delete ui;		
 }
