#include "Node.h"
#include <string>
using namespace std;

Node::Node(Node* prev, Node* next, string key, string data)
{
	this->NextElement = next;
	this->PrevElement = prev;
	this->Data = data;
	this->Key = key;
}