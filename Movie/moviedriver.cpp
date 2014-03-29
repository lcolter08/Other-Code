// File Name: MovieDriver.cpp
// 
// Author: Jill Seaman
// Date: 10/28/2012
// Assignment Number: 5
// CS 2308 Fall 2012
// Instructor: Jill Seaman 
// 
// A demo driver for Movie Inventory classes.
//
//   You will want to do more complete testing than this.

#include<iostream>
#include<iomanip>
using namespace std;

#include "MovieInventory.h"

int main()
{
    MovieInventory mi;
    
    Movie movie1(5678, 2, 1.25, "Gone With the Wind");
    Movie movie2(8856, 3, 2.50, "Bull Durham");
    Movie movie3(6672, 1, 1.35, "Miracle on Ice");
    Movie movie4(6672, 1, 1.35, "Miracle on Ice");
    Movie movie5(6672, 2, .50, "Alien");

    bool result = mi.addMovie(movie1);
    cout << "add result = " << result << endl;
    
    mi.showInventory();
          
    result = mi.addMovie(movie2);
    cout << "add result = " << result << endl;
    
    mi.showInventory();
       
    result = mi.addMovie(movie3);
    cout << "add result = " << result << endl;
       
    result = mi.addMovie(movie4);
    cout << "add result = " << result << endl;
       
    result = mi.addMovie(movie5);
    cout << "add result = " << result << endl;
    
    mi.showInventory();
    
    int delResult;
    delResult = mi.removeMovie(movie2);
    cout << "delete result = " << delResult << endl;
  
    delResult = mi.removeMovie(movie3);
    cout << "delete result = " << delResult << endl;

    mi.showInventory();
    cout << "total quantity (should be 4) = " << mi.getTotalQuantity() << endl;
    cout << "total price (should be 3.50) = " << mi.getTotalPrice() << endl;

    delResult = mi.removeMovie(movie1);
    cout << "delete result = " << delResult << endl;
 
    delResult = mi.removeMovie(movie5);
    cout << "delete result = " << delResult << endl;
    
    delResult = mi.removeMovie(movie4);
    cout << "delete result = " << delResult << endl;
    
    mi.showInventory();
    
    result = mi.addMovie(movie5);
    cout << "add result = " << result << endl;
    
    mi.showInventory();
    
    return EXIT_SUCCESS;
}
