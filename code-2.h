#pragma once
#include <iostream>
#include <string>

using namespace std;

struct items
{
	string name;
	string vurobnuk;
	int price;
	string item_group;
	string data;
	string termin;
};

struct sklad
{
	int item_num = 0;
	items* item = new items[item_num];

	void add_item()
	{
		int new_num = item_num + 1;
		items* tmp = new items[new_num];

		for (size_t i = 0; i < new_num; i++)
		{
			if (i != (new_num - 1))
			{
				tmp[i] = item[i];
			}

			else 
			{
				cin.ignore(256, '\n');
				cout << "Name: ";
				getline(cin, tmp[i].name);
				cout << "Price: ";
				cin >> tmp[i].price;
				cin.ignore(256, '\n');
				cout << "vurobnuk: ";
				getline(cin, tmp[i].vurobnuk);
				cout << "item_group: ";
				getline(cin, tmp[i].item_group);
				cout << "data: ";
				getline(cin, tmp[i].data);
				cout << "termin: ";
				getline(cin, tmp[i].termin);
			}
		}

		delete[]item;
		item = tmp;
		item_num = new_num;
	}

	void fil_item(int& i)
	{
		cin.ignore(256, '\n');
		cout << "Name: ";
		getline(cin, item[i].name);
		cout << "Price: ";
		cin >> item[i].price;
		cin.ignore(256, '\n');
		cout << "vurobnuk: ";
		getline(cin, item[i].vurobnuk);
		cout << "item_group: ";
		getline(cin, item[i].item_group);
		cout << "data: ";
		getline(cin, item[i].data);
		cout << "termin: ";
		getline(cin, item[i].termin);
	}

	void show_item(int& i)
	{
		cout << "\n-------------------------";
		cout << "\n" << i + 1 << " ITEM";
		cout << "\nName: " << item[i].name;
		cout << "\nVurobnuk: " << item[i].vurobnuk;
		cout << "\nPrice: " << item[i].price;
		cout << "\nitem_group: " << item[i].item_group;
		cout << "\ndata: " << item[i].data;
		cout << "\ntermin: " << item[i].termin;
		cout << "\n-------------------------\n";
	}

	void show_item()
	{
		for (int i = 0; i < item_num; i++)
		{
			cout << "\n-------------------------";
			cout << "\n" << i + 1 << " ITEM";
			cout << "\nName: " << item[i].name;
			cout << "\nVurobnuk: " << item[i].vurobnuk;
			cout << "\nPrice: " << item[i].price;
			cout << "\nitem_group: " << item[i].item_group;
			cout << "\ndata: " << item[i].data;
			cout << "\ntermin: " << item[i].termin;
			cout << "\n-------------------------\n";
		}
	}

	void sort_by()
	{
		for (int i = 0; i < item_num - 1; i++)
		{
			int minIndex = i;


			for (int j = i + 1; j < item_num; j++)
			{
				if (item[j].price < item[minIndex].price)
				{
					minIndex = j;
				}
			}


			swap(item[i], item[minIndex]);
		}
	}

	void edit_data()
	{
		string name;
		cin.ignore(1, '\n');
		cout << "\nEnter the item's name you want to change: ";
		getline(cin, name);

		int i = 0;

		if (name == item[i].name && i < item_num)
		{
			fil_item(i);
		}
		else if (name != item[i].name && i < item_num)
		{
			i++;
		}
		else
		{
			cout << "\nWe don't have such item in our data :(";
		}

	}

	void delete_item()
	{
		cout << "\nEnter item's name you want to delete: ";
		string name;
		cin.ignore(256, '\n');
		getline(cin, name);

		int index;//правильний індекс(тобто,якщо наше ім'я було знайдене успішно)

		for (int i = 0; i < item_num; i++)
		{
			if (name == item[i].name)
			{
				index = i;
				break;
			}

		}

		if (index + 1 == item_num)
		{

		}

		else if (index + 1 != item_num)
		{
			for (index; index < item_num; index++)
			{
				if (index + 1 >= item_num)
				{

				}
				else {
					swap(item[index], item[index + 1]);
				}
			}
		}

		int new_num = item_num - 1;
		items* tmp = new items[new_num];
		for (int i = 0; i < new_num; i++)
		{
			tmp[i] = item[i];
		}

		delete[]item;
		item = tmp;
		item_num = new_num;
		cout << "\nThe item was deleted SUCCESSFULLY";

	}

	void search_by()
	{
		int choiser;
		cout << "\nEnter 1 to search by the price\nEnter 2 to search by the name\n";
		cin >> choiser;
		if (choiser == 1)
		{
			int e_price;// enter price (ціна, яку вводимо)
			cout << "\nEnter item's price: ";
			cin >> e_price;

			for (int i = 0; i < item_num; i++)
			{
				if (e_price == item[i].price)
				{
					show_item(i);
				}

			}

		}
		else if (choiser == 2)
		{
			string name;
			cout << "\nEnter person's name: ";
			cin.ignore(256, '\n');
			getline(cin, name);

			for (int i = 0; i < item_num; i++)
			{
				if (name == item[i].name)
				{
					show_item(i);
				}
			}
		}
	}
	void clearing()
	{
		delete[]item;
	}
};
