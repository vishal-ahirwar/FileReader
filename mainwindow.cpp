#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<fstream>
#include<iostream>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}



void MainWindow::on_actionSave_File_triggered()
{
  if(!this->ui->lineEdit->text().isEmpty())
    {

      std::fstream file;
      file.open(this->ui->lineEdit->text().toStdString().c_str(),std::ios::out);
      if(file.is_open())
        {
          file<<(this->ui->textEdit->toPlainText().toStdString());
        };
      file.close();
    }else
    {
      std::cerr<<"false running ..\n";
    }

}


void MainWindow::on_actionOpen_File_triggered()
{
  QString fileName{QFileDialog::getOpenFileName(this,"Open File(File Reader) ...","./")};
  this->ui->lineEdit->setText(fileName);
  FILE* file;
  file=fopen(fileName.toStdString().c_str(),"r");
  if(file)
    {
      QString str;
      int c= getc(file);
      while(c!=EOF)
        {
          str.append(QChar(c));
          c=getc(file);
        };
      this->ui->textEdit->setText(str);
      fclose(file);
    }

}


void MainWindow::on_actionQuit_Application_triggered()
{
    this->destroy();
}


void MainWindow::on_actionAbout_triggered()
{

}

