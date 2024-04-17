// Project 6.1 Hash Table.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <iomanip>
#include <cmath>
#include <chrono>
#include "HashTable.h"
using namespace std; 

void allTasks(int count);

int main()
{
	// Insert, Retrieve, Remove for all 3 data sizes
	// Prints out times in microseconds
	allTasks(100);
	allTasks(1000);
	allTasks(10000);
    return 0;
}

/*
Insert	Inserts the specified Key / Value pair into the Hash Table in a location that is based on the hash of the Key.
Retrieve	Retrieves the Value from the hash table that is paired with the specified key.Returns null if the key is not found in the hash table.
Remove	Removes the key / value pair(specified by the key) from the Hash Table.
*/

void allTasks(int count){
	HashTable ht;
	cout << "INSERTING:\n";
	auto start = chrono::system_clock::now();//gets the start time
	// make a BST and insert 'count' elements into the tree
	while (ht.size() < count) {// makes sure we get 'count' in the tree
		ht.insert(rand());
	}
	auto end = chrono::system_clock::now();// gets the end time
	auto total = chrono::duration_cast<std::chrono::microseconds>(end - start);
	cout << count << " elements took " << total.count() << " microseconds\n";


	// 2.
	cout << "RETRIEVING:\n";
	start = chrono::system_clock::now();
	int numberFound = 0;
	for(int i =0; i<count; i++){
		// try to retrieve 'count' random numbers
		int value2find = rand();// the number
		int* foundIt = ht.retrieve(value2find);
		if(foundIt !=nullptr){
			numberFound++;
		}
	}
	 end = chrono::system_clock::now();// gets the end time
	 total = chrono::duration_cast<std::chrono::microseconds>(end - start);
	cout << count << " elements took " << total.count() << " microseconds\n";

	// 3.
	cout << "REMOVALS:\n";
	start = chrono::system_clock::now();
	int numberRemoved = 0;
	for (int i = 0; i < count; i++) {
		// try to remove 'count' random numbers
		int value2find = rand();// the number
		bool isRemoved= ht.remove(value2find);
		if (isRemoved) {
			numberRemoved++;
		}
	}
	end = chrono::system_clock::now();// gets the end time
	total = chrono::duration_cast<std::chrono::microseconds>(end - start);
	cout << count << " elements took " << total.count() << " microseconds\n";
	
}