#ifndef FONTS_H
#define FONTS_H

#include <TextureLoader.h>
#include <iostream>
#include <string.h>

using namespace std;


class Fonts
{
    public:
        TextureLoader *ftex = new TextureLoader();
        Fonts();
        virtual ~Fonts();

        typedef struct
        {
            char letter;
            float xMin, yMin, xMax, yMax;
            float offset;
            float fontSize;
        }
        charSet;

        void initFonts(char *);
        void buildFonts(char *);
        void drawFont(int);

        charSet c[1024];
        int cCnt;
        float zoom;

        float xPos, yPos, zPos;


    protected:

    private:
};

#endif // FONTS_H
