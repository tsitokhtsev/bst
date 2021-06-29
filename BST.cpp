/* BST Implementation */

#include <iostream>
#include "BST.h"

/* Node Search (helper) */
template<typename T>
bool BST<T>::search(TreeNode<T>* node, const T data) const {
	if (node == nullptr) return false; // no nodes left

	if (node->data == data) return true; // node found

	if (node->data > data)
		return search(node->lChild, data); // go to left child
	else
		return search(node->rChild, data); // go to right child
}

/* Node Insertion (helper) */
template<typename T>
TreeNode<T>* BST<T>::insert(TreeNode<T>* node, const T data) {
	if (node == nullptr) {
		std::cout << "Node was added!\n\n";
		return new TreeNode<T>(data);
	}

	if (node->data > data)
		node->lChild = insert(node->lChild, data); // go to left child
	else
		node->rChild = insert(node->rChild, data); // go to right child

	return node;
}

/* Node Deletion (helper) */
template<typename T>
TreeNode<T>* BST<T>::remove(TreeNode<T>* node, T data) {
	if (node == nullptr) return node;

	if (node->data > data) {
		node->lChild = remove(node->lChild, data); // go to left child
		return node;
	}

	if (node->data < data) {
		node->rChild = remove(node->rChild, data); // go to right child
		return node;
	}

	/* If node has one child */
	if (node->lChild == nullptr) {
		TreeNode<T>* temp = node->rChild;
		delete node;
		return temp;
	}

	if (node->rChild == nullptr) {
		TreeNode<T>* temp = node->lChild;
		delete node;
		return temp;
	}

	/* If node has two children */
	TreeNode<T>* newParent = node;

	TreeNode<T>* successor = node->rChild;
	while (successor->lChild != nullptr) { // finding leftmost successor
		newParent = successor;
		successor = successor->lChild;
	}

	if (newParent != node)
		newParent->lChild = successor->rChild;
	else
		newParent->rChild = successor->rChild;

	node->data = successor->data;

	delete successor;
	return node;
}

/* Preorder Traversal */
template<typename T>
void BST<T>::preorder(TreeNode<T>* node) const {
	if (node != nullptr) {
		std::cout << node->data << " "; // root
		preorder(node->lChild); // left subtree
		preorder(node->rChild); // right subtree
	}
}

/* Inorder Traversal */
template<typename T>
void BST<T>::inorder(TreeNode<T>* node) const {
	if (node != nullptr) {
		inorder(node->lChild); // left subtree
		std::cout << node->data << " "; // root
		inorder(node->rChild); // right subtree
	}
}

/* Postorder Traversal */
template<typename T>
void BST<T>::postorder(TreeNode<T>* node) const {
	if (node != nullptr) {
		postorder(node->lChild); // left subtree
		postorder(node->rChild); // right subtree
		std::cout << node->data << " "; // root
	}
}

/* Node Search (public) */
template<typename T>
void BST<T>::search(const T data) const {
	std::cout << "Searching for " << data << "...\n";

	if (search(root, data)) // if found
		std::cout << "Node was found!\n\n";
	else
		std::cout << "Node was NOT found!\n\n";
}

/* Node Insertion (public) */
template<typename T>
void BST<T>::insert(const T data) {
	std::cout << "Inserting " << data << " in BST...\n";

	if (search(root, data)) // if found
		std::cout << "This item is already in tree!\n\n";
	else
		root = insert(root, data);
}

/* Node Deletion (public) */
template<typename T>
void BST<T>::remove(const T data) {
	std::cout << "Removing " << data << " from BST...\n";

	if (search(root, data)) {
		root = remove(root, data);
		std::cout << data << " was removed!\n\n";
	} else {
		std::cout << "BST does not contain node " << data << "!\n\n";
	}
}

/* Print */
template<typename T>
void BST<T>::print() const {
	while (true) {
		std::cout << "Choose BST traversal technique:\n"
			<< "1.Preorder\n"
			<< "2.Inorder\n"
			<< "3.Postorder\n"
			<< "Enter number: ";
		int i;
		std::cin >> i;

		switch (i) {
			case 1: preorder(root); std::cout << "\n\n"; return;
			case 2: inorder(root); std::cout << "\n\n"; return;
			case 3: postorder(root); std::cout << "\n\n"; return;
			default: std::cout << "Try again...\n\n";
		}
	}
}