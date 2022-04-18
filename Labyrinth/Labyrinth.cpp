#include <iostream>
#include "Level1.h"
#include "Level2.h"
#include "RunLevel1.h"
#include "RunLevel2.h"
using namespace std;

unsigned int timer = 0;



int main()
{
    setlocale(LC_ALL, "Russian");

    // Уровень 1

    const int x1 = 15, y1 = 15;
    char level1[x1][y1];

    char* pLvl1 = &level1[x1][y1];
    fillLevel1(level1, 15, 15);

   /* char* pLevel1[15];
    for (int i = 0; i < 15; i++)
        pLevel1[i] = level1[x]; */

    runLevel1(level1, 15, 15);


    // Уровень 2

    const int x2 = 20, y2 = 20;
    char level2[x2][y2];
    fillLevel2(level2, 20, 20);
    
    runLevel2(level2, 20, 20);

    return 0;
}
