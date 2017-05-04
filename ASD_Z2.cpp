#include "stdafx.h"
#include <iostream>
#include <cstdio>

using namespace std;

//Node struct...
struct Node {
	Node() {
		prev = 0;
		left = 0;
		right = 0;
	}
	Node* prev;
	Node* left;
	Node* right;
	char val;
};

char* build(Node* leaf) {
	char* w = new char[65];
	char* index = w;

	while (leaf != NULL) {
		*index = leaf->val;
		index++;
		leaf = leaf->prev;
	}
	*index = 0;
	return w;
}

char* compare(char* left, char* right) {
	char* l = left;
	char* r = right;
	while (*l != 0 || *r != 0) {
		if (*l < *r)
			return right;
		else if (*l > *r)
			return left;
		l++;
		r++;
	}
	if ((*l == 0 && *r == 0) || *r == 0)
		return left;
	else return right;
}

char* result = new char[65];

void go(Node* root) {
	Node* tmp = root;

	if (tmp->left) //Going to the left subtree
		go(tmp->left);
	if (tmp->right) //going to the right subtree
		go(tmp->right);
	if (!tmp->left && !tmp->right) //Checking if it is Leaf
		result = compare(result, build(tmp));
}

int main()
{
	int	MAX_DATA_SIZE = 15 * 1024 * 1024; //Array size
	int input_size = 0;

	char *data = new char[MAX_DATA_SIZE];
	char* index = data;

	cin.read(data, MAX_DATA_SIZE); //Getting input data

	unsigned long int size = cin.gcount(); //Getting quantity of elements

	data[size] = 0; //Putting zero at the end

	Node** pool = new Node*[10000000];
	Node* root = new Node(); //Root of the tree
	Node* tmp = root; //Tree iterator
	Node* previous; //Helpng variable to keep previous Node reference

	char value = '0'; //Variable to keep value, which will be assigned to "final" node.

	//Tree building
	while (*index) {
		if (*index <= 122 && *index >= 97) { //Reading Node value
			value = *index;
			input_size++; //Counting read characters
		}
		else if (*index == 76) { //Piece of path to the Node.
			if (tmp->left == 0) {//Create Node if it does not already exist.
				*pool = new Node();
				tmp->left = *pool;
				pool++;
			}
			previous = tmp;
			tmp = tmp->left;
			tmp->prev = previous;
			input_size++; //Counting read characters
		}
		else if (*index == 82) {
			if (tmp->right == 0) {
				*pool = new Node();
				tmp->right = *pool;
				pool++;
			}
			previous = tmp;
			tmp = tmp->right;
			tmp->prev = previous;
			input_size++;
		}
		else if (*index == 10) { //New line character - putting value in Node, then reset tmp to the Root of a tree
			if (*(index - 1) != 10)
				tmp->val = value;
			tmp = root;
		}
		index++; //Next element
	}
	//<../tests/stud5.txt
	result[0] = 0;

	//Recursive function that goes through the tree
	go(root);

	cout << result << endl;
	cout << input_size;

	return 0;
}
