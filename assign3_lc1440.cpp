/*
 *File Name: assign3_lc1440.cpp
 *
 *Author: Lamont Colter
 *Date: 10/1/2012
 *Assignment number: 3
 *CS 2308.003 Fall 2012
 *Instructor: Jill Seaman
 *
 *Some different functions designed to show different used of pointers
 * when programming with C++
 */


#include <iostream>

using namespace std;

const int SIZE = 10; // initial size of arrayOne
const int SIZE2 = 10; // initial size of arrayTwo

int minimum ( int SIZE, int arrayOne[]);
int swapTimesTen (int *xptr, int *yptr);
int *expand ( int arrayOne[], int SIZE);
int *concatenate(int arrayOne[], int arrayTwo[], int SIZE, int SIZE2);

int main()
{
	// generic arrays used within the different functions
	int arrayOne[SIZE] = {15, 2, 3, 4, 5, 6, 7, 8, 9, 1};
	int arrayTwo[SIZE] = {12, 25, 96, 7, 854, 23, 4, 5, 38, 7};
	int *ptr3; // pointer to hold value returned from expand function
	int *ptr4; // pointer to hold the value returned from concatenate

	cout << "testing minimum:" << endl
		 << "expected minimum: 1" << endl
		 << "actual minimum: " << minimum(SIZE, arrayOne) << endl << endl;

	cout << "testing minimum:" << endl
		 << "expected minimum: 4" << endl
		 << "actual minimum: " << minimum(SIZE, arrayTwo) << endl << endl;

	int x = 2,
		y = 3; // random variables with values given for swapTimesTen

	int *xptr = &x,
		*yptr = &y; // pointers to the variables used in swapTimesTen

	swapTimesTen (xptr, yptr);
	cout << "testing swapTimesTen:" << endl
		 << "expected result: 50  x = 20  y = 30" << endl
		 << "actual result: " << x + y << " x= "
		 << x << " y= " << y << endl << endl;


	cout << "testing expand: " << endl
		 << "expected result: 15 2 3 4 5 6 7 8 9 1 0 0 0 0 0 0 0 0 0 0" << endl
		 << "actual result: ";

	ptr3 = expand(arrayOne, SIZE);

	for (int index = 0; index < (SIZE * 2); index++)
	{
		cout << *(ptr3 + index) << " ";
	}

	ptr4 = concatenate(arrayOne, arrayTwo, SIZE, SIZE2);

	cout << endl << endl << "testing concatenate: " << endl
		 << "expected result: 15 2 3 4 5 6 7 8 9 1 12 25 96 7 854 "
		 << "23 4 5 38 7" << endl
		 << "actual result: ";

	for (int index = 0; index < (SIZE + SIZE2); index++)
		{
			cout << *(ptr4 + index) << " ";
		}


	return 0;
}

/*
 * minimum: takes an int array and returns the minimum value contained in the
 * array.
 *
 * SIZE: Size of initial arrays in program
 * arrayOne: generic array used within the different functions
 * returns: the minimum value contained in the array passed in
 */

int minimum ( int SIZE, int arrayOne[])
{
	int minValue = *arrayOne;

	for(int i = 0; i < SIZE; i++)
		if ( *(arrayOne + i) < minValue )
			minValue = *(arrayOne + i);
	return minValue;
}

/*
 * swapTimesTen: takes x and y from main swaps their values between themselves
 * and multiplies both variables by 10
 *
 * xptr: pointer to the variables used in swapTimesTen
 * yptr: pointer to the variables used in swapTimesTen
 *
 * returns: xptr + yptr
 */

int swapTimesTen (int *xptr, int *yptr)
{
	int temp = *xptr;
	*xptr = *yptr * 10;
	*yptr = temp * 10;
	return *xptr + *yptr;
}
/*
 * expand: takes any array and creates a new array double its size, then
 * copies the old array into the new one.
 *
 * arrayOne: generic array used within the different functions
 * Size: Size of initial arrays in program
 * returns: a pointer the new array that was created
 */

int *expand ( int arrayOne[], int SIZE)
{
	int *exArray;
	exArray = new int[SIZE * 2];

	if (exArray == NULL)
	  {
	  		cout << "Error allocating memory." << endl;
	  		return NULL;
	  }
	  else
	  {
		  for (int i = 0; i < (SIZE * 2); i++)
			  exArray[i] = 0;

		  for (int i = 0; i < (SIZE); i++)
			  exArray[i] = arrayOne[i];
	  }

	delete [] exArray;
	return exArray;

}
/*
 * concatenate: takes two arrays and combines them together in a new array
 * sequentially
 *
 * arrayOne: generic array used within the different functions
 * arrayTwo: generic array used within the different functions
 * SIZE1: Size of initial arrays in program
 */

int *concatenate(int arrayOne[], int arrayTwo[], int SIZE, int SIZE2)
{
	int *dblArray;
	dblArray = new int [SIZE + SIZE2];


	  if (dblArray == NULL)
	  {
	  		cout << "Error allocating memory." << endl;
	  		return NULL;
	  }
	  else
	  {
		  for (int i = 0; i < SIZE; i++)
			  dblArray[i] = arrayOne[i];

		  for (int j = 10; j < (SIZE + SIZE2); j++)
			  dblArray[j] = arrayTwo[j - SIZE];
	  }

	delete [] dblArray;
	return dblArray;

}
