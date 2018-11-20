#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

class BSTAVL {
public:
	BSTAVL() {
		root = nullptr;
	}
	~BSTAVL() {
		deleteAllNodes();
	}
	void insert(string key, string value) {
		Node* newNode = new Node(key, value);
		insert(newNode, root);
	}
	string find(string key) {
		return find(key, root);
	}
	void deleteAllNodes() {
		deleteAllNodes(root);
	}
private:
	struct Node {
		string key;
		string value;
		Node* left;
		Node* right;
		Node(string key, string value) {
			this->key = key;
			this->value = value;
			left = nullptr;
			right = nullptr;
		}
	};

	Node* root;

	void insert(Node* newNode, Node*& root) {
		if (root == nullptr) {
			root = newNode;

		} else if (root->key.compare(newNode->key) > 0) {
			insert(newNode, root->left);
		} else {
			insert(newNode, root->right);
		}
	}
	string find(string key, Node* root) {
		if (root->key == key) {
			return root->value;
		} else if (root->key > key) {
			return find(key, root->left);
		} else if (root->key < key) {
			return find(key, root->right);
		}
		return NULL;
	}

	void deleteAllNodes(Node* root) {
		if (root->left != nullptr) {
			deleteAllNodes(root->left);
		} else if (root->right != nullptr) {
			deleteAllNodes(root->right);
		}
		delete root;
	}
};

#endif
