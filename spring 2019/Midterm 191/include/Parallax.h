#ifndef PARALLAX_H
#define PARALLAX_H
#include<iostream>
#include<windows.h>

using namespace std;

class Parallax
{
    public:
        Parallax();
        virtual ~Parallax();

        void drawSquare(float, float);//drawing a square
        void parallaxInit(char *);//to initialize with texture
        void scroll(string,float); //auto scrolling,direction,speed of float ///to scroll the background
        float xMin,xMax,yMin,yMax;


    protected:

    private:
};

#endif // PARALLAX_H
