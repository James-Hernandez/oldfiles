#include "Model.h"
#include <TextureLoader.h>

TextureLoader *tex = new TextureLoader();
Model::Model()
{
    //ctor
         RotateX = 0.0;
         RotateY = 0.0;
         RotateZ = 0.0;

         zoom = -8.0;
         xPos = 0.0;
         yPos = 0.0;





}
void Model::modelInit(char* fileName)
{
tex->loadTexture(fileName);
}

Model::~Model()
{
    //dtor
}
void Model::drawModel()
{
    tex->binder();
    glColor3f(0.3,0.5,0.7);
    glTranslated(xPos,yPos,zoom);
    glRotated(RotateX,1,0,0);
    glRotated(RotateY,0,1,0);
    glRotated(RotateZ,0,0,1);
    //glutSolidCube(1.0);
    glutSolidTeapot(1.5);
    //What ever the model you draw
}
