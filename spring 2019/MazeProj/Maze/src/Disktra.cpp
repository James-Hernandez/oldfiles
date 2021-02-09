#include "Disktra.h"

Disktra::Disktra(int v)
{
    //ctor
    this->numVerts = v;
    adjL = new list<int>[v];
}

Disktra::~Disktra()
{
    //dtor
    for(int i = 0;i < numVerts;i++){
        adjL[i].clear();
    }
    adjL->clear();
}
int Disktra::dataK(int a, int b)
{
    for(auto key = pathMap.begin(); key != pathMap.end();key++){
    ///so for this function what we are doing is that we are passing in a set of
    ///coordinates a and b and we are then traversing the pathMap from begining
    ///to end using the variable key and declaring it an auto for the compiler to decide
    ///next as we are traversing the set, we are checking key's data's key using .second.first
    /// and comparing it to a, then we are doing the same with keys.second.second
    ///we are doing this because we are using unordered map using pair with <a,b>
        if((*key).second.first == a && (*key).second.second == b){
            return (*key).first;
        }
    }
    return 0;
}

void Disktra::djk(int currentP, Player* Goku)
{///Alright so right here is the main function, the big boi right here
/// so in this function what we are doing is that we are first passing int he the players
///current position and the player Goku, as we go down this funtion what we are going to
///want to do at the first of this function is mark all posistions/verticies as not
///visited because the players current position will always be changing so whenever
///this function is called we esentially clear the board and find the paths again
///for everytime it is updated.
vector<bool> vertsV(numVerts,false);
stack<int> col;
col.push(currentP);
PathFinder.push_back(currentP);/// so right here we are pushin the
///current placement into the pathfinder.
while(!col.empty()){
   currentP = col.top();
   col.pop();/// takin the top of the structue and tthen poping it off
   if(!vertsV[currentP]){
    PathFinder.push_back(currentP);
    vertsV[currentP] = true;
   }
   if(pathMap[currentP].first == Goku->getPlayerLoc().x && pathMap[currentP].second == Goku->getPlayerLoc().y){
       ///this little tid bit is just to check wheather or not the currentP is equal to
       ///gokus position.
       return;
   }
   for(auto no = adjL[currentP].begin(); no != adjL[currentP].end();no++){
    if(vertsV[*no] == 0){
        col.push(*no);
    }
   }
}


}



void Disktra::aE(int a, int b)
{
    ///so for this function what we are doing here is adding edges to the matrix/graph
    ///all we are doing here really is adding the edge from a to be with the adjL[]list
    ///by adding b to the 'a' list
adjL[a].push_back(b);
}

void Disktra::relinquishVector()
/// so the reason we have this relinquish vector function is becasue
/// we have to clean the vector before running the algorithm  again
///because the players position will always be changing.
{
PathFinder.clear();
}

bool Disktra::isMatch(int a, int b)
{///so for this function what we are doing is that we are passing in a set of
    ///coordinates a and b and we are then traversing the pathMap from begining
    ///to end using the variable key and declaring it an auto for the compiler to decide
    ///next as we are traversing the set, we are checking key's data's key using .second.first
    /// and comparing it to a, then we are doing the same with keys.second.sec
    for(auto key = pathMap.begin(); key != pathMap.end(); key++){
        if((*key).second.first == a && (*key).second.second == b){
            return true;
        }
    }
    return false;
}

bool Disktra::dataCheck(int z)
{
if(pathMap.find(z)== this->pathMap.end()){
    return false;
}
return true;
}
///alright so for right here we are using the function make pair to set the values in the
///in the pair list and what we are using this function for is that we are pushing the new
///coordinates for the next step of the algorithm
pair<int,int> Disktra::gokuAct()
{
return make_pair(pathMap[PathFinder[2]].first,pathMap[PathFinder[2]].second);
}

/// ///////////
void Disktra::adjM(int **matrix, int mazeCount)
{///awesome now we are at the big boi alg, really the meat of the program and what we
    ///doing here is that we are essentially making the graph that we are going
    ///to be using so we pass in the matrix 2D  and mazecount
int z = -1;
int c = 0;
for(int i = mazeCount -1; i>= 0;i--){
    for(int j = 0; j < mazeCount;j++){///so in this loop we are starting at mazecount
            ///which is the size of maze and checking for where walls are placed'
            ///and if there are no walls then we are increasing the amount in new matrix
            /// and puting that pair into the pathmap graph
        if(matrix[j][i] != 1){
            z++;
            pathMap.insert({z,make_pair(j,i)});
        }
    }
}
for(int i = mazeCount-1;i>=0;i--){
    for(int j = 0; j < mazeCount-1;j++){
            ///so in this loop we are starting at mazecount
            ///which is the size of maze and checking for where walls are placed'
            ///and if there are no walls then we are increasing the amount in new matrix
            /// and puting that pair into the pathmap graph and then next we are adding
            ///edges from basically point a to point b constructing the graph
        if(matrix[j][i] != 1 && matrix[j+1][i] != 1){
            aE(dataK(j,i),dataK(j+1,i));
            aE(dataK(j+1,i),dataK(j,i));
            c += 2;
        }
    }
}
for(int j = 0; j<mazeCount;j++){
    for(int i = mazeCount-1;i-1 >= 0;i--){
            ///so in this loop we are starting at mazecount
            ///which is the size of maze and checking for where walls are placed'
            ///and if there are no walls then we are increasing the amount in new matrix
            /// and puting that pair into the pathmap graph and then next we are adding
            ///edges from basically point a to point b constructing the graph
        if(matrix[j][i] != 1 && matrix[j][i-1] != 1){
            aE(dataK(j,i),dataK(j,i-1));
            aE(dataK(j,i-1),dataK(j,i));
            c += 2;
        }
    }
}
}
