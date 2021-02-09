#ifndef SOUNDS_H
#define SOUNDS_H

#include <iostream>
//#include <irrKlang.h>

#include<SNDS/irrKlang.h>

#pragma comment(lib, "irrKlang.lib");

using namespace irrklang;
using namespace std;
class Sounds
{
    public:
        Sounds();
        ~Sounds();
        void playSoundEffects(char *);
        void playMusic(char *);
        void stopAllSounds();
        void pauseSound(char*);
        int initSounds();
        ISoundEngine *engine = createIrrKlangDevice();
    protected:

    private:
};


#endif // SOUNDS_H
