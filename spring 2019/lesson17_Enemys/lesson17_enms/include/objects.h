#ifndef OBJECTS_H
#define OBJECTS_H

#include <gl/gl.h>


class objects
{
    public:
        objects();
        virtual ~objects();

        void drawObjects();     // draw objects
        void placeObjects(float, float,float); // place objects

        bool isObjectLive= true; //status of the objects
        GLuint objectTex;      // handle Texture


        float xPos;             //placing objects on x
        float yPos;             //placing objects on y
        float zPos;             //placing objects on z

        float xSize;            // for scaling x
        float ySize;            // for scaling y

        float rotateX;
        float rotateY;
        float rotateZ;
    protected:

    private:
};

#endif // OBJECTS_H
