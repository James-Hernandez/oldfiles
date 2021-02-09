#ifndef PLAYER_H
#define PLAYER_H
#include<GL/gl.h>
#include<TextureLoader.h>

typedef struct {

    float x;
    float y;
    float z;
}vec;


class Player
{
    public:
        Player();
        virtual ~Player();

        void drawPlayer();
        void playerInit(char *);
        void playerActions();
        void playerAct(string );
        string actionTrigger;
        vec verticies[4];

float xMin,yMin,xMax,yMax;
float xPos, yPos, zPos;
float alpha;
float siz;

    protected:

    private:
};

#endif // PLAYER_H
