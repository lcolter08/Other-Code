/*
 * displayAll.cpp
 *
 *  Created on: Sep 19, 2012
 *      Author: lc1440
 */

void displayAll (int count, database movieInventory[])
{
for (int i = 0; i < count; i++)
	{
	cout << "SKU: " << movieInventory[i].SKU << endl
		 << "Quantity: " << movieInventory[i].quantity << endl
		 << "Price: " << movieInventory[i].price << endl
		 << " Title: " << movieInventory[i].title << endl << endl;
	}
}

