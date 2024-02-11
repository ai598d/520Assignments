#ifndef TYPED_ARRAY
#define TYPED_ARRAY

#include <assert.h>
#include <iostream>
#include <stdexcept>

template <typename ElementType>

// just a regular class
class TypedArray {

public:

    TypedArray();
    TypedArray(const TypedArray& other);

    int show_indx_offset();

    // Copy constructor
    TypedArray& operator=(const TypedArray& other);

    // concat
    TypedArray& operator+(const TypedArray& other);

    // Destructor
    ~TypedArray();

    // Getters
    ElementType &get(int index);
    ElementType &safe_get(int index) const;
    int size() const;

    // Setters
    void set(int index, ElementType value);

    // Methods for HW4

    void push(ElementType value);
    ElementType pop();
    void push_front(ElementType value);
    ElementType pop_front();


    TypedArray concat( const TypedArray& other);
    TypedArray reverse();


   // *********MY PUBLIC METHODS
   int TestMethod(int &array); // Test


   
   // print private getters
    void print_capacity(){ // prints origin
        int x = get_capacity();
        std::cout<<x<<"\n"<<std::endl;
    }
   void print_origin(){ // prints origin
        int x = get_origin();
        std::cout<<x<<"\n"<<std::endl;
    }
    void print_end(){ // prints origin
        int x = get_end();
        std::cout<<x<<"\n"<<std::endl;
    }

private:

    int capacity,
        origin,
        end;

    ElementType * buffer;   

    const int INITIAL_CAPACITY = 10;

    int index_to_offset(int index) const;
    int offset_to_index(int offset) const;
    bool out_of_buffer(int offset) const;
    void extend_buffer(void);

    // Pivate var getters
    int get_capacity();
    int get_origin();
    int get_end();    

};

//******************************************** Class Defination Ends***********************************************





/*******************************************
*
*METHOD DEFINITIONS
*
*/

//************************************Constructor Method*************
template <typename ElementType>
TypedArray<ElementType>::TypedArray() {
    buffer = new ElementType[INITIAL_CAPACITY]();
    capacity = INITIAL_CAPACITY;    
    origin = capacity / 2;
    end = origin;    
}

// Copy constructor: i.e TypedArray b(a) where a is a TypedArray
template <typename ElementType>
TypedArray<ElementType>::TypedArray(const TypedArray& other) : TypedArray() {
    *this = other;
}

// Assignment operator: i.e TypedArray b = a 
template <typename ElementType>
TypedArray<ElementType>& TypedArray<ElementType>::operator=(const TypedArray<ElementType>& other) {
    if ( this != &other) {
        delete[] buffer; // don't forget this or you'll get a memory leak!
        buffer = new ElementType[other.capacity]();
        capacity = other.capacity;
        origin = other.origin;
        end = origin;
        for ( int i=0; i<other.size(); i++) {
            set(i,other.safe_get(i));
        }
    }
    return *this;
}

// concat
template <typename ElementType>
TypedArray<ElementType>& TypedArray<ElementType>:: operator+(const TypedArray& other){
    
    while(size()> (2*other.size()) ){
        extend_buffer();
    }
    end = other.end;
    for ( int i=size(); i<other.size(); i++) {
        set(i,other.safe_get(i));
        }

    return *this ;    


}

// Destructor
template <typename ElementType>
TypedArray<ElementType>::~TypedArray() {
    delete[] buffer;
}

// Getters
template <typename ElementType>
ElementType &TypedArray<ElementType>::get(int index) {
    if (index < 0) {
        throw std::range_error("Out of range index in array");
    }
    if ( index >= size() ) {
        ElementType x;
        set(index, x);
    } 
    return buffer[index_to_offset(index)];
}

// Getters
template <typename ElementType>
ElementType &TypedArray<ElementType>::safe_get(int index) const {
    if (index < 0 || index >= size() ) {
        throw std::range_error("Out of range index in array");
    }
    return buffer[index_to_offset(index)];
}

template <typename ElementType>
int TypedArray<ElementType>::size() const {
    return end - origin;
}

// Setters
template <typename ElementType>
void TypedArray<ElementType>::set(int index, ElementType value) {
    if (index < 0) {
        throw std::range_error("Negative index in array");
    }
    while ( out_of_buffer(index_to_offset(index) ) ) {
        extend_buffer();
    }
    buffer[index_to_offset(index)] = value; // Should call the copy constructor
                                            // of ElementType.
    if ( index >= size() ) {
        end = index_to_offset(index+1);
    }
}

template <typename ElementType>
std::ostream &operator<<(std::ostream &os, TypedArray<ElementType> &array)
{
    os << '[';
    for (int i=0; i<array.size(); i++ ) {
        os << array.get(i);
        if ( i < array.size() - 1 ) {
            os << ",";
        }
    }
    os << ']';
    return os;
}

template <typename ElementType>
void TypedArray<ElementType>::push (ElementType value ) {
    
    int indx = size();

    if(indx==capacity){
        extend_buffer();
    }

    set(indx,value);


}


template <typename ElementType>
void TypedArray<ElementType>::push_front (ElementType value ) {
    
    // get the size
    int buf_size = size();

    // extend the buuffer if out of capacity
    if(buf_size==capacity){
        extend_buffer();
    }

    // move the buffer elements to the right
    int i = buf_size+1;
    while(i>1){
        set(i,get(i-1));
        i=i-1;
    }

    // set the value at 0 position
    set(0,value);   

}

template <typename ElementType>
ElementType TypedArray<ElementType>::pop(){

    int indx = size();

    // get the last element
    ElementType last_val = get(indx);

    // end cursor shifted one step left
    end = end-1;

    return last_val;

}

template <typename ElementType>
ElementType TypedArray<ElementType>::pop_front(){

     // get the first element
    ElementType first_val = get(0);

    //shift all elements 1 step to the left
    
    
    int buf_size = size(); // get the size

    int i = 0;

    while(i<buf_size){
        
        set(i,get(i+1));
        i=i+1;

    }

    // end cursor shifted one step left
    end = end-1;    


    return first_val;


}

template <typename ElementType>
TypedArray<ElementType> TypedArray<ElementType>::concat( const TypedArray& other){

    TypedArray NewArray;

    

    int this_size = size();
    int other_size = other.size();

    while(NewArray.size()>(2*(this_size+other_size))){
        NewArray.extend_buffer();
    }

    int i = 0;
    int j = this_size;
    int k =0;

    while(i<this_size){

        NewArray.set(i,get(i));
        i=i+1;
    }

    while(j<(this_size+other_size)){

        NewArray.set(j,other.safe_get(k));

        j=j+1;
        k=k+1;

    }


    return NewArray; 

}

template <typename ElementType>
TypedArray<ElementType> TypedArray<ElementType>:: reverse(){

    TypedArray container;
    int cont_size = container.size();
    while(cont_size> size()*2){
        container.extend_buffer();
    }

    int i = 0;
    while(i<size()){
        container.set(i,get(size()-i));
        i=i+1;
    }

    int j = 0;
    while(j<size()){
        set(j,container.get(j));
        j=j+1;
    }

    return *this;


}



//**************************************************************PRIVATE METHODS STARTS************************************
// Private methods

template <typename ElementType>
int TypedArray<ElementType>::index_to_offset ( int index ) const {
    return index + origin;
}

/* Position of the element at buffer position 'offset' */
template <typename ElementType>
int TypedArray<ElementType>::offset_to_index ( int offset ) const  {
    return offset - origin;
}

/* Non-zero if and only if offset lies ouside the buffer */
template <typename ElementType>
bool TypedArray<ElementType>::out_of_buffer ( int offset ) const {
    return offset < 0 || offset >= capacity;
}

/* Makes a new buffer that is twice the size of the old buffer,
   copies the old information into the new buffer, and deletes
   the old buffer */
template <typename ElementType>
void TypedArray<ElementType>::extend_buffer() {

    auto temp = new ElementType[2 * capacity]();
    int new_origin = capacity - (end - origin)/2,
           new_end = new_origin + (end - origin);

    for ( int i=0; i<size(); i++ ) {
        temp[new_origin+i] = get(i);
    }

    delete[] buffer;
    buffer = temp;

    capacity = 2 * capacity;
    origin = new_origin;
    end = new_end;

    return;

}

// Private getters
template <typename ElementType>
int TypedArray<ElementType>::get_capacity(){

    return capacity;

}

template <typename ElementType>
int TypedArray<ElementType>::get_origin(){

    return origin;

}
template <typename ElementType>
int TypedArray<ElementType>::get_end(){

    return end;

}

template <typename ElementType>
int TypedArray<ElementType>::TestMethod(int &array){

    return array;


}
#endif