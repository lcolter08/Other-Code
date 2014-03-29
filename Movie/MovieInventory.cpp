// File Name: MovieInventory.cpp
//
// Author: Lamont Colter
// Date: 10/28/2012
// Assignment Number: 5
// CS 2308 Fall 2012
// Instructor: Jill Seaman
//
// functions for movieInventory class

#include<iostream>
#include<string>
#include<iomanip>
#include"MovieInventory.h"
using namespace std;

MovieInventory::MovieInventory()
{
	count = 0;
}
/*
 * addMovie: adds a movie to the inventory
 *
 * Movie entry: Movie passed in
 * returns true or false
 */

bool MovieInventory::addMovie(Movie entry)
{
	bool flag = false;

	if(count < 100)
	{
		inventArr[count] = entry;
		count++;
		flag = true;
	}
	else
		cout << "Database is full. Please remove Movies and try again." << endl;

	return flag;
}

/*
 * removeMovie: removes movie a movie from the inventory
 *
 * Movie entry: Movie passed in
 * returns the number of movies removed.
 */

int MovieInventory::removeMovie(Movie entry)
{
	int removed = 0;

	for(int i = 0; i < (count); i++)
	{
		if(entry.getSku() == inventArr[i].getSku() &&
		   entry.getQuantity() == inventArr[i].getQuantity() &&
		   entry.getPrice() == inventArr[i].getPrice() &&
		   entry.getTitle() == inventArr[i].getTitle())
		{
			inventArr[i] = inventArr[count];
			count--;
			removed++;
		}
	}

	return removed;
}

/*
 * showInventory: displays the entire inventory
 */

void MovieInventory::showInventory()
{
	for(int i = 0; i < (count); i++)
		cout << "sku: " << inventArr[i].getSku() << " quantity: "
		     << inventArr[i].getQuantity() << " price : " << setprecision(2)
		     << inventArr[i].getPrice() << " title : " << inventArr[i].getTitle() << endl;
}

/*
 * sortInventory: sorts the inventory by sku, then by title if skus are equal
 */

void MovieInventory::sortInventory()
{
	Movie temp;
	for(int i = 0; i < (count); i++)
		for(int j = 0; j < (count); j++)
		{
			if(inventArr[j+1].getSku() == inventArr[j].getSku())
				if(inventArr[j+1].getTitle() == inventArr[j].getTitle())
			{
				temp = inventArr[j];
				inventArr[j] = inventArr[j+1];
				inventArr[j+1] = temp;
			}
			else if(inventArr[j+1].getSku() < inventArr[j].getSku())
			{
				temp = inventArr[j];
				inventArr[j] = inventArr[j+1];
				inventArr[j+1] = temp;
			}
		}


}

/*
 * getTotalQuantity: adds all the quantities of the movies in the inventory
 *
 * returns the total quantity
 */

int MovieInventory::getTotalQuantity()
{
	int total = 0;

	for(int i = 0; i < (count); i++)
		total = total + inventArr[i].getQuantity();


	return total;
}

/*
 * getTotalPrice: multiplies quantity by price for each movie and sums them up
 *
 * returns the total price
 */

double MovieInventory::getTotalPrice()
{
	double total = 0;

	for(int i = 0; i < (count); i++)
		total = total + (inventArr[i].getQuantity() * inventArr[i].getPrice());

	return total;
}

