#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Node
{
	/// <summary>
	/// Конструктор инициализирующий узел списка
	/// </summary>
	/// <param name="prev"> указатель
	///  на предыдущий элемент</param>
	/// <param name="next"> указатель
	///  на следующий элемент</param>
	/// <param name="data"> данные узла</param>
	Node(Node* prev, Node* next, string key, string data);
	/// <summary>
	/// указатель на следующий элемент
	/// </summary>
	Node* NextElement = nullptr;
	/// <summary>
	/// указатель на предыдущий элемент
	/// </summary>
	Node* PrevElement = nullptr;

	string Data;

	string Key;
};