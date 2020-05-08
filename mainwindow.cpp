#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myglwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_widthPanel_textChanged(const QString &arg1)
{
    this->ui->myGLWidget->wedthP = arg1.toFloat();
}

void MainWindow::on_heightPanel_textChanged(const QString &arg1)
{
    this->ui->myGLWidget->heightP = arg1.toFloat();
}

void MainWindow::on_topPanel_textChanged(const QString &arg1)
{
    this->ui->myGLWidget->topP = arg1.toFloat();
}

void MainWindow::on_action_Close_triggered()
{
    close();
}
