#include "RingQueue.h"

RingQueue::RingQueue(int capacity)
{
	this->_RingQueue = new List();
	this->_RingQueue->_Head = new List::Node();
	List::Node* temp = this->_RingQueue->_Head;
	this->_Capacity = capacity;
	for (int i = 1; i < this->_Capacity; i++)
	{
		temp->Next = new List::Node();
		temp = temp->Next;
	}
	temp = this->_RingQueue->_Head;
	while (temp->Next != nullptr)
	{
		temp = temp->Next;
	}
	temp->Next = this->_RingQueue->_Head;
	this->_Length = 0;
	this->_Top = this->_RingQueue->_Head;
}

int RingQueue::GetFreePlace()
{
	return this->_Capacity - this->_Length;
}

int RingQueue::GetBusyPlace()
{
	return this->_Length;
}

void RingQueue::Enqueue(int data)
{
	if (this->_IsFirstElementReady)
	{
		this->_Top->Next->Data = data;
		this->_Top = this->_Top->Next;
		this->_Length += 1;
		this->Resize();
	}
	else
	{
		this->_RingQueue->_Head->Data = data;
		this->_Length += 1;
		this->_IsFirstElementReady = true;
		this->Resize();
	}
}

bool RingQueue::isEmpty()
{
	if (this->_Length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool RingQueue::isFulling()
{
	if (this->_Length == this->_Capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int RingQueue::Dequeue()
{
	int temp = this->_RingQueue->_Head->Data;
	this->_RingQueue->_Head->Data = NULL;
	this->_RingQueue->_Head = this->_RingQueue->_Head->Next;
	this->_Top->Next->Data = temp;
	this->_Top = this->_Top->Next;
	return temp;
}

void RingQueue::Resize()
{
	if (this->isFulling())
	{
		int lastCapacity = this->_Capacity;
		this->_Capacity = this->_Capacity * this->_GrowthFactor;
		List::Node* temp = this->_Top;
		for (int i = 0; i < this->_Capacity - lastCapacity; i++)
		{
			temp->Next = new List::Node();
			temp = temp->Next;
		}
		temp->Next = this->_RingQueue->_Head;
	}
}

void RingQueue::ShowRing()
{
	if (this->isEmpty())
	{
		cout << endl << " Кольцевая очередь пуста.";
	}
	else
	{
		cout << endl;
		List::Node* temp = this->_RingQueue->_Head;
		for (int i = 0; i < this->_Length; i++)
		{
			cout << temp->Data << " | ";
			temp = temp->Next;
		}
	}
}

void RingQueue::Clear()
{
	List::Node* temp = this->_RingQueue->_Head;
	for (int i = 0; i < this->_Capacity; i++)
	{
		temp->Data = 0;
		temp = temp->Next;
	}
	this->_Top = this->_RingQueue->_Head;
	this->_IsFirstElementReady = false;
	this->_Length = 0;
}

RingQueue::~RingQueue()
{
	List::Node* temp = this->_RingQueue->_Head;
	for (int i = 0; i < this->_Length; i++)
	{
		temp = this->_RingQueue->_Head->Next;
		delete this->_RingQueue->_Head;
		this->_RingQueue->_Head = temp;
	}
	this->_IsFirstElementReady = false;
	this->_Top = nullptr;
	this->_Capacity = 0;
	this->_Length = 0;
}
