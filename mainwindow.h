#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QIcon>
#include <QPushButton>
#include <QAction>
#include <QToolBar>
#include <QFileDialog>
#include <QString>
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

    void on_action_Open_triggered();

    void on_action_Save_triggered();

    void on_actionTools_toggled(bool arg1);

    void on_lineX_textChanged(const QString &arg1);

    void on_lineY_textChanged(const QString &arg1);

    void on_lineDiam_textChanged(const QString &arg1);

    void on_lineDepth_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
