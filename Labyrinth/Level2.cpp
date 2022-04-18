#pragma once
void fillLevel2(char level2[20][20], int levelRows, int levelColumns) {

    for (int i = 0; i < levelRows; i++) {
        for (int j = 0; j < levelColumns; j++) {
            if (i == 0 || i == 19 || j == 19 || j == 0)
                level2[i][j] = '#';
            else
            {
                level2[i][j] = ' ';
                level2[9][1] = 'O';
            }
        }
    }

}