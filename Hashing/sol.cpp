/*
 * Please note that it's Function problem i.e.
 * you need to write your solution in the form of Function(s) only.
 * Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

/* A binary tree node has data, pointer to left child
 *    and a pointer to right child 
 *    struct Node
 *    {
 *      int data;
 *      Node* left;
 *      Node* right;
 *     }; */
/* Should print vertical order such that each vertical line
 *    is separated by $ */
#include <map>
#include <utility>
#include <functional>
#include <iostream>
using namespace std;

typedef multimap<int, Node*, greater<int>> Map;

void verticalOrder(Node * root, int vertical_position, Map &mapdata) {
	if (root) {
		mapdata.insert(make_pair(vertical_position, root));
		verticalOrder(root->left, vertical_position + 1, mapdata);
		verticalOrder(root->right, vertical_position - 1, mapdata);
	}
}

void printOrder(Map &mapdata) {
	int last_key = (mapdata.begin())->first;
	for (Map::iterator start = mapdata.begin(); start != mapdata.end();++start)
	{
		if (last_key != start->first) {
			cout << "$" << start->second->data << " ";
		}
		else if (last_key == start->first) {
			cout << start->second->data << " ";
		}
		last_key = start->first;
	}
}

void verticalOrder(Node *root) {
	int vertical_position = 0;
	Map mapdata;
	verticalOrder(root, vertical_position, mapdata);
	printOrder(mapdata);
	return;
}
