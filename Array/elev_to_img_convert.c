#include "func.h"

//���� -> rgb ��ȯ ����
int loadGreyscale(elevation elev, int value) {
    double result;
    result = (((double)value - (double)elev.min) / ((double)elev.max - (double)elev.min)) * (double)255;
    return (int)result;
}

//���� -> red ��ȯ
void red(file fl, elevation elev, image* img) {
    int** array;
    array = (int**)malloc(sizeof(int*) * fl.row);
    for (int i = 0; i < fl.row; i++) {
        array[i] = (int*)malloc(sizeof(int) * fl.col);
    }

    for (int i = 0; i < fl.row; i++) {
        for (int j = 0; j < fl.col; j++) {
            array[i][j] = loadGreyscale(elev, elev.array[i][j]);
            //printf("%d ", array[i][j]);
        }
    }
    img->red = array;
    return;
}

//���� -> green ��ȯ
void green(file fl, elevation elev, image* img) {
    int** array;
    array = (int**)malloc(sizeof(int*) * fl.row);
    for (int i = 0; i < fl.row; i++) {
        array[i] = (int*)malloc(sizeof(int) * fl.col);
    }
    for (int i = 0; i < fl.row; i++) {
        for (int j = 0; j < fl.col; j++) {
            array[i][j] = loadGreyscale(elev, elev.array[i][j]);
        }
    }
    img->green = array;
    return;
}

//���� -> blue ��ȯ
void blue(file fl, elevation elev, image* img) {
    int** array;
    array = (int**)malloc(sizeof(int*) * fl.row);
    for (int i = 0; i < fl.row; i++) {
        array[i] = (int*)malloc(sizeof(int) * fl.col);
    }
    for (int i = 0; i < fl.row; i++) {
        for (int j = 0; j < fl.col; j++) {
            array[i][j] = loadGreyscale(elev, elev.array[i][j]);
        }
    }
    img->blue = array;
    return;
}