#pragma once
#include "MultiMap.h"

class MultiMap;

class IteratorMultiMap
{
	friend class MultiMap;

private:

	MultiMap& mm;
	int currentPos;
	Node* currentNode;
	IteratorMultiMap(MultiMap& mm);

public:

	Info getCurrent();
	void next();
	bool valid();


};


