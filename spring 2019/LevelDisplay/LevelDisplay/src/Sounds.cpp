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
void Sounds::playSounds(char* fileName)
{
    engine->play2D(fileName,false, false);
}

void Sounds::playMusic(char* fileName)
{
    engine->play2D(fileName,true,false, false, ESM_AUTO_DETECT);
}

void Sounds::stopAllSounds()
{
    engine->stopAllSounds();
}

int Sounds::initSounds()
{
    if(!engine){
        cout <<"Could Not Start the Engine \n";
        return 0;
    }
return 1;
}
