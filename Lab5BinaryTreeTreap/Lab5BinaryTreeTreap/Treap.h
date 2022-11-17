#pragma once
#include <iostream>
#include <random>

using namespace std;

struct TreapNode
{
	//���� ����
	int Key;
	//��������� �� ����� ������� ����
	TreapNode* Left;
	//��������� �� ������ ������� ����
	TreapNode* Right;
	//��������� ����
	int Priority;
	TreapNode(int key, TreapNode* left, TreapNode* right, int priority) : Key(key),
		Left(left), Right(right), Priority(priority) {}
};

class Treap
{
private:
	//������ ������
	TreapNode* _root;
	//������� ������
	int _depth;

	/// <summary>
	/// ������� ���� ��������
	/// </summary>
	/// <param name="leftTree"> ����� ������ (leftkey ������ rigth key )</param>
	/// <param name="rightTree"> ������ ������ (rightkey ������ leftkey)</param>
	/// <returns> ��������� �� ������</returns>
	TreapNode* Merge(TreapNode* leftTree, TreapNode* rightTree);

	/// <summary>
	/// ���������� �� ��� ������ �� �����
	/// </summary>
	/// <param name="root"> ������ ������</param>
	/// <param name="key"> ����, �� �������� ���� ����������</param>
	/// <param name="leftTree"> ����� ������</param>
	/// <param name="rightTree"> ������ ������</param>
	void Split(TreapNode* root, int key, TreapNode*& leftTree, TreapNode*& rightTree);

	/// <summary>
	/// ���� ��������� � ������� ����������� ��� ��������, ����� ��� ���-�� �������
	/// </summary>
	/// <param name="root"></param>
	/// <param name="priority"></param>
	/// <returns></returns>
	TreapNode** FindLessPriorityNode(TreapNode** root, int priority);

public:
	/// <summary>
	///�� ���������������� ������� 1 �����, 2 ����
	/// </summary>
	/// <param name="key"> ����</param>
	void InsertNotOptimized(int key);

	/// <summary>
	/// ����� ��������
	/// </summary>
	/// <param name="key"> ���� �� �������� ���� �����</param>
	/// <param name="root"> ������ ������</param>
	/// <returns> ��������� �� ������� � ������ ������</returns>
	TreapNode* Find(int key, TreapNode* root);

	/// <summary>
	/// ������������������ �������� ��������
	/// </summary>
	/// <param name="key"></param>
	void EraseNotOptimized(int key);

	/// <summary>
	/// ���������������� �������
	/// </summary>
	/// <param name="key"> ����</param>
	void InsertOptimized(int key);

	/// <summary>
	///���������������� ��������
	/// </summary>
	void EraseOptimized(int key);

	/// <summary>
	/// ���� ��������� �� ���� � ������ ������
	/// </summary>
	TreapNode** FindPointerToNode(int key, TreapNode** root);

	/// <summary>
	/// ���������� ������ ������
	/// </summary>
	/// <returns> ������</returns>
	TreapNode* GetRoot()
	{
		return _root;
	}
};