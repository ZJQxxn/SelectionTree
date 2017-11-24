//main.cpp : Main funtion to test selection tree
#include "WinnerTree.h"
#include "LoserTree.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	int* nums = new int[8]{10,9,20,6,8,11,90,17};
	cout << "List contains :";
	for (int i = 0; i < 8; i++)
	{
		cout << nums[i] << "  ";
	}
	cout << endl;

	LoserTree tree(nums, 8);
	cout << "The minimum :"<<tree.getTop() << endl;

	tree.adjust(3, 15);
	cout << "After change 6 to 15 the minimum :" << tree.getTop() << endl;

	tree.adjust(4, 16);
	cout << "After change 8 to 16 the minimum :" << tree.getTop() << endl;

	system("pause");
	return 0;
}