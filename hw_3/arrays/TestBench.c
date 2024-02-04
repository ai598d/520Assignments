#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



int main(){

    DynamicArray * da = DynamicArray_new();
    DynamicArray_push(da, 1);

    //DynamicArray_set(da, 0, 3);
    //DynamicArray_set(da, 3, 5);

    //double x = DynamicArray_get(da,0);

    double x = 2.1;

    printf("%f",x);

    return 0;
}