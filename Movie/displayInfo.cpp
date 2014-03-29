/*
 * displayInfo.cpp
 *
 *  Created on: Sep 17, 2012
 *      Author: lc1440
 */
void displayInfo(database movieInventory[], int SKU)
{
cout << "SKU: " << movieInventory[SKU].SKU << endl
     << "Quantity: " << movieInventory[SKU].quantity << endl
     << "Price: " << movieInventory[SKU].price << endl
     << "Title: " << movieInventory[SKU].title << endl << endl;
}


