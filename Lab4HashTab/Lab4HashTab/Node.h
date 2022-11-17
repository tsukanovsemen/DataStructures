#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Node
{
	/// <summary>
	/// ����������� ���������������� ���� ������
	/// </summary>
	/// <param name="prev"> ���������
	///  �� ���������� �������</param>
	/// <param name="next"> ���������
	///  �� ��������� �������</param>
	/// <param name="data"> ������ ����</param>
	Node(Node* prev, Node* next, string key, string data);
	/// <summary>
	/// ��������� �� ��������� �������
	/// </summary>
	Node* NextElement = nullptr;
	/// <summary>
	/// ��������� �� ���������� �������
	/// </summary>
	Node* PrevElement = nullptr;

	string Data;

	string Key;
};