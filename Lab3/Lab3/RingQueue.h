#pragma once
#include <iostream>
#include "List.h"

class RingQueue
{
public:
	/// <summary>
	/// ����������� ��� ������������� ����� 
	/// </summary>
	/// <param name="capacity"> �������</param>
	RingQueue(int capacity);

	/// <summary>
	/// ������� ���������� ��������� �����
	/// </summary>
	/// <returns></returns>
	int GetFreePlace();

	/// <summary>
	/// ������� ���������� ������� �����
	/// </summary>
	/// <returns></returns>
	int GetBusyPlace();

	/// <summary>
	/// ��������� ������� � ������
	/// </summary>
	/// <param name="data"> ����������� �������</param>
	void Enqueue(int data);

	/// <summary>
	/// ��������� ������ �� ������ ��� ���
	/// </summary>
	/// <returns> ��� �� ����</returns>
	bool isEmpty();

	/// <summary>
	/// ��������� ��������� �������� �� ������
	/// </summary>
	/// <returns> ��� �� ����</returns>
	bool isFulling();

	/// <summary>
	/// ������� ������� � ������ ��� � ����� �������
	/// </summary>
	/// <returns> �������</returns>
	int Dequeue();

	/// <summary>
	/// ������� �������� ������� �� �����
	/// </summary>
	void ShowRing();

	/// <summary>
	/// ������� ������
	/// </summary>
	void Clear();

	~RingQueue();

private:
	List* _RingQueue = nullptr;
	int _Capacity;
	int _Length;
	float const _GrowthFactor = 1.5;
	bool _IsFirstElementReady = false;
	List::Node* _Top = nullptr;

	/// <summary>
	/// ��� ������������ �������, ����������� ��� �������.
	/// </summary>
	void Resize();
};