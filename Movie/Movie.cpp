// File Name: Movie.cpp
//
// Author: Lamont Colter
// Date: 10/28/2012
// Assignment Number: 5
// CS 2308 Fall 2012
// Instructor: Jill Seaman
//
// functions for movie class

#include<iostream>
#include<string>
#include"Movie.h"
using namespace std;



Movie::Movie()
{
   sku = -1;
   quantity = 0;
   price = 0;
   title = "";
}
             
Movie::Movie(int Sku, int Quantity, double Price, string Title)
{
   sku = Sku;
   quantity = Quantity;
   price = Price;
   title = Title;
}

void Movie::setSku(int SKU)
{
	sku = SKU;
}

int Movie::getSku()
{
	return sku;
}

void Movie::setQuantity(int Quantity)
{
	quantity = Quantity;
}

int Movie::getQuantity()
{
	return quantity;
}

void Movie::setPrice(double Price)
{
	price = Price;
}

double Movie::getPrice()
{
	return price;
}

void Movie::setTitle(string Title)
{
	title = Title;
}

string Movie::getTitle()
{
	return title;
}

bool Movie::operator== (Movie &rhs)
{
	if(sku == rhs.getSku() && quantity == rhs.getQuantity() && price == rhs.getPrice() && title == rhs.getTitle())
		return true;
	else
		return false;


}

bool Movie::operator< (Movie &rhs)
{
	if(sku < rhs.getSku() || title < rhs.getTitle())
		return true;
	else
		return false;
}

