#include <assert.h>
#include <iostream>
#include <stdexcept>
#include "..\hw4\typed_array.h"
#include "..\hw4\complex.h"


int main(){    

    TypedArray<int> x; // instantiate

    x.extend_buffer();


    x.print_origin();
    /*
    x.set(0,3);
    x.set(1,4);
    x.set(2,5);
    x.set(3,6);
    */
    /* *************************************push pop test**********************
    x.push_front(4);
    std::cout<<x.get(0)<<"\n"<<std::endl;    
    x.push_front(3);
    std::cout<<x.get(0)<<"\n"<<std::endl;
    x.push_front(2);
    std::cout<<x.get(0)<<"\n"<<std::endl;
    x.push_front(1);
    std::cout<<x.get(0)<<"\n"<<std::endl;
    */

    /*
    x.print_capacity();
    x.print_origin();
    x.print_end();
    int val = x.size();

    std::cout<<val<<std::endl;
    */

   /* *************************************CONCAT TEST*****************
   TypedArray<int> b = x.concat(x);
   std::cout<<b.get(0)<<"\n"<<std::endl; 
   std::cout<<x.get(0)<<"\n"<<std::endl;
   */

    //x.reverse();
    //std::cout<<x.get(0)<<"\n"<<std::endl; 


    /*
    TypedArray<int> b = x+x;

    for(int i=0; i<b.size();i++){

        std::cout<<b.get(i)<<"\n"<<std::endl; 

    }
    */

    //const 

  


    return 0;
}