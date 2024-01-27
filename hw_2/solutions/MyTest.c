#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


// initialize argument tracker function

/*!
* return the sum of argument over execution time.
*/

int running_total(int x);


/*!
* reverse an input array and reutns as a pointer to the array.
*/
int * reverse(int arr[], int len); 


/*!
* reverse an input array in place.
*/
void reverse_in_place(int arr[], int len);


/*!
* Returns the count of as specefic instance. 
*/
int num_occurences(int arr[], int len, int val);



int main(){    

    /**  TESTBENCH FOR RunningTotal
    int arg;
    
    arg = RunningTotal(4);

    printf("run 1:%d\n",arg);

    arg = RunningTotal(2);

    printf("run 2:%d\n",arg);

    arg = RunningTotal(-3);

    printf("run 3:%d\n",arg);
    */

   
   int testarr[] = {1,23,4,5,6};
   int * y = reverse(testarr,5);


    printf("Test bench Real array:  %d\n",testarr[1]); 

    printf("Test bench Reverse array :  %d\n",y[1]); 

    


   /**
   int numarray[] = {1,1,1,1,1,1,1,23,4,5,6};

   int x = NumInstances(numarray,11,1);

   printf("%d",x);
    **/





    return 0;
}

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
