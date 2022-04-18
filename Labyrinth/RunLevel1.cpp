#pragma once
#include "RunLevel1.h"
#include <iostream>
#include <conio.h>
#include "windows.h"
void runLevel1(char level1[15][15], int levelRows, int levelColumns) {

    system("color 2F");

    int posX = 1, posY = 0;

    char move;
    int moves = 0;

    level1[posX][posY] = '�';

    // �������� ������� (��������� �����)   
    std::cout << "���-�� �����: " << moves << "\n\n";

    for (int i = 0; i < levelRows; i++) {
        for (int j = 0; j < levelColumns; j++) {
            std::cout << level1[i][j] << " ";

        }
        std::cout << "\n";
    }

    // ������ ����������� ���� while
    bool levelComplete = false;
    while (levelComplete != true) {
        // if (_kbhit()) { 
     /*
             sym = _getch();

             switch (sym) {
             case 'a': case 'A': system("cls"); cout << "��� �����\n"; break;
             case 'd': case 'D': system("cls"); cout << "��� ������\n"; break;
             }*/
             //  }
               //Sleep(100);
               //timer += 100;
              // if (timer >= 1000) {
              //     cout << ".\n";
              //     timer = 0;

        std::cout << "\n������� ������� (W A S D): ";
        //cin >> move;
        move = _getch();

        // ��������� ���� � ������ W A S D
        // ����� ����������� ������ - ��������� ��� "����"

        if (move == 's' || move == 'S') {
            //std::cout << "��� ����" << std::endl;
            posX++;
            // swap(level1[posX][posY], level1[posX+1][posY]);
            if (posX >= 0)
                level1[posX - 1][posY] = ' '; // �������� ����
        }
        if (move == 'w' || move == 'W') {
            posX--;
            if (posX >= 0)
                level1[posX + 1][posY] = ' ';
        }
        if (move == 'a' || move == 'A') {
            posY--;
            if (posY >= 0)
                level1[posX][posY + 1] = ' ';
        }

        if (move == 'd' || move == 'D') {
            posY++;
            if (posY >= 0)
                level1[posX][posY - 1] = ' ';
        }
        if (level1[posX][posY] == 'O') {
            system("cls");
            std::cout << "����� ���������� ����� �� �������: " << moves << std::endl;
            std::cout << "LEVEL 1 COMPLETED";
            Sleep(2000);
            levelComplete = true;

            //break;
        }

        if (level1[posX][posY] == '#') {
            system("cls");
            // moves--;
            if (move == 's')
                posX--;
            if (move == 'w')
                posX++;
            if (move == 'a')
                posY++;
            if (move == 'd')
                posY--;
            //cout << "FINISH";
        }
        else

            // ������� �����

            if (level1[posX][posY] == ' ') {
                moves++;
            }

        system("cls");

        level1[posX][posY] = '�';

        std::cout << "���-�� �����: " << moves << "\n\n";

        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                std::cout << level1[i][j] << " ";

            }
            std::cout << "\n";
        }
    }
}