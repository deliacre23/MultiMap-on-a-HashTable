#include "MultiMap.h"
#include "IteratorMultiMap.h"
#include <iostream>


int hashFunction(string s, int m)
{
	int pos = 0;
	for (int i = 0; i < s.length(); i++)
	{
		pos = pos + int(s[i]) * pow(31, s.length() - i - 1);

	}
	if (pos < 0) pos = -pos;
	return pos % m;
}

MultiMap::MultiMap()
{
	this->m = 100;
	this->hf = hashFunction;
	this->table = new Node* [this->m];
	for (int i = 0; i < m; i++)
	{
		this->table[i] = nullptr;
	}

}

void MultiMap::getTable(Node* l[])
{
	for (int i = 0; i < m; i++) 
		l[i] = this->table[i]; 
}

void MultiMap::add(string key, string value)
{
	Node* n = new Node{ key,value };
	n->next = this->table[this->hf(key, m)];
	this->table[this->hf(key, m)] = n;
}

bool MultiMap::remove(string key, string value)
{
	Node* currentNode = this->table[this->hf(key,m)];
	Node* prevNode = nullptr;
	if (currentNode == nullptr)
		return false;
	bool found = false;
	while (currentNode != nullptr && found==false)
	{
		if (currentNode->info.key == key && currentNode->info.value == value)
			found = true;
		else 
		{
			prevNode = currentNode;
			currentNode = currentNode->next;
		}
	}
	if (found == false)
		return false;

	if (prevNode == nullptr && currentNode->next == nullptr)
		this->table[this->hf(key, m)] = nullptr; 
	else 
		if (prevNode == nullptr && currentNode->next != nullptr)
			this->table[this->hf(key, m)] =currentNode->next;
		else
			prevNode->next = currentNode->next;
	return true;

}


void MultiMap::search(string key, vector<string>& values)
{
	values.clear();
	Node* currentNode = this->table[this->hf(key, m)];
	while (currentNode != nullptr)
	{
		if (currentNode->info.key == key)
			values.push_back(currentNode->info.value);
		currentNode = currentNode->next;
	}
}

int MultiMap::size()
{
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		Node* currentNode = this->table[i];
		while (currentNode != nullptr)
		{
			currentNode = currentNode->next;
			count++;
		}
	}
	return count;
}

bool MultiMap::isEmpty()
{
	for (int i = 0; i < m; i++)
		if (this->table[i] != nullptr)
			return  false;
	return true;
}


IteratorMultiMap MultiMap::iterator() {
	return IteratorMultiMap(*this);
}

MultiMap::~MultiMap()
{

	for (int i = 0; i < m; i++)
	{
		Node* current = this->table[i];
		while (current != nullptr)
		{
			Node* prev = current;
			current = current->next;
			delete prev;
		}
	}
	delete[] this->table;

}

void MultiMap::update(string key, string value, string newValue)
{
	Node* currentNode = this->table[this->hf(key, this->m)];

	while (currentNode != nullptr)
	{
		if (currentNode->info.key == key && currentNode->info.value == value)
			currentNode->info.value = newValue;
		currentNode = currentNode->next;
	}
}
