#pragma once
#include <vector>
#include <list>

class HashTable
{ 
private:
	const int MAX_SIZE = 1000;// how many LLs we have
	std::vector< std::list<int> > valueTable;// this a vector of linkedLists -> we're doing separate chaining
	int numElements = 0;
public:
	HashTable();
	bool insert(int);// fails if number already in table
	int* retrieve(int);// false if number not in table
	bool remove(int);
	int size() const {
		return numElements;
	}
private:
	int hash(int v);// simple modulo by MAX_SIZE
};

