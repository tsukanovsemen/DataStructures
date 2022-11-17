#pragma once
#include <iostream>
#include "List.h"

using namespace std;

class HashTable
{
public:
	/// <summary>
	/// ����������� ��� �������������
	/// </summary>
	/// <param name="capacity"> ������� ��� �������</param>
	HashTable(int capacity);

	/// <summary>
	/// ������� �������� �� �����
	/// </summary>
	/// <param name="key"> ����</param>
	/// <param name="value"> ��������</param>
	virtual void Insert(string key, string value);

	/// <summary>
	/// �������� �� �����
	/// </summary>
	/// <param name="key"> ����</param>
	void Delete(string key);

	/// <summary>
	/// ����� �� �����
	/// </summary>
	/// <param name="key"> ����</param>
	/// <returns> ��������</returns>
	string Search(string key);

	/// <summary>
	/// ������� ����������
	/// </summary>
	void ShowHashTable();

protected:
	/// <summary>
	/// ��������������� � ������ �������������� �������
	/// </summary>
	void ReHash();

	/// <summary>
	/// ���������� ��� ��������
	/// </summary>
	/// <returns> ��� ���</returns>
	int HashCode(string key);

	List** _hashTable = nullptr;
	int _Capacity = 0;
	int _Length = 0;
	const float _GROWTH_FACTOR = 1.5;

	/// <summary>
	/// �������� ��������
	/// </summary>
	/// <param name="index"> ������ ��������� �� �������</param>
	/// <returns> ���  ���� ���� ��������, ���� ���� ���</returns>
	virtual bool CollisionManager(int index);

};