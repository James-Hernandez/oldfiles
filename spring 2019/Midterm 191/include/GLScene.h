#ifndef GLSCENE_H
#define GLSCENE_H
#include <windows.h>
#include <GL/glut.h>


class GLScene
{
    public:
        GLScene();                             //constructor
        virtual ~GLScene();                    //De-constructor
       GLint initGL();
       GLint drawGLScene();
       GLvoid resizeGLScene(GLsizei,GLsizei);

       int winMsg(HWND,UINT,WPARAM,LPARAM);			// Handle For This Window
        float screenWidth,screenHeight;
    protected:

    private:
};

#endif // GLSCENE_H
