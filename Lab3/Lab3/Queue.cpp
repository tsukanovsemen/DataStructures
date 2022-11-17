#include "Queue.h"

Queue::Queue(int capacity)
{
	this->_stack1 = new Stack(capacity);
	this->_stack2 = new Stack(capacity);
	this->_Capacity = capacity;
	this->_Length = 0;
}

void Queue::Enqueue(int data)
{
	this->_stack1->Push(data);
	this->_Length += 1;
}

int Queue::Dequeue()
{
	
	 if (this->_stack2->GetLength() == 0)
	{
		for (int i = 0; i < this->_Length; i++)
		{
			this->_stack2->Push(this->_stack1->Pop());
		}
		this->_Length -= 1;
		int tempData = this->_stack2->Pop();
		return tempData;
	}
	else
	{
		this->_Length -= 1;
		return this->_stack2->Pop();
	}
}

void Queue::Clear()
{
	this->_stack1->DeleteStack();
	this->_stack2->DeleteStack();
}

void Queue::ShowQueue()
{
	if (this->_Length == 0)
	{
		cout << endl << " queue пуста." << endl;
	}
	else
	{
		if (this->_stack2->GetLength() == 0)
		{
			cout << endl;
			this->_stack1->ShowStack();
		}
		else if(this->_stack1->GetLength() == 0)
		{
			for (int i = 0; i < this->_Length; i++)
			{
				_stack1->Push(this->_stack2->Pop());
			}
			this->_stack1->ShowStack();
			for (int i = 0; i < this->_Length; i++)
			{
				this->_stack2->Push(this->_stack1->Pop());
			}
		}
	}
}

int Queue::GetLength()
{
	return this->_Length;
}

Queue::~Queue()
{
	delete this->_stack1;
	delete this->_stack2;
	this->_Length = 0;
	this->_Capacity = 0;
}


