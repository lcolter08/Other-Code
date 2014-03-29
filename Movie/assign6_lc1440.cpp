// File Name: movieinventory.cpp
//
// Author: Lamont Colter
// Date: 11/25/2012
// Assignment Number: 6
// CS 2308.001 and 003 Fall 2012
// Instructor: Jill Seaman


#include <iostream>
#include <iomanip>
using namespace std;

#include "MovieInventory.h"



//***********************************************************
// MovieInventory: constructs an empty inventory
//***********************************************************
MovieInventory::MovieInventory() 
{
   movieList = NULL;
}

//***********************************************************
// addMovie: attempts to add a movie to the inventory
// movie: the movie to add
// returns true if the the movie was added.
//***********************************************************
bool MovieInventory::addMovie(Movie movie) 
{
   MovieNode *newNode;  // To point to a new node
   MovieNode *nodePtr;  // To move through the list
   
   // Allocate a new node and store movie there
   newNode = new MovieNode;
   newNode->m = movie;
   newNode->next = NULL;
   
   // If empty, make newNode the first node
   if (!movieList)
      movieList = newNode;
   else {
      // make nodePtr pt to head of list
      nodePtr = movieList;

      // traverse list to find last node
      while (nodePtr->next)
         nodePtr = nodePtr->next;

      // make last node point to newNode
      nodePtr->next = newNode;
   }
   return true;
}

//***********************************************************
// removeMovie: accepts a movie to remove from the inventory
//   Removes ALL matching entries for that movie (using == over Movies).
// movie: the movie to remove
// returns the number of entries removed by the function.
//***********************************************************
int MovieInventory::removeMovie(Movie remMovie) {
    
    bool found;       // true if removeOne did remove one
    int removed = 0;  // counter for how many were removed
    
    // keep trying to remove one, until there are no more
    found = removeOne(remMovie);
    while (found) {
        removed++;
        found = removeOne(remMovie);
    }
    
    return removed;
}

//***********************************************************
// removeOne: accepts a movie to remove from the inventory
//   Removes the FIRST matching entry for that movie (using == over Movies).
// movie: the movie to remove
// returns true if a movie was found and remoed
//***********************************************************

bool MovieInventory::removeOne (Movie movie)
{
    MovieNode *nodePtr = movieList;   // to traverse the list
    MovieNode *previousNode = NULL;   //trailing node (there's no prevNode yet)
    
    // traverse list, remove movie when found
    while (nodePtr) {
        if (nodePtr->m == movie) {
            // remove movie
            if (previousNode == NULL) // this means nodePtr points to first node
                movieList = nodePtr->next;
            else
                previousNode->next = nodePtr->next;
            delete nodePtr;
            return true;
        }
        //else: advance both pointers
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }
    return false;
    
}

//***********************************************************
// showInventory: displays the entire movie inventory to the screen
//***********************************************************

void MovieInventory::showInventory() 
{

	MovieNode *nodePtr;
	nodePtr = movieList;

	while(nodePtr)
	{
		cout << "SKU: " << nodePtr->m.getSku() << " quantity: "
			 << nodePtr->m.getQuantity()
			 << setprecision(2) << " price: " << nodePtr->m.getPrice()
			 << " Title : " << nodePtr->m.getTitle();

		nodePtr = nodePtr->next;
	}


}

//***********************************************************
// getTotalQuantity: calculates the total quantity of movies in the inventory
//					 to the screen
// returns the number of movies in the inventory
//***********************************************************

int MovieInventory:: getTotalQuantity()
{
   int total = 0;

   MovieNode *nodePtr;
   	nodePtr = movieList;

   	while(nodePtr)
   	{
   		total += nodePtr->m.getQuantity();

   		nodePtr = nodePtr->next;
   	}

   return total;
}

//***********************************************************
// getTotalPrice: calculates the total price of all movies in inventory
// returns the total price of all the movies in the inventory
//***********************************************************

float MovieInventory:: getTotalPrice()
{
   float total = 0;

   MovieNode *nodePtr;
   nodePtr = movieList;

   while(nodePtr)
   	   {
     	total = total + ((nodePtr->m.getQuantity()) * (nodePtr->m.getPrice()));

     	nodePtr = nodePtr->next;
       }

   return total;
}

//***********************************************************
// findMinimum: the minimum sku of the movies in the array
// returns the minimum movie.
//***********************************************************

Movie MovieInventory:: findMinimum() 
{
   Movie aMovie;

   MovieNode *nodePtr;
   nodePtr = movieList;

   aMovie = nodePtr->m;
   while(nodePtr)
   {
	   if(nodePtr->m < aMovie)
		   aMovie = nodePtr->m;
	   nodePtr->next;
   }

   return aMovie;
}


void MovieInventory::sortInventory()
{


}

