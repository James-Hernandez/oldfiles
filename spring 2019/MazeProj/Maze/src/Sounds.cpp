#include "Sounds.h"

Sounds::Sounds()
{
    //ctor
}

Sounds::~Sounds()
{
    //dtor
    engine->drop();
}
void Sounds::playSoundEffects(char* fileName)
{
    engine->play2D(fileName,false,false);
}

void Sounds::playMusic(char* fileName)
{
    engine->play2D(fileName,true);
}

void Sounds::stopAllSounds()
{
engine->stopAllSounds();
}
void Sounds::pauseSound(char*fileName)
{
    engine->play2D(fileName,true,false);
}

int Sounds::initSounds()
{
    if(!engine){
    cout << "could not start engine\n";
    return 0;//this is only if you want to quit the game.
}
return 1;
}
