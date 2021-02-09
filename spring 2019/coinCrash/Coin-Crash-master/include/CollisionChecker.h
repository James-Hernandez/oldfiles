#ifndef COLLISIONCHECKER_H
#define COLLISIONCHECKER_H
#include "Player.h"
#include "Litecoin.h"

class CollisionChecker
{
    public:
        CollisionChecker();
        virtual ~CollisionChecker();
        bool playerToBTC(Player*, Coin);
        bool playerToLTC(Player*, Litecoin);
        bool checkIntersection(float, float, float, float);
    protected:

    private:
};

#endif // COLLISIONCHECKER_H
