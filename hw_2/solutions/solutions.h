#ifndef SOLUTIONS_H
#define SOLUTIONS_H

/*! @file */

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


#endif