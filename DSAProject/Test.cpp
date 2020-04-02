#include "Test.h"
#include "MultiMap.h"
#include <assert.h>

int hf(string s, int m)
{
	int pos = 0;
	for (int i = 0; i < s.length(); i++)
	{
		pos = pos + int(s[i]) * pow(31, s.length() - i - 1);

	}
	if (pos < 0) pos = -pos;
	return pos % m;
}



void Test::createTest()
{
	MultiMap mm{};
	Node* l[100];
	mm.getTable(l);
	for (int i = 0; i < mm.getCapacity(); i++)
		assert(l[i] == nullptr);

}

void Test::addTest()
{
		MultiMap mm{ };
		assert(mm.size() == 0);
		mm.add("F. Scott Fitzgerald", "The Great Gatsby");
		assert(mm.size() == 1);
		mm.add("Margaret Atwood", "The Handmaid's Tale");
		assert(mm.size() == 2);
		mm.add("Margaret Atwood", "The Handmaid's Tale");
		assert(mm.size() == 3);

		mm.add("Daniel Keyes", "Flowers For Algernon");
		mm.add("Amy Harmon", "From Sand and Ash");
		mm.add("Jane Austen", "Emma");
		mm.add("Daniel Keyes", "The Minds of Billy Milligan");
		mm.add("Amy Harmon", "From Sand and Ash");
		mm.add("Jane Austen", "Persuasion");
		mm.add("Charlotte Bronte", "Jane Eyre");
		assert(mm.size() == 10);
		mm.add("Daniel Keyes", "Flowers For Algernon");
		mm.add("Amy Harmon", "From Sand and Ash");
		mm.add("Jane Austen", "Emma");
		mm.add("Daniel Keyes", "The Minds of Billy Milligan");
		mm.add("Amy Harmon", "From Sand and Ash");
		mm.add("Jane Austen", "Persuasion");
		mm.add("Charlotte Bronte", "Jane Eyre");
		assert(mm.size() == 17);
	
}

void Test::removeTest()
{
	MultiMap mm{ };
	assert(mm.size() == 0);
	mm.add("F. Scott Fitzgerald", "The Great Gatsby");
	assert(mm.size() == 1);
	assert(mm.remove("F. Scott Fitzgerald", "The Great Gatsby")==true);
	assert(mm.size() == 0);
	assert(mm.remove("F. Scott Fitzgerald", "The Great Gatsby")==false);
	assert(mm.size() == 0);
	mm.add("Margaret Atwood", "The Handmaid's Tale");
	assert(mm.size() == 1);
	mm.add("Margaret Atwood", "The Handmaid's Tale");
	assert(mm.size() == 2);
	assert(mm.remove("F. Scott Fitzgerald", "The Great Gatsby")==false);
	assert(mm.size() == 2);
	assert(mm.remove("Margaret Atwood", "The Handmaid's Tale")==true);
	assert(mm.size() == 1);
	assert(mm.remove("Margaret Atwood", "The Handmaid's Tale")==true);
	assert(mm.size() == 0);

}

void Test::searchTest()
{

	MultiMap mm{ };
	assert(mm.size() == 0);
	mm.add("Daniel Keyes", "Flowers For Algernon");
	mm.add("Amy Harmon", "From Sand and Ash");
	mm.add("Jane Austen", "Emma");
	mm.add("Daniel Keyes", "The Minds of Billy Milligan");
	mm.add("Amy Harmon", "From Sand and Ash");
	mm.add("Jane Austen", "Persuasion");
	mm.add("Charlotte Bronte", "Jane Eyre");
	mm.add("Daniel Keyes", "Flowers For Algernon");
	mm.add("Amy Harmon", "From Sand and Ash");
	mm.add("Jane Austen", "Emma");
	mm.add("Daniel Keyes", "The Minds of Billy Milligan");
	mm.add("Amy Harmon", "From Sand and Ash");
	mm.add("Jane Austen", "Persuasion");
	mm.add("Charlotte Bronte", "Jane Eyre");
	mm.add("F. Scott Fitzgerald", "The Great Gatsby");
	mm.add("Jane Austen", "Persuasion");

	vector <string> v;
	mm.search("Kristin Hannah",v);
	assert(v.size() == 0);

	mm.search("Daniel Keyes",v);
	assert(v.size() == 4);

	mm.search("Charlotte Bronte",v);
	assert(v.size() == 2);

	mm.search("Jane Austen",v);
	assert(v.size() == 5);

	mm.search("F. Scott Fitzgerald",v);
	assert(v.size() == 1);

}

void Test::sizeTest()
{
	//contained in the others
}

void Test::isEmptyTest()
{
	MultiMap mm{ };
	assert(mm.size() == 0);
	assert(mm.isEmpty() == 1);
	mm.add("F. Scott Fitzgerald", "The Great Gatsby");
	assert(mm.size() == 1);
	assert(mm.isEmpty() == 0);
	mm.remove("F. Scott Fitzgerald", "The Great Gatsby");
	assert(mm.size() == 0);
	assert(mm.isEmpty() == 1);
	mm.add("Margaret Atwood", "The Handmaid's Tale");
	assert(mm.size() == 1);
	assert(mm.isEmpty() == 0);
}