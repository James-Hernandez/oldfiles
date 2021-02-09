#ifndef PARTICLES_H
#define PARTICLES_H

#include <loadShader.h>
#include <vector>
#include <Coin.h>
#include <TextureLoader.h>

class Particles
{
    public:
        Particles();
        virtual ~Particles();


        void particlesInit();
        float position[3], velocity[3];
        float color[4];
        float lifeTime;
        int numParticles = 500;
        int newParticles = 2;
        int recentDeadParticle = 0;
        GLuint pVAO;
        GLuint pVBO;
        vector<Particles> pVec;
        loadShader* shader = new loadShader();
        TextureLoader* pTex = new TextureLoader();
        void setParticles(float, float, float);
        void respawnParticle(Particles&, Coin);
        void addNewParticles();
        void updateParticles(Coin);
        void drawParticles(Coin);
        int getDeadParticle();


    protected:

    private:
};

#endif // PARTICLES_H
