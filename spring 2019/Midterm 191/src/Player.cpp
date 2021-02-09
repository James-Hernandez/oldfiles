#include "Player.h"
#include <Timer.h>
TextureLoader * T = new TextureLoader();
Timer *Time = new Timer();

Player::Player()
{
    //ctor
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

    xMin = 0.0;
    yMin = 0.0;
    xMax = 0.0;
    yMax = 0.0;

    xPos = -.15; //org -.5
    yPos = -.15;  //org -.5
    zPos = -1.0;
    alpha = 0.0;
    siz = 0.3;

}

Player::~Player()
{
    //dtor
}
void Player::drawPlayer()
{
    T->binder();
glPushMatrix();
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

void Player::playerInit(char * fileName)
{
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
T->loadTexture(fileName);
Time->start();
xMin = 0.0;
xMax = 1.0/4.0; //0.25;  /////reverse the xmin and xmax and ymin and ymax if you want the sprite image to be inversed

yMin = 2.0/4.0;
yMax = 4.0/4.0;
}

void Player::playerActions()
{
    if(actionTrigger == "Stand"){
        xMin = xMin;//0.0;
        xMax = xMax;//1.0/4.0; //0.25;  /////reverse the xmin and xmax and ymin and ymax if you want the sprite image to be inversed

        yMin = yMin;//0.0;
        yMax = yMax;//1.0/4.0;//.25;
        //yPos = -0.6;

    }



    if(actionTrigger == "Right"){
        //yPos = -0.6;
       yMin = 2.0/4.0;
       yMax = 4.0/4.0;
        if(Time->getTicks() > 85){
        xMin += (1.0/4.0);//+= 0.16;
        xMax += (1.0/4.0);//0.16;
        xPos += .06;

        if(xPos >= 1.0){
            xPos = -1.0;
        }

        Time->reset();
        }

    }

    if(actionTrigger == "Left"){
        yMin = 2.0/4.0;
        yMax = 4.0/4.0;
        if(Time->getTicks() > 85){
        xMin += (1.0/4.0);//+= 0.16;
        xMax += (1.0/4.0);//0.16;
        xPos -= .06;
        if(xPos <= -1.4){
            xPos = 1.0;
        }
        Time->reset();
        }

    }

    if(actionTrigger == "Up"){
    yMin = 2.0/4.0;
    yMax = 4.0/4.0;
    if(Time->getTicks() > 85){
        xMin += (1.0/4.0);//+= 0.16;
        xMax += (1.0/4.0);//0.16;
        yPos += .06;
        //cout << yPos << " ";
        if(yPos >= .55){
            yPos = -0.68;
        }

        Time->reset();
    }
    }

    if(actionTrigger == "Down"){
    yMin = 2.0/4.0;
    yMax = 4.0/4.0;
    if(Time->getTicks() > 85){
        xMin += (1.0/4.0);//+= 0.16;
        xMax += (1.0/4.0);//0.16;
        yPos += -.06;

        if(yPos <= -.74){
            yPos = 0.55;
        }
        Time->reset();
    }
    }

    if(actionTrigger == "Slant"){
   yMin = 2.0/4.0;
   yMax = 4.0/4.0;
    if(Time->getTicks() > 85){
        xMin += (1.0/4.0);//+= 0.16;
        xMax += (1.0/4.0);//0.16;
        yPos += .2;
        xPos += .2;
        //cout << yPos << " ";
        if(yPos >= .55){
            yPos = -0.68;
        }

        Time->reset();
    }
    }

     if(actionTrigger == "RotatezCCW"){


            alpha = alpha + .95;

    }
    if(actionTrigger == "RotatezCW"){


            alpha = alpha - .95;

    }

        if(actionTrigger == "Shrink"){


            siz = siz - .01;

    }

        if(actionTrigger == "Grow"){


            siz = siz + .01;

    }

    if(actionTrigger == "Fire"){


    }

}
void Player::playerAct(string action)
{
if(action == "Go"){
        //yPos = -0.6;
        yMin = 2.0/4.0;
        yMax = 4.0/4.0;
        if(Time->getTicks() > 85){
        xMin += (1.0/4.0);//+= 0.16;
        xMax += (1.0/4.0);//0.16;
        //xPos += .06;

        if(xPos >= 1.0){
            xPos = -1.0;
        }

        Time->reset();
        }

    }
}
