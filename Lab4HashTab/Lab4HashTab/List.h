#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

/// <summary>
/// ��������� ������, 
/// � ������������ ���������������� �������� ���������
/// </summary>
class List
{
private:
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
	Node* FindElementData(string data);

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
	List(int count, string key, string* array);

	Node* GetHead();

	/// <summary>
	/// ���������� ��������� (�� ��������� � ����� ������)
	/// </summary>
	/// <param name="data"> ����������� �������</param>
	void AddElement(string key, string data);

	/// <summary>
	/// ���������� �������� �� ������������ �������
	/// </summary>
	/// <param name="data">�������� ������������ ��������</param>
	/// <param name="index">������� ������� ��������</param>
	void AddElemByIndex(string key, string data, int index);

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
	/// <param name="value"> ��������</param>
	void DeleteElemByValue(string value);

	/// <summary>
	/// ������� � ������
	/// </summary>
	/// <param name="indexElement"> ��������
	/// ������������ ��������</param>
	void InsertInStart(string data);

	/// <summary>
	/// ������� � �����
	/// </summary>
	/// <param name="indexEelememt"> ������ 
	/// ������������ ��������</param>
	void InsertInEnd(string data);

	/// <summary>
	/// ������� ����� ������������ ��������
	/// </summary>
	/// <param name="indexElement"> ������ 
	/// ������������ ��������</param>
	/// <param name="indexSelectedElem"> ������ �������� 
	/// ����� �������� ���� �������</param>
	void InsertAfterSelectedElem(string data, string selectedElem);

	/// <summary>
	/// ������� ����� ��������� ���������
	/// </summary>
	/// <param name="indexElement">������ 
	/// ������������ ��������</param>
	/// <param name="indexSelectedElem">������ ��������
	///  ����� ������� ���� �������</param>
	void InsertBeforeSelectedElem(string data, string selectedData);

	/// <summary>
	/// ���������� ������
	/// </summary>
	void Sort();

	/// <summary>
	/// ����� �������� �� �������
	/// </summary>
	/// <param name="index"> ������ ��������</param>
	/// <returns> �������� </returns>
	string LiningSearchByIndex(int index);

	/// <summary>
	/// ����� �� ��������
	/// </summary>
	/// <param name="value"> �������� ��������</param>
	/// <returns> ������</returns>
	string LiningSeacrhByValue(string value);

	/// <summary>
	/// ���������� ���-�� ���������
	/// </summary>
	/// <returns> ����������� ��������� ������</returns>
	int GetCountList();
}; 
