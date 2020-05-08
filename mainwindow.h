#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include "myglwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_widthPanel_textChanged(const QString &arg1);

    void on_heightPanel_textChanged(const QString &arg1);

    void on_topPanel_textChanged(const QString &arg1);

    void on_action_Close_triggered();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
