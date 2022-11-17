#pragma once
#include <iostream>
#include "HashTable.h"

class Dictionary : public HashTable
{
public:
	/// <summary>
	/// ����������� �� ��������� ��� ������������� �������
	/// </summary>
	/// <param name="capacity"></param>
	Dictionary(int capacity);

	/// <summary>
	/// ������� ��������
	/// </summary>
	/// <param name="key"> ����</param>
	/// <param name="value"> ��������</param>
	void Insert(string key, string value) override;

protected:
	/// <summary>
	/// ��������� ������������� ������
	/// </summary>
	/// <param name="index"> ������ "�����"</param>
	/// <param name="key"> ����</param>
	/// <returns>true - ���� ����� ���� ��� ����, false - ���� ����</returns>
	bool CollisionManager(int index, string key, string value);
};