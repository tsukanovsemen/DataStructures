#pragma once
#include <iostream>
#include "List.h"

using namespace std;

class Stack
{
public:
	/// <summary>
	/// ����������� ��� �������� �����
	/// </summary>
	/// <param name="capacity"> ������� �����</param>
	Stack(int capacity);

	/// <summary>
	/// ���������� �������� �����(� ����� ������)
	/// </summary>
	/// <param name="data"> �������</param>
	void Push(int data);

	/// <summary>
	/// ���������� �� �����
	/// </summary>
	/// <returns> ����������� �������</returns>
	int Pop();

	/// <summary>
	/// �������� �����
	/// </summary>
	void DeleteStack();

	/// <summary>
	/// ������� ����
	/// </summary>
	void ShowStack();

	/// <summary>
	/// ������� ���� � ��������
	/// </summary>
	void ReverseShowStack();

	/// <summary>
	/// ������� �����
	/// </summary>
	/// <returns>�������</returns>
	int GetCapacity();

	/// <summary>
	/// ������ �����
	/// </summary>
	/// <returns> ������</returns>
	int GetLength();

	~Stack();
private:
	List* _Stack = new List();
	List::Node* _Top = nullptr;
	int _Capacity;
	const float _GrowthFactor = 1.5;
	int _Length;
	bool _isFirstElementReady = false;

	/// <summary>
	/// ������� ��������� ������� ����� ��� ��� ������������
	/// </summary>
	void Resize();
};
