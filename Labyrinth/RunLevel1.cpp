#pragma once
#include "RunLevel1.h"
#include <iostream>
#include <conio.h>
#include "windows.h"

void changeWindowSize1() {

    //�������� ������ ����
    HWND hwnd;
    char Title[1024]; // ���������� ��� ����������� ��������� ����
    GetConsoleTitle((LPWSTR)Title, 1024); // ����� ��� ����
    hwnd = FindWindow(NULL, (LPWSTR)Title); // ����� hwnd ����
    MoveWindow(hwnd, 0, 0, 400, 400, TRUE);  // x, y, w, h - ����� ���������, x, y - ������ ����

    //����� ���� �������
    system("color 2F");
}

void runLevel1(char level1[15][15], int levelRows, int levelColumns) {

    //��������� ������� �� ��������� ������� ����
    changeWindowSize1();
    // ��������� ���������� ������
    int posX = 1, posY = 0;

    // ���������� ��� ���������� ����
    char move;

    // ���������� ��� �������� �����
    int moves = 0;

    // ������ ������
    level1[posX][posY] = '�';

    // ������� ���������� �����
    std::cout << "���-�� �����: " << moves << "\n\n";

    // �������� ������� (��������� �����)  
    showLevel1(level1, levelRows, levelColumns);

    // ������ ����������� ���� while. 
    bool levelComplete = false;
    while (!levelComplete) {

        std::cout << "\n������� ������� (W A S D): ";
        move = _getch();

        // ��������� ���� � ������ W A S D
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

        // ���� �� ��������� �� �������-��������� �������
        if (level1[posX][posY] == 'O') {
            system("cls");
            std::cout << "����� ���������� ����� �� �������: " << moves << std::endl;
            std::cout << "LEVEL 1 COMPLETED";
            Sleep(2000);
            levelComplete = true;
        }

        // ���� ������ ������ ������ ������ - ��� �����
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

        // ������������� ������� ������
        system("cls");
        level1[posX][posY] = '�';
        std::cout << "���-�� �����: " << moves << "\n\n";

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