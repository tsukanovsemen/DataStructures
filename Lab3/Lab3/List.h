#pragma once
#include <iostream>

using namespace std;

class List
{
public:
	struct Node
	{
		int Data = 0;
		Node* Next;
	};
	Node* _Head = nullptr;
};