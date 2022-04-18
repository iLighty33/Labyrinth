#pragma once
#include "Level1.h"
#include <iostream>
#include <conio.h>
#include "windows.h"
void fillLevel1(char level1[15][15], int levelRows, int levelColumns) {

    for (int i = 0; i < levelRows; i++) {
        for (int j = 0; j < levelColumns; j++) {
            if (i == 0 || i == 14 || j == 14) {
                level1[i][j] = '#';
            }
            else
                if (j == 2 && i > 0 && i < 3)
                    level1[i][j] = '#';
                else
                    if (j == 4 && i > 0 && i < 5)
                        level1[i][j] = '#';
                    else
                        if (j == 6 && i > 0 && i < 4)
                            level1[i][j] = '#';
                        else
                            if (j == 10 && i > 0 && i < 2)
                                level1[i][j] = '#';
                            else
                                if (j == 12 && i > 0 && i < 2)
                                    level1[i][j] = '#';
                                else
                                    if (j == 3 && i > 8 && i < 13)
                                        level1[i][j] = '#';
                                    else
                                        if (j == 6 && i > 4 && i < 7)
                                            level1[i][j] = '#';
                                        else
                                            if (j == 8 && i > 4 && i < 7)
                                                level1[i][j] = '#';
                                            else
                                                if (j == 8 && i > 1 && i < 4)
                                                    level1[i][j] = '#';
                                                else
                                                    if (j == 8 && i > 4 && i < 13)
                                                        level1[i][j] = '#';
                                                    else
                                                        if (j == 12 && i > 8 && i < 13)
                                                            level1[i][j] = '#';
                                                        else
                                                            if (j == 10 && i > 10 && i < 14)
                                                                level1[i][j] = '#';
                                                            else
                                                                if (j == 6 && i > 10 && i < 13)
                                                                    level1[i][j] = '#';
                                                                else
                                                                    if (i == 4 && j > 0 && j < 3)
                                                                        level1[i][j] = '#';
                                                                    else
                                                                        if (i == 6 && j > 0 && j < 5)
                                                                            level1[i][j] = '#';
                                                                        else
                                                                            if (i == 8 && j > 0 && j < 8)
                                                                                level1[i][j] = '#';
                                                                            else
                                                                                if (i == 12 && j > 0 && j < 2)
                                                                                    level1[i][j] = '#';
                                                                                else
                                                                                    if (i == 12 && j > 3 && j < 7)
                                                                                        level1[i][j] = '#';
                                                                                    else
                                                                                        if (i == 10 && j > 4 && j < 7)
                                                                                            level1[i][j] = '#';
                                                                                        else
                                                                                            if (i == 3 && j > 12 && j < 14)
                                                                                                level1[i][j] = '#';
                                                                                            else
                                                                                                if (i == 3 && j > 7 && j < 12)
                                                                                                    level1[i][j] = '#';
                                                                                                else
                                                                                                    if (i == 5 && j > 10 && j < 14)
                                                                                                        level1[i][j] = '#';
                                                                                                    else
                                                                                                        if (i == 5 && j > 11 && j < 13)
                                                                                                            level1[i][j] = '#';
                                                                                                        else
                                                                                                            if (i == 5 && j > 9 && j < 11)
                                                                                                                level1[i][j] = '#';
                                                                                                            else
                                                                                                                if (i == 7 && j > 10 && j < 14)
                                                                                                                    level1[i][j] = '#';
                                                                                                                else
                                                                                                                    if (i == 7 && j > 8 && j < 10)
                                                                                                                        level1[i][j] = '#';
                                                                                                                    else
                                                                                                                        if (i == 9 && j > 8 && j < 11)
                                                                                                                            level1[i][j] = '#';
                                                                                                                        else
                                                                                                                            if (j == 0 && i > 1 && i < 9)
                                                                                                                                level1[i][j] = '#';
                                                                                                                            else
                                                                                                                                if (j == 0 && i > 9 && i < 14)
                                                                                                                                    level1[i][j] = '#';
                                                                                                                                else
                                                                                                                                    if (i == 10 && j > 1 && j < 4)
                                                                                                                                        level1[i][j] = '#';
                                                                                                                                    else
                                                                                                                                    {
                                                                                                                                        level1[i][j] = ' ';
                                                                                                                                        level1[9][0] = 'O';
                                                                                                                                    }
        }
    }
 
}