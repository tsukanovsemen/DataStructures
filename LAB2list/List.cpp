#include "List.h"

List::Node* List::FindElement(int index)
{
	if (index > this->_CountList - 1 || index < 0)
	{
		throw exception("Index is not correct \n ArrayIndexOutOfBounds");
	}
	else
	{
		//Если индекс меньше индекса среднего элемента то поиск 
	//идет сначала списка
		if (index <= (this->_CountList / 2))
		{
			Node* temp = this->_HeadList;
			for (int i = 0; i < this->_CountList; i++)
			{
				if (index == i)
				{
					return temp;
					break;
				}
				temp = temp->NextElement;
			}
		}
		//Иначе поиск идет с конца списка
		else
		{
			Node* temp = this->_TailList;
			for (int i = this->_CountList - 1; i > 0; i--)
			{
				if (index == i)
				{
					return temp;
					break;
				}
				temp = temp->PrevElement;
			}
		}
	}
}

List::Node* List::FindElementByData(int data)
{
	Node* tempElement = this->_HeadList;
	while (tempElement->Data != data)
	{
		if (tempElement == nullptr)
		{
			break;
		}
		else
		{
			tempElement = tempElement->NextElement;
			if (tempElement == nullptr)
				break;
		}
	}
	return tempElement;
}

void List::SwapNodes(Node* elem1, Node* elem2)
{
	if (this->_HeadList == elem1)
	{
		Node* tempElement = elem2->NextElement;
		elem2->PrevElement =
			elem1->PrevElement;
		elem2->NextElement = elem1;
		elem1->PrevElement = elem2;
		elem1->NextElement = tempElement;
		tempElement->PrevElement = elem1;
		this->_HeadList = elem2;
	}
	else if (this->_TailList == elem2)
	{
		Node* tempElem = elem1->PrevElement;
		elem2->PrevElement =
			elem1->PrevElement;
		elem2->NextElement = elem1;
		elem1->PrevElement = elem2;
		elem1->NextElement = nullptr;
		tempElem->NextElement = elem2;
		this->_TailList = elem1;
	}
	else
	{
		Node* tempElement = elem1->PrevElement;
		elem1->NextElement = elem2->NextElement;
		elem1->PrevElement = elem2;
		elem2->PrevElement = tempElement;
		elem2->NextElement = elem1;
		tempElement->NextElement = elem2;
		elem1->NextElement->PrevElement = elem1;
	}
}

List::List() {}

List::Node::Node(Node* prev, Node* next, int data)
{
	this->NextElement = next;
	this->PrevElement = prev;
	this->Data = data;
}

List::List(int count, int* array)
{
	Node* temp = new Node(nullptr, nullptr, array[0]);
	this->_HeadList = temp;
	for (int i = 1; i < count ; i++)
	{
		temp->NextElement = new Node(temp, nullptr, array[i]);
		this->_TailList = temp->NextElement;
		temp = temp->NextElement;
	}
	this->_CountList = count;
}

void List::AddElement(int data)
{
	Node* temp = new Node(this->_TailList, nullptr, data);

	if (this->_CountList == 0)
	{
		this->_HeadList = temp;
		this->_TailList = _HeadList;
	}
	else
	{
		this->_TailList->NextElement = temp;
		this->_TailList = temp;
	}
	this->_CountList += 1;
}

void List::AddElemByIndex(int data, int index)
{
	if (index > this->_CountList - 1 || index < 0)
	{
		throw exception("Index is not correct \n ArrayIndexOutOfBounds");
	}
	else
	{
		//Если индекс меньше среднего индекса списка
		if (index <= (this->_CountList / 2))
		{
			Node* temp = this->_HeadList;
			int i = 0;
			while (temp != nullptr)
			{
				if (index == i)
				{
					if (temp == this->_HeadList)
					{
						Node* newElem = new Node(nullptr, temp, data);
						temp->PrevElement = newElem;
						this->_HeadList = newElem;
						this->_CountList += 1;
						break;
					}
					else
					{
						Node* newElem = new Node(temp->PrevElement, temp, data);
						temp->PrevElement->NextElement = newElem;
						temp->PrevElement = newElem;
						this->_CountList += 1;
						break;
					}
				}
				temp = temp->NextElement;
				i += 1;
			}
		}
		else
		{
			Node* temp = this->_TailList;
			int i = this->_CountList - 1;
			while (temp != nullptr)
			{
				if (index == i)
				{
					if (temp == this->_TailList)
					{
						Node* newElem = new Node(temp->PrevElement, temp, data);
						temp->PrevElement->NextElement = newElem;
						temp->PrevElement = newElem;
						this->_CountList += 1;
						break;
					}
					else
					{
						Node* newElem = new Node(temp->PrevElement, temp, data);
						temp->PrevElement->NextElement = newElem;
						temp->PrevElement = newElem;
						this->_CountList += 1;
						break;
					}
				}
				temp = temp->PrevElement;
				i -= 1;
			}
		}
	}
}

void List::DeleteElement()
{
	if (this->GetCountList() == 1)
	{
		delete this->_HeadList;
		this->_CountList -= 1;
	}
	else
	{
		Node* temp = this->_TailList;
		temp = this->_TailList->PrevElement;
		delete _TailList;
		this->_TailList = temp;
		this->_TailList->NextElement = nullptr;
		this->_CountList -= 1;
	}
}

void List::DeleteElemByIndex(int index)
{
	if (index > this->_CountList - 1 || index < 0)
	{
		throw exception("Index is not correct \n ArrayIndexOutOfBounds");
	}
	else
	{
		if (index <= (this->_CountList / 2))
		{
			Node* temp = this->_HeadList;
			for (int i = 0; i < this->_CountList; i++)
			{
				if (index == i)
				{
					// Если удаляется первый элемент
					if (index == 0)
					{
						this->_HeadList = temp->NextElement;
						delete temp;
						this->_HeadList->PrevElement = nullptr;
						this->_CountList -= 1;
						break;
					}
					else
					{
						temp->PrevElement->NextElement = temp->NextElement;
						temp->NextElement->PrevElement = temp->PrevElement;
						delete temp;
						this->_CountList -= 1;
						break;
					}
				}
				temp = temp->NextElement;
			}
		}
		else
		{
			Node* temp = this->_TailList;
			for (int i = this->_CountList - 1; i > 0; i--)
			{
				if (index == i)
				{
					//Если удаляется последний элемент
					 if (index == this->_CountList - 1)
					{
						this->_TailList = temp->PrevElement;
						delete temp;
						this->_TailList->NextElement = nullptr;
						this->_CountList -= 1;
						break;
					}
					else
					{
						temp->PrevElement->NextElement = temp->NextElement;
						temp->NextElement->PrevElement = temp->PrevElement;
						temp->NextElement = nullptr;
						temp->PrevElement = nullptr;
						delete temp;
						this->_CountList -= 1;
						break;
					}
				}
				temp = temp->PrevElement;
			}
		}
	}
}

int List::DeleteElemByValue(int value)
{
	bool isFound = false;
	Node* temp = this->_HeadList;
	while(temp!=nullptr)
	{
		if (value == temp->Data)
		{
			if (temp == this->_HeadList)
			{
				this->_HeadList = temp->NextElement;
				delete temp;
				if (this->_HeadList != nullptr)
				{
					this->_HeadList->PrevElement = nullptr;
					this->_CountList -= 1;
				}
				else
				{
					this->_CountList -= 1;
				}
				isFound = true;
				return 0;
			}
			else if (temp == this->_TailList)
			{
				this->_TailList = temp->PrevElement;
				delete temp;
				this->_TailList->NextElement = nullptr;
				this->_CountList -= 1;
				isFound = true;
				return 0;
			}
			else
			{
				temp->PrevElement->NextElement = temp->NextElement;
				temp->NextElement->PrevElement = temp->PrevElement;
				temp->NextElement = nullptr;
				temp->PrevElement = nullptr;
				delete temp;
				this->_CountList -= 1;
				isFound = true;
				return 0;
			}
		}
		temp = temp->NextElement;
	}
	if (!isFound) 
	{
		return -1;
	}
}

void List::InsertInStart(int data)
{
	Node* temp = this->FindElementByData(data);
	if (temp == nullptr)
	{
		cout << endl << "No data with this value: ";
	}
	else
	{
		if (temp == this->_TailList)
		{
			this->_TailList = temp->PrevElement;
			this->_TailList->NextElement = nullptr;
			temp->NextElement = this->_HeadList;
			temp->PrevElement = nullptr;
			this->_HeadList->PrevElement = temp;
			this->_HeadList = temp;
		}
		else if(temp != this->_HeadList)
		{
			temp->PrevElement->NextElement = temp->NextElement;
			temp->NextElement->PrevElement = temp->PrevElement;
			temp->NextElement = this->_HeadList;
			temp->PrevElement = nullptr;
			this->_HeadList->PrevElement = temp;
			this->_HeadList = temp;
		}
		else
		{
			//nothing
		}
	}	
}

void List::InsertInEnd(int data)
{
	Node* temp = this->FindElementByData(data);
	if (temp == nullptr)
	{

		cout << endl << "No data with this value: ";
	}
	else
	{
		if (temp == this->_HeadList)
		{
			this->_HeadList = temp->NextElement;
			this->_HeadList->PrevElement = nullptr;
			this->_TailList->NextElement = temp;
			temp->NextElement = nullptr;
			temp->PrevElement = this->_TailList;
			this->_TailList = temp;
		}
		else if(temp != this->_TailList)
		{
			temp->PrevElement->NextElement = temp->NextElement;
			temp->NextElement->PrevElement = temp->PrevElement;
			this->_TailList->NextElement = temp;
			temp->NextElement = nullptr;
			temp->PrevElement = this->_TailList;
			this->_TailList = temp;
		}
		else
		{
			//nothing
		}
	}
}

void List::InsertAfterSelectedElem(int data, int selectedData)
{
	//tempElem - элемент который перставляем
	Node* tempElement = this->FindElementByData(data);
	//tempSelected - элемент после которого вставляем
	Node* tempSelected = this->FindElementByData(selectedData);
	if (tempElement == nullptr || tempSelected == nullptr)
	{
		cout << endl << "Not correct values: ";
	}
	else
	{
		if (tempElement == this->_HeadList)
		{
			if (tempSelected == this->_TailList)
			{
				this->_HeadList = tempElement->NextElement;
				this->_HeadList->PrevElement = nullptr;
				this->_TailList->NextElement = tempElement;
				tempElement->PrevElement = this->_TailList;
				tempElement->NextElement = nullptr;
				this->_TailList = tempElement;
			}
			else
			{
				this->_HeadList = tempElement->NextElement;
				this->_HeadList->PrevElement = nullptr;
				tempElement->NextElement = tempSelected->NextElement;
				tempElement->PrevElement = tempSelected;
				tempSelected->NextElement->PrevElement = tempElement;
				tempSelected->NextElement = tempElement;
			}
		}
		else if (tempElement == this->_TailList)
		{
			this->_TailList = tempElement->PrevElement;
			this->_TailList->NextElement = nullptr;
			tempElement->NextElement = tempSelected->NextElement;
			tempElement->PrevElement = tempSelected;
			tempSelected->NextElement->PrevElement = tempElement;
			tempSelected->NextElement = tempElement;
		}
		else
		{
			if (tempSelected == this->_TailList)
			{
				tempElement->PrevElement->NextElement = tempElement->NextElement;
				tempElement->NextElement->PrevElement = tempElement->PrevElement;
				tempElement->NextElement = tempSelected->NextElement;
				tempElement->PrevElement = tempSelected;
				tempSelected->NextElement = tempElement;
				this->_TailList = tempElement;
			}
			else
			{
				tempElement->PrevElement->NextElement = tempElement->NextElement;
				tempElement->NextElement->PrevElement = tempElement->PrevElement;
				tempElement->NextElement = tempSelected->NextElement;
				tempElement->PrevElement = tempSelected;
				tempSelected->NextElement->PrevElement = tempElement;
				tempSelected->NextElement = tempElement;
			}
		}
	}
}

void List::InsertBeforeSelectedElem(int data, int selectedData)
{
	Node* tempElement = this->FindElementByData(data);
	Node* tempSelected = this->FindElementByData(selectedData);

	if (tempElement == nullptr || tempSelected == nullptr)
	{
		cout << endl << "Not correct values: ";
	}
	else
	{
		if (tempElement == this->_TailList)
		{
			if (tempSelected == this->_HeadList)
			{
				this->_TailList = tempElement->PrevElement;
				this->_TailList->NextElement = nullptr;
				this->_HeadList->PrevElement = tempElement;
				tempElement->NextElement = this->_HeadList;
				tempElement->PrevElement = nullptr;
				this->_HeadList = tempElement;
			}
			else
			{
				this->_TailList = tempElement->PrevElement;
				this->_TailList->NextElement = nullptr;
				tempElement->PrevElement = tempSelected->PrevElement;
				tempSelected->PrevElement->NextElement = tempElement;
				tempElement->NextElement = tempSelected;
				tempSelected->PrevElement = tempElement;
			}
		}
		else if (tempElement == this->_HeadList)
		{
			this->_HeadList = tempElement->NextElement;
			this->_HeadList->PrevElement = nullptr;
			tempElement->PrevElement = tempSelected->PrevElement;
			tempSelected->PrevElement->NextElement = tempElement;
			tempElement->NextElement = tempSelected;
			tempSelected->PrevElement = tempElement;
		}
		else
		{
			if (tempSelected == this->_HeadList)
			{
				tempElement->PrevElement->NextElement = tempElement->NextElement;
				tempElement->NextElement->PrevElement = tempElement->PrevElement;
				tempElement->NextElement = this->_HeadList;
				tempElement->PrevElement = nullptr;
				this->_HeadList->PrevElement = tempElement;
				this->_HeadList = tempElement;
			}
			else
			{
				tempElement->PrevElement->NextElement = tempElement->NextElement;
				tempElement->NextElement->PrevElement = tempElement->PrevElement;
				tempElement->PrevElement = tempSelected->PrevElement;
				tempSelected->PrevElement->NextElement = tempElement;
				tempElement->NextElement = tempSelected;
				tempSelected->PrevElement = tempElement;
			}
		}
	}
}

void List::Sort()
{
	for (int i = 0; i < this->_CountList - 1 ; i++) 
	{
		for (int j = 0; j < this->_CountList - i - 1 ; j++)
		{
			if (this->FindElement(j)->Data > this->FindElement(j+1)->Data)
			{
				// меняем элементы местами
				this->SwapNodes(this->FindElement(j), this->FindElement(j + 1));
			}
		}
	}
}

int List::LiningSearchByIndex(int index)
{
	if (index > this->_CountList - 1 || index < 0)
	{
		throw exception("Index is not correct \n ArrayIndexOutOfBounds");
	}
	else
	{
		//Если индекс меньше индекса среднего элемента то поиск 
	//идет сначала списка
		if (index <= (this->_CountList / 2))
		{
			Node* temp = this->_HeadList;
			for (int i = 0; i < this->_CountList; i++)
			{
				if (index == i)
				{
					return temp->Data;
					break;
				}
				temp = temp->NextElement;
			}
		}
		//Иначе поиск идет с конца списка
		else
		{
			Node* temp = this->_TailList;
			for (int i = this->_CountList - 1; i > 0; i--)
			{
				if (index == i)
				{
					return temp->Data;
					break;
				}
				temp = temp->PrevElement;
			}
		}
	}
}

int List::LiningSeacrhByValue(int value)
{
	Node* temp = this->_HeadList;
	int i = 0;
	while (temp != nullptr)
	{
		if (value == temp->Data)
		{
			return i+1;
			break;
		}
		temp = temp->NextElement;
		i += 1;
	}
	return -1;
}

int List::GetCountList()
{
	return this->_CountList;
}
