#include "person.h"

//Place the implementation of the constructors here for the person.h
//Step 6a
 address::address()
 {  
       //Place your code here
 }

 
 address::address(const address & to_copy)
 {
       //Place the code to copy the argument into the data members
       //Avoid a shallow copy
 }

 name::name(const name & to_copy)
 {
       //Place the code to copy the argument into the data members
       //Avoid a shallow copy
 }

// Provide an initialization list for the name's constructor
// Syntax: after the header put a colon and a comma separated
// list of everything that needs to get initialized
 person::person(char * initial_name, char * street, char * zip)
 {


 }

// Step 6b
 person::person()  //already finished
 {  
       //This is the default person constructor. NO CODE is needed
       //Think about why this is all that is needed.
 }

// Step 6c
//Implement the wrapper function that you designed in the person class
//to allow the address to be changeed without using friends or public
//data members!
