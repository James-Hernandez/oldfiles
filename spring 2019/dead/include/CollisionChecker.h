#ifndef COLLISIONCHECKER_H
#define COLLISIONCHECKER_H
#include "Player.h"
#include "Litecoin.h"

class CollisionChecker
{
    public:
        CollisionChecker();
        virtual ~CollisionChecker();
        template <class T>
        bool playerToObject(Player* p, T obj){
            float pwOffset = p->get_width();
            float phOffset = p->get_height();
            float cwOffset = obj.get_width();
            float chOffset = obj.get_height();

            float p_xmin = p->get_xpos() - pwOffset;
            float p_xmax = p->get_xpos() + pwOffset;
            float p_ymin = p->get_ypos() - phOffset;
            float p_ymax = p->get_ypos() + phOffset;

            // tbh I really don't like this work around but it will do.
            // 0.65 is the ratio of the bounding boxes actual position divided
            // by the coin's position.
            float c_xmin = obj.get_xpos() * 0.65 - cwOffset;
            float c_xmax = obj.get_xpos() * 0.65 + cwOffset;
            float c_ymin = obj.get_ypos() * 0.65 - chOffset;
            float c_ymax = obj.get_ypos() * 0.65 + chOffset;

            if( checkIntersection(p_xmin, p_xmax, c_xmin, c_xmax) &&
                checkIntersection(p_ymin, p_ymax, c_ymin, c_ymax) ){
                //coinSound->playSound("sounds/smw_coin.wav");
                return true;
                }
            return false;
        };

        bool checkIntersection(float min1, float max1, float min2, float max2){
            return max1 >= min2 && min1 <= max2;
        };


    protected:

    private:
};

#endif // COLLISIONCHECKER_H
