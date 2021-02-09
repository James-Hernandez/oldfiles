#ifndef MUSICSELECTSCENE_H
#define MUSICSELECTSCENE_H
#include <GLScene.h>
#include <Inputs.h>
#include <SceneLoader.h>

class MusicSelectScene : public GLScene
{
    public:
        MusicSelectScene(SceneLoader*);
        virtual ~MusicSelectScene();
        GLint initGL();
        GLint drawGLScene();
        int winMsg(HWND, UINT, WPARAM, LPARAM);
        GLvoid resizeGLScene(GLsizei width, GLsizei height);
        SceneLoader* loader;
    protected:

    private:
};

#endif // MUSICSELECTSCENE_H
