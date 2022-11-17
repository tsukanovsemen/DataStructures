#include "List.h"
Node* List::FindElement(int index)
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

Node* List::FindElementData(string data)
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

List::List(int count, string key, string* array)
{
	Node* temp = new Node(nullptr, nullptr, key, array[0]);
	this->_HeadList = temp;
	for (int i = 1; i < count; i++)
	{
		temp->NextElement = new Node(temp, nullptr, key, array[i]);
		this->_TailList = temp->NextElement;
		temp = temp->NextElement;
	}
	this->_CountList = count;
}

Node* List::GetHead()
{
	return this->_HeadList;
}

void List::AddElement(string key, string data)
{
	Node* temp = new Node(this->_TailList, nullptr, key, data);

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

void List::AddElemByIndex(string key, string data, int index)
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
						Node* newElem = new Node(nullptr, temp, key, data);
						temp->PrevElement = newElem;
						this->_HeadList = newElem;
						this->_CountList += 1;
						break;
					}
					else
					{
						Node* newElem = new Node(temp->PrevElement, temp, key, data);
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
						Node* newElem = new Node(temp->PrevElement, temp, key, data);
						temp->PrevElement->NextElement = newElem;
						temp->PrevElement = newElem;
						this->_CountList += 1;
						break;
					}
					else
					{
						Node* newElem = new Node(temp->PrevElement, temp, key, data);
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
	Node* temp = this->_TailList;
	temp = this->_TailList->PrevElement;
	delete _TailList;
	this->_TailList = temp;
	this->_TailList->NextElement = nullptr;
	this->_CountList -= 1;
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
						temp->NextElement = nullptr;
						temp->PrevElement = nullptr;
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

void List::DeleteElemByValue(string value)
{
	Node* temp = this->_HeadList;
	while (temp != nullptr)
	{
		if (value == temp->Key)
		{
			if (temp == this->_HeadList)
			{
				if (this->_HeadList != nullptr)
				{
					if (_HeadList->NextElement != nullptr)
					{
						this->_HeadList->NextElement->PrevElement = nullptr;
						_HeadList = _HeadList->NextElement;
					}
					delete temp;
					this->_CountList -= 1;
					break;
				}
				else
				{
					this->_CountList -= 1;
				}
			}
			else if (temp == this->_TailList)
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
		temp = temp->NextElement;
	}
}

void List::InsertInStart(string data)
{
	Node* temp = this->FindElementData(data);
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
		else
		{
			temp->PrevElement->NextElement = temp->NextElement;
			temp->NextElement->PrevElement = temp->PrevElement;
			temp->NextElement = this->_HeadList;
			temp->PrevElement = nullptr;
			this->_HeadList->PrevElement = temp;
			this->_HeadList = temp;
		}
	}
}

void List::InsertInEnd(string data)
{
	Node* temp = this->FindElementData(data);
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
		else
		{
			temp->PrevElement->NextElement = temp->NextElement;
			temp->NextElement->PrevElement = temp->PrevElement;
			this->_TailList->NextElement = temp;
			temp->NextElement = nullptr;
			temp->PrevElement = this->_TailList;
			this->_TailList = temp;
		}
	}
}

void List::InsertAfterSelectedElem(string data, string selectedData)
{
	//tempElem - элемент который перставляем
	Node* tempElement = this->FindElementData(data);
	//tempSelected - элемент после которого вставляем
	Node* tempSelected = this->FindElementData(selectedData);
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

void List::InsertBeforeSelectedElem(string data, string selectedData)
{
	Node* tempElement = this->FindElementData(data);
	Node* tempSelected = this->FindElementData(selectedData);

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
	for (int i = 0; i < this->_CountList - 1; i++)
	{
		for (int j = 0; j < this->_CountList - i - 1; j++)
		{
			if (this->FindElement(j)->Data > this->FindElement(j + 1)->Data)
			{
				// меняем элементы местами
				this->SwapNodes(this->FindElement(j), this->FindElement(j + 1));
			}
		}
	}
}

string List::LiningSearchByIndex(int index)
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

string List::LiningSeacrhByValue(string value)
{
	Node* temp = this->_HeadList;
	int i = 0;
	while (temp != nullptr)
	{
		if (value == temp->Key)
		{
			return temp->Data;
			break;
		}
		temp = temp->NextElement;
		i += 1;
	}
	return " ";
}

int List::GetCountList()
{
	return this->_CountList;
}