#include "Objects.h"

//TextureLoader * T1 = new TextureLoader();
Timer *Time1 = new Timer();
Objects::Objects()
{
    //ctor
        //xPos = 0.0;
       // yPos = 0.0;
        zPos = -0.5;

        xSize = 1.0;
        ySize = 1.0;

        rotateX = 0.0;
        rotateY = 0.0;
        rotateZ = 0.0;

    verticies[0].x = 0.0;
    verticies[0].y = 0.0;
    verticies[0].z = -1.0;

    verticies[1].x = 1.0;
    verticies[1].y = 0.0;
    verticies[1].z = -1.0;

    verticies[2].x = 1.0;
    verticies[2].y = 1.0;
    verticies[2].z = -1.0;

    verticies[3].x = 0.0;
    verticies[3].y = 1.0;
    verticies[3].z = -1.0;
}

Objects::~Objects()
{
    //dtor
}
void Objects::objectsInit()
{
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
//T1->loadTexture(fileName);
Time1->start();
xMin = 0.0;
xMax = 1.0;
yMin = 0.0;
yMax = 1.0;
}

void Objects::placeObjects(float x, float y, float z)
{
xPos = x;
yPos = y;
zPos = z;

}
void Objects::drawObjects()
{
    //T1->binder();

   yPos -= 0.01;   // call your object movements right here
    if(yPos < -.9){
    yPos = 0.6;
    }

   ///collision(float x, float y);
    //for the collision make some thing to where if player xpos and ypos is eqaul to objects xpos and ypos to translate object in
    //another direction probably at some sin angle or or something, but probably make a collision function.
    //if you have the time also make a function that will scale the player with a button probably 'w' to grow and 's' to shrink.
    glPushMatrix();

    glTranslated(xPos,yPos,zPos);
    glRotated(rotateX,1.0,0.0,0.0);
    glRotated(rotateY,0.0,1.0,0.0);
    glRotated(rotateZ,0.0,0.0,1.0);

    glScaled(xSize, ySize,1.0);


glBegin(GL_QUADS);

    glTexCoord2f(xMin,yMax);
    glVertex3f(verticies[0].x,verticies[0].y,verticies[0].z);

    glTexCoord2f(xMax,yMax);
    glVertex3f(verticies[1].x,verticies[1].y,verticies[1].z);

    glTexCoord2f(xMax,yMin);
    glVertex3f(verticies[2].x,verticies[2].y,verticies[2].z);

    glTexCoord2f(xMin,yMin);
    glVertex3f(verticies[3].x,verticies[3].y,verticies[3].z);

glEnd();
glPopMatrix();
}
void Objects::collision(float x,float y)
{

       // yPos -= 0.01;
    //if(yPos < -.9){
    //yPos = 0.60;
    //}
//if(((y <= xPos) && (y >= xPos))||((x <= yMax) && (x >= yMin))){
//glTranslated(xPos,-yPos,zPos);
//}

if(((x <= xPos) && (x >= xPos))||((y <= yMax) && (y >= yMin))){
glTranslated(xPos,-yPos,zPos);
}
}
