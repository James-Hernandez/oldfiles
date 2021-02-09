#include "MusicSelectScene.h"
static Parallax* Plx = new Parallax();

MusicSelectScene::MusicSelectScene(SceneLoader* loader)
{
    this->loader = loader;
}

MusicSelectScene::~MusicSelectScene()
{
    //dtor
}

GLint MusicSelectScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(128.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    Plx->parallaxInit("images/background.jpg");
    return true;
}

GLint MusicSelectScene::drawGLScene()
{
    glLoadIdentity();

    glPushMatrix();
        Plx->drawSquare(screenWidth, screenHeight);
    glPopMatrix();

    glEnable(GL_SCISSOR_TEST);
    glScissor(screenWidth/2 - 400, screenHeight/2 - 300, 800, 600);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidSphere(1.2, 30, 30);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

int MusicSelectScene::winMsg(HWND, UINT, WPARAM, LPARAM)
{
    // inputs here.
}

GLvoid MusicSelectScene::resizeGLScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat) width / (GLfloat) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspectRatio, 1.0, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
}
