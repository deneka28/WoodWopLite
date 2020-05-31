#include "myglwidget.h"
#include "ui_mainwindow.h"

#define PI 3.1415927

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
    glClearColor(0.53, 0.63, 0.66, 1);
    glEnable(GL_DEPTH_TEST); // задаем глубину проверки пикселей
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

    glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
    drawPanel(heightP, wedthP, topP);

    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
    drawCylinder(cylX, cylY, cylHeight, cylRad);

    glFlush();

}

void MyGlWidget::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat ratio = (GLfloat)h/(GLfloat)w;

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
        glColor4f(0.5f, 0.3f, 0.2f, 1.0f);
        glBegin(GL_QUADS);
        // FRONT
        glVertex3f(0.0f, -0.0f, top);
        glVertex3f( height, 0.0f, top);
        glVertex3f( height, wedth, top);
        glVertex3f(0.0f, wedth, top);
        // BACK
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, wedth, 0.0f);
        glVertex3f( height, wedth, 0.0f);
        glVertex3f( height, 0.0f, 0.0f);
        // LEFT
        glVertex3f(0.0f, 0.0f, top);
        glVertex3f(0.0f, wedth, top);
        glVertex3f(0.0f, wedth, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        // RIGHT
        glVertex3f( height, 0.0f, 0.0f);
        glVertex3f( height, wedth, 0.0f);
        glVertex3f( height, wedth, top);
        glVertex3f( height, 0.0f, top);
        // TOP
        glVertex3f(0.0f, wedth, top);
        glVertex3f( height, wedth, top);
        glVertex3f( height, wedth, 0.0f);
        glVertex3f(0.0f, wedth, 0.0f);
        // BOTTOM
        glVertex3f(0.0f, 0.0f, top);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f( height, 0.0f, 0.0f);
        glVertex3f( height, 0.0f, top);
        glEnd();
}

void MyGlWidget::drawCylinder(float cX, float cY, float cHeight, float cRad)
{
    int num_segments = 32;

    /** Draw the tube */
    glColor3f(0, 40, 0);
    glBegin(GL_QUAD_STRIP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * PI * float(ii) / float(num_segments);
        float x = cRad / 2 * cosf(theta);
        float y = cRad / 2 * sinf(theta);

        glVertex3f(x + cX, y + cY, topP);
        glVertex3f(x + cX, y + cY, topP - cHeight);
    }
   glEnd();

    //cyrkle
   glColor3f(0, 40, 0);
    glBegin(GL_POLYGON);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * PI * float(ii) / float(num_segments);//get the current angle
        float x = cRad / 2 * cosf(theta);
        float y = cRad / 2 * sinf(theta);

        glVertex3f(x + cX, y + cY, topP);
    }
    glEnd();

    glColor3f(0, 40, 0);
     glBegin(GL_POLYGON);
     for(int ii = 0; ii < num_segments; ii++)
     {
         float theta = 2.0f * PI * float(ii) / float(num_segments);//get the current angle
         float x = cRad / 2 * cosf(theta);
         float y = cRad / 2 * sinf(theta);

         glVertex3f(x + cX, y + cY, topP - cHeight);
     }
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
    glLineWidth(4.0f);

    glColor4f(1.00f, 0.00f, 0.00f, 1.0f);
    glBegin(GL_LINES);
       glVertex3f( 8.0f,  -1.0f,  0.0f);
       glVertex3f(-1.0f,  -1.0f,  0.0f);
    glEnd();

    QColor halfGreen(0, 128, 0, 255);
    qglColor(halfGreen);
    glBegin(GL_LINES);
       glVertex3f( -1.0f,  8.0f,  0.0f);
       glVertex3f( -1.0f, -1.0f,  0.0f);

       glColor4f(0.00f, 0.00f, 1.00f, 1.0f);
       glVertex3f( -1.0f,  -1.0f,  8.0f);
       glVertex3f( -1.0f,  -1.0f, 0.0f);
    glEnd();
}


