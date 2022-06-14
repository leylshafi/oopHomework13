#pragma once

template<typename T>
class BinarySearchTree
{
	struct Node
	{
		T key;
		Node* left, * right;

		Node(T key) : key(key), left(), right() {}
	};

	Node* root = NULL;

	Node* insertRec(Node* tree, T key)
	{
		if (tree == NULL)
			return new Node(key);


		if (key < tree->key)
			tree->left = insertRec(tree->left, key);
		else if (key > tree->key)
			tree->right = insertRec(tree->right, key);

		return tree;
	}

	void inOrderRec(Node* tree)
	{
		if (tree != NULL)
		{
			inOrderRec(tree->left);
			cout << tree->key << endl;
			inOrderRec(tree->right);
		}
	}

	Node* searchRec(Node* tree, T key)
	{
		if (tree == NULL)
			return NULL;

		if (key == tree->key)
			return tree;

		if (key > tree->key)
			return searchRec(tree->right, key);

		return searchRec(tree->left, key);
	}

	int minValue(Node* tree)
	{
		T min = tree->key;

		while (tree->left != NULL)
		{
			min = tree->left->key;
			tree = tree->left;
		}

		return min;
	}

	Node* deleteRec(Node* tree, T key)
	{
		if (tree == NULL)
			return NULL;

		if (key < tree->key)
			tree->left = deleteRec(tree->left, key);
		else if (key > tree->key)
			tree->right = deleteRec(tree->right, key);
		else
		{
			if (tree->left == NULL)
				return tree->right;
			else if (tree->right == NULL)
				return tree->left;

			tree->key = minValue(tree->right);
			tree->right = deleteRec(tree->right, tree->key);
		}

		return tree;
	}

public:

	void insert(T key)
	{
		root = insertRec(root, key);
	}

	void inOrder()
	{
		inOrderRec(root);
	}

	Node* search(T key)
	{
		return searchRec(root, key);
	}

	int minValue()
	{
		minValue(root);
	}

	void deleteKey(T key)
	{
		root = deleteRec(root, key);
	}
};