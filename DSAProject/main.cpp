#include <string>
#include <iostream>
#include "MultiMap.h"
#include "IteratorMultiMap.h"
#include "Test.h"
using namespace std;

void populate(MultiMap& mm)
{

	mm.add("F. Scott Fitzgerald","The Great Gatsby");
	mm.add("Margaret Atwood", "The Handmaid's Tale");
	mm.add("Daniel Keyes", "Flowers For Algernon");
	mm.add("Amy Harmon", "From Sand and Ash");
	mm.add("Jane Austen", "Emma");
	mm.add("Daniel Keyes", "The Minds of Billy Milligan");
	mm.add("Amy Harmon", "From Sand and Ash");
	mm.add("Jane Austen", "Persuasion");
	mm.add("Charlotte Bronte", "Jane Eyre");
	mm.add("Emily Bronte", "Wuthering Heights");
	mm.add("F. Scott Fitzgerald", "The Great Gatsby");
	mm.add("George Orwell", "1984");
	mm.add("George Orwell", "Animal Farm");
	mm.add("Anthony Doerr", "All the Light We Cannot See");
	mm.add("Kristin Hannah", "The Nightingale");
	mm.add("F. Scott Fitzgerald", "Tender Is the Night");
	mm.add("Harper Lee", "To Kill a Mockingbird");
	mm.add("Harper Lee", "Go Set a Watchman");
	mm.add("Jane Austen", "Pride and Prejudice");
	mm.add("Jane Austen", "Sense and Sensibility");
	mm.add("Kristin Hannah", "The Great Alone");
	mm.add("Kristin Hannah", "The Great Alone");
	mm.add("Kristin Hannah", "The Nightingale");
	mm.add("Anthony Doerr", "All the Light We Cannot See");
	mm.add("Kristin Hannah", "The Nightingale");
	mm.add("F. Scott Fitzgerald", "Tender Is the Night");
	mm.add("Amy Harmon", "From Sand and Ash");
	mm.add("Harper Lee", "To Kill a Mockingbird");
	mm.add("Harper Lee", "Go Set a Watchman");
	mm.add("Jane Austen", "Pride and Prejudice");

}

void tests()
{
	Test t{};
	t.addTest();
	t.removeTest();
	t.searchTest();
	t.sizeTest();
	t.isEmptyTest();
	t.createTest();
}

void printMenu()
{
	cout << endl;
	cout << "0. Exit" << endl;
	cout << "1. Add book" << endl;
	cout << "2. Delete book" << endl;
	cout << "3. Search books by author" << endl;
	cout << "4. Show all available books" << endl;
	cout << "5. Update value" << endl;
	cout << endl;
}


int main()
{
	tests();
	MultiMap mm{};
	populate(mm);

	while (true)
	{
		printMenu();
		int command;
		cout << "Give command  ";
		cin >> command;
		cin.ignore();

		if (command == 0)
			break;
		switch (command)
		{
		case 1:
		{
			string author, title;
			cout << "Please give author  ";
			getline(cin, author);
			cout << "Please give title  ";
			getline(cin, title);
			mm.add(author, title);

		}
			break;
		case 2:
		{
			string author, title;
			cout << "Please give author  ";
			getline(cin, author);
			cout << "Please give title  ";
			getline(cin, title);
			if (mm.remove(author, title) == true)
				cout << "The book was removed"<<endl;
			else
				cout << "The book did not exist"<<endl;
			
		}
			break;
		case 3:
		{
			string author;
			cout << "Please give author  ";
			getline(cin, author);
			vector <string> books;
			mm.search(author,books);
			cout << endl<<"The books written by "<<author<<" are" << endl;
			for (auto b : books)
			{
				cout << b << endl;
			}
			break;
		}
		case 4:
		{
			IteratorMultiMap imm = mm.iterator();
			try
			{
				while (imm.valid()) {
					Info b = imm.getCurrent();
					cout << b.key << " - " << b.value << endl;
					imm.next();
				}
			}
			catch (exception e)
			{
				cout << e.what();
			}
			break;
		}
		case 5:
		{
			string author, title, newTitle;
			cout << "Please give author  ";
			getline(cin, author);
			cout << "Please give title  ";
			getline(cin, title);
			cout << "Please give new title  ";
			getline(cin, newTitle);
			mm.update(author, title, newTitle);

		}
		}
	}

	return 0;
}
