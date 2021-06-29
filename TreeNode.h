/* TreeNode Definition and Implementation */

#pragma once

template<typename T>
class TreeNode {
	T data;
	TreeNode* lChild, * rChild;

	template<typename>
	friend class BST;

public:
	TreeNode();
	TreeNode(T i, TreeNode<T>* l = nullptr, TreeNode<T>* r = nullptr);
	T getData() const;
};

template<typename T>
TreeNode<T>::TreeNode() { lChild = rChild = nullptr; }

template<typename T>
TreeNode<T>::TreeNode(T i, TreeNode<T>* l, TreeNode<T>* r)
	: data(i), lChild(l), rChild(r) {}

template<typename T>
T TreeNode<T>::getData() const { return data; }