#include "HashTable.h"

//constructor: just sets up our table of LLs
HashTable::HashTable()
{ 
	// valueTable will be made with MAX_SIZE linked lists
	valueTable = std::vector< std::list<int> >(MAX_SIZE); 
}
 
// to insert a value 'v' into the hash table, we first find a spot for it
 // but our 'spot' is really a linked list
 // and in that linked list, we don't store duplicates! 
 // so we return false if v already exists in HT
bool HashTable::insert(int v) {
	// first thing to do is find what spot we would put v in
	// so that's finding the index in our table
	int index = hash(v);// which LL we go into
	// but what's at each index? We have a LL at each index
	// To put the value in the LL means we first need to search LL until the end 
	// and if the value is not there, then we can insert it at the back or whatever 
	std::list<int>& hashedList = valueTable[index];// this is like a pointer; get an alias
	for (int llv : hashedList) {// go through all the present value in the LL
		// if you we find the SAME value in this ll, 
		if (llv == v) {
			return false;//then we return FALSE because we don't insert duplicates
		}
	}
	hashedList.emplace_back(v);// put 'v' at back of LL
	numElements++;// successful add so # go brrr
	return true;
}

// fails if number already in table
int* HashTable::retrieve(int v){
	// 1. hash the value to find the index where we expect a LL with our value in it.
	int index = hash(v);
	// 2. look in that LL to see if we have the value
	for(int valueOfLinkedList : valueTable[index]){
		if(valueOfLinkedList == v) {
			return &valueOfLinkedList;// return address of value
		}
	}
	return nullptr;// we did not find
}
// false if number not in table
bool HashTable::remove(int value2remove){
	// 1. find index of LL
	int indexLinkedList = hash(value2remove);
	std::list<int>& linkedList = valueTable[indexLinkedList];// this is like a pointer; get an alias

	// This is advanced iterator stuff that's a bit weird to learn
	for(auto it = linkedList.begin(); it != linkedList.end(); it++){
		if(*it == value2remove){// if the value inside the iterator is equal to the value we wanto remove
			it = linkedList.erase(it);
			numElements--;
			return true;// we found the value and so we remove it -> return true because success
		}
	}
	return false;// we didn't find value2remove so failure
}

// because we are doing separate chaining
//this function takes a value then % by MAX_SIZE (1000 as of writing)
// and tells us which linkedList to look in (LL0 through LL999)
int HashTable::hash(int v){
	return v % MAX_SIZE;// remainder by 
}