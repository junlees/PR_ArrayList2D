#include "func.h"

int main(void)
{
	file fl; //파일 구조체
	elevation elev; //고도 구조체
	image img; //이미지 구조체

	findFilelist(&fl); //.dat 파일 검색, 선택
	fileCheck(&fl); //선택한 .dat 파일 검사


	elevationArray(&elev, fl); //.dat 파일 고도값 추출
	findMaxMin(&elev, fl); //고도값 최대최소

	red(fl, elev, &img); //고도값 -> red 변환
	green(fl, elev, &img); //고도값 -> green 변환
	blue(fl, elev, &img); //고도값 -> blue 변환

	outputImage(fl, elev, img); //rgb -> img파일 변환, 출력

	return 0;
}