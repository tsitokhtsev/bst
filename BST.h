/* BST Definition */

#pragma once
#include "TreeNode.h"

template<typename T>
class BST {
	TreeNode<T>* root = nullptr;

	/* Helper Functions */
	bool search(TreeNode<T>* node, T data) const;
	TreeNode<T>* insert(TreeNode<T>* node, T data);
	TreeNode<T>* remove(TreeNode<T>* node, T data);

	/* Tree Traversal Functions */
	void preorder(TreeNode<T>* node) const;
	void inorder(TreeNode<T>* node) const;
	void postorder(TreeNode<T>* node) const;

public:
	BST() = default;

	/* Public Functions */
	void search(T data) const;
	void insert(T data);
	void remove(T data);
	void print() const;
};