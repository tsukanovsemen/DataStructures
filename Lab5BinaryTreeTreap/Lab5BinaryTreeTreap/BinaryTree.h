#pragma once
#include <iostream>

using namespace std;

//	�������� ������
struct Node
{
	//��������� �� ������������ ������� ���� ������
	Node* Parent;
	//��������� �� ������������ 
	Node* Left;
	//��������� �� ������ �������
	Node* Right;
	//���� ����
	int Key;
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	/// <summary>
	/// ��������� �������� � ������
	/// </summary>
	/// <param name="key"> ����</param>
	/// <param name="subgraph"> ��������� �� ������������ ����</param>
	void Insert(int key, Node* subgraph);

	/// <summary>
	/// ������� ������� ������
	/// </summary>
	/// <param name="key"> �������� ��������</param>
	void Remove(int key);

	/// <summary>
	/// ����� �������� ������
	/// </summary>
	/// <param name="key"> �������� ��������</param>
	/// <param name="subgraph"> ������� � �������� ���� �����</param>
	/// <returns></returns>
	Node* Find(int key, Node* subgraph);

	/// <summary>
	/// ����� ����������� �������� ������
	/// </summary>
	/// <param name="subgraph"> ������� � ������� ���� �����</param>
	/// <returns> ��������� �� ������� � ����������� ���������</returns>
	Node* FindMinimum(Node* subgraph);

	/// <summary>
	/// ����� ������������� ��������
	/// </summary>
	/// <param name="subgraph"> ������� � ������� ���� �����</param>
	/// <returns> ��������� �� ������������ ������� ������</returns>
	Node* FindMaximum(Node* subgraph);

	/// <summary>
	/// ���������� ��������� �� ������ ������
	/// </summary>
	/// <returns> ��������� �� ������ ������</returns>
	Node* GetRoot();

	/// <summary>
	/// ���������� ������� ������
	/// </summary>
	/// <returns> ������� ������</returns>
	int GetDepth();

private:
	Node* _root;
	int _depth;
	/// <summary>
	/// ���������� ������� ������
	/// </summary>
	/// <param name="root"> ������ ������</param>
	/// <param name="countDepth"> ������� �������</param>
	void UpdateDepth(Node* root, int countDepth);
};