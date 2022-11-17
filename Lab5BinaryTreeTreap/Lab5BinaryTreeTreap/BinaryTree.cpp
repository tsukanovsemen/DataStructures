#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	this->_root = nullptr;
}

BinaryTree::~BinaryTree()
{

}

void BinaryTree::Insert(int key, Node* subgraph)
{
	if (this->_root == nullptr)
	{
		this->_root = new Node();
		this->_root->Key = key;
		this->_root->Left = nullptr;
		this->_root->Right = nullptr;
		this->_root->Parent= nullptr;
	}
	else if (key < subgraph->Key)
	{
		if (subgraph->Left == nullptr)
		{
			subgraph->Left = new Node();
			subgraph->Left->Key = key;
			subgraph->Left->Left = nullptr;
			subgraph->Left->Right = nullptr;
			subgraph->Left->Parent = subgraph;
		}
		else
		{
			this->Insert(key, subgraph->Left);
		}
	}
	else if (key > subgraph->Key)
	{
		if (subgraph->Right == nullptr)
		{
			subgraph->Right = new Node();
			subgraph->Right->Key = key;
			subgraph->Right->Left = nullptr;
			subgraph->Right->Right = nullptr;
			subgraph->Right->Parent = subgraph;
		}
		else
		{
			this->Insert(key, subgraph->Right);
		}
	}
	else
	{
		throw "Элемент с таким ключом уже существует.";
	}
}

void BinaryTree::Remove(int key)
{
	Node* released = Find(key, _root);
	if (released != nullptr)
	{
		if (released->Right != nullptr)
		{
			Node* subgraphMinimum = FindMinimum(released->Right);
			if (released->Left != nullptr)
			{
				subgraphMinimum->Left = released->Left;
				released->Left->Parent = subgraphMinimum;
			}
			if (subgraphMinimum != released->Right)
			{
				subgraphMinimum->Parent->Left = nullptr;
				subgraphMinimum->Right = released->Right;
				released->Right->Parent = subgraphMinimum;
			}

			if (released != _root)
			{
				subgraphMinimum->Parent = released->Parent;

				if (key < released->Parent->Key)
				{
					released->Parent->Left = subgraphMinimum;
				}
				else
				{
					released->Parent->Right = subgraphMinimum;
				}
			}
			else
			{
				_root = subgraphMinimum;
				_root->Parent = nullptr;
			}
		}
		else if (released->Left != nullptr)
		{
			if (released != _root)
			{
				released->Left->Parent = released->Parent;

				if (key < released->Parent->Key)
				{
					released->Parent->Left = released->Left;
				}
				else
				{
					released->Parent->Right = released->Left;
				}
			}
			else
			{
				_root = released->Left;
				_root->Parent = nullptr;
			}
		}
		else
		{
			if (released != _root)
			{
				if (key < released->Parent->Key)
				{
					released->Parent->Left = nullptr;
				}
				else
				{
					released->Parent->Right = nullptr;
				}
			}
			else
			{
				_root = nullptr;
			}
		}
		delete released;
	}
	else
	{
		throw "Такого элемента с таким ключом не существует";
	}
}


Node* BinaryTree::Find(int key, Node* subgraph)
{
	if (subgraph == nullptr)
	{
		return nullptr;
	}
	if (key < subgraph->Key)
	{
		return Find(key, subgraph->Left);
	}
	else if (key > subgraph->Key)
	{
		return Find(key, subgraph->Right);
	}
	else
	{
		return subgraph;
	}
}

Node* BinaryTree::FindMinimum(Node* subgraph)
{
	if (subgraph->Left == nullptr)
	{
		return subgraph;
	}
	else
	{
		return FindMinimum(subgraph->Left);
	}
}

Node* BinaryTree::FindMaximum(Node* subgraph)
{
	if (subgraph->Right == nullptr)
	{
		return subgraph;
	}
	else
	{
		return FindMaximum(subgraph->Right);
	}
}

Node* BinaryTree::GetRoot()
{
		return _root;
}

int BinaryTree::GetDepth()
{
	_depth = 0;
	UpdateDepth(_root, 1);
	return _depth;
}

void BinaryTree::UpdateDepth(Node* root, int countDepth)
{
	if (root == nullptr)
	{
		return;
	}
	UpdateDepth(root->Left, countDepth + 1);
	UpdateDepth(root->Right, countDepth + 1);
	if (countDepth > _depth)
	{
		_depth = countDepth;
	}
}

