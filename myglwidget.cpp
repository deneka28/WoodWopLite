#include "myglwidget.h"
#include "ui_mainwindow.h"

MyGlWidget::MyGlWidget(QWidget *parent)
    : QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(16);

    xRot=0; yRot=0; zRot=0; zTra=0; nSca=1;

}

MyGlWidget::~MyGlWidget()
{

}

void MyGlWidget::initializeGL()
{
    glClearColor(0.30, 0.43, 0.48, 0);
    glEnable(GL_DEPTH_TEST); // задаем глубину проверки пикселей
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);
}

void MyGlWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glScalef(nSca, nSca, nSca);
    glTranslatef(0.0f, zTra, 0.0f);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glRotatef(zRot, 0.0f, 0.0f, 1.0f);

    drawAxis();
    drawPanel(heightP, wedthP, topP);

    glFlush();

}

void MyGlWidget::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat ratio=(GLfloat)h/(GLfloat)w;

    if (w>=h)
       glOrtho(-1.0/ratio, 1.0/ratio, -1.0, 1.0, -10.0, 1.0);
    else
       glOrtho(-1.0, 1.0, -1.0*ratio, 1.0*ratio, -10.0, 1.0);

    glViewport(0, 0, (GLint)w, (GLint)h);
}

void MyGlWidget::mousePressEvent(QMouseEvent *pe)
{
    ptrMousePosition = pe->pos();
}

void MyGlWidget::mouseMoveEvent(QMouseEvent *pe)
{
    xRot += 180/1*(GLfloat)(pe->y()-ptrMousePosition.y())/height();
    zRot += 180/1*(GLfloat)(pe->x()-ptrMousePosition.x())/width();

    ptrMousePosition = pe->pos();

    updateGL();
}


void MyGlWidget::wheelEvent(QWheelEvent *pe)
{
    if ((pe->delta())>0) scale_plus(); else if ((pe->delta())<0) scale_minus();

    updateGL();
}

void MyGlWidget::drawPanel(float height, float wedth, float top)
{
        glLineWidth(1.0f);
        glColor3f(0.5f, 0.5f, 0.2f);
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

void MyGlWidget::scale_plus()
{
   nSca = nSca*1.1;
}

void MyGlWidget::scale_minus()
{
   nSca = nSca/1.1;
}

void MyGlWidget::defaultScene()
{
    xRot=0; yRot=0; zRot=0; zTra=0; nSca=1;
}

void MyGlWidget::drawAxis()
{
    glLineWidth(2.0f);

    glColor4f(1.00f, 0.00f, 0.00f, 1.0f);
    glBegin(GL_LINES);
//       glVertex3f( 1.0f,  0.0f,  0.0f);
//       glVertex3f(-1.0f,  0.0f,  0.0f);
           glVertex3f( heightP/2,  0.0f,  0.0f);
           glVertex3f(-1.0f * (heightP/2),  0.0f,  0.0f);
    glEnd();

    QColor halfGreen(0, 128, 0, 255);
    qglColor(halfGreen);
    glBegin(GL_LINES);
       glVertex3f( 0.0f,  1.0f * (wedthP/2),  0.0f);
       glVertex3f( 0.0f, -1.0f * (wedthP/2),  0.0f);

       glColor4f(0.00f, 0.00f, 1.00f, 1.0f);
       glVertex3f( 0.0f,  0.0f,  1.0f * (topP/2));
       glVertex3f( 0.0f,  0.0f, -1.0f * (topP/2));
    glEnd();
}


