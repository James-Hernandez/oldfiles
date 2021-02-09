#ifndef SOUNDS_H
#define SOUNDS_H
#include <SNDS/irrKlang.h>
#include <iostream>
#pragma comment(lib,"irrKlang.lib");

using namespace irrklang;
using namespace std;

class Sounds
{
    public:
        Sounds();
        virtual ~Sounds();

        void playSounds(char*);
        void playMusic(char*);
        void stopAllSounds();
        int initSounds();

        ISoundEngine *engine = createIrrKlangDevice();


    protected:

    private:
};

#endif // SOUNDS_H
