#pragma once
#include "RunLevel2.h"
#include <iostream>
#include <conio.h>
#include "windows.h"

void changeWindowSize2() {

    //�������� ������ ����
    HWND hwnd;
    char Title[1024]; // ���������� ��� ����������� ��������� ����
    GetConsoleTitle((LPWSTR)Title, 1024); // ����� ��� ����
    hwnd = FindWindow(NULL, (LPWSTR)Title); // ����� hwnd ����
    MoveWindow(hwnd, 0, 0, 450, 450, TRUE);  // x, y, w, h - ����� ���������, x, y - ������ ����

    //����� ���� �������
    system("color 5F");
}

void runLevel2(char level2[20][20], int levelRows, int levelColumns) {

    //������� ������� �� ����������� ������
    system("cls");
    //��������� ������� �� ��������� ������� ����
    changeWindowSize2();
    // ��������� ���������� ������
    int posX = 1, posY = 0;

    // ���������� ��� ���������� ����
    char move;

    // ���������� ��� �������� �����
    int moves = 0;

    // ������ ������
    level2[posX][posY] = '�';

    // ������� ���������� �����
    std::cout << "���-�� �����: " << moves << "\n\n";

    // �������� ������� (��������� �����)  
    showLevel2(level2, levelRows, levelColumns);

    // ������ ����������� ���� while. 
    bool levelComplete = false;
    while (!levelComplete) {

        std::cout << "\n������� ������� (W A S D): ";
        move = _getch();

        // ��������� ���� � ������ W A S D
        switch (move) {
        case 's': case 'S':
            posX++;
            if (posX >= 0 && level2[posX][posY] != '#' && level2[posX][posY] != 'O') {
                std::swap(level2[posX][posY], level2[posX - 1][posY]);
                moves++;
                break;
            }
            break;

        case 'w': case 'W':
            posX--;
            if (posX >= 0 && level2[posX][posY] != '#' && level2[posX][posY] != 'O') {
                std::swap(level2[posX][posY], level2[posX + 1][posY]);
                moves++;
                break;
            }
            break;

        case 'a': case 'A':
            posY--;
            if (posY >= 0 && level2[posX][posY] != '#' && level2[posX][posY] != 'O') {
                std::swap(level2[posX][posY], level2[posX][posY + 1]);
                moves++;
                break;
            }
            break;


        case 'd': case 'D':
            posY++;
            if (posY >= 0 && level2[posX][posY] != '#' && level2[posX][posY] != 'O') {
                std::swap(level2[posX][posY], level2[posX][posY - 1]);
                moves++;
                break;
            }
            break;

        }

        // ���� �� ��������� �� �������-��������� �������
        if (level2[posX][posY] == 'O') {
            system("cls");
            std::cout << "����� ���������� ����� �� �������: " << moves << std::endl;
            std::cout << "LEVEL 2 COMPLETED";
            Sleep(2000);
            levelComplete = true;
        }

        // ���� ������ ������ ������ ������ - ��� �����
        if (level2[posX][posY] == '#') {
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

        // ������������� ������� ������
        system("cls");
        level2[posX][posY] = '�';
        std::cout << "���-�� �����: " << moves << "\n\n";

        showLevel2(level2, levelRows, levelColumns);

    }
}

void showLevel2(char level2[20][20], int levelRows, int levelColumns) {
    for (int i = 0; i < levelRows; i++) {
        for (int j = 0; j < levelColumns; j++) {
            std::cout << level2[i][j] << " ";

        }
        std::cout << "\n";
    }
}