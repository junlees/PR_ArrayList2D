#include "func.h"

//.dat ���� �˻�, ����
void findFilelist(file* fl) {
    int i = 0;
    int n = 0;
    int selectNum;

    //map-inputs ������ .dat������ �ִ��� �˻�
    //true - ������ ����
    if ((hFile = _findfirst("map-inputs\\*.dat", &c_file)) == -1L) {
        printf("Error : No *.dat files in current directory\n");
        exit(0);
    }

    //���� ����Ʈ ���
    printf("Select file\n");
    do {
        strcpy(fl->filename, &c_file.name);
        printf("%d | %s\n", i+1, fl->filename);
        i++;
    } while (_findnext(hFile, &c_file) == 0);

    //���ϴ� ���� ���ڷ� ����
    //true - break
    //false - �߸��� ���� ���� ��� �� continue
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

    //���� �̸� ����
    do {
        strcpy(fl->filename, &c_file.name);
        //printf("%s\n", fl->filename);
        n++;
    } while ((_findnext(hFile, &c_file) == 0) && (selectNum > n));

    printf("filename : %s\n", fl->filename);

    //���� ��� ����
    strcpy(fl->path, dat_folder_name);
    strcat(fl->path, fl->filename);
    printf("path : %s\n", fl->path);

    _findclose(hFile);
    return;
}

//������ .dat ���� �˻�
void fileCheck(file *fl) {
    char check[100] = "\0";
    int col = 0, row = 0;
    
    //���� �̸����� ��, �� ����
    sscanf(fl->filename, "%10s%d-%d", check, &col, &row);
    printf("name check : [%s] [%d] [%d]\n", check, col, row);

    //���� �̸� �˻�
    if (strcmp(check, dat_file_name) != 0 || col < 1 || row < 1) {
        printf("Error : Problem reading in rows and columns\n");
        exit(0);
    }

    fl->col = col;
    fl->row = row;
    printf("row : %d\n", fl->row);
    printf("col : %d\n", fl->col);

    int size = col * row; //���� �̸��� ���ǵ� ���� �� ����

    char numCheck[10] = "\0";
    double num;
    int num_count = 0; //���� �� ����

    FILE* fp;
	fp = fopen(fl->path, "r");

    //���� read �˻�
	if (fp == NULL){
        printf("Error : Unable to open file <%s>\n", fl->filename);
        exit(0);
	}

    //���� �� �˻�
    //������ ���� ���� ������ ����
    while (fscanf(fp, "%s", &numCheck) != EOF) {
        //printf("%s ", numCheck);
        
        //�������� �ִ��� �˻�
        if (sscanf(numCheck, "%lf", &num) != 1) {
            printf("\nError : Read a non-integer value .");
            exit(0);
        }

        //������ �ƴ� �������� �ִ��� �˻�
        else if ((num - (int)num) != 0.0) {
            printf("\nError : Read a non-integer value .");
            exit(0);
        }
        num_count++;
    }

    fclose(fp);

    printf("\n");
    printf("size : %d count : %d\n", size, num_count);

    //���� �̸��� ���ǵ� �� ������ ���� ������ �� ������ �´��� �˻�
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

//.dat ���� ���� ����
void elevationArray(elevation* elev, file fl) {
    int** array;

    //fp = fopen("map-inputs\\map-input-844-480.dat", "r");//�ӽ�
    fp = fopen(fl.path, "r");

    //2���� ���� �迭 ����
    array = (int**)malloc(sizeof(int*) * fl.row);
    for (int i = 0; i < fl.row; i++) {
        array[i] = (int*)malloc(sizeof(int) * fl.col);
    }

    //���Ͽ��� �ҷ��� ������ ��, ���� ���� �޸𸮿� ����
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