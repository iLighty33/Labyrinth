#pragma once
#include "RunLevel3.h"
#include <iostream>
#include <conio.h>
#include "windows.h"

void changeWindowSize3() {

    // Change windows size
    HWND hwnd;
    char Title[1024]; // Variable for remember title of the window
    GetConsoleTitle((LPWSTR)Title, 1024); // Getting to know title of the window
    hwnd = FindWindow(NULL, (LPWSTR)Title); // Getting to know hwnd of the window
    MoveWindow(hwnd, 0, 0, 600, 600, TRUE);  // x, y, w, h - new positions, x, y - width of the window

    // Change windows color
    system("color 3F");
}

void runLevel3(char level3[30][30], int levelRows, int levelColumns) {

    // Cleaning the console because of previous level
    system("cls");
    // Running function to change window size
    changeWindowSize3();
    // Default coordinats of player position
    int posX = 1, posY = 6;

    // Variable for reading steps
    char move;

    // Variable for counting moves
    int moves = 0;

    // Icon of the player
    level3[posX][posY] = 'Æ';

    // Counter of quantity of moves
    std::cout << "Quantity of steps: " << moves << "\n\n";

    // Show level (home screen)  
    showLevel3(level3, levelRows, levelColumns);

    // Creating endless cycle "while"
    bool levelComplete = false;
    while (!levelComplete) {

        std::cout << "\nPress the key (W A S D): ";
        move = _getch();

        // adding entrance from keyboard W A S D
        switch (move) {
        case 's': case 'S':
            posX++;
            if (posX >= 0 && level3[posX][posY] != '#' && level3[posX][posY] != 'O') {
                std::swap(level3[posX][posY], level3[posX - 1][posY]);
                moves++;
                break;
            }
            break;

        case 'w': case 'W':
            posX--;
            if (posX >= 0 && level3[posX][posY] != '#' && level3[posX][posY] != 'O') {
                std::swap(level3[posX][posY], level3[posX + 1][posY]);
                moves++;
                break;
            }
            break;

        case 'a': case 'A':
            posY--;
            if (posY >= 0 && level3[posX][posY] != '#' && level3[posX][posY] != 'O') {
                std::swap(level3[posX][posY], level3[posX][posY + 1]);
                moves++;
                break;
            }
            break;


        case 'd': case 'D':
            posY++;
            if (posY >= 0 && level3[posX][posY] != '#' && level3[posX][posY] != 'O') {
                std::swap(level3[posX][posY], level3[posX][posY - 1]);
                moves++;
                break;
            }
            break;

        }

        // If we get to the portal - complting the level
        if (level3[posX][posY] == 'O') {
            system("cls");
            std::cout << "Common quantity of step for level: " << moves << std::endl;
            std::cout << "LEVEL 3 COMPLETED";
            Sleep(2000);
            levelComplete = true;
        }

        // If we trying to go though wall - step back
        if (level3[posX][posY] == '#') {
            system("cls");

            switch (move) {
            case 's': case 'S':
                posX--; break;
            case 'w': case 'W':
                posX++; break;
            case 'a': case 'A':
                posY++; break;
            case 'd': case 'D':
                posY--; break;
            }

        }

        // Showing level again
        system("cls");
        level3[posX][posY] = 'Æ';
        std::cout << "Quantity of moves: " << moves << "\n\n";

        showLevel3(level3, levelRows, levelColumns);

    }
}

void showLevel3(char level2[30][30], int levelRows, int levelColumns) {
    for (int i = 0; i < levelRows; i++) {
        for (int j = 0; j < levelColumns; j++) {
            std::cout << level2[i][j] << " ";

        }
        std::cout << "\n";
    }
}