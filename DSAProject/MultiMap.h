#pragma once
#include <utility>
#include<vector>
#include <string>
using namespace std;


struct Info
{
	string key;
	string value;
};

struct Node
{
	Info info;
	Node* next;
};

typedef int(*TFunction)(string key, int m);

class IteratorMultiMap;

class MultiMap
{

	friend class IteratorMultiMap;

private:
	Node** table;  //pointer to pointer
	int m;
	TFunction hf;

public:

	//constructor
	MultiMap();

	//getters 
	void getTable(Node* l[]);
	int getCapacity(){ return this->m; }
	TFunction getHashFunction() { return this->hf; }

	//adds a key value pair to the multimap
	void add(string key, string value);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(string key, string value);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	//vector<string> search(string key);
	void search(string key, vector<string>& values);

	//returns the number of pairs from the multimap
	int size();

	//checks whether the multimap is empty
	bool isEmpty();
	
	//returns an iterator for the multimap
	IteratorMultiMap iterator();

	//destructor
	~MultiMap();

	void update(string key, string value, string newValue);


};
