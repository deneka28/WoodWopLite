#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myglwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pixmap(":/new/icons/icons/utilities.svg");
    QIcon iconTab_2(pixmap);
    ui->tabWidget->setTabIcon(1, iconTab_2);
    ui->tabWidget->setIconSize(pixmap.rect().size());

    QPixmap pixmap2(":/new/icons/icons/icon.svg");
    QIcon iconTab_1(pixmap2);
    ui->tabWidget->setTabIcon(0, iconTab_1);
    ui->tabWidget->setIconSize(pixmap.rect().size());
    ui->action_Close->setIcon(QIcon::fromTheme("window-close"));

    ui->actionVerticalDrill->setVisible(false);
    ui->actionHorizontalDrill->setVisible(false);
    ui->myGLWidget->setFocus();


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

void MainWindow::on_action_Open_triggered()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("Open file"), QDir::currentPath());
}

void MainWindow::on_action_Save_triggered()
{
    QString path;
    path = QDir::currentPath() + "/untitled.mpr";

    QString fileName;
    fileName = QFileDialog::getSaveFileName(this, tr("Save file"), path);
}

void MainWindow::on_actionTools_toggled(bool arg1)
{
    ui->actionVerticalDrill->setVisible(arg1);
    ui->actionHorizontalDrill->setVisible(arg1);

}
