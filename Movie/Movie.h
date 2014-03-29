// File Name: Movie.h
//
// Author: Lamont Colter
// Date: 10/28/2012
// Assignment Number: 5
// CS 2308 Fall 2012
// Instructor: Jill Seaman
//
// Movie class

#include<iostream>
#include<string>
using namespace std;

class Movie
{
      private:
              int sku;
              int quantity;
              double price;
              string title;
      
      public:
              Movie();
              Movie(int Sku, int Quantity, double Price, string Title);

              void setSku(int SKU);
              int getSku();

              void setQuantity(int Quantity);
              int getQuantity();

              void setPrice(double Price);
              double getPrice();

              void setTitle(string Title);
              string getTitle();

              bool operator== (Movie &rhs);
              bool operator< (Movie &rhs);
};
             
             
