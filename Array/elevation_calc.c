#include "func.h"

//고도값 최대최소
void findMaxMin(elevation* elev, file fl) {
    elev->max = elev->array[0][0];
    elev->min = elev->array[0][0];

    for (int i = 0; i < fl.row; i++) {
        for (int j = 0; j < fl.col; j++) {
            if (elev->max < elev->array[i][j]) {
                elev->max = elev->array[i][j];
            }
            else if (elev->min > elev->array[i][j]) {
                elev->min = elev->array[i][j];
            }
        }
    }
    printf("max : %d\n", elev->max);
    printf("min : %d\n", elev->min);

    return;
}