#include "Treap.h"
#include <queue>

TreapNode* Treap::Merge(TreapNode* leftTree, TreapNode* rightTree)
{
	if (!leftTree || !rightTree)
	{
		return leftTree ? leftTree : rightTree;
	}
	if (leftTree->Priority > rightTree->Priority)
	{
		leftTree->Right = Merge(leftTree->Right, rightTree);
		return leftTree;
	}
	else
	{
		rightTree->Left = Merge( leftTree, rightTree->Left);
		return rightTree;
	}
}

void Treap::Split(TreapNode* root, int key, TreapNode*& leftTree, TreapNode*& rightTree)
{
	if (!root)
	{
		leftTree = rightTree = nullptr;
		return;
	}
	else
	{
		if (root->Key < key)
		{
			Split(root->Right, key, root->Right, rightTree);
			leftTree = root;
		}
		else
		{
			Split(root->Left, key, leftTree, root->Left);
			rightTree = root;
		}
	}
}

TreapNode** Treap::FindLessPriorityNode(TreapNode** root, int priority)
{
	if (root == nullptr)
	{
		return nullptr;
	}

	std::queue<TreapNode**> queue;
	queue.push(root);
	while (!queue.empty())
	{
		TreapNode** current = queue.front();
		queue.pop();

		if (priority > (*current)->Priority)
		{
			return current;
		}

		if ((*current)->Left != nullptr)
		{
			queue.push(&(*current)->Left);
		}
		if ((*current)->Right != nullptr)
		{
			queue.push(&(*current)->Right);
		}
	}
	return nullptr;
}

void Treap::InsertNotOptimized(int key)
{
	if (!_root)
	{
		_root = new TreapNode(key, nullptr,nullptr,rand());
	}
	else if (!Find(key, _root))
	{
		TreapNode* less;
		TreapNode* greater;
		Split(_root, key, less, greater);
		less = Merge(less, new TreapNode(key, nullptr, nullptr, rand()));
		_root = Merge(less, greater);
	}
	else
	{
		throw "This element already exists.";
	}
}

TreapNode* Treap::Find(int key, TreapNode* root)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (key < root->Key)
	{
		return Find(key, root->Left);
	}
	else if (key > root->Key) 
	{
		return Find(key, root->Right);
	}
	else
	{
		return root;
	}	
}

void Treap::EraseNotOptimized(int key)
{
	if (Find(key, _root) != nullptr)
	{
		TreapNode* less;
		TreapNode* greater;
		TreapNode* temp;
		Split(_root, key, less, greater);
		Split(greater, key + 1, temp, greater);
		delete temp;
		_root = Merge(less, greater);
	}
	else
	{
		throw "Element with this key doesnt exist";
	}
	
}

void Treap::EraseOptimized(int key)
{
	if (Find(key, _root))
	{
		TreapNode** releasedPointer = FindPointerToNode(key, &_root);
		TreapNode* released = *releasedPointer;
		TreapNode* newNode = Merge(released->Left, released->Right);
		*releasedPointer = newNode;
		delete released;
	}
	else
	{
		throw "This element doesn't exists";
	}
}

TreapNode** Treap::FindPointerToNode(int key, TreapNode** root)
{
	if (root == nullptr)
	{
		return nullptr;
	}

	if (key < (*root)->Key)
	{
		return FindPointerToNode(key, &(*root)->Left);
	}
	else if (key > (*root)->Key)
	{
		return FindPointerToNode(key, &(*root)->Right);
	}
	else
	{
		return root;
	}
}

void Treap::InsertOptimized(int key)
{
	if (_root == nullptr)
	{
		_root = new TreapNode{ key, nullptr, nullptr, short(rand()) };
	}
	else if (Find(key, _root) == nullptr)
	{
		short priority = short(rand());

		TreapNode** node = FindLessPriorityNode(&_root, priority);

		TreapNode* lessThanKey = nullptr;
		TreapNode* greaterThanKey = nullptr;

		Split(*node, key, lessThanKey, greaterThanKey);

		*node = new TreapNode{ key, lessThanKey, greaterThanKey, priority };
	}
	else
	{
		throw "Element with this key value already exists. Treep can't store two element with the same key.";
	}

}
