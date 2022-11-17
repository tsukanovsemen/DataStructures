#include "RingBuffer.h"

RingBuffer::RingBuffer(int capacity)
{
	this->_ringBuffer = new List();
	this->_ringBuffer->_Head = new List::Node();
	List::Node* temp = this->_ringBuffer->_Head;
	this->_Capacity = capacity;
	this->_Length = 0;
	for (int i = 0; i < capacity - 1; i++)
	{
		temp->Next = new List::Node();
		temp = temp->Next;
	}
	temp = this->_ringBuffer->_Head;
	while (temp->Next != nullptr)
	{
		temp = temp->Next;
	}
	temp->Next = this->_ringBuffer->_Head;
	this->_Top = this->_ringBuffer->_Head;
}

int RingBuffer::GetFreePlace()
{
	return this->_Capacity - this->_Length;
}

int RingBuffer::GetBusyPlace()
{
	return this->_Length;
}

void RingBuffer::Push(int data)
{
	if (this->_isFirstElementReady)
	{
		this->_Top->Next->Data = data;
		this->_Top = this->_Top->Next;
		if (this->isFulling())
		{
			this->_ringBuffer->_Head = this->_ringBuffer->_Head->Next;
		}
		else
		{
			this->_Length += 1;
		}
	}
	else
	{
		this->_ringBuffer->_Head->Data = data;
		this->_Length += 1;
		this->_isFirstElementReady = true;
	}
}

int RingBuffer::Pop()
{
	int deletedElement = this->_ringBuffer->_Head->Data;
	this->_ringBuffer->_Head = 
	this->_ringBuffer->_Head->Next;
	this->_Length -= 1;
	return deletedElement;
}

bool RingBuffer::isFulling()
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

bool RingBuffer::isEmpty()
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

void RingBuffer::ShowBuffer()
{
	if (this->isEmpty())
	{
		cout << endl << " Ring Buffer пустой. ";
	}
	else
	{
		List::Node* temp = this->_ringBuffer->_Head;
		cout << endl;
		for (int i = 0; i < this->_Length; i++)
		{
			cout << temp->Data << " | ";
			temp = temp->Next;
		}
	}
}

List::Node* RingBuffer::GetTop()
{
	return this->_Top;
}

List::Node* RingBuffer::GetHead()
{
	return this->_ringBuffer->_Head;
}

void RingBuffer::ClearBuffer()
{
	List::Node* temp = this->_ringBuffer->_Head;
	for (int i = 0; i < this->_Capacity; i++)
	{
		temp->Data = 0;
		temp = temp->Next;
	}
	this->_Top = this->_ringBuffer->_Head;
	this->_isFirstElementReady = false;
	this->_Length = 0;
}

RingBuffer::~RingBuffer()
{
	List::Node* temp = this->_ringBuffer->_Head;
	for (int i = 0; i < this->_Length; i++)
	{
		temp = this->_ringBuffer->_Head->Next;
		delete this->_ringBuffer->_Head;
		this->_ringBuffer->_Head = temp;
	}
	this->_isFirstElementReady = false;
	this->_Top = nullptr;
	this->_Capacity = 0;
	this->_Length = 0;
}
