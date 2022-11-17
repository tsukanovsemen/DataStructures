#pragma once
#include <iostream>
#include "Stack.h"

using namespace std;

class Queue
{
public:
	/// <summary>
	/// ����������� ��� ������������� ������ �������
	/// </summary>
	/// <param name="capacity"> ������� �������</param>
	Queue(int capacity);

	/// <summary>
	/// ������� ���������� � �������
	/// </summary>
	/// <param name="data"> ����������� �������</param>
	void Enqueue(int data);

	/// <summary>
	/// ������� ���������� �� �������
	/// </summary>
	/// <returns> ������������� �������</returns>
	int Dequeue();

	/// <summary>
	/// ������� �������
	/// </summary>
	void Clear();

	/// <summary>
	/// ������� ������� �� �����
	/// </summary>
	void ShowQueue();

	/// <summary>
	/// ���������� ���-�� ���������
	/// </summary>
	/// <returns> ���-�� ���������</returns>
	int GetLength();

	~Queue();

private:
	Stack* _stack1;
	Stack* _stack2;
	/// <summary>
	/// ��� ������ �� �����
	/// </summary>
	int _Capacity;
	int _Length;
	float const _GrowthFactor = 1.5;
};