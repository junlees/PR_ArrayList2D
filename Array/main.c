#include "func.h"

int main(void)
{
	file fl; //���� ����ü
	elevation elev; //�� ����ü
	image img; //�̹��� ����ü

	findFilelist(&fl); //.dat ���� �˻�, ����
	fileCheck(&fl); //������ .dat ���� �˻�


	elevationArray(&elev, fl); //.dat ���� ���� ����
	findMaxMin(&elev, fl); //���� �ִ��ּ�

	red(fl, elev, &img); //���� -> red ��ȯ
	green(fl, elev, &img); //���� -> green ��ȯ
	blue(fl, elev, &img); //���� -> blue ��ȯ

	outputImage(fl, elev, img); //rgb -> img���� ��ȯ, ���

	return 0;
}