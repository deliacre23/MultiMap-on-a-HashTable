#include "IteratorMultiMap.h"
#include "MultiMap.h"


IteratorMultiMap::IteratorMultiMap(MultiMap& mm) : mm(mm)
{
	
	this->currentNode = nullptr;
	this->currentPos = 0; 
	while(currentPos < this->mm.m && this->currentNode==nullptr)
	{
		this->currentNode = this->mm.table[currentPos];
		currentPos++;
	}
	if (this->valid())
		this->currentPos--;
	else
		this->currentNode = nullptr;

}

Info IteratorMultiMap::getCurrent()
{
	if (this->valid())
		return this->currentNode->info;
	else 
		throw exception("There is no current element because the iterator is invalid");
}

void IteratorMultiMap::next()
{
	this->currentNode = this->currentNode->next;
	while (currentPos < this->mm.m-1 && this->currentNode == nullptr)
	{
		currentPos++;
		this->currentNode = this->mm.table[currentPos];
	}
	//if (!this->valid())
		//throw exception("There is no current element because the iterator is invalid");
}


bool IteratorMultiMap::valid()
{
	if (currentNode != nullptr)
		return true;
	return false;
}
