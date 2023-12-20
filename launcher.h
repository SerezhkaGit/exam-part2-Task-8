#pragma once
#include "code-2.h"
void launcher()
{

	sklad k;
	int choiser = 0;

	while (choiser != 8)
	{
		cout << "\nEnter 1 to add item\nEnter 2 to show item(items)\nEnter 3 to sort items\nEnter 4 to change item's data\nEnter 5 to delete item\nEnter 6 to search item/'s\nEnter 7 to leave";
		cout << "\nEnter the num: ";
		cin >> choiser;
		cout << endl;

		switch (choiser)
		{
		case 1:
		{
			k.add_item();
			break;

		}
		case 2:
		{
			k.show_item();
			break;

		}
		case 3:
		{
			k.sort_by();
			break;

		}
		case 4:
		{
			k.edit_data();
			break;
		}
		case 5:
		{
			k.delete_item();
			break;
		}
		case 6:
		{
			k.search_by();
			break;
		}
		case 7:
		{
			k.clearing();
			choiser = 8;
		}

		default:
			break;
		}
	}
}