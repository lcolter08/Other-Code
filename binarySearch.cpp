int binarySearch( int SIZE, database movieInventory[])
{
	int first = 0,
		last = SIZE - 1,
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
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}

	}
	return position;
}


