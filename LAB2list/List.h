#pragma once
#include <iostream>

using namespace std;

/// <summary>
/// ��������� ������, 
/// � ������������ ���������������� �������� ���������
/// </summary>
class List
{
private:
/// <summary>
/// ��������� ���� ������ � ������ ���������� 
/// � ����������� �������� � �������� ������
/// </summary>
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
		Node(Node* prev, Node* next, int data);
		/// <summary>
		/// ��������� �� ��������� �������
		/// </summary>
		Node* NextElement = nullptr;
		/// <summary>
		/// ��������� �� ���������� �������
		/// </summary>
		Node* PrevElement = nullptr;
		/// <summary>
		/// ������ ����
		/// </summary>
		int Data;
	};
	/// <summary>
	/// ������� ��������� ������
	/// </summary>
	int _CountList = 0;
	/// <summary>
	/// ��������� �� ������
	/// </summary>
	Node* _HeadList = nullptr;
	/// <summary>
	/// ��������� �� �����
	/// </summary>
	Node* _TailList = nullptr;

	/// <summary>
	/// ����� �������� �� �������
	/// </summary>
	/// <param name="index"> ������ ��������</param>
	/// <returns> ��������� �� ���� ������</returns>
	Node* FindElement(int index);

	/// <summary>
	/// ����� ������� �� ������
	/// </summary>
	/// <param name="data"> ������</param>
	/// <returns> ��������� �� ������ �������</returns>
	Node* FindElementByData(int data);

	/// <summary>
	/// ������ ���� �������
	/// </summary>
	/// <param name="elem1">������ �������</param>
	/// <param name="elem2">������ �������</param>
	void SwapNodes(Node* elem1, Node* elem2);

public:
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	List();

	/// <summary>
	/// ����������� ��� ������������� ������
	/// �� ������ ������������� �������
	/// </summary>
	/// <param name="count"> ����������� 
	/// ��������� �������</param>
	/// <param name="array"> ������</param>
	List(int count, int* array);

	/// <summary>
	/// ���������� ��������� (�� ��������� � ����� ������)
	/// </summary>
	/// <param name="data"> ����������� �������</param>
	void AddElement(int data);

	/// <summary>
	/// ���������� �������� �� ������������ �������
	/// </summary>
	/// <param name="data">�������� ������������ ��������</param>
	/// <param name="index">������� ������� ��������</param>
	void AddElemByIndex(int data,int index);

	/// <summary>
	/// �������� ���������� ������������ ��������
	/// </summary>
	void DeleteElement();

	/// <summary>
	/// �������� �������� �� �������
	/// </summary>
	/// <param name="index"> ������ ��������</param>
	void DeleteElemByIndex(int index);

	/// <summary>
	/// �������� �������� �� ��������
	/// </summary>
	/// <param name="value">��������</param>
	/// <returns>0 ���� ����� ����� �������, -1 ���� ������ ��� �� ������</returns>
	int DeleteElemByValue(int value);

	/// <summary>
	/// ������� � ������
	/// </summary>
	/// <param name="data"> ��������</param>
	void InsertInStart(int data);

	/// <summary>
	/// ������� � �����
	/// </summary>
	/// <param name="data"> ��������</param>
	void InsertInEnd(int data);

	/// <summary>
	/// ������� ����� ������������ ��������
	/// </summary>
	/// <param name="indexElement"> ������ 
	/// ������������ ��������</param>
	/// <param name="indexSelectedElem"> ������ �������� 
	/// ����� �������� ���� �������</param>
	void InsertAfterSelectedElem(int data, int selectedElem);

	/// <summary>
	/// ������� ����� ��������� ���������
	/// </summary>
	/// <param name="indexElement">������ 
	/// ������������ ��������</param>
	/// <param name="indexSelectedElem">������ ��������
	///  ����� ������� ���� �������</param>
	void InsertBeforeSelectedElem(int data, int selectedData);

	/// <summary>
	/// ���������� ������
	/// </summary>
	void Sort();

	/// <summary>
	/// ����� �������� �� �������
	/// </summary>
	/// <param name="index"> ������ ��������</param>
	/// <returns> �������� </returns>
	int LiningSearchByIndex(int index);

	/// <summary>
	/// ����� �� ��������
	/// </summary>
	/// <param name="value"> �������� ��������</param>
	/// <returns> ������</returns>
	int LiningSeacrhByValue(int value);

	/// <summary>
	/// ���������� ���-�� ���������
	/// </summary>
	/// <returns> ����������� ��������� ������</returns>
	int GetCountList();
};