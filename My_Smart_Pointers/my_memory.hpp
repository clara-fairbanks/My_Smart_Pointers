/******************************************************************************
 Title : my_memory.h
 Author : Clara Fairbanks
 Created on : Sept. 13, 2018
 Description : Header file for a simple implementation of smart pointers
 Purpose : Implement Smart Pointers in order to better understand the function and functioning of pointers in cpp.
 ******************************************************************************/

#ifndef my_memory_hpp
#define my_memory_hpp
#include <stdio.h>
#include <iostream>

/* Unique PTR */
template <class T>
class my_unique_ptr{
private:
    T *ptr;
public:
    my_unique_ptr();
    my_unique_ptr( T *rhs );
    my_unique_ptr( my_unique_ptr &&rhs );
    ~my_unique_ptr();
    
    T & operator *();
    T * operator ->();
    
    my_unique_ptr & operator=( my_unique_ptr &&rhs );
    
    my_unique_ptr( const my_unique_ptr &rhs) = delete;
    my_unique_ptr & operator=( const my_unique_ptr &rhs ) = delete;
};

/* Shared PTR */
template <class T>
class my_shared_ptr {
private:
    T *ptr;
    int *countPtr;
public:
    my_shared_ptr();
    my_shared_ptr( my_shared_ptr &rhs );
    my_shared_ptr( T *rhs );
    my_shared_ptr( my_shared_ptr &&rhs );
    ~my_shared_ptr();
    
    T & operator *();
    T * operator ->();
    
    my_shared_ptr & operator=( my_shared_ptr &rhs );
    my_shared_ptr & operator=( my_shared_ptr &&rhs );
    
};
#endif
