// File Name: assign2_lc1440.cpp
//
// Author: Lamont Colter
// Date: 9/19/2012
// Assignment Number: 2
// CS 2308.003 Fall 2012
// Instructor: Jill Seaman
//
// A Program used to manage (add, delete, search, display) the video inventory
// of a store.


#include <iostream>
#include <string>

using namespace std;

const int SIZE = 10000; // maximum size of array
struct database // structure containing data for the movies
{
	int SKU;
	int quantity;
	double price;
	string title;
};

//***********************************************************
// <sortBySku>: Sorts array in ascending order based on Sku number
//              in each structure
//
// <SIZE> <Maximum size of array>
// <movieInventory[]> <Structure array containing the information
//                     for each video>
//***********************************************************

void sortBySku(int count, database movieInventory[])
{
	   bool swap;
	   int temp;
	   do {
	      swap = false;
	      for (int i = 0; i < (count-1); i++) {
	         if (movieInventory[i].SKU > movieInventory[i+1].SKU) {
	            temp = movieInventory[i].SKU;
	            movieInventory[i].SKU = movieInventory[i+1].SKU;
	            movieInventory[i+1].SKU = temp;
	            swap = true;
	         }
	      }
	   } while (swap);
}

//***********************************************************
// <addMovie>: <Prompts the user to add information about each movie>
//
// <count> <index to keep track of the # of movies entered and deleted
//          from array.>
// <movieInventory[]> <Structure array containing the information
//                     for each video>
//***********************************************************

int addMovie( int count, database movieInventory[])
{
	cout << "Enter SKU for Movie: ";
	cin >> movieInventory[count].SKU;

	cout << "Enter Number of movies on hand: ";
	cin >> movieInventory[count].quantity;

	cout << "Enter price of movie: ";
	cin >> movieInventory[count].price;

	cout << "Enter title of the movie: ";

	getline(cin, movieInventory[count].title);
	getline(cin, movieInventory[count].title);

	return count;
}

//***********************************************************
// <binarySearch>: <short description of what the function does.>
//
// <SIZE> <Maximum size of array>
// <movieInventory[]> <Structure array containing the information
//                     for each video>
// <SKU> <an integer entered by the user that the function compares
//        to when searching>
// <returns> <the position of the SKU number in the array>
//***********************************************************

int binarySearch( int count, database movieInventory[], int SKU)
{

	int first = 0,
		last = count - 1,
		middle,
		position = -1;
	bool found = false;
	while (first <= last && !found)
	{
		middle = (first + last) / 2;

		if (movieInventory[middle].SKU == SKU)
		{
			found = true;
			position = middle;
		}
		else if (movieInventory[middle].SKU > SKU)
			last = middle - 1;
		else
			first = middle + 1;

	}
	return position;
}

//***********************************************************
// <displayInfo>: <Displays the information for a specific
//                 movie given the SKU.>
//
// <movieInventory[]> <Structure array containing the information
//                     for each video>
// <SKU> <an integer entered by the user that the function compares
//        to when searching>
//***********************************************************

void displayInfo(database movieInventory[], int position)
{
cout << "SKU: " << movieInventory[position].SKU << endl
     << "Quantity: " << movieInventory[position].quantity << endl
     << "Price: " << movieInventory[position].price << endl
     << "Title: " << movieInventory[position].title << endl << endl;
}

//***********************************************************
// <displayAll>: <Displays all items in the array in ascending order.>
//
// <count> <index to keep track of the # of movies entered and deleted
//          from array.>
// <movieInventory[]> <Structure array containing the information
//                     for each video>
//***********************************************************

void displayAll (int count, database movieInventory[])
{
for (int i = 0; i < count; i++)
	{
	cout << "SKU: " << movieInventory[i].SKU << endl
		 << "Quantity: " << movieInventory[i].quantity << endl
		 << "Price: " << movieInventory[i].price << endl
		 << "Title: " << movieInventory[i].title << endl << endl;
	}
}

int main ()
{

	database movieInventory[SIZE] = {0};
	int number = 0; // SKU searched for within the program
	int count = 0; // index to keep track of the # of movies entered and deleted
	               // from array.
	int menuChoice; // number of the menu option the user chooses
	int position;

	do
	{
	cout << "Please enter the number of the option you want to select :" << endl
		 << "1. Add a movie to the inventory" << endl
		 << "2. Remove a movie from the inventory" << endl
		 << "3. Display the information for a movie" << endl
		 << "4. Display the inventory sorted by SKU" << endl
		 << "5. Quit" << endl << endl;
	cin >> menuChoice;

	switch (menuChoice)
	{
	case 1:

		addMovie( count, movieInventory);
		count++;
		break;

	case 2:

		cout << "Enter SKU of movie you wanted to delete from inventory: ";
		cin >> number;
		sortBySku(count, movieInventory);
		position = binarySearch( count, movieInventory, number);
		if (position == -1)
			cout << "Movie not in Database" << endl << endl;
		else
		{
		movieInventory[position] = movieInventory[count - 1];
		count--;
		cout << "SKU " << number << " DELETED." << endl << endl;
		}
		break;

	case 3:

		cout << "Enter SKU of movie you wanted to display: ";
		cin >> number;

		sortBySku(count, movieInventory);
		position = binarySearch( count, movieInventory, number);

		if (position == -1)
			cout << "Movie not in Database" << endl << endl;
		else
			displayInfo(movieInventory, position);

		break;

	case 4:

		sortBySku(count, movieInventory);

		displayAll (count, movieInventory);

		break;

	case 5:

		cout << "Exiting Application!" << endl << endl;

		return 0;
	}
	}while(menuChoice <= 4);
}

