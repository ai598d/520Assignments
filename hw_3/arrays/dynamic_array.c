//!  A Dynamic Array Class. 
/*!
  A more elaborate class description.
*/
#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int NumArrays = 0; // global variable to keep track of number of Dynamic arrays created

double* ptr;
/*! \fn int main(void)
* param void
* \return EXIT_SICCESS
*/

int main(){

    DynamicArray * da = DynamicArray_new();
    DynamicArray_push(da,4);
    DynamicArray_push(da,3);
    DynamicArray_push(da,5);
    DynamicArray_push(da,0.1);
    DynamicArray_push(da,0.7);
    //DynamicArray_push(da,100);

    /*
    double x = DynamicArray_get(da,4);

    double y = DynamicArray_min(da); 
    
    double z = DynamicArray_max(da); 

    double avg = DynamicArray_mean(da);

    double mid = DynamicArray_median(da);

    DynamicArray * linspace = DynamicArray_range(0,1,.1); 

    double r1 =  DynamicArray_get(linspace ,10);

    DynamicArray * da_linsapce_con = DynamicArray_concat(linspace,da);

    double con = DynamicArray_get(da_linsapce_con,15);

    DynamicArray * n_arr = DynamicArray_take(da_linsapce_con,-2);

    double t = DynamicArray_get(n_arr,0);

    int numarray = DynamicArray_num_arrays();

    printf("%f\n",t);
    printf("%d\n",numarray);

    */

    printf("%d\n",ptr);
    printf("%d",&da->buffer);
    
    return 0;
}




/* private functions *********************************************************/

/* Position in the buffer of the array element at position index */
static int index_to_offset ( const DynamicArray * da, int index ) {
    return index + da->origin;
}

/* Position of the element at buffer position 'offset' */
static int offset_to_index ( const DynamicArray * da, int offset ) {
    return offset - da->origin;
}

/* Non-zero if and only if offset lies ouside the buffer */
static int out_of_buffer ( DynamicArray * da, int offset ) {
    return offset < 0 || offset >= da->capacity;
}

/* Makes a new buffer that is twice the size of the old buffer,
   copies the old information into the new buffer, and deletes
   the old buffer */
static void extend_buffer ( DynamicArray * da ) {

    double * temp = (double *) calloc ( 2 * da->capacity, sizeof(double) );
    int new_origin = da->capacity - (da->end - da->origin)/2,
           new_end = new_origin + (da->end - da->origin);

    for ( int i=0; i<DynamicArray_size(da); i++ ) {
        temp[new_origin+i] = DynamicArray_get(da,i);
    }

    free(da->buffer);
    da->buffer = temp;

    da->capacity = 2 * da->capacity;
    da->origin = new_origin;
    da->end = new_end;

    return;

}

/* public functions **********************************************************/

// This is constructor
DynamicArray * DynamicArray_new(void) {
    DynamicArray * da = (DynamicArray *) malloc(sizeof(DynamicArray));
    da->capacity = DYNAMIC_ARRAY_INITIAL_CAPACITY;    
    da->buffer = (double *) calloc ( da->capacity, sizeof(double) ); 
    da->origin = da->capacity / 2;
    da->end = da->origin;
    NumArrays=NumArrays+1;    // keeps the total number of DA
    ptr = da->buffer; 
    return da;
}

// Desctructor
void DynamicArray_destroy(DynamicArray * da) {
    free(da->buffer);
    da->buffer = NULL;
    return;
}

//Give size of array
int DynamicArray_size(const DynamicArray * da) {
    assert(da->buffer != NULL);
    return da->end - da->origin;
}

char * DynamicArray_to_string(const DynamicArray * da) {
    assert(da->buffer != NULL);
    char * str = (char *) calloc (20,DynamicArray_size(da)),
         temp[20];
    int j = 1;
    str[0] = '[';
    for ( int i=0; i < DynamicArray_size(da); i++ ) {
        if ( DynamicArray_get(da,i) == 0 ) {
            snprintf ( temp, 20, "0" );
        } else {
            snprintf ( temp, 20, "%.5lf", DynamicArray_get(da,i) ); 
        }
        if ( i < DynamicArray_size(da) - 1 ) {
            sprintf( str + j, "%s,", temp);
            j += strlen(temp) + 1;
        } else {
            sprintf( str + j, "%s", temp);
            j += strlen(temp);
        }

    }
    str[j] = ']';
    return str;
}

void DynamicArray_print_debug_info(const DynamicArray * da) {

    char * s = DynamicArray_to_string(da);
    printf ( "  %s\n", s);
    printf ( "  capacity: %d\n  origin: %d\n  end: %d\n  size: %d\n\n",
      da->capacity, 
      da->origin, 
      da->end,
      DynamicArray_size(da));

    free(s);

}

void DynamicArray_set(DynamicArray * da, int index, double value) {
    assert(da->buffer != NULL);
    assert ( index >= 0 );
    while ( out_of_buffer(da, index_to_offset(da, index) ) ) {
        extend_buffer(da);
    }
    da->buffer[index_to_offset(da, index)] = value;
    if ( index >= DynamicArray_size(da) ) {
        da->end = index_to_offset(da,index+1);
    }

}

double DynamicArray_get(const DynamicArray * da, int index) {
    assert(da->buffer != NULL);
    assert ( index >= 0 );
    if ( index >= DynamicArray_size(da) ) {
        return 0;
    } else {
        return da->buffer[index_to_offset(da,index)];
    }
}

void DynamicArray_push(DynamicArray * da, double value ) {
    DynamicArray_set(da, DynamicArray_size(da), value );
}

void DynamicArray_push_front(DynamicArray * da, double value) {
    assert(da->buffer != NULL);
    while ( da->origin == 0 ) {
        extend_buffer(da);
    }
    da->origin--;
    DynamicArray_set(da,0,value);
}

double DynamicArray_pop(DynamicArray * da) {
    assert(DynamicArray_size(da) > 0);
    double value = DynamicArray_get(da, DynamicArray_size(da)-1);
    DynamicArray_set(da, DynamicArray_size(da)-1, 0.0);
    da->end--;
    return value;
}

double DynamicArray_pop_front(DynamicArray * da) {
    assert(DynamicArray_size(da) > 0);
    double value = DynamicArray_get(da, 0);
    da->origin++;
    return value;    
}


// Total number of dynamic arrays created
int DynamicArray_num_arrays(){

    return NumArrays;

}

// Return minimum value

double DynamicArray_min ( const DynamicArray * da ){
    assert(da->buffer != NULL);

    
    double temp = DynamicArray_get(da, 0); // temporary buffer initialize with first value
    int size = DynamicArray_size(da);
    int indx = 0;
    while(indx<size){        

        if(temp>DynamicArray_get(da, indx)){

            temp = DynamicArray_get(da, indx); // compare and move if greater
        }

        indx=indx+1;

    }

    return temp;
}

// Return Max value

double DynamicArray_max ( const DynamicArray * da ){
    
    assert(da->buffer != NULL);

    
    double temp = DynamicArray_get(da, 0); // temporary buffer initialize with first value
    int size = DynamicArray_size(da);
    int indx = 0;
    while(indx<size){        

        if(temp<DynamicArray_get(da, indx)){

            temp = DynamicArray_get(da, indx); // compare and move if less
        }

        indx=indx+1;

    }

    return temp;


}

// return mean
double DynamicArray_mean ( const DynamicArray * da ){
    assert(da->buffer != NULL);

    int size = DynamicArray_size(da);
    double sum = DynamicArray_sum (da);
    

    return (sum/size);
}

// return median
double DynamicArray_median ( const DynamicArray * da ){
    assert(da->buffer != NULL);

    double min = DynamicArray_min(da);
    double max = DynamicArray_max(da);

    double median = (max+min)/2;
    

    return median;

}

// return sum
double DynamicArray_sum ( const DynamicArray * da ){
    //assert(da->buffer != NULL);

    double sum = 0; // temporary buffer initialize with first value
    int size = DynamicArray_size(da);
    int indx = 0;

    while(indx<size){

        sum = sum+DynamicArray_get(da, indx);

        indx=indx+1;
    }

    return sum;

}

double DynamicArray_first ( const DynamicArray * da ){
    assert(da->buffer != NULL);

    double first = DynamicArray_get(da,0);

    return first;

}


double DynamicArray_last ( const DynamicArray * da ){
    assert(da->buffer != NULL);

    int size = DynamicArray_size(da);

    double last = DynamicArray_get(da,size-1);

    return last;



}


DynamicArray * DynamicArray_copy ( const DynamicArray * da ){

    DynamicArray * result = DynamicArray_new();

    int size = DynamicArray_size(da);

    int i = 0;

    while(i<size){

        DynamicArray_set(result,i,DynamicArray_get(da,i));

        i=i+1;


    }

    return result;
}

DynamicArray * DynamicArray_range ( double a, double b, double step){

    DynamicArray * result = DynamicArray_new();
    
    double datapt = a;

    int i = 0 ;

    while(i<=(b/step)){

        DynamicArray_set(result,i,datapt);

        datapt=datapt+step;

        i=i+1;
    }

    return result; 

}

DynamicArray * DynamicArray_concat ( const DynamicArray * a, const DynamicArray * b ){

double size_a = DynamicArray_size(a);
double size_b = DynamicArray_size(b);

DynamicArray * result = DynamicArray_new();

int i = 0;
int j = 0;
while(i<(size_a+size_b)){

    if(i<size_a){

        DynamicArray_set(result,i,DynamicArray_get(a,i));

    }

    else{

        DynamicArray_set(result,i,DynamicArray_get(b,j));
        j=j+1;
    }


    i=i+1;




}

return result ;
}


DynamicArray * DynamicArray_take(DynamicArray * da, int n){

    int size = DynamicArray_size(da);

    DynamicArray * result = DynamicArray_new();

    if(n<0){

        int i = size-1;
        int j =0 ;

        n=n*(-1);

        while(i>(size-n)-1){

            DynamicArray_set(result, j, DynamicArray_get(da,i));

            i=i-1;
            j=j+1;


        }
    }

    else{


        int k =0 ;

        while(k<n){

            DynamicArray_set(result, k, DynamicArray_get(da,k));

            k=k+1;


        }

    }


    return result;
}





DynamicArray * DynamicArray_map(const DynamicArray * da, double (*f) (double)) {
    assert(da->buffer != NULL);
    DynamicArray * result = DynamicArray_new();
    for ( int i=0; i<DynamicArray_size(da); i++ ) {
        DynamicArray_set(result, i, f(DynamicArray_get(da, i)));
    }
    return result;
}

DynamicArray * DynamicArray_subarray(DynamicArray * da, int a, int b) {

  assert(da->buffer != NULL);
  assert(b >= a);

  DynamicArray * result = DynamicArray_new();

  for (int i=a; i<b; i++) {
      DynamicArray_push(result,DynamicArray_get(da, i));
  }

  return result;

}