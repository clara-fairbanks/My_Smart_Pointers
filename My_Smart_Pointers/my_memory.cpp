/******************************************************************************
 Title : my_memory.cpp
 Author : Clara Fairbanks
 Created on : Sept. 13, 2018
 Description : A simple implementation of smart pointers
 Purpose : Implement Smart Pointers in order to better understand the function and functioning of pointers in cpp
 ******************************************************************************/

#include "my_memory.hpp"

/* ----------------- Unique PTR ------------------ */

/* Default constructor  */
template <class T>
my_unique_ptr<T>::my_unique_ptr():ptr( nullptr ){ };


/* Constructor that accepts a pointer Type T */
template <class T>
my_unique_ptr<T>::my_unique_ptr( T *rhs ){
    
    ptr = rhs;
};

/* Move constructor */
template <class T>
my_unique_ptr<T>::my_unique_ptr( my_unique_ptr<T> &&rhs ){
    
    swap( ptr, rhs.ptr );
};

/* Destructor */
template <class T>
my_unique_ptr<T>::~my_unique_ptr(){
    
    if( ptr )
        delete( ptr );
};

/* Dereference operator  */
template <class T>
T& my_unique_ptr<T>::operator*(){
    
    return *ptr;
};

/* Operator -> */
template <class T>
T* my_unique_ptr<T>::operator->(){
    
    return ptr;
};

/* Move assignment operator. */
template <class T>
my_unique_ptr<T> & my_unique_ptr<T>::operator=( my_unique_ptr<T> &&rhs ){
    
    swap( ptr, rhs.ptr );
    return *this;
};


/* ----------------- Shared PTR ------------------ */

/*Default constructor  */
template <class T>
my_shared_ptr<T>::my_shared_ptr():ptr( nullptr ),countPtr( nullptr ){ };


/* Constructor accepts type T */
template <class T>
my_shared_ptr<T>::my_shared_ptr( T *rhs ):ptr( rhs ){
    
    countPtr = new int(1);
};

/* Copy constructor */
template <class T>
my_shared_ptr<T>::my_shared_ptr( my_shared_ptr<T> &rhs ):ptr( rhs.ptr ){
    
    if( rhs.countPtr == nullptr ){
        std:: cout<<"Cannot copy an object with an uninitialized value. \n";
    } else {
        countPtr = rhs.countPtr;
        (*countPtr)++;
    }
}

/* Move constructor. */
template <class T>
my_shared_ptr<T>::my_shared_ptr( my_shared_ptr<T> &&rhs ):ptr( rhs.ptr ), countPtr( rhs.countPtr ){
    
    countPtr = rhs.countPtr;
};

/* Destructor */
template <class T>
my_shared_ptr<T>::~my_shared_ptr(){
    
    if( countPtr != nullptr )
        (*countPtr)--;
    
    if( countPtr == 0 ){
        if( ptr != nullptr )
            delete( ptr );
        delete( countPtr );
    }
};

/* Operator * that returns the object. */
template <class T>
T& my_shared_ptr<T>::operator*(){
    
    return *ptr;
};

/* Operator -> returns the pointer to the object. */
template <class T>
T* my_shared_ptr<T>::operator->(){
    
    return ptr;
};

/* Copy assignment operator  */
template <class T>
my_shared_ptr<T>& my_shared_ptr<T>::operator=( my_shared_ptr &rhs ){
    
    ptr = rhs.ptr;
    countPtr = rhs.countPtr;
    (*countPtr)++;
    
    return *this;
};

/* Move assignment operator */
template <class T>
my_shared_ptr<T>& my_shared_ptr<T>::operator=( my_shared_ptr<T> &&rhs ){
    
    countPtr = rhs.countPtr;
    std::swap( ptr, rhs.ptr );
    
    if( *rhs.countPtr > 0 ){
        ( *rhs.countPtr )--;
    }
    if( *rhs.countPtr == 0 ){
        delete rhs.ptr;
        delete rhs.countPtr;
    }
    (*countPtr)++;
    
    return *this;
};

