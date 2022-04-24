#pragma once
#include "RunLevel3.h"
#include <iostream>
#include <conio.h>
#include "windows.h"

void changeWindowSize3() {

    //�������� ������ ����
    HWND hwnd;
    char Title[1024]; // ���������� ��� ����������� ��������� ����
    GetConsoleTitle((LPWSTR)Title, 1024); // ����� ��� ����
    hwnd = FindWindow(NULL, (LPWSTR)Title); // ����� hwnd ����
    MoveWindow(hwnd, 0, 0, 600, 600, TRUE);  // x, y, w, h - ����� ���������, x, y - ������ ����

    //����� ���� �������
    system("color 3F");
}

void runLevel3(char level3[30][30], int levelRows, int levelColumns) {

    //������� ������� �� ����������� ������
    system("cls");
    //��������� ������� �� ��������� ������� ����
    changeWindowSize3();
    // ��������� ���������� ������
    int posX = 1, posY = 6;

    // ���������� ��� ���������� ����
    char move;

    // ���������� ��� �������� �����
    int moves = 0;

    // ������ ������
    level3[posX][posY] = '�';

    // ������� ���������� �����
    std::cout << "���-�� �����: " << moves << "\n\n";

    // �������� ������� (��������� �����)  
    showLevel3(level3, levelRows, levelColumns);

    // ������ ����������� ���� while. 
    bool levelComplete = false;
    while (!levelComplete) {

        std::cout << "\n������� ������� (W A S D): ";
        move = _getch();

        // ��������� ���� � ������ W A S D
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

        // ���� �� ��������� �� �������-��������� �������
        if (level3[posX][posY] == 'O') {
            system("cls");
            std::cout << "����� ���������� ����� �� �������: " << moves << std::endl;
            std::cout << "LEVEL 3 COMPLETED";
            Sleep(2000);
            levelComplete = true;
        }

        // ���� ������ ������ ������ ������ - ��� �����
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

        // ������������� ������� ������
        system("cls");
        level3[posX][posY] = '�';
        std::cout << "���-�� �����: " << moves << "\n\n";

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