void addMovie( int count, database &movieInventory[])
{
	cout << "Enter SKU for Movie: ";
	cin >> movieInventory[count].SKU;

	cout << "Enter Number of movies on hand: ";
	cin >> movieInventory[count].quantity;

	cout << "Enter price of movie: ";
	cin >> movieInventory[count].price;

	cout << "Enter title of the movie: ";
	cin >> movieInventory[count].title;
}
