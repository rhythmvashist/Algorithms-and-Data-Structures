/*

In this fule we implement the generic Binary search tree using the Node class 
*/
#ifndef BST_H
#define BST_H
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class BST;

template<typename T>
class Node {
public:
	friend class BST<T>;
	Node() {
		left = nullptr;
		right = nullptr;
	}

	Node(const T& info, Node<T>* rt, Node<T>* lf) {
		left = lf;
		right = rt;
		data = info;
	}

	T getData(){
	    return data;
	}

	Node<T>* getLeft() {
		return left;
	}

	Node<T>* getRight() {
		return right;
	}

	void setLeft(Node<T>* temp){
	    left=temp;
	}

	void setRight(Node<T>* temp){
	    right=temp;
	}

private:
	T data;
	Node<T>* left;
	Node<T>* right;
};

template <typename T>
class BST {
public:
	BST();
	BST(Node<T>* nt);
	Node<T>* insert(T x, Node<T>* root);
	void inorder(Node<T>* root);
	Node<T>* search(Node<T>* root,T info);
	Node<T>* sarr2bst(vector<T> list,int s,int e);
	Node<T>* getRoot();
	void settRoot(Node<T>* temp);

private:
	Node<T>* root;
};

template <typename T>
BST<T>::BST() {
	root = nullptr;
}


template <typename T>
BST<T>::BST(Node<T>* nt) {
	root = nt;
}


template <typename T>
Node<T>* BST<T>::getRoot() {
	return root;
}


template <typename T>
void BST<T>::settRoot(Node<T>* temp) {
	 root=temp;
}

template <typename T>
Node<T>* BST<T>::insert(T x, Node<T>* r) {
	if (r == nullptr) {
		Node<T>* temp=new Node<T>(x, nullptr, nullptr);
		return temp;
	}
	if (x < r->data) {
		r->left = insert(x, r->left);
	}
	if (x > r->data) {
		r->right = insert(x, r->right);
	}
	return r;
}


template<typename T>
void BST<T>::inorder(Node<T>* r) {
	if (r != nullptr) {
		inorder(r->left);
		cout << r->data << " ";
		inorder(r->right);
	}
}



template<typename T>
Node<T>* BST<T>::search(Node<T>* r, T info) {
	while (r != nullptr) {
		if (info == r->data) {
			return r;
		}
		else if (info < r->data)
			r = r->left;
		else
			r = r->right;
	}
	return nullptr;
}


template <typename T>
Node<T>* BST<T>::sarr2bst(vector<T> arr, int s, int e) {
	if (s > e) {
		return nullptr;
	}
	int mid = (e + s) / 2;
	Node<T>* r = new Node<T>(arr[mid], nullptr, nullptr);
	r->left = sarr2bst(arr, s, mid - 1);
	r->right = sarr2bst(arr, mid + 1, e);
	return r;
}



#endif // BST_H
