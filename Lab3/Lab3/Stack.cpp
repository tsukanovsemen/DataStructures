#include "Stack.h"

Stack::Stack(int capacity)
{
	this->_Stack->_Head = new List::Node();
	List::Node* temp = this->_Stack->_Head;
	for (int i = 0; i < capacity - 1; i++)
	{
		temp->Next = new List::Node();
		temp = temp->Next;
	}
	this->_Top = this->_Stack->_Head;
	this->_Capacity = capacity;
	this->_Length = 0;
}

void Stack::Push(int data)
{
	if(this->_isFirstElementReady)
	{
		this->_Top->Next->Data = data;
		this->_Top = this->_Top->Next;
		this->_Length += 1;
		this->Resize();
	}
	else
	{
		this->_Top->Data = data;
		this->_isFirstElementReady = true;
		this->_Length += 1;
		this->Resize();
	}
}

int Stack::Pop()
{
	if (this->_Length == 0)
	{
		return NULL;
	}
	else
	{
		int deletedElement = this->_Top->Data;
		this->_Top->Data = 0;
		List::Node* temp = this->_Stack->_Head;
		if (this->_Stack->_Head == this->_Top)
		{
			this->_Length -= 1;
			this->_isFirstElementReady = false;
		}
		else
		{
			while (temp->Next != this->_Top)
			{
				temp = temp->Next;
			}
			this->_Top = temp;
			this->_Length -= 1;
		}
		return deletedElement;
	}
}

void Stack::DeleteStack()
{
	List::Node* temp = this->_Stack->_Head;
	for (int i = 0; i < this->_Length; i++)
	{
		temp->Data = 0;
		temp = temp->Next;
	}
	this->_Top = this->_Stack->_Head;
	this->_isFirstElementReady = false;
	this->_Length = 0;
}

void Stack::ShowStack()
{
	if (this->_isFirstElementReady)
	{
		List::Node* temp = this->_Stack->_Head;
		for (int i = 0; i < this->_Length; i++)
		{
			cout << temp->Data << " | ";
			temp = temp->Next;
		}
		cout << " - is Top" << endl;
	}
	else
	{
		cout << endl << "Stack is clear. ";
	}
}

void Stack::ReverseShowStack()
{
	List::Node* temp = this->_Top;
	for (int i = 0; i < this->_Length; i++)
	{
		List::Node* tempHead = this->_Stack->_Head;
		while (tempHead->Next != temp)
		{
			tempHead = tempHead->Next;
		}
		cout << temp->Data << " | ";
		temp = tempHead;
	}
}

int Stack::GetCapacity()
{
	return this->_Capacity;
}

int Stack::GetLength()
{
	return this->_Length;
}

Stack::~Stack()
{
	List::Node* temp;
	for (int i = 0; i < this->_Capacity; i++)
	{
		temp = this->_Stack->_Head;
		this->_Stack->_Head = temp->Next;
		delete temp;
	}
	this->_isFirstElementReady = false;
}

void Stack::Resize()
{
	if (this->_Length == this->_Capacity)
	{
		int lastCapacity = this->_Capacity;
		this->_Capacity = this->_Capacity * this->_GrowthFactor;
		List::Node* temp = this->_Stack->_Head;
		while (temp->Next != nullptr) 
		{
			temp = temp->Next;
		}
		for (int i = 0; i < this->_Capacity - lastCapacity + 1; i++)
		{
			temp->Next = new List::Node();
			temp = temp->Next;
		}
	}
}
