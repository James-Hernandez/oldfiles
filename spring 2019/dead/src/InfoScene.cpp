#include "InfoScene.h"
#include "GLLight.h"

//Parallax* Para = new Parallax();

static Parallax* Plx = new Parallax();
static Parallax* Plx1 = new Parallax();

static Timer* Time1 = new Timer();
static Timer* Time2 = new Timer();

static Objects obj[5];
static TextureLoader *objTex = new TextureLoader;
static TextureLoader *objTex1 = new TextureLoader;
static TextureLoader *objTex2 = new TextureLoader;
static TextureLoader *objTex3 = new TextureLoader;
static TextureLoader *objTex4 = new TextureLoader;

static float parallaxYpos = -5;

InfoScene::InfoScene(SceneLoader* loader)
{
    // take the loader from the start screen
    this->loader = loader;
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    float xSize = 1;
    float ySize = 0.5;
}

InfoScene::~InfoScene()
{
    //dtor
}
GLint InfoScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);


    //GLLight Light(GL_LIGHT0);
    //Light.setLight(GL_LIGHT5);
    Plx->parallaxInit("images/landingpage.png");

    objTex->loadTexture("images/car.png");
    objTex1->loadTexture("images/red_button.png");
    objTex2->loadTexture("images/credits.png");
    objTex3->loadTexture("images/controls.png");

    //Para->parallaxInit("images/landingpage.png");
    return 1;
}

GLint InfoScene::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    /*
    glPushMatrix();
        Para->drawSquare(screenWidth, screenHeight);
    glPopMatrix();
    */
    glPushMatrix();
    Plx->drawSquare(screenWidth, screenHeight);
    glPopMatrix();
    Plx->scroll("right",0.04);

    obj[0].placeObjects(-2.25,-1.17,-2.5);//z -0.5
    obj[0].objectsInit();
    objTex->binder();
    obj[0].drawObjects(1,0.5);

    obj[1].placeObjects(2.5,1.3,-3.75);//z -0.5
    obj[1].objectsInit();
    objTex1->binder();
    obj[1].drawObjects(0.5,0.5);

    if(Time2->getTicks()>1000)
    {
    obj[1].placeObjects(-1.25,parallaxYpos,-3.75);//z -0.5
    obj[1].objectsInit();
    objTex2->binder();
    obj[1].drawObjects(3,3);

    if(parallaxYpos>-5)
    {
        parallaxYpos-=0.05;
    }
    }
    if(parallaxYpos<=-5)
    {
        parallaxYpos=1.5;
    }

    obj[3].placeObjects(-2.5,-1.0,-3.75);//z -0.5
    obj[3].objectsInit();
    objTex3->binder();
    obj[3].drawObjects(1.05,2);

}

int InfoScene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg){
        case WM_KEYDOWN:
            if(wParam == VK_BACK){
                loader->actuallyLoadScene("Start");
            }
        case WM_LBUTTONDOWN:
            {
            //  Copied from StartScene.cpp
            GLdouble modelMat[16];
            GLdouble projMat[16];
            GLint viewport[4];
            glGetDoublev(GL_MODELVIEW_MATRIX, modelMat);
            glGetDoublev(GL_PROJECTION_MATRIX, projMat);
            glGetIntegerv(GL_VIEWPORT, viewport);

            GLScene::convertMouseCoord((float)LOWORD(lParam), (float) viewport[3] - (GLfloat)HIWORD(lParam) - 1, modelMat, projMat, viewport);
            //cout << mouseX << " X " << mouseY << " Y " << endl; //getting coords
            if(mouseX > 2.55863 && mouseX < 2.9304 && mouseY > 1.3667 && mouseY < 1.738){
                loader->actuallyLoadScene("Start");
            }
            else if(mouseX > -2.438 && mouseX < 1.58 && mouseY > 0.0208 && mouseY < 0.5612){

            }
            }
        case 0x43:
            {

            }
    }
}
