#include "solutions.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


// *****************************************Count instances  Function********************
int num_occurences(int arr[], int len, int val){


    int count = 0;
    int i = 0;

    while(i<len){


        if (val == arr[i])
        {
            count = count+1;
        }
        

        i = i+1;



    }


return count;




}



// *****************************************Reverse In Place Function********************
void reverse_in_place(int arr[], int len){

    int i =0 ;
    int  newarr[len];         

    while (i<len)
    {
        newarr[i] = arr[(len-1)-i]; // temporary array
        i=i+1;
    }

    i =0 ;

    while (i<len)
    {        

        arr[i] = newarr[i]; // temporary array
        i=i+1;
    }    
    
}






//*************************************** Reverse function*************************
int * reverse(int arr[], int len){


     int* pt = calloc(len, sizeof(int));    // allocate and zero out an array of len int

    int i = 0;

    while (i<len)
    {
        pt[i] = arr[(len-1)-i]; // temporary array

        i=i+1;
    }    
    return  pt ;
}






//***********************************Running Total Function****************************

int running_total(int x){

    static int arg=0;

    arg = arg+x;

    return arg;
}