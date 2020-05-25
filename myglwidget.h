#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <QtWidgets>
#include <QGLWidget>
#include <QTimer>
#include "mainwindow.h"


class MyGlWidget : public QGLWidget
{
       Q_OBJECT
public:
    explicit MyGlWidget(QWidget *parent = nullptr);
    ~MyGlWidget();

    float heightP = 600.0f, wedthP = 300.0f, topP = 16.0f;
    float cylX, cylY, cylHeight, cylRad;

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    void mousePressEvent(QMouseEvent* pe) override;
    void mouseMoveEvent(QMouseEvent* pe) override;
//
    void wheelEvent(QWheelEvent* pe) override;

private:
    void drawPanel(float height, float wedth, float top);
    void drawCylinder(float cX, float cY, float cHeight, float cRad);
    QTimer timer;

    GLfloat xRot;
    GLfloat yRot;
    GLfloat zRot;
    GLfloat zTra;
    GLfloat nSca;

    QPoint ptrMousePosition;

    void scale_plus();
    void scale_minus();
    void rotate_up();
    void rotate_down();
    void rotate_left();
    void rotate_right();
    void translate_down();
    void translate_up();
    void defaultScene();

    void drawAxis();


};

#endif // MYGLWIDGET_H
