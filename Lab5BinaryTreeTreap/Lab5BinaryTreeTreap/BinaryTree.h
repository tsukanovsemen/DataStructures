#pragma once
#include <iostream>

using namespace std;

//	Бинарное дерево
struct Node
{
	//Указатель на родительский элемент узла дерева
	Node* Parent;
	//Указатель на левыйэлемент 
	Node* Left;
	//Указатель на правый элемент
	Node* Right;
	//Ключ узла
	int Key;
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	/// <summary>
	/// Добавляет значение в дерево
	/// </summary>
	/// <param name="key"> ключ</param>
	/// <param name="subgraph"> Указатель на родительский узел</param>
	void Insert(int key, Node* subgraph);

	/// <summary>
	/// Удаляет элемент дерева
	/// </summary>
	/// <param name="key"> значение элемента</param>
	void Remove(int key);

	/// <summary>
	/// Поиск элемента дерева
	/// </summary>
	/// <param name="key"> значение элемента</param>
	/// <param name="subgraph"> подграф с которого идет поиск</param>
	/// <returns></returns>
	Node* Find(int key, Node* subgraph);

	/// <summary>
	/// Поиск минимальнго значения дерева
	/// </summary>
	/// <param name="subgraph"> подграф в котором идет поиск</param>
	/// <returns> указатель на элемент с минимальным значением</returns>
	Node* FindMinimum(Node* subgraph);

	/// <summary>
	/// Поиск максимального значения
	/// </summary>
	/// <param name="subgraph"> подграф в котором идет поиск</param>
	/// <returns> указатель на максимальный элемент дерева</returns>
	Node* FindMaximum(Node* subgraph);

	/// <summary>
	/// Возвращает указатель на корень дерева
	/// </summary>
	/// <returns> указатель на корень дерева</returns>
	Node* GetRoot();

	/// <summary>
	/// Возвращает глубину дерева
	/// </summary>
	/// <returns> гулбина дерева</returns>
	int GetDepth();

private:
	Node* _root;
	int _depth;
	/// <summary>
	/// Обновление глубины дерева
	/// </summary>
	/// <param name="root"> корень дерева</param>
	/// <param name="countDepth"> счетчик глубины</param>
	void UpdateDepth(Node* root, int countDepth);
};