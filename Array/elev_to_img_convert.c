#include "func.h"

//고도값 -> rgb 변환 수식
int loadGreyscale(elevation elev, int value) {
    double result;
    result = (((double)value - (double)elev.min) / ((double)elev.max - (double)elev.min)) * (double)255;
    return (int)result;
}

//고도값 -> red 변환
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

//고도값 -> green 변환
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

//고도값 -> blue 변환
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