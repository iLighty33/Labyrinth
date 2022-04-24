#pragma once
#include "RunLevel1.h"
#include <iostream>
#include <conio.h>
#include "windows.h"

void changeWindowSize1() {

    //Изменить размер окна
    HWND hwnd;
    char Title[1024]; // Переменная для запоминания заголовка окна
    GetConsoleTitle((LPWSTR)Title, 1024); // Узнаём имя окна
    hwnd = FindWindow(NULL, (LPWSTR)Title); // Узнаём hwnd окна
    MoveWindow(hwnd, 0, 0, 400, 400, TRUE);  // x, y, w, h - новые положения, x, y - ширина окна

    //Задаём цвет консоли
    system("color 2F");
}

void runLevel1(char level1[15][15], int levelRows, int levelColumns) {

    //Запускаем функцию по изменению размера окна
    changeWindowSize1();
    // Начальные координаты игрока
    int posX = 1, posY = 0;

    // Переменная для считывания шага
    char move;

    // Переменная для счётчика шагов
    int moves = 0;

    // Значок игрока
    level1[posX][posY] = 'Ж';

    // Счётчик количества шагов
    std::cout << "Кол-во шагов: " << moves << "\n\n";

    // Показать уровень (начальный экран)  
    showLevel1(level1, levelRows, levelColumns);

    // Создаём бесконечный цикл while. 
    bool levelComplete = false;
    while (!levelComplete) {

        std::cout << "\nНажмите клавишу (W A S D): ";
        move = _getch();

        // добавляем ввод с клавиш W A S D
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

        // Если мы добрались до портала-завершаем уровень
        if (level1[posX][posY] == 'O') {
            system("cls");
            std::cout << "Общее количество шагов за уровень: " << moves << std::endl;
            std::cout << "LEVEL 1 COMPLETED";
            Sleep(2000);
            levelComplete = true;
        }

        // Если пытаем пройти сквозь стенку - шаг назад
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

        // Прорисовываем уровень заного
        system("cls");
        level1[posX][posY] = 'Ж';
        std::cout << "Кол-во шагов: " << moves << "\n\n";

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