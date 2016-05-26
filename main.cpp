#include "Maze.h"
#include "maze.cpp"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


using namespace std;

Maze*   pMaze = new Maze();

int main(int argc,char** argv)
{
    pMaze->initMazeArray(20,20);
    //pMaze->printMazeArray();
    pMaze->autoGenerate();
    pMaze->printMazeArray();

    //pMaze->reset();
    //pMaze->initMazeArray(3,8);
    //pMaze->autoGenerate();
    //pMaze->printMazeArray();

    if(pMaze)
    {
        delete pMaze;
    }
    return 0;
}
