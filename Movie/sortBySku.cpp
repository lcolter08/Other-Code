
void sortBySku(database &movieInventory[])
{
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++)
			if (movieInventory[i].SKU > movieInventory[j].SKU)
			{
				int temp = 0;
				temp = movieInventory[i].SKU;
				movieInventory[i].SKU = movieInventory[j].SKU;
				movieInventory[j].SKU = temp;
			}
}

