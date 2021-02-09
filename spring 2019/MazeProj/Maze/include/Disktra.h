#ifndef DISKTRA_H
#define DISKTRA_H
#include <stack>
#include <utility>
#include <vector>
#include <list>
#include <unordered_map>
#include <iostream>
#include <player.h>
using namespace std;
///This class was made so it would be easier for me to make the algorithm for the paths
///also it makes the project look a bit nicer rather than all messy with bunch a code everywhere
///so it looks more appealing.
class Disktra
{
    public:
    Disktra(int numVerts);
    virtual ~Disktra();

    vector<int> PathFinder;              /// stores the paths to goku
    int dataK(int, int);        ///this will give us the data key if they are appropriate to what we finding
    void djk(int, Player *);     /// main algorithm with parameters for key and player
    void adjM(int **, int);    /// starts with creating adjecency graph
    void aE(int, int);     /// finding and adding edges for our graph

    void relinquishVector();             /// We clear the vector to prevent memory leakage and to reuse the vector

    unordered_map<int, pair<int,int> > pathMap; /// stores the paths keys for saibamen and goku
    bool isMatch(int, int);       /// flag for checking if pair exists
    int numVerts;              /// verticies number
    bool dataCheck(int);             /// checks if the data is valid in a sort of sense
    list<int> *adjL;
    pair<int, int> gokuAct();  /// Goku tracker
    protected:

    private:
};

#endif // DISKTRA_H
