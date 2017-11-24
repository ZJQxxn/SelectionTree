//LoserTree.h : Declaretion of a winner tree.
#ifndef LOSERTREE_H
#define LOSERTREE_H

//class:'LoserTree'
class LoserTree
{
private:
	int* loserArray;	//store loser tree array
	int size;			//size of unsorted list
	int* winnerArray; //store winner nodes

	void _modify(int index);
public:
	LoserTree(const int* nums, const int size);		//construct a winner tree given an unsorted list and its size
	int getTop();						//get the top element (i.e. the minima element)
	void adjust(int index, int newValue);	//change a value in list, adjust the tree structure 
};
#endif