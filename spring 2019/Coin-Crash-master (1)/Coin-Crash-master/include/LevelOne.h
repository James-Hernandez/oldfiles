#ifndef LEVELONE_H
#define LEVELONE_H
#include<windows.h>
#include <GLScene.h>
#include <Parallax.h>
#include <Inputs.h>
#include <SceneLoader.h>
#include <Player.h>
#include <Coin.h>

class SceneLoader;

class LevelOne : public GLScene
{
    public:
        LevelOne(SceneLoader*);
        virtual ~LevelOne();
        GLint initGL();
        GLint drawGLScene();

        int winMsg (HWND, UINT, WPARAM, LPARAM);
        GLvoid resizeGLScene(GLsizei width, GLsizei height);
        float screenWidth, screenHeight;
        void playerMovements(Player *);
        WPARAM wParam;
        bool keys[256];
        SceneLoader* loader;

    protected:

    private:
};

#endif // LEVELONE_H
