/*
 * MAZE Game Framework
 * Written by Dr. Dhanyu Amarasinghe Spring 2018
 */
//#define numberOfWalls 10;
#include <string.h>
#include <CommonThings.h>
#include <Maze.h>
#include <iostream>
#include <Timer.h>
#include <fstream>
#include <sstream>
#include <player.h>
#include <vector>
#include <stack>
#include <list>
#include <utility>
#include <Disktra.h>
#include <unordered_map>
#include <Disktra.h>
#include <Sounds.h>
/// /////////////////////

#include <Enemies.h>

#include <wall.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
//#include<graph.h>


/* GLUT callback Handlers */

using namespace std;
bool status = false;//scence loader
const int mazeQuad = 10;
Maze *M = new Maze(10); // Set Maze grid size
Maze *Info = new Maze(mazeQuad);
int **matrix;//standard 2d array
Maze *Gwin = new Maze(mazeQuad);///decides if goku won
Maze *Swin = new Maze (mazeQuad);///decides if saibamen won
Player *Goku = new Player();
Sounds *SND = new Sounds();
//Goku->numberOfWalls;                       // create player

const int walls = mazeQuad * mazeQuad;
int CW = 1;
wall W[walls];
const int verts = walls;
Disktra disk(verts);
const int enemies = 10;
int enyC = 0;
///wall W[100];                                    // wall with number of bricks
Enemies E[10];                                  // create number of enemies
Timer *T0 = new Timer();                        // animation timer

float wWidth, wHeight;                          // display window width and Height
float xPos,yPos;                                // Viewpoar mapping


void display(void);                             // Main Display : this runs in a loop

void resize(int width, int height)              // resizing case on the window
{
    wWidth = width;
    wHeight = height;

    if(width<=height)
        glViewport(0,(GLsizei) (height-width)/2,(GLsizei) width,(GLsizei) width);
    else
        glViewport((GLsizei) (width-height)/2 ,0 ,(GLsizei) height,(GLsizei) height);
}
/// for the algorithm we are going to initialize the matrix the adjacency lists
void adjMatrix(){
    cout << "This is the initialized set:" << '/n';
matrix = new int*[mazeQuad];/// will create a new
for(int i= 0; i < mazeQuad; i++){
    matrix[i] = new int[mazeQuad];///
    for(int j = 0; j < mazeQuad;j++){
        matrix[i][j] = 0;///This will fill the 2d array martrix with zero's


    }
    ///cout << endl;
}
cout << endl;
}


void printAdjMatrix(){
    cout<<"This is the new set: " << endl;///straight forward function to just print out the matrix
for(int i = mazeQuad - 1; i>= 0;i--){
    for(int j = 0;j < mazeQuad;j++)
        cout << matrix[j][i] << " ";
    cout << endl;
}
cout << endl;

}

void enemyPlacement(int x, int y){
    if(enyC < enemies){///function to place enemies in the proper coordinates while
                       ///assigning the enemy texture file initializer
        E[enyC].initEnm(M->getGridSize(),4,"images/buu.png"); //Load enemy image
        E[enyC].enemyPlacement(x,y);
        enyC++;
    }
    else{///if they try and place to many that the array cannot handle
        cout << "WOAH! SLOW DOWN YOU HAVE TOO MANY ENEMIES FRIEND!" << endl;
        cout << "IF YOU WANT THAT MANY ENEMIES PERHAPS MAKING THE EARRAY LARGER WILL HELP?" << endl;
        return;
    }
}

void wallPlacement(int x, int y){
    if(CW < walls){/// this is to ensure that the number of walls do exceed the wall array or else the game will be broken,
        W[CW].wallInit(M->getGridSize(),"images/wall2.png");///we will begin to initalize the placement of walls
        W[CW].wallPlacement(x, y);///placement of walls
        CW++;///increase the counter so that we constantly check to make sure the threshold limit is not exceeded
    }
    else {///if they try and place to many that the array cannot handle
        cout << "WOAH! SLOW DOWN YOU HAVE TOO MANY WALLS FRIEND!" << endl;
        cout << "IF YOU WANT THAT MANY WALLS PERHAPS MAKING THE GRID LARGER WILL HELP?" << endl;
        return;
    }
}
void openFile(string fileName)
{

    string line, pattern;///i have string line to get each indiv line and pattern for the file readers recognition
    int x, y;///so for the array it will be [x][y]
    ifstream infile(fileName);///read this file

    if(infile.is_open()){///if the file was opened succesfully
        while(getline(infile, line)){///mess with to make more efficent
            istringstream field(line);
            field >> pattern >> x >> y;///This is the pattern that the file will be read in
            /// //////////////////////////////////////
if(pattern == "Goku"){///here will begin the placement of goku
    cout << "Goku placed at: " << x << "," << y << endl;///given coordinates for goku
    Goku->initPlayer(M->getGridSize(),4,"images/goku.png");  ///initlize size of sprite sheet
    Goku->loadArrowImage("images/energy.png"); /// here we are loading senzu
    Goku->placePlayer(x, y);///placing goku is desired field
    matrix[x][y] = 3;
    }
    /// /////////////////////////////////////////////////
            if(pattern == "Saibamen"){///here will begin the placement of saibamen
                cout << "Saibamen placed at: " << x << "," << y << endl;///given coordinates for saibamen
                enemyPlacement(x, y);///placing saibamen is desired field
                matrix[x][y] = 2;
            }
         /// ////////////////////////////////////////////////

if(pattern == "wall"){///here will begin the placement of walls
  cout << "Wall found at: " << x << "," << y << endl;///given coordinates for walls
  wallPlacement(x, y);///placing walls is desired field
  matrix[x][y] = 1;
    }
        /// ////////////////////////////////////////////////////

            if(pattern == "senzubean"){///here will begin the placement of the senzubean
                cout << "senzubean placed at: " << x << "," << y << endl;///given coordinates for senzubean
                M->loadSetOfArrowsImage("images/senzu.png"); ///initalize by loading the image of our senzubean
                M->placeStArrws(x, y); ///placing senzubean is desired field
                matrix[x][y] = 5;
            }
            /// //////////////////////////////////////////////
if(pattern == "capsule"){///here will begin the placement of the capsule
  cout << "capsule found at: " << x << "," << y << endl;///given coordinates for capsule
  ///M->loadBackgroundImage("images/grass.png");///initalize by loading the image of our background
  M->loadChestImage("images/logo.png");  ///initalize by loading the image of our capsule
  M->placeChest(x, y);///placing senzubean is desired field
  matrix[x][y] = 4;
    }
        }
    }
}
void relinquishMemory(){///here we are relinquishing memmory just in case of leakage
    ///so we first begin with the matrix that we filled so for then when we create a new matrix.
for (int i = 0; i < mazeQuad; i++){
    delete [] matrix;
}///have to free up the space
	delete M;
	delete T0;
	delete Goku;
	delete[] matrix;
}

void musicSelection(){

/// this was just something i was going to workshop but decided not to use it
}

void init()
{
    glEnable(GL_COLOR_MATERIAL);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0,0.0,0.0,0.0);
    gluOrtho2D(0, wWidth, 0, wHeight);

    T0->Start();                                        // set timer to 0

    glEnable(GL_BLEND);                                 //display images with transparent
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Gwin->loadBackgroundImage("images/win.png");///if goku wins display


        Swin->loadBackgroundImage("images/loss.png");///if saibamen wins display aka you lost
//SND->playMusic("sounds/lost.mp3");


    Info->loadBackgroundImage("images/op3.png");///displays at start of program title pages

    ///Im taking this stuff out becasue im initializing as i am reading in a text file for the levels.
    ///since this is hard coded and wont adapt to my file reader its out
/*
    M->loadBackgroundImage("images/bak.jpg");           // Load maze background image
    M->loadChestImage("images/chest.png");              // load chest image
    M->placeChest(3,3);                                 // place chest in a grid

    M->loadSetOfArrowsImage("images/arrwset.png");      // load set of arrows image
    M->placeStArrws(5,3);                               // place set of arrows

    Goku->initPlayer(M->getGridSize(),6,"images/p.png");   // initialize player pass grid size,image and number of frames
    Goku->loadArrowImage("images/arr.png");                // Load arrow image
    Goku->placePlayer(9,9);                                // Place player

    for(int i=1; i< M->getGridSize();i++)
    {
      W[i].wallInit(M->getGridSize(),"images/wall.png");// Load walls
      W[i].wallPlacement(i,5);                              // place each brick
    }


    for(int i=0; i<10;i++)
    {
        E[i].initEnm(M->getGridSize(),4,"images/e.png"); //Load enemy image////this will also allow you to pass in number of frames needed for your sprite sheet
        E[i].enemyPlacement(float(rand()%(M->getGridSize())),float(rand()%(M->getGridSize())));
        //place enemies random x,y
    }
    */
    //SND->initSounds();//address with the return value as you wish
    SND->playMusic("sounds/open.mp3");///playing the opening music
adjMatrix();
printAdjMatrix();
cout << endl;
}
void soundlib(){
if(Swin->GG == true){///another function i was workshopping for something but decided to
        ///to go in a different direction

    SND->playMusic("sounds/lost.mp3");
}

}
void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT);        // clear display screen

        glPushMatrix();
         Info->drawBackground();///first start out displaing the info/start screen
        glPopMatrix();
if(status){
        glPushMatrix();
        M->drawBackground();///if player hasnt died yet display background
        glPopMatrix();
        if(M->GG == true){
               static const auto hasWon = [] { printAdjMatrix(); return true;}(); ///
            glPushMatrix();/// once player wins we will display matrix that he won

            Gwin->drawBackground();///draw the winning output screen

            glPopMatrix();
        }
        else if(Swin->GG == true){
            glPushMatrix();
//SND->stopAllSounds();
            Swin->drawBackground();///now if goku dies then what we are going to do is display the lost background
            //soundlib();

            glPopMatrix();
        }
        else{
        glPushMatrix();
        M->drawBackground();
        glPopMatrix();///if anything else what we are doing is drawing the background and drawing the
        ///appropriate amount of walls for the maze
        for(int i=0; i<= walls;i++)
        {
           W[i].drawWall();
        }

        glPushMatrix();
            M->drawGrid();
        glPopMatrix();

        glPushMatrix();
            Goku->drawplayer();
        glPopMatrix();

        for(int i=0; i<10;i++)
        {
        E[i].drawEnemy();
        }

        glPushMatrix();
            Goku->drawArrow();
        glPopMatrix();

         glPushMatrix();
           M->drawChest();
        glPopMatrix();

        glPushMatrix();
           M->drawArrows();
        glPopMatrix();
        }

}



    glutSwapBuffers();
}


///start here

void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 0x31:   ///here is the case if player his the '1' key then we are going to load level 1
        status = true;///changes the status to true so we draw the background
        openFile("levels/L1.txt");


        M->loadBackgroundImage("images/grass.png");
        SND->stopAllSounds();/// we load everything taht pertains to that level here
        SND->playMusic("sounds/game.mp3");
        disk.adjM(matrix,mazeQuad);

        ///
        break;
    case 0x32:///here is the case if player his the '2' key then we are going to load level 1
        status = true;
        openFile("levels/L2.txt");
        ///have level loader for background put here
        M->loadBackgroundImage("images/lava.png");
        SND->stopAllSounds();
        SND->playMusic("sounds/lost.mp3");
        disk.adjM(matrix,mazeQuad);
        ///
        break;
    case 0x33:///here is the case if player his the '3' key then we are going to load level 1
        status = true;
        openFile("levels/L3.txt");
        M->loadBackgroundImage("images/rocky.jpg");
        SND->stopAllSounds();
        SND->playMusic("sounds/open.mp3");
        disk.adjM(matrix,mazeQuad);
        ///
        break;
    case 'k':///here is the case if player his the 'k' key then we are going to load level 1
        Goku->trigger = !(Goku->trigger);/// this changes the flag from false to true so that
        ///goku can fire his attack at enemeis

        if(Goku->trigger == true){
            cout << "GOKU CAN USE ENERGY BEAMS NOW!" << endl;

        }
        else
            cout <<"GOKU CANNOT USE ENERGY NOW!" << endl;
        break;
        /// i dont want this getting in the way down the line so im commenting it out for now

        case 'r':
            Info->loadBackgroundImage("images/op3.png");
            Info->drawBackground();

            break;
        case 27 :                       // esc key to exit
        case 'q':
            exit(0);
            break;

    }

    glutPostRedisplay();
}


 void GetOGLPos(int x, int y)
{
    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY, winZ;
    GLdouble posX, posY, posZ;

    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
    glGetDoublev( GL_PROJECTION_MATRIX, projection );
    glGetIntegerv( GL_VIEWPORT, viewport );

    winX = (float)x;
    winY = (float)viewport[3] - (float)y;
    glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

    gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

    xPos =posX ;
    yPos =posY ;
}
void arrowsAquired(int a,int b){
if(matrix[a][b] == 5){/// here are checking if the player has stepped into the grid position to where
        ///the bean is placed, for this we are checking the matrix
    cout << "GOKU HAS RECOVERED HIS STRENGTH!" << endl;
    Goku->arrowA = true;
    M->liveSetOfArrws = false;
}
}
void capsuleAquired(int a,int b){
if(matrix[a][b] == 4){/// here are checking if the player has stepped into the grid position to where
        ///the capsule is placed, for this we are checking the matrix
    cout <<"GOKU HAS DEFEATED THE VILLAN" << endl;
    glPushMatrix();
    Swin->drawBackground();
    M->GG = true;///if goku get the capsule then we assigning values to exit and draw the new
                 ///the new background
    glPopMatrix();
    M->liveChest = false;

}

}
 void idle(void)
{
for(int i = 0;i<enyC;i++){
    if((E[i].getEnemyLoc().x == Goku->getPlayerLoc().x) && (E[i].getEnemyLoc().y == Goku->getPlayerLoc().y)){///so for this function
            ///we are checking to see if goku and an enemy are in the same grid point and if they
            ///then we are assigning that goku has been defeated then we are saying the live = false to to then jump into
            ///another loop to display the the loss screen to the player
        /// ////////////////
        static const auto hasDied = []{cout <<"GOKU HAS BEEN DEFEATED" << endl;return true;}();
        Goku->livePlayer = false;
        Swin->GG = true;
        matrix[Goku->getPlayerLoc().x][Goku->getPlayerLoc().y] = 2;///then since goku died we replace his spot with a enenmy 2.
    }
}
if(Goku->arrowStatus == 1){
        if(Goku->getArrowLoc().x - 1 >= -1 && Goku->getArrowLoc().x + 1 <= 10){
            /// so what we are checking for here is to see if the arrows are colliding with a wall then the arrow will not
            ///be drawn any further
            if(matrix[Goku->getArrowLoc().x][Goku->getArrowLoc().y] == 1)
                Goku->arrowStatus = 0;


            for(int i = 0; i < enyC; i++){
                    /// so here is another big boi, this here is to check whether or not the arrow is comming into contact with the
                    /// any of the enemies and if so change the enemy life to zero then stop drawing the arrow
                if(E[i].getEnemyLoc().x == Goku->getArrowLoc().x && E[i].getEnemyLoc().y == Goku->getArrowLoc().y){
                    E[i].live = false;
                    matrix[E[i].getEnemyLoc().x][E[i].getEnemyLoc().y] = 0;
                    E[i].enemyPlacement(mazeQuad + 1, mazeQuad + 1);
                    Goku->arrowStatus = false;
                }
            }
        }
    }
    //Your Code here

    glutPostRedisplay();
}

void moveEnemies(){
    for(int i = 0; i < enyC; i ++){
        if(E[i].live){

            disk.djk(disk.dataK(E[i].getEnemyLoc().x, E[i].getEnemyLoc().y), Goku);
          ///here is where the enemies are getting their movement based on the player actions that goku takes.
          ///so here what we are doing is tht we are checking gokus action and if they are returned as the -1 and 0
          ///then we know that goku has taken a right and we will next move to filling the matrix with zeros '
          ///and then update the saibamen's new location and move the enemy
            if(E[i].getEnemyLoc().x - disk.gokuAct().first == -1 && E[i].getEnemyLoc().y - disk.gokuAct().second == 0){
                matrix[E[i].getEnemyLoc().x][E[i].getEnemyLoc().y] = 0;
                matrix[E[i].getEnemyLoc().x + 1][E[i].getEnemyLoc().y] = 2;
                E[i].moveEnemy("right");
                disk.relinquishVector();
            }
            ///here is where the enemies are getting their movement based on the player actions that goku takes.
          ///so here what we are doing is tht we are checking gokus action and if they are returned as the 1 and 0
          ///then we know that goku has taken a left and we will next move to filling the matrix with zeros '
          ///and then update the saibamen's new location and move the enemy
            else if(E[i].getEnemyLoc().x - disk.gokuAct().first == 1 && E[i].getEnemyLoc().y - disk.gokuAct().second == 0){
                matrix[E[i].getEnemyLoc().x][E[i].getEnemyLoc().y] = 0;
                matrix[E[i].getEnemyLoc().x - 1][E[i].getEnemyLoc().y] = 2;
                E[i].moveEnemy("left");
                disk.relinquishVector();
            }
            ///here is where the enemies are getting their movement based on the player actions that goku takes.
          ///so here what we are doing is tht we are checking gokus action and if they are returned as the 0 and 1
          ///then we know that goku has taken a down and we will next move to filling the matrix with zeros '
          ///and then update the saibamen's new location and move the enemy
            else if(E[i].getEnemyLoc().x - disk.gokuAct().first == 0 && E[i].getEnemyLoc().y - disk.gokuAct().second == 1){
                matrix[E[i].getEnemyLoc().x][E[i].getEnemyLoc().y] = 0;
                matrix[E[i].getEnemyLoc().x][E[i].getEnemyLoc().y - 1] = 2;
                E[i].moveEnemy("down");

                disk.relinquishVector();
            }
            ///here is where the enemies are getting their movement based on the player actions that goku takes.
          ///so here what we are doing is tht we are checking gokus action and if they are returned as the 0 and -1
          ///then we know that goku has taken a up and we will next move to filling the matrix with zeros '
          ///and then update the saibamen's new location and move the enemy
            else if(E[i].getEnemyLoc().x - disk.gokuAct().first == 0 && E[i].getEnemyLoc().y - disk.gokuAct().second == -1){
                matrix[E[i].getEnemyLoc().x][E[i].getEnemyLoc().y] = 0;
                matrix[E[i].getEnemyLoc().x][E[i].getEnemyLoc().y + 1] = 2;
                E[i].moveEnemy("up");
disk.relinquishVector();
            }

        }
    }
}
void mouse(int btn, int state, int x, int y){

    switch(btn){
        case GLUT_LEFT_BUTTON:

        if(state==GLUT_DOWN){

              GetOGLPos(x,y);
            }
            break;


      case GLUT_RIGHT_BUTTON:

        if(state==GLUT_DOWN){

              GetOGLPos(x,y);
            }
            break;
    }
     glutPostRedisplay();
};

void Specialkeys(int key, int x, int y)
{

    // Your Code here
    switch(key)
    {
    case GLUT_KEY_UP:/// i had to change these special keys becuase it wouldnt work with whaat i ws planning
         /*cout<< Goku->getPlayerLoc().x<< "    "<<Goku->getPlayerLoc().y<<endl;
         Goku->movePlayer("up");
         E[0].moveEnemy("up");
         E[1].moveEnemy("up");
         E[2].moveEnemy("up");

         */

         if(Goku->trigger == false){
                /// ///////////////////////////////////////////Goku->checkCollisionWithWalls(W);

            if(Goku->getPlayerLoc().y +1 < mazeQuad){
              ///
              if(!(matrix[Goku->getPlayerLoc().x][Goku->getPlayerLoc().y+1] == 1)){

                    ///all this function is doing is checking to see if the goku in the matrix is at the coordinates of the bean and
                    ///capsule are one above his, so we are checking to see and we are only allowed to move if there isnt a wall in the way
                    ///if not then we move
              arrowsAquired(Goku->getPlayerLoc().x,Goku->getPlayerLoc().y+1);
              capsuleAquired(Goku->getPlayerLoc().x,Goku->getPlayerLoc().y+1);
              matrix[Goku->getPlayerLoc().x][Goku->getPlayerLoc().y] = 0;
              Goku->movePlayer("up");

              matrix[Goku->getPlayerLoc().x][Goku->getPlayerLoc().y] = 3;
              ///still neeed enemy movement
              cout << '\n';
              moveEnemies();
              printAdjMatrix();

                }

            }
         }
         else if(Goku->arrowA == true){
            Goku->playerDir = "up";///if goku has the beans and we are shooting mode then whenever the key is pressed then we are also using a
            ///sound effect to go along with it.
            Goku->shootArrow();
             SND->playSoundEffects("sounds/blast.mp3");
         }
    break;

    case GLUT_KEY_DOWN:
         /*cout<< Goku->getPlayerLoc().x<< "    "<<Goku->getPlayerLoc().y<<endl;
         Goku->movePlayer("down");
         E[0].moveEnemy("down");
         E[1].moveEnemy("down");
         E[2].moveEnemy("down");
         */
          if(Goku->trigger == false){
            if(Goku->getPlayerLoc().y -1 >= 0){
              ///
              ///
              ///all this function is doing is checking to see if the goku in the matrix is at the coordinates of the bean and
                    ///capsule are one below his, so we are checking to see and we are only allowed to move if there isnt a wall in the way
                    ///if not then we move
              if(!(matrix[Goku->getPlayerLoc().x][Goku->getPlayerLoc().y-1]==1)){
                arrowsAquired(Goku->getPlayerLoc().x,Goku->getPlayerLoc().y-1);
              capsuleAquired(Goku->getPlayerLoc().x,Goku->getPlayerLoc().y-1);
                matrix[Goku->getPlayerLoc().x][Goku->getPlayerLoc().y] = 0;
              Goku->movePlayer("down");
              matrix[Goku->getPlayerLoc().x][Goku->getPlayerLoc().y] = 3;
              ///still neeed enemy movement
              cout << '\n';///after all of the checking we are moving the enenmies accordingly and then print the matrix
              moveEnemies();
              printAdjMatrix();
              }

            }
         }
         else if(Goku->arrowA == true){
            Goku->playerDir = "down";///if goku has the beans and we are shooting mode then whenever the key is pressed then we are also using a
            ///sound effect to go along with it.
            Goku->shootArrow();
            SND->playSoundEffects("sounds/blast.mp3");
         }
    break;

    case GLUT_KEY_LEFT:
        /*
         cout<< Goku->getPlayerLoc().x<< "    "<<Goku->getPlayerLoc().y<<endl;
         Goku->movePlayer("left");
         E[0].moveEnemy("left");
         E[1].moveEnemy("left");
         E[2].moveEnemy("left");
*/
 if(Goku->trigger == false){
            if(Goku->getPlayerLoc().x -1 >= 0){
              ///
              ///
///all this function is doing is checking to see if the goku in the matrix is at the coordinates of the bean and
                    ///capsule are one to  his left, so we are checking to see and we are only allowed to move if there isnt a wall in the way
                    ///if not then we move
              if(!(matrix[Goku->getPlayerLoc().x-1][Goku->getPlayerLoc().y]==1)){
                arrowsAquired(Goku->getPlayerLoc().x-1,Goku->getPlayerLoc().y);
              capsuleAquired(Goku->getPlayerLoc().x-1,Goku->getPlayerLoc().y);
                matrix[Goku->getPlayerLoc().x][Goku->getPlayerLoc().y] = 0;
              Goku->movePlayer("left");
              matrix[Goku->getPlayerLoc().x][Goku->getPlayerLoc().y] = 3;
              ///still neeed enemy movement
              cout << '\n';
              moveEnemies();
              printAdjMatrix();
              }

            }
         }
         else if(Goku->arrowA == true){
            Goku->playerDir = "left";///assigning the dircection of the arrow to fire
            Goku->shootArrow();///if goku has the beans and we are shooting mode then whenever the key is pressed then we are also using a
            ///sound effect to go along with it.
            SND->playSoundEffects("sounds/blast.mp3");
         }
    break;

    case GLUT_KEY_RIGHT:
         /*cout<< Goku->getPlayerLoc().x<< "    "<<Goku->getPlayerLoc().y<<endl;
         Goku->movePlayer("right");
         E[0].moveEnemy("right");
         E[1].moveEnemy("right");
         E[2].moveEnemy("right");
         */
          if(Goku->trigger == false){
            if(Goku->getPlayerLoc().x +1 < mazeQuad){
              ///
              ///all this function is doing is checking to see if the goku in the matrix is at the coordinates of the bean and
            ///capsule are one to his right his, so we are checking to see and we are only allowed to move if there isnt a wall in the way
                    ///if not then we move
              if(!(matrix[Goku->getPlayerLoc().x+1][Goku->getPlayerLoc().y]==1)){
                arrowsAquired(Goku->getPlayerLoc().x+1,Goku->getPlayerLoc().y);
              capsuleAquired(Goku->getPlayerLoc().x+1,Goku->getPlayerLoc().y);
                matrix[Goku->getPlayerLoc().x][Goku->getPlayerLoc().y] = 0;
              Goku->movePlayer("right");
              matrix[Goku->getPlayerLoc().x][Goku->getPlayerLoc().y] = 3;
              ///still neeed enemy movement
              cout << '\n';
              moveEnemies();
              printAdjMatrix();
              }

            }
         }
         else if(Goku->arrowA == true){
            Goku->playerDir = "right";///assigning the dircection of the arrow to fire
            Goku->shootArrow();///if goku has the beans and we are shooting mode then whenever the key is pressed then we are also using a
            ///sound effect to go along with it.
            SND->playSoundEffects("sounds/blast.mp3");
         }
    break;

   }
  glutPostRedisplay();
}


/* Program entry point */

int main(int argc, char *argv[])
{
   glutInit(&argc, argv);

   glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
   glutInitWindowSize (800, 800);                //window screen
   glutInitWindowPosition (100, 100);            //window position
   glutCreateWindow ("Maze");                    //program title
   init();

   glutDisplayFunc(display);                     //callback function for display
   glutReshapeFunc(resize);                      //callback for reshape
   glutKeyboardFunc(key);                        //callback function for keyboard
   glutSpecialFunc(Specialkeys);
   glutMouseFunc(mouse);
   glutIdleFunc(idle);
   glutMainLoop();

   return EXIT_SUCCESS;
}
