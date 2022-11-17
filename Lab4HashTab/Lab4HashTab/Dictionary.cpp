#include "Dictionary.h"

Dictionary::Dictionary(int capacity): HashTable(capacity)
{

}

void Dictionary::Insert(string key, string value)
{
	int index = this->HashCode(key);
	if (this->CollisionManager(index, key, value))
	{
		cout << "Element with this key \""<< key <<"\" already exists";
	}
	else
	{
		if (this->_hashTable[index]->GetHead() == nullptr)
		{
			this->_Length += 1;
			this->ReHash();
		}
		this->_hashTable[index]->AddElement(key, value);
	}
}

bool Dictionary::CollisionManager(int index, string key, string value)
{
	if (this->_hashTable[index]->GetHead() == nullptr)
	{
		return false;
	}
	else
	{
		Node* temp = this->_hashTable[index]->GetHead();
		while (temp != nullptr)
		{
			if (temp->Key == key ) //&& temp->Data == value
			{
				return true;
			}
			temp = temp->NextElement;
		}
		return false;
	}
}
