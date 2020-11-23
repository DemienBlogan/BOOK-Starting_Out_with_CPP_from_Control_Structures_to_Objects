#pragma once
#include <iostream>

template <typename T>
class BinaryTree
{
private:
	struct Node
	{
		T value;
		Node* left;
		Node* right;
	};

	Node* root;

	void DestroySubTree(Node* node)
	{
		if (node != nullptr)
		{
			if (node->left)
				DestroySubTree(node->left);
			if (node->right)
				DestroySubTree(node->right);
			delete node;
		}
	}

	void Insert(Node*& node, Node*& newNode)
	{
		if (node == nullptr)
			node = newNode;
		else if (newNode->value < node->value)
			Insert(node->left, newNode);
		else
			Insert(node->right, newNode);
	}

	void DeleteNode(const T& value, Node*& node)
	{
		if (value < node->value)
			DeleteNode(value, node->left);
		else if (value > node->value)
			DeleteNode(value, node->right);
		else
			MakeDeletion(node);
	}

	void MakeDeletion(Node*& node)
	{
		Node* tempNode = nullptr;

		if (node->right == nullptr)
		{
			tempNode = node;
			node = node->left;
			delete tempNode;
		}
		else if (node->left == nullptr)
		{
			tempNode = node;
			node = node->right;
			delete tempNode;
		}
		else
		{
			tempNode = node->right;

			while (tempNode->left)
				tempNode = tempNode->left;

			tempNode->left = node->left;

			tempNode = node;
			node = node->right;
			delete tempNode;
		}
	}

	void DisplayInOrder(Node* node) const
	{
		if (node != nullptr)
		{
			DisplayInOrder(node->left);
			std::cout << node->value << " ";
			DisplayInOrder(node->right);
		}
	}

	void DisplayPreOrder(Node* node) const
	{
		if (node != nullptr)
		{
			std::cout << node->value << " ";
			DisplayPreOrder(node->left);
			DisplayPreOrder(node->right);
		}
	}

	void DisplayPostOrder(Node* node) const
	{
		if (node != nullptr)
		{
			DisplayPostOrder(node->left);
			DisplayPostOrder(node->right);
			std::cout << node->value << " ";
		}
	}

	size_t GetNodesCount(Node* node) const
	{
		if (node == nullptr)
			return 0;

		return 1 + GetNodesCount(node->left) + GetNodesCount(node->right);
	}

	size_t GetLeafNodesCount(Node* node) const
	{
		if (node == nullptr)
			return 0;

		if (node->left == nullptr && node->right == nullptr)
			return 1;

		return GetLeafNodesCount(node->left) + GetLeafNodesCount(node->right);
	}

	T FindMax(const T& value1, const T& value2) const
	{
		return value1 >= value2 ? value1 : value2;
	}

	size_t GetHeight(Node* node) const
	{
		if (node == nullptr)
			return 0;

		return FindMax(GetHeight(node->left), GetHeight(node->right)) + 1;
	}

	size_t GetLevelWidth(Node* node, int level) const
	{
		if (node == nullptr)
			return 0;

		if (level == 1)
			return 1;

		if (level > 1)
			return GetLevelWidth(node->left, level - 1) + GetLevelWidth(node->right, level - 1);
	}

	size_t GetWidth(Node* node) const
	{
		size_t maxWidth = 0;
		size_t width;
		size_t height = GetHeight(root);

		for (int level = 1; level <= height; level++)
		{
			width = GetLevelWidth(node, level);

			if (width > maxWidth)
				maxWidth = width;
		}

		return maxWidth;
	}

public:
	BinaryTree()
		: root(nullptr)
	{ }

	~BinaryTree()
	{
		DestroySubTree(root);
	}

	void Insert(const T& value)
	{
		Node* newNode = new Node{ value, nullptr, nullptr };
		Insert(root, newNode);
	}

	bool Find(const T& value)
	{
		Node* node = root;

		while (node != nullptr)
		{
			if (node->value == value)
				return true;
			else if (value < node->value)
				node = node->left;
			else
				node = node->right;
		}

		return false;
	}

	void Remove(const T& value)
	{
		RemoveNode(value, root);
	}

	void DisplayInOrder() const
	{
		DisplayInOrder(root);
	}

	void DisplayPreOrder() const
	{
		DisplayPreOrder(root);
	}

	void DisplayPostOrder() const
	{
		DisplayPostOrder(root);
	}

	size_t GetNodesCount() const
	{
		return GetNodesCount(root);
	}

	size_t GetLeafNodesCount() const
	{
		return GetLeafNodesCount(root);
	}

	size_t GetHeight() const
	{
		return GetHeight(root);
	}

	size_t GetWidth() const
	{
		return GetWidth(root);
	}
};