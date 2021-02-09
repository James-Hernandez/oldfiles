#include "CollisionChecker.h"

CollisionChecker::CollisionChecker()
{
    //ctor
}

CollisionChecker::~CollisionChecker()
{
    //dtor
}

// TODO: potentially template this
bool CollisionChecker::playerToBTC(Player* p, Coin c){

    float pwOffset = p->get_width();
    float phOffset = p->get_height();

    float cwOffset = c.get_width();
    float chOffset = c.get_height();

    float p_xmin = p->get_xpos() - pwOffset;
    float p_xmax = p->get_xpos() + pwOffset;
    float p_ymin = p->get_ypos() - phOffset;
    float p_ymax = p->get_ypos() + phOffset;

    // tbh I really don't like this work around but it will do.
    // 0.65 is the ratio of the bounding boxes actual position divided
    // by the coin's position.
    float c_xmin = c.get_xpos() * 0.65 - cwOffset;
    float c_xmax = c.get_xpos() * 0.65 + cwOffset;
    float c_ymin = c.get_ypos() * 0.65 - chOffset;
    float c_ymax = c.get_ypos() * 0.65 + chOffset;

    //cout << "COIN: " << c.get_xpos() << ", " << c.get_ypos() << endl;

    if( checkIntersection(p_xmin, p_xmax, c_xmin, c_xmax) &&
        checkIntersection(p_ymin, p_ymax, c_ymin, c_ymax) )
            return true;
    return false;
}

bool CollisionChecker::playerToLTC(Player* p, Litecoin c){
    float pwOffset = p->get_width();
    float phOffset = p->get_height();

    float cwOffset = c.get_width();
    float chOffset = c.get_height();

    float p_xmin = p->get_xpos() - pwOffset;
    float p_xmax = p->get_xpos() + pwOffset;
    float p_ymin = p->get_ypos() - phOffset;
    float p_ymax = p->get_ypos() + phOffset;

    // tbh I really don't like this work around but it will do.
    // 0.65 is the ratio of the bounding boxes actual position divided
    // by the coin's position.
    float c_xmin = c.get_xpos() * 0.65 - cwOffset;
    float c_xmax = c.get_xpos() * 0.65 + cwOffset;
    float c_ymin = c.get_ypos() * 0.65 - chOffset;
    float c_ymax = c.get_ypos() * 0.65 + chOffset;

    //cout << "COIN: " << c.get_xpos() << ", " << c.get_ypos() << endl;

    if( checkIntersection(p_xmin, p_xmax, c_xmin, c_xmax) &&
        checkIntersection(p_ymin, p_ymax, c_ymin, c_ymax) )
        return true;
    return false;

}

bool CollisionChecker::checkIntersection(float min1, float max1, float min2, float max2){
    return max1 >= min2 && min1 <= max2;
}
