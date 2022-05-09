#pragma once
#include "RunLevel1.h"
#include <iostream>
#include <conio.h>
#include "windows.h"

void changeWindowSize1() {

    // Change windows size
    HWND hwnd;
    char Title[1024]; // Variable for remember title of the window
    GetConsoleTitle((LPWSTR)Title, 1024); // Getting to know title of the window
    hwnd = FindWindow(NULL, (LPWSTR)Title); // Getting to know hwnd of the window
    MoveWindow(hwnd, 0, 0, 400, 400, TRUE);  // x, y, w, h - new positions, x, y - width of the window

    // Change windows color
    system("color 2F");
}

void runLevel1(char level1[15][15], int levelRows, int levelColumns) {

    // Rurring finction to change window size
    changeWindowSize1();
    // Default coordinats of player position
    int posX = 1, posY = 0;

    // Variable for reading steps
    char move;

    // Variable for counting moves
    int moves = 0;

    // Icon of the player
    level1[posX][posY] = '�';

    // Counter of quantity of moves
    std::cout << "Quantity of steps: " << moves << "\n\n";

    // Show level (home screen)  
    showLevel1(level1, levelRows, levelColumns);

    // Creating endless cycle "while"
    bool levelComplete = false;
    while (!levelComplete) {

        std::cout << "\nPress the key (W A S D): ";
        move = _getch();

        // adding entrance from keyboard W A S D
        switch (move) {
        case 's': case 'S':
            posX++;
            if (posX >= 0 && level1[posX][posY] != '#' && level1[posX][posY] != 'O') { 
                std::swap(level1[posX][posY], level1[posX - 1][posY]);
                moves++;
                break;
            }
            break;

        case 'w': case 'W':
            posX--;
            if (posX >= 0 && level1[posX][posY] != '#' && level1[posX][posY] != 'O') {
                std::swap(level1[posX][posY], level1[posX + 1][posY]);
                moves++;
                break;
            }
            break;

        case 'a': case 'A':
            posY--;
            if (posY >= 0 && level1[posX][posY] != '#' && level1[posX][posY] != 'O') {
                std::swap(level1[posX][posY], level1[posX][posY + 1]);
                moves++;
                break;
            }
            break;


        case 'd': case 'D':
            posY++;
            if (posY >= 0 && level1[posX][posY] != '#' && level1[posX][posY] != 'O') {
                std::swap(level1[posX][posY], level1[posX][posY - 1]);
                moves++;
                break;
            }
            break;
            
        }

        // If we get to the portal - complting the level
        if (level1[posX][posY] == 'O') {
            system("cls");
            std::cout << "Common quantity of step for level: " << moves << std::endl;
            std::cout << "LEVEL 1 COMPLETED";
            Sleep(2000);
            levelComplete = true;
        }

        // If we trying to go though wall - step back
        if (level1[posX][posY] == '#') {
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
        level1[posX][posY] = '�';
        std::cout << "Quantity of moves: " << moves << "\n\n";

        showLevel1(level1, levelRows, levelColumns);

    }
}

void showLevel1(char level1[15][15], int levelRows, int levelColumns) {
    for (int i = 0; i < levelRows; i++) {
        for (int j = 0; j < levelColumns; j++) {
            std::cout << level1[i][j] << " ";

        }
        std::cout << "\n";
    }
}