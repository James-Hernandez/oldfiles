#ifndef PAUSESCENCE_H
#define PAUSESCENCE_H
#include<GLScene.h>
#include<Inputs.h>
#include<SceneLoader.h>
#include<GLLight.h>
#include<LevelOne.h>
///should include other level headers
#include <Player.h>
#include<InfoScene.h>
#include <GL/gl.h>
#include <StartScene.h>
#include<Sounds.h>

class PauseScence : public GLScene
{
    public:
        PauseScence(SceneLoader*, Sounds*);
        virtual ~PauseScence();
        GLint initGL();
        GLint drawGLScene();
        int winMsg(HWND, UINT, WPARAM, LPARAM);
        GLvoid resizeGLScene(GLsizei width, GLsizei height);
        SceneLoader* loader;
        bool fire1;
        bool fire2;
        bool fire3;
        bool fire4;
        float xize;
        float yize;
        float zize;
        Sounds* SND;

    protected:

    private:
};

#endif // PAUSESCENCE_H
