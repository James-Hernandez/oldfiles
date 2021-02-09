#include "GLScene.h"
#include <GLLight.h>
#include<Inputs.h>
#include<Model.h>
#include<Parallax.h>
#include<Player.h>
#include<Objects.h>


Inputs *KbMs = new Inputs();
Model *Mdl = new Model();
Parallax *plx = new Parallax();
Player *ply = new Player();
Objects Obj[10];///because of multiple objects
TextureLoader *objTex = new TextureLoader();

GLScene::GLScene()
{
    //ctor
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
}

GLScene::~GLScene()
{
    //dtor
}
GLint GLScene::initGL()
{
    glShadeModel(GL_SMOOTH);//for good transition in animations
    glClearColor(0.5f,1.0f,0.0f,0.0f);//set background color
    glClearDepth(1.0f);//decide what is at front and behind
    glEnable(GL_DEPTH_TEST);//for the depth calculations
    //glEnable(GL_COLOR_MATERIAL);
    GLLight Light(GL_LIGHT0);//create light instance

    //for(int i = 0; i < 26; i++)
    //{

    //}

    /*int GLScene::winMsg(HWND hWnd, UNIT uMsg, WPARAM wParam, LPARAM lParam)
    {

    }
    */
    objTex->loadTexture("images/asteroid.png");
    for(int i = 0; i < 10; i++)
    {

    Obj[i].xSize = Obj[i].ySize = (rand()% 5)/10.0;

    Obj[i].placeObjects(((rand()% 20)-10)/10.0,(rand()% 10)/10.0, -0.5);//((rand()% 10)-10)/10.0,-0.5);

    //Obj[i].ySize = (rand()% 10)/10.0;
    Obj[i].objectsInit();
    }

    Light.setLight(GL_LIGHT0);
    Mdl->modelInit("images/teapot.png");
    plx->parallaxInit("images/space.jpg");
    ply->playerInit("images/rocket.png");
    return true;
}

GLint GLScene::drawGLScene()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();

/*
glPushMatrix();
Mdl->drawModel();
glPopMatrix();
*/
glPushMatrix();
plx->drawSquare(screenWidth,screenHeight);
glPopMatrix();

glPushMatrix();

    objTex->binder();
    //Obj[0].drawObjects();
    for(int i =0; i < 10; i++){
           // Obj[i].xSize = Obj[i].ySize = (rand()% 5)/10.0;
           //Obj[i].placeObjects(((rand()% 20)-10)/10.0,((rand()% 10)-10)/10.0,-0.5);
       Obj[i].drawObjects();
       //Obj[i].collision(ply->xPos,ply->yPos);

    }
//obj->moveObjects();

glPopMatrix();

glPushMatrix();
    glTranslated(ply->xPos,ply->yPos,ply->zPos);
    glScaled(ply->siz,ply->siz,ply->siz);
//glPopMatrix();


//glPushMatrix();
glRotatef(ply->alpha,0.0,0.0,1.0);
ply->drawPlayer();

ply->playerActions();
ply->playerAct("Go");

glPopMatrix();

glPushMatrix();
Obj->collision(ply->xPos,ply->yPos);
glPopMatrix();

//ply->playerActions("left");
//ply->playerActions("right");
plx->scroll("up",0.01);


}

GLvoid GLScene::resizeGLScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat)height;
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,aspectRatio,0.1,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
}
int GLScene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch(uMsg)
        {
        case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
			KbMs ->wParam = wParam;
			KbMs ->keyPressed(Mdl);
			KbMs ->keyEnv(plx,0.005);
			KbMs ->playerAction(ply);
		}break;

        case WM_KEYUP:								// Has A Key Been Released?
		{
			ply ->actionTrigger = "Stand";								// Jump Back


		}break;

		case WM_LBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(Mdl,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

   		case WM_RBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(Mdl,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

          case WM_MBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(Mdl,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
        {
            KbMs->mouseEventUp();
        break;								// Jump Back
        }

        case WM_MOUSEMOVE:
        {
             KbMs->mouseEventMove(Mdl,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

        case WM_MOUSEWHEEL:
        {
            KbMs->mouseEventWheel(Mdl,(double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;								// Jump Back
        }
}
}




