//WinnerTree.cpp : Implementation of a winner tree to get max element of a list
#include "WinnerTree.h"

//Constructor
WinnerTree::WinnerTree(const int* nums, const int size)
{
	this->size = size;
	//leaf node==nonleaf node + 1, hold array[0] as a mark
	winnerArray = new int[size * 2];
	//initialize winnerArray
	for (int i = 0; i < size; i++)
	{
		winnerArray[i+size] = nums[i];
	}

	//tournament from bottom to top
	int parent = size - 1;
	while (parent != 0)
	{
		//compare two child nodes
		winnerArray[parent] = (winnerArray[parent * 2] < winnerArray[parent * 2 + 1]) ? winnerArray[parent * 2] : winnerArray[parent * 2 + 1];
		parent--;
	}
}


//public operations
/*
	Get the minima.
*/
int WinnerTree::getTop()
{
	return winnerArray[1];
}

/*
	Adjust the tree when modify the list given a index and new value.
*/
void WinnerTree::adjust(int index, int newValue)
{
	int innerIndex = index + size;
	int parent = innerIndex / 2;
	winnerArray[innerIndex] = newValue;
	while (parent != 0)
	{
		//compare two child nodes
		winnerArray[parent] = (winnerArray[parent * 2] < winnerArray[parent * 2 + 1]) ? winnerArray[parent * 2] : winnerArray[parent * 2 + 1];
		parent--;
	}
}