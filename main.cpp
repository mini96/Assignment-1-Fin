/*
Author: Menelik Gedion
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <cmath>
#include <queue>
#include <cstdio> //EXIT_SUCESS
using namespace std;
#include "State.h"
#include "Game.h"

int main()
{
    srand (time(NULL));

    cout <<"Hello This program is to get the numbers arranged in a certain order\n"
    //<< "Hello This Program is just uses four basic command u 'up', j 'down', h'left and k'right' \n"
         << " 1 2 3\n"
         << " 4 0 5\n"
         << " 6 7 8\n";
    Game g;
    g.startGame();

    return 0;
}
