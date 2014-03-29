// File Name: MovieInventory.cpp
//
// Author: Lamont Colter
// Date: 10/28/2012
// Assignment Number: 5
// CS 2308 Fall 2012
// Instructor: Jill Seaman
//
// movieInventory class

#include<iostream>
#include<string>
#include"movie.h"
using namespace std;

class MovieInventory
{

private:
	int count; // index for array
	Movie inventArr[100]; // array of type movie that houses the database

public:
	  MovieInventory ();
      bool addMovie(Movie entry);
      int removeMovie(Movie entry);
      void showInventory();
      void sortInventory();
      int getTotalQuantity();
      double getTotalPrice();

};
