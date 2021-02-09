#include "Fonts.h"

Fonts::Fonts()
{
    //ctor
    zoom = -4.0;

    xPos = 1.0;
    yPos = 0.5;
    zPos = 0.0;
    cCnt = 0;
}

Fonts::~Fonts()
{
    //dtor
}
void Fonts::initFonts(char* fileName)
{
    ftex->loadTexture(fileName);
}

void Fonts::buildFonts(char* str)
{
    for(int i = 0; i < strlen(str); i++)
    {
        switch(str[i])
        {
        case 'A':
            c[cCnt].xMin = 0;
            c[cCnt].xMax = 1.0/13.0;
            c[cCnt].yMin = 0.0;
            c[cCnt].yMax = 1.0/7.0;
            break;

        case 'B':
            c[cCnt].xMin = 1.0/13.0;
            c[cCnt].xMax = 2.0/13.0;
            c[cCnt].yMin = 0.0;
            c[cCnt].yMax = 1.0/7.0;
            break;

        case 'C':
            c[cCnt].xMin = 2.0/13.0;
            c[cCnt].xMax = 3.0/13.0;
            c[cCnt].yMin = 0.0;
            c[cCnt].yMax = 1.0/7.0;
            break;

        case 'D':
            c[cCnt].xMax = 3.0/13.0;
            c[cCnt].xMax = 4.0/13.0;
            c[cCnt].yMin = 0.0;
            c[cCnt].yMax = 1.0/7.0;
            break;

        case 'E':
            c[cCnt].xMax = 4.0/13.0;
            c[cCnt].xMax = 5.0/13.0;
            c[cCnt].yMin = 0.0;
            c[cCnt].yMax = 1.0/7.0;
            break;

        case 'F':
            c[cCnt].xMax = 5.0/13.0;
            c[cCnt].xMax = 6.0/13.0;
            c[cCnt].yMin = 0.0;
            c[cCnt].yMax = 1.0/7.0;
            break;

        case 'G':
            c[cCnt].xMax = 6.0/13.0;
            c[cCnt].xMax = 1.0/13.0;
            c[cCnt].yMin = 0.0;
            c[cCnt].yMax = 1.0/7.0;
            break;

        case 'H':
            c[cCnt].xMax = 7.0/13.0;
            c[cCnt].xMax = 8.0/13.0;
            c[cCnt].yMin = 0.0;
            c[cCnt].yMax = 1.0/7.0;
            break;

        case 'I':
            c[cCnt].xMax = 8.0/13.0;
            c[cCnt].xMax = 9.0/13.0;
            c[cCnt].yMin = 0.0;
            c[cCnt].yMax = 1.0/7.0;
            break;

        case 'J':
            c[cCnt].xMax = 9.0;
            c[cCnt].xMax = 10.0/13.0;
            c[cCnt].yMin = 0.0;
            c[cCnt].yMax = 1.0/7.0;
            break;

        case 'K':
            c[cCnt].xMax = 10.0/13.0;
            c[cCnt].xMax = 11.0/13.0;
            c[cCnt].yMin = 0.0;
            c[cCnt].yMax = 1.0/7.0;
            break;

        case 'L':
            c[cCnt].xMax = 11.0/13.0;
            c[cCnt].xMax = 12.0/13.0;
            c[cCnt].yMin = 0.0;
            c[cCnt].yMax = 1.0/7.0;
            break;

        case 'M':
            c[cCnt].xMax = 12.0/13.0;
            c[cCnt].xMax = 13.0/13.0;
            c[cCnt].yMin = 0.0;
            c[cCnt].yMax = 1.0/7.0;
            break;

        case 'N':
            c[cCnt].xMax = 0;
            c[cCnt].xMax = 1.0/13.0;
            c[cCnt].yMin = 1.0/7.0;
            c[cCnt].yMax = 2.0/7.0;
            break;

        case 'O':
            c[cCnt].xMax = 1.0/13.0;
            c[cCnt].xMax = 2.0/13.0;
            c[cCnt].yMin = 1.0/7.0;
            c[cCnt].yMax = 2.0/7.0;
            break;

        case 'P':
            c[cCnt].xMax = 2.0/13.0;
            c[cCnt].xMax = 3.0/13.0;
            c[cCnt].yMin = 1.0/7.0;
            c[cCnt].yMax = 2.0/7.0;
            break;

        case 'Q':
            c[cCnt].xMax = 3.0/13.0;
            c[cCnt].xMax = 4.0/13.0;
            c[cCnt].yMin = 1.0/7.0;
            c[cCnt].yMax = 2.0/7.0;
            break;

        case 'R':
            c[cCnt].xMax = 4.0/13.0;
            c[cCnt].xMax = 5.0/13.0;
            c[cCnt].yMin = 1.0/7.0;
            c[cCnt].yMax = 2.0/7.0;
            break;

        case 'S':
            c[cCnt].xMax = 5.0/13.0;
            c[cCnt].xMax = 6.0/13.0;
            c[cCnt].yMin = 1.0/7.0;
            c[cCnt].yMax = 2.0/7.0;
            break;

        case 'T':
            c[cCnt].xMax = 6.0/13.0;
            c[cCnt].xMax = 7.0/13.0;
            c[cCnt].yMin = 1.0/7.0;
            c[cCnt].yMax = 2.0/7.0;
            break;

        case 'U':
            c[cCnt].xMax = 7.0/13.0;
            c[cCnt].xMax = 8.0/13.0;
            c[cCnt].yMin = 1.0/7.0;
            c[cCnt].yMax = 2.0/7.0;
            break;

        case 'V':
            c[cCnt].xMax = 8.0/13.0;
            c[cCnt].xMax = 9.0/13.0;
            c[cCnt].yMin = 1.0/7.0;
            c[cCnt].yMax = 2.0/7.0;
            break;

        case 'W':
            c[cCnt].xMax = 9.0/13.0;
            c[cCnt].xMax = 10.0/13.0;
            c[cCnt].yMin = 1.0/7.0;
            c[cCnt].yMax = 2.0/7.0;
            break;

        case 'X':
            c[cCnt].xMax = 10.0/13.0;
            c[cCnt].xMax = 11.0/13.0;
            c[cCnt].yMin = 1.0/7.0;
            c[cCnt].yMax = 2.0/7.0;
            break;

        case 'Y':
            c[cCnt].xMax = 11.0/13.0;
            c[cCnt].xMax = 12.0/13.0;
            c[cCnt].yMin = 1.0/7.0;
            c[cCnt].yMax = 2.0/7.0;
            break;

        case 'Z':
            c[cCnt].xMax = 12.0/13.0;
            c[cCnt].xMax = 13.0/13.0;
            c[cCnt].yMin = 1.0/7.0;
            c[cCnt].yMax = 2.0/7.0;
            break;

        case '0':
            c[cCnt].xMax = 0;
            c[cCnt].xMax = 1.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '1':
            c[cCnt].xMax = 1.0/13.0;
            c[cCnt].xMax = 2.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '2':
            c[cCnt].xMax = 2.0/13.0;
            c[cCnt].xMax = 3.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '3':
            c[cCnt].xMax = 3.0/13.0;
            c[cCnt].xMax = 4.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '4':
            c[cCnt].xMax = 4.0/13.0;
            c[cCnt].xMax = 5.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '5':
            c[cCnt].xMax = 5.0/13.0;
            c[cCnt].xMax = 6.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '6':
            c[cCnt].xMax = 6.0/13.0;
            c[cCnt].xMax = 7.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '7':
            c[cCnt].xMax = 7.0/13.0;
            c[cCnt].xMax = 8.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '8':
            c[cCnt].xMax = 8.0/13.0;
            c[cCnt].xMax = 9.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '9':
            c[cCnt].xMax = 9.0/13.0;
            c[cCnt].xMax = 10.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '.':
            c[cCnt].xMax = 0;
            c[cCnt].xMax = 1.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case ',':
            c[cCnt].xMax = 1.0/13.0;
            c[cCnt].xMax = 2.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case ';':
            c[cCnt].xMax = 2.0/13.0;
            c[cCnt].xMax = 3.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case ':':
            c[cCnt].xMax = 3.0/13.0;
            c[cCnt].xMax = 4.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '@':
            c[cCnt].xMax = 4.0/13.0;
            c[cCnt].xMax = 5.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '#':
            c[cCnt].xMax = 5.0/13.0;
            c[cCnt].xMax = 6.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '`':
            c[cCnt].xMax = 6.0/13.0;
            c[cCnt].xMax = 7.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '!':
            c[cCnt].xMax = 7.0/13.0;
            c[cCnt].xMax = 8.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '"':
            c[cCnt].xMax = 8.0/13.0;
            c[cCnt].xMax = 9.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '/':
            c[cCnt].xMax = 9.0/13.0;
            c[cCnt].xMax = 10.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '?':
            c[cCnt].xMax = 10.0/13.0;
            c[cCnt].xMax = 11.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '<':
            c[cCnt].xMax = 11.0/13.0;
            c[cCnt].xMax = 12.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '>':
            c[cCnt].xMax = 12.0/13.0;
            c[cCnt].xMax = 13.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '%':
            c[cCnt].xMax = 0;
            c[cCnt].xMax = 1.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '&':
            c[cCnt].xMax = 1.0/13.0;
            c[cCnt].xMax = 2.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '*':
            c[cCnt].xMax = 2.0/13.0;
            c[cCnt].xMax = 3.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '(':
            c[cCnt].xMax = 3.0/13.0;
            c[cCnt].xMax = 4.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case ')':
            c[cCnt].xMax = 4.0/13.0;
            c[cCnt].xMax = 5.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case ' ':
            c[cCnt].xMax = 5.0/13.0;
            c[cCnt].xMax = 6.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        case '$':
            c[cCnt].xMax = 6.0/13.0;
            c[cCnt].xMax = 7.0/13.0;
            c[cCnt].yMin = 4.0/7.0;
            c[cCnt].yMax = 5.0/7.0;
            break;

        }
        cCnt++;
    }
}

void Fonts::drawFont(int i)
{
    ftex->binder();
   // glPushMatrix();

    glBegin(GL_QUADS);

        glTexCoord2f(c[i].xMin, c[i].yMax);
        glVertex3f(0.0, 0.0, 0.0); // depending on your image

        glTexCoord2f(c[i].xMax, c[i].yMax);
        glVertex3f(1.0/13.0, 0.0, 0.0); // depending on your image

        glTexCoord2f(c[i].xMax, c[i].yMin);
        glVertex3f(1.0/13.0, 1.0, 0.0); // depending on your image

        glTexCoord2f(c[i].xMin, c[i].yMin);
        glVertex3f(0.0, 1.0, 0.0); // depending on your image

    glEnd();

  //  glPopMatrix();
}
