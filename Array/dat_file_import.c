#include "func.h"

//.dat 파일 검색, 선택
void findFilelist(file* fl) {
    int i = 0;
    int n = 0;
    int selectNum;

    //map-inputs 폴더에 .dat파일이 있는지 검사
    //true - 없으면 종료
    if ((hFile = _findfirst("map-inputs\\*.dat", &c_file)) == -1L) {
        printf("Error : No *.dat files in current directory\n");
        exit(0);
    }

    //파일 리스트 출력
    printf("Select file\n");
    do {
        strcpy(fl->filename, &c_file.name);
        printf("%d | %s\n", i+1, fl->filename);
        i++;
    } while (_findnext(hFile, &c_file) == 0);

    //원하는 파일 숫자로 선택
    //true - break
    //false - 잘못된 숫자 에러 출력 후 continue
    do {
        printf("Enter a number\n");
        scanf("%d", &selectNum);
        if (selectNum <= i && selectNum >= 1) {
            break;
        }
        else {
            while (getchar() != '\n');
            printf("Entered the wrong number\n\n");
        } 
    } while (1);
    
    hFile = _findfirst("map-inputs\\*.dat", &c_file);

    //파일 이름 추출
    do {
        strcpy(fl->filename, &c_file.name);
        //printf("%s\n", fl->filename);
        n++;
    } while ((_findnext(hFile, &c_file) == 0) && (selectNum > n));

    printf("filename : %s\n", fl->filename);

    //파일 경로 저장
    strcpy(fl->path, dat_folder_name);
    strcat(fl->path, fl->filename);
    printf("path : %s\n", fl->path);

    _findclose(hFile);
    return;
}

//선택한 .dat 파일 검사
void fileCheck(file *fl) {
    char check[100] = "\0";
    int col = 0, row = 0;
    
    //파일 이름에서 행, 열 추출
    sscanf(fl->filename, "%10s%d-%d", check, &col, &row);
    printf("name check : [%s] [%d] [%d]\n", check, col, row);

    //파일 이름 검사
    if (strcmp(check, dat_file_name) != 0 || col < 1 || row < 1) {
        printf("Error : Problem reading in rows and columns\n");
        exit(0);
    }

    fl->col = col;
    fl->row = row;
    printf("row : %d\n", fl->row);
    printf("col : %d\n", fl->col);

    int size = col * row; //파일 이름에 정의된 파일 값 개수

    char numCheck[10] = "\0";
    double num;
    int num_count = 0; //파일 값 개수

    FILE* fp;
	fp = fopen(fl->path, "r");

    //파일 read 검사
	if (fp == NULL){
        printf("Error : Unable to open file <%s>\n", fl->filename);
        exit(0);
	}

    //파일 값 검사
    //정수형 외의 값이 있으면 종료
    while (fscanf(fp, "%s", &numCheck) != EOF) {
        //printf("%s ", numCheck);
        
        //문자형이 있는지 검사
        if (sscanf(numCheck, "%lf", &num) != 1) {
            printf("\nError : Read a non-integer value .");
            exit(0);
        }

        //정수가 아닌 유리수가 있는지 검사
        else if ((num - (int)num) != 0.0) {
            printf("\nError : Read a non-integer value .");
            exit(0);
        }
        num_count++;
    }

    fclose(fp);

    printf("\n");
    printf("size : %d count : %d\n", size, num_count);

    //파일 이름에 정의된 값 개수와 실제 내부의 값 개수가 맞는지 검사
    if (size > num_count) {
        printf("Error : End of file reached prior to getting all the required data\n");
        exit(0);
    }
    if (size < num_count) {
        printf("Error : Too many data points\n");
        exit(0);
    }
    return;
}

//.dat 파일 고도값 추출
void elevationArray(elevation* elev, file fl) {
    int** array;

    //fp = fopen("map-inputs\\map-input-844-480.dat", "r");//임시
    fp = fopen(fl.path, "r");

    //2차원 동적 배열 생성
    array = (int**)malloc(sizeof(int*) * fl.row);
    for (int i = 0; i < fl.row; i++) {
        array[i] = (int*)malloc(sizeof(int) * fl.col);
    }

    //파일에서 불러온 고도값을 행, 열에 맞춰 메모리에 저장
    for (int i = 0; i < fl.row; i++) {
        for (int j = 0; j < fl.col; j++) {
            fscanf(fp, "%d", &array[i][j]);
            //printf("row : %d | col : %d | value : %d \n", i, j, array[i][j]);
        }
        //printf("\n");
        //printf("--------------------------------------------------------------------");
        //printf("\n");
    }
    elev->array = array;

    fclose(fp);
    /*for (int i = 0; i < fl->col; i++)
        free(array[i]);
    free(array);*/

    return;
}