//WinnerTree.h : Declaretion of a winner tree.
#ifndef WINNERTREE_H
#define WINNERTREE_H

//class:'WinnerTree'
class WinnerTree
{
private:
	int* winnerArray;	//store winner tree array
	int size;			//size of unsorted list
public:
	WinnerTree(const int* nums,const int size);		//construct a winner tree given an unsorted list and its size
	int getTop();						//get the top element (i.e. the minima element)
	void adjust(int key,int newValue);	//change a value in list, adjust the tree structure 
};
#endif