#pragma once
#include "RunLevel2.h"
#include <iostream>
#include <conio.h>
#include "windows.h"
void runLevel2(char level2[20][20], int levelRows, int levelColumns) {
    system("cls");
    system("color 5F");

    int posX = 1, posY = 0;

    char move;
    int moves = 0;

    level2[posX][posY] = '�';

    // �������� ������� (��������� �����)   
    std::cout << "���-�� �����: " << moves << "\n\n";

    for (int i = 0; i < levelRows; i++) {
        for (int j = 0; j < levelColumns; j++) {
            std::cout << level2[i][j] << " ";

        }
        std::cout << "\n";
    }

    // ������ ����������� ���� while

    while (true) {
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
                level2[posX - 1][posY] = ' '; // �������� ����
        }
        if (move == 'w' || move == 'W') {
            posX--;
            if (posX >= 0)
                level2[posX + 1][posY] = ' ';
        }
        if (move == 'a' || move == 'A') {
            posY--;
            if (posY >= 0)
                level2[posX][posY + 1] = ' ';
        }

        if (move == 'd' || move == 'D') {
            posY++;
            if (posY >= 0)
                level2[posX][posY - 1] = ' ';
        }
        if (level2[posX][posY] == 'O') {
            system("cls");
            std::cout << "����� ���������� ����� �� �������: " << moves << std::endl;
            std::cout << "LEVEL 2 COMPLETED";
            break;
        }

        if (level2[posX][posY] == '#') {
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

            if (level2[posX][posY] == ' ') {
                moves++;
            }

        system("cls");

        level2[posX][posY] = '�';

        std::cout << "���-�� �����: " << moves << "\n\n";

        for (int i = 0; i < levelRows; i++) {
            for (int j = 0; j < levelColumns; j++) {
                std::cout << level2[i][j] << " ";

            }
            std::cout << "\n";
        }
    }
}