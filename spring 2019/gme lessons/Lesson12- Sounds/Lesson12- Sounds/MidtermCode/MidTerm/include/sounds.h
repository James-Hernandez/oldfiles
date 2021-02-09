#ifndef SOUNDS_H
#define SOUNDS_H

#include <SNDS/irrKlang.h>

#include <stdlib.h>
#include <iostream>

#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll
using namespace irrklang;


using namespace std;

class sounds
{
    public:
        sounds();
        virtual ~sounds();
        void playMusic(char *);
        void playSound(char *);
        void pauseSound(char *);
        void stopAllSounds();
        int initSounds();

    protected:

    private:
};



#endif // SOUNDS_H
