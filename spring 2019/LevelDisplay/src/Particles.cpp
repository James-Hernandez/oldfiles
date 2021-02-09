#include "Particles.h"

Particles::Particles()
{
    //ctor
    color[0] = 1.0f;
    color[1] = 0.843f;
    color[2] = 0.0f;
    color[3] = 1.0f;

}

Particles::~Particles()
{
    //dtor
}

void Particles::particlesInit(){
    pTex->loadTexture("images/coin.png");
    shader->initShader("pv.vs", "pf.fs");
    // initialize pVec (particles vector)


    // probably make this a circle once I brush up on math...
    GLfloat square_particle[] = {
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &pVAO);
    glGenBuffers(1, &pVBO);

    glBindVertexArray(pVAO);

    glBindBuffer(GL_ARRAY_BUFFER, pVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(square_particle), square_particle, GL_STATIC_DRAW);
    // attributes stuff
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
    glBindVertexArray(0);

    for(int i = 0; i < numParticles; i++){
        pVec.push_back(Particles());
    }
}


// where x, y, z is the location of the effected coin.
void Particles::setParticles(float x, float y, float z){

}

// TODO: needa template this later too...
void Particles::updateParticles(Coin btc){
    // add particles
    float aging = 0.2;
    for(int i = 0; i < newParticles; i++){
        int deadParticle = getDeadParticle();
        respawnParticle(pVec.at(deadParticle), btc);
    }

    // now update
    for(int i = 0; i < newParticles; i++){
        Particles &p = pVec[i];
        p.lifeTime -= aging;
        if(p.lifeTime > 0.0f){
                p.position[0] = btc.xPos -= p.velocity[0] * aging;
                p.position[1] = btc.yPos -= p.velocity[1] * aging;
                p.position[2] = btc.zPos -= p.velocity[2] * aging;

                p.color[0] = 1.0f;
                p.color[1] = 0.843f;
                p.color[2] = 0.0f;
                p.color[3] = 1.0f;
        }
    }
}

// returns index of a "dead" particle
int Particles::getDeadParticle(){
    // try most recent dead particle first.
    for(int i = recentDeadParticle; i < newParticles; i++){
        if(pVec.at(i).lifeTime <= 0.0f){
            recentDeadParticle = i;
            return i;
        }
    }

    // just go through vector if couldn't find one that way
    for(int i = 0; i < recentDeadParticle; i++){
        if(pVec.at(i).lifeTime <= 0.0f){
            recentDeadParticle = i;
            return i;
        }
    }

    // everything is alive...
    recentDeadParticle = 0;
    return 0;
}

// probably have to template this
void Particles::respawnParticle(Particles &p, Coin c){
    float random = ((rand() % 100) - 50) / 10.0f;

    // particle explosion begins at the position of the object
    p.position[0] = c.xPos + random;
    p.position[1] = c.yPos + random;
    p.position[2] = c.zPos + random;

    // TODO: particle color will vary will do this later, for now it is gold.
    p.color[0] = 1.0f;
    p.color[1] = 0.843f;
    p.color[2] = 0.0f;
    p.color[3] = 1.0f;

    p.lifeTime = 1.0f;

    // adjust velocity as needed later.
    p.velocity[0] = 1.0f;
    p.velocity[1] = 1.0f;
    p.velocity[2] = 1.0f;
}

void Particles::drawParticles(Coin c){
    glPushMatrix();
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        glUseProgram(shader->program);
        for(Particles p : pVec){
            if(p.lifeTime > 0.0f){
                glUniform4f(glGetUniformLocation(shader->program, "color"), p.color[0], p.color[1], p.color[2], p.color[3]);
                pTex->binder();
                glBindVertexArray(pVAO);
                glPointSize(4.0);
                glDrawArrays(GL_TRIANGLES, 0, 6);
                glBindVertexArray(0);
            }
        }
        glUseProgram(0);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPopMatrix();
}
