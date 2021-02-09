#ifndef SPIKES_H
#define SPIKES_H

#include <cstdlib>
#include <GL/gl.h>


class Spikes
{
    typedef struct{
        float x, y, z;
    }vec3;

    public:
        Spikes();
        void spikeInit();
        void drawSpike();
        void placeSpike(float, float, float);
        void assignTex(char*);
        float xPos, yPos, zPos;
        float xSize, ySize;
        float xMin, yMin;
        float xMax, yMax;
        vec3 verticies[4];
        float width, height;
        float get_xpos();
        float get_ypos();
        float get_width();
        float get_height();

        virtual ~Spikes();

    protected:

    private:
};

#endif // SPIKES_H
