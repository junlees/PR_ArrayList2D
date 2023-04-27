#include "func.h"

//img파일 출력
void outputImage(file fl, elevation elev, image img) {
    char buf[10];
    char extractPath[100];
    strcpy(extractPath, dat_folder_name);
    strcat(extractPath, fl.filename);
    strcat(extractPath, ".ppm");
    fw = fopen(extractPath, "w");

    //.ppm 파일 열기, 생성 여부 검사
    if (fw == NULL) {
        printf("Error : Unable to open/create file <%s> Extract fail\n", fl.filename);
        exit(0);
    }

    fputs("P3\n", fw);

    sprintf(buf, "%d ", fl.col);
    fputs(buf, fw);

    sprintf(buf, "%d\n", fl.row);
    fputs(buf, fw);

    sprintf(buf, "%d\n", max_color_value);
    fputs(buf, fw);

    //.ppm 파일 작성
    for (int i = 0; i < fl.row; i++) {
        for (int j = 0; j < fl.col; j++) {
            sprintf(buf, "%d ", img.red[i][j]);
            fputs(buf, fw);
            sprintf(buf, "%d ", img.green[i][j]);
            fputs(buf, fw);
            sprintf(buf, "%d ", img.blue[i][j]);
            fputs(buf, fw);

         //   printf(" %d %d %d ", img.red[i][j], img.green[i][j], img.blue[i][j]);
        }
        //printf("\n");
    }
    fclose(fw);

    printf("File convert complite\n");

    return;
}
