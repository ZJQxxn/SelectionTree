//LoserTree.h : Implementation of a loser tree to get minimize element of a unsorted list.
#include "LoserTree.h"
#include <iostream>
using namespace std;

//private operations
/*
	Description: Modify nodes on the path from index to root.
*/
void LoserTree::_modify(int index)
{
	int leftChild = 0;
	int rightChild = 0;
	if (index < size / 2)
	{
		leftChild = winnerArray[index * 2];
		rightChild = winnerArray[index * 2 + 1];
	}
	else
	{
		leftChild = loserArray[index * 2];
		rightChild = loserArray[index * 2 + 1];
	}
	int loser = (leftChild>rightChild) ? leftChild : rightChild;
	int winner = (loser == leftChild) ? rightChild : leftChild;
	loserArray[index] = loser;
	winnerArray[index] = winner;
}

//Constructor
LoserTree::LoserTree(const int* nums, const int size)
{
	this->size = size;
	//leaf node==nonleaf node + 1, hold array[0] to store minima
	loserArray = new int[size * 2];
	winnerArray = new int[size];

	//initialize winnerArray
	for (int i = 0; i < size; i++)
	{
		loserArray[i + size] = nums[i];
	}

	//tournament from bottom to top
	int parent = size - 1;
	while (parent != 0)
	{
		_modify(parent);
		parent--;
	}

	//winNode just like a winner tree
	loserArray[0] = winnerArray[1];
}


//public operations
/*
Get the minima.
*/
int LoserTree::getTop()
{
	return loserArray[0];
}

/*
Adjust the tree when modify the list given a index and new value.
*/
void LoserTree::adjust(int index, int newValue)
{
	int innerIndex = index + size;
	loserArray[innerIndex] = newValue;
	int parent = innerIndex / 2;
	while (parent != 0)
	{
		_modify(parent);

		//move to its parent
		parent = parent / 2;
	}
	loserArray[0] = winnerArray[1];
}