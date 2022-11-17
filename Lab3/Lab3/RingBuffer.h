#pragma once
#include <iostream>
#include "List.h"

using namespace std;

class RingBuffer
{
public:
	/// <summary>
	/// ������������� �������
	/// </summary>
	/// <param name="capacity"> ������� �������</param>
	RingBuffer(int capacity);

	/// <summary>
	/// ���������� ��������� �����
	/// </summary>
	/// <returns> ���-�� ���������� �����</returns>
	int GetFreePlace();

	/// <summary>
	/// ������� �����
	/// </summary>
	/// <returns> ���-�� �������� �����</returns>
	int GetBusyPlace();

	/// <summary>
	/// ��������� ������ � ������ 
	/// </summary>
	/// <param name="data"> �������� ��������</param>
	void Push(int data);

	/// <summary>
	/// ��������� ������� �� �������(������ ����������� (FIFO)) 
	/// </summary>
	/// <returns> ����������� �������</returns>
	int Pop();

	/// <summary>
	/// ��������� ������� �� ������
	/// </summary>
	/// <returns> ��/���(���/����))</returns>
	bool isFulling();

	/// <summary>
	/// ��������� ������ �� ������</summary>
	/// <returns> true/false</returns>
	bool isEmpty();

	/// <summary>
	/// ������� ��������� ������
	/// </summary>
	void ShowBuffer();

	/// <summary>
	/// ���������� ��������� ����������� ������� � ������
	/// </summary>
	/// <returns> ��������� ����������� �������</returns>
	List::Node* GetTop();

	/// <summary>
	/// ���������� ������ ����������� ������� � ������
	/// </summary>
	/// <returns>������ ����������� �������</returns>
	List::Node* GetHead();

	/// <summary>
	/// ������� ��������� ������
	/// </summary>
	void ClearBuffer();

	~RingBuffer();

private:
	List* _ringBuffer;
	int _Capacity;
	int _Length;
	List::Node* _Top;
	bool _isFirstElementReady = false;
};