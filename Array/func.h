#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <stdbool.h>
#include <math.h>

#define file_enter(type) fputs("\n", type)
#define max_color_value 255
#define dat_file_name "map-input-"
#define dat_folder_name "map-inputs\\"

struct _finddata_t c_file;
intptr_t hFile;
FILE* fp; //.dat FILE read
FILE* fw; //.ppm FILE write

//파일 구조체
typedef struct _file {
	char filename[100]; //.dat 파일 이름
	char path[100]; //.dat 파일 경로
	int row; //행
	int col; //열
}file;

//고도 구조체
typedef struct _elevation {
	int max; //고도값 최대
	int min; //고도값 최소
	int **array; //고도 배열
}elevation;

//이미지 구조체
typedef struct _image{
	int **red;
	int **green;
	int **blue;
}image;

//파일 함수
void findFilelist(file *fl); //.dat 파일 검색, 선택
void fileCheck(file *fl); //선택한 .dat 파일 검사


//고도 함수
void elevationArray(elevation *elev, file fl); //.dat 파일 고도값 추출
void findMaxMin(elevation *elev, file fl); //고도값 최대최소



//이미지 함수
//void imageArray(image *img); 
int loadGreyscale(elevation elev, int value); //고도값 -> rgb 변환 수식
void red(file fl, elevation elev, image* img); //고도값 -> red 변환
void green(file fl, elevation elev, image* img); //고도값 -> green 변환
void blue(file fl, elevation elev, image* img); //고도값 -> blue 변환


//이미지 변환 함수
void outputImage(file fl, elevation elev, image img); //img파일 출력