#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <QtWidgets>
#include <QGLWidget>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <QTimer>
#include "mainwindow.h"


class MyGlWidget : public QGLWidget
{
       Q_OBJECT
public:
    explicit MyGlWidget(QWidget *parent = nullptr);
    ~MyGlWidget();

    float heightP = 0.5f, wedthP = 0.5f, topP = 0.5f;

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;



private:
    void draw();
    void drawPanel(float height, float wedth, float top);
    QTimer timer;

};

#endif // MYGLWIDGET_H
