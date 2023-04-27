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

//���� ����ü
typedef struct _file {
	char filename[100]; //.dat ���� �̸�
	char path[100]; //.dat ���� ���
	int row; //��
	int col; //��
}file;

//�� ����ü
typedef struct _elevation {
	int max; //���� �ִ�
	int min; //���� �ּ�
	int **array; //�� �迭
}elevation;

//�̹��� ����ü
typedef struct _image{
	int **red;
	int **green;
	int **blue;
}image;

//���� �Լ�
void findFilelist(file *fl); //.dat ���� �˻�, ����
void fileCheck(file *fl); //������ .dat ���� �˻�


//�� �Լ�
void elevationArray(elevation *elev, file fl); //.dat ���� ���� ����
void findMaxMin(elevation *elev, file fl); //���� �ִ��ּ�



//�̹��� �Լ�
//void imageArray(image *img); 
int loadGreyscale(elevation elev, int value); //���� -> rgb ��ȯ ����
void red(file fl, elevation elev, image* img); //���� -> red ��ȯ
void green(file fl, elevation elev, image* img); //���� -> green ��ȯ
void blue(file fl, elevation elev, image* img); //���� -> blue ��ȯ


//�̹��� ��ȯ �Լ�
void outputImage(file fl, elevation elev, image img); //img���� ���