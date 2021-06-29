#include "BST.cpp"
#include "BST.h"

int main() {
	/* BST initialization... */
	BST<int> tree;

	/* ...and node insertion */
	tree.insert(23);
	tree.insert(15);
	tree.insert(6);
	tree.insert(25);
	tree.insert(5);
	tree.insert(10);
	tree.insert(17);
	tree.insert(5);
	tree.insert(30);

	/* Printing out tree nodes */
	tree.print();

	/* Node search */
	tree.search(10);

	/* Removing nodes from tree */
	tree.remove(7); tree.print();  // does not exist
	tree.remove(17); tree.print(); // has no children
	tree.remove(25); tree.print(); // has one child
	tree.remove(6); tree.print();  // has two children
}