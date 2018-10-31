/******************************************************************************
 Title : main.cpp
 Author : Clara Fairbanks
 Created on : Sept. 13, 2018
 Description : Driver file for a simple implementation of smart pointers
 Purpose : Implement Smart Pointers in order to better understand the function and functioning of pointers in cpp.
 ******************************************************************************/

#include <iostream>
#include "my_memory.hpp"
#include "my_memory.cpp"


using unique = my_unique_ptr<std::string>;
using shared = my_shared_ptr<std::string>;

int main()
{
    //Unique PTR tests:
    
    //Base Constructor with T element test
    unique u1{ new std::string("some string of significant length\n") };
    //Move Constructor test
    unique u2{ std::move(u1) };
    //Base Constructor test
    unique u3;
    
    //Operator * test
    std::cout << *u2;
    
    //Move assignment operator test
    u3 = std::move(u2);
    
    std::cout << "the size of the string is " << u3->size() << std::endl;
    
    //Share PTR tests:
    
    shared s1{ new std::string("another string of significant length\n") };
    shared s2{ std::move(s1) };
    shared s3;
    shared s4{ s3 };
    std::cout << *s2;
    s3 = std::move(s2);
    std::cout << *s3;
    s4 = s3;
    std::cout << "the size of the string is " << s3->size() << std::endl;
    
    return 0;
}
