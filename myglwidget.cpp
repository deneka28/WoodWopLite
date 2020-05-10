#include "myglwidget.h"


MyGlWidget::MyGlWidget(QWidget *parent)
    : QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(16);

}

MyGlWidget::~MyGlWidget()
{

}

void MyGlWidget::initializeGL()
{
    glClearColor(0.30, 0.43, 0.48, 1);
    glEnable(GL_DEPTH_TEST); // задаем глубину проверки пикселей
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void MyGlWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очистка экрана
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);

    gluLookAt(0,0,5, 0,0,0, 0,1,0);

    glRotatef(30.0f, 0.5f, 0.0f, 0.0f);
    glRotatef(30.0f, 0.0f, 0.5f, 0.0f);

    glColor3f(1.0f, 0.4f, 0.3f);

    drawPanel(wedthP, heightP, topP);

    glFlush();

}

void MyGlWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h); // установка точки обзора
    glMatrixMode(GL_PROJECTION); // установка режима матрицы
    glLoadIdentity(); // загрузка матрицы
    gluPerspective(45.0, (float)w/h, 0.01, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    updateGL();
}

void MyGlWidget::drawPanel(float height, float wedth, float top)
{
        glBegin(GL_QUADS);
        // FRONT
        glVertex3f(-1.0f * height, -1.0f * wedth, top);
        glVertex3f( height, -1.0f * wedth, top);
        glVertex3f( height, wedth, top);
        glVertex3f(-1.0f * height, wedth, top);
        // BACK
        glVertex3f(-1.0f * height, -1.0f * wedth, -1.0f * top);
        glVertex3f(-1.0f * height, wedth, -1.0f * top);
        glVertex3f( height, wedth, -1.0f * top);
        glVertex3f( height, -1.0f * wedth, -1.0f * top);
        // LEFT
        glVertex3f(-1.0f * height, -1.0f * wedth, top);
        glVertex3f(-1.0f * height, wedth, top);
        glVertex3f(-1.0f * height, wedth, -1.0f * top);
        glVertex3f(-1.0f * height, -1.0f * wedth, -1.0f * top);
        // RIGHT
        glVertex3f( height, -1.0f * wedth, -1.0f * top);
        glVertex3f( height, wedth, -1.0f * top);
        glVertex3f( height, wedth, top);
        glVertex3f( height, -1.0f * wedth, top);
        // TOP
        glVertex3f(-1.0f * height, wedth, top);
        glVertex3f( height, wedth, top);
        glVertex3f( height, wedth, -1.0f * top);
        glVertex3f(-1.0f * height, wedth, -1.0f * top);
        // BOTTOM
        glVertex3f(-1.0f * height, -1.0f * wedth, top);
        glVertex3f(-1.0f * height, -1.0f * wedth, -1.0f * top);
        glVertex3f( height, -1.0f * wedth, -1.0f * top);
        glVertex3f( height, -1.0f * wedth, top);
        glEnd();
}

