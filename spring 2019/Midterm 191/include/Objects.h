#ifndef OBJECTS_H
#define OBJECTS_H

#include<Timer.h>
#include<Player.h>
//#include<GLScene.h>
#include<GL/gl.h>

#include<TextureLoader.h>

typedef struct{
float x;
float y;
float z;


}vec2;

class Objects
{
    public:
        Objects();
        virtual ~Objects();
        void objectsInit();
        void placeObjects(float, float, float);
        void drawObjects();
        void collision(float,float);

        bool isObjectLive = true;
        GLuint objectTex;
        Player *p = new Player();
        float xPos;
        float yPos;
        float zPos;

        float xSize;
        float ySize;

        float rotateX;
        float rotateY;
        float rotateZ;

        float xMin, xMax = 0.0;
        float yMin, yMax = 0.0;

        vec verticies[4];

    protected:

    private:
};

#endif // OBJECTS_H
