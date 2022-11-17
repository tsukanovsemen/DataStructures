#include "HashTable.h"

HashTable::HashTable(int capacity)
{
	this->_hashTable = new List * [capacity];
	for (int i = 0; i < capacity; i++)
	{
		this->_hashTable[i] = new List();
	}

	this->_Capacity = capacity;
}

void HashTable::Insert(string key, string value)
{
	int index = this->HashCode(key);
	if (!this->CollisionManager(index))
	{
		this->_Length += 1;
		this->ReHash();
	}
	this->_hashTable[index]->AddElement(key, value);
}

void HashTable::Delete(string key)
{
	int index = this->HashCode(key);
	this->_hashTable[index]->DeleteElemByValue(key);
	if (!this->CollisionManager(index))
	{
		this->_Length -= 1;
	}
}

string HashTable::Search(string key)
{
	int index = this->HashCode(key);
	if (this->_hashTable[index]->LiningSeacrhByValue(key) == " ")
	{
		return "No value with this key";
	}
	else
	{
		return this->_hashTable[index]->LiningSeacrhByValue(key);
	}
}

void HashTable::ShowHashTable()
{
	for (int i = 0; i < this->_Capacity; i++)
	{
		if (this->_hashTable[i] == nullptr)
		{
			continue;
		}
		else
		{
			cout << endl << " [" << i << "]";
			Node* temp = this->_hashTable[i]->GetHead();
			for (int k = 0; k < this->_hashTable[i]->GetCountList(); k++)
			{
				cout << " key: " << temp->Key << ", value: " << temp->Data <<" ;";
				temp = temp->NextElement;
			}
		}
	}
}

void HashTable::ReHash()
{
	if (this->_Length == this->_Capacity)
	{
		int Lastcapacity = this->_Capacity;
		int newCapacity = this->_Capacity * this->_GROWTH_FACTOR;
		this->_Capacity = newCapacity;
		List** tempHashTable = new List * [newCapacity];
		for (int j = 0; j < newCapacity; j++)
		{
			tempHashTable[j] = new List();
		}

		int newLength = 0;
		for (int i = 0; i < Lastcapacity; i++)
		{
			Node* tempNode = this->_hashTable[i]->GetHead();
			while (tempNode != nullptr)
			{
				int index = this->HashCode(tempNode->Key);
				if (tempHashTable[index]->GetHead() == nullptr)
				{
					newLength += 1;
				}
				tempHashTable[index]->AddElement(tempNode->Key,tempNode->Data);
				tempNode = tempNode->NextElement;
			}
		}
		delete* this->_hashTable;
		this->_hashTable = tempHashTable;
		this->_Length = newLength;
	}
}

int HashTable::HashCode(string key)
{
	int hash = 0;
	for (int i = 0; i < key.length(); i++)
	{
		hash = (hash * (this->_Capacity - 1) + key[i]) % this->_Capacity;
	}
	return hash;
}

bool HashTable::CollisionManager(int index)
{
	if (this->_hashTable[index]->GetHead() == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}