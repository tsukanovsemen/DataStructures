#pragma once
#include <iostream>
#include <random>

using namespace std;

struct TreapNode
{
	//Ключ узла
	int Key;
	//Указатель на левый элемент узла
	TreapNode* Left;
	//Указатель на правый элемент узла
	TreapNode* Right;
	//Приоритет узла
	int Priority;
	TreapNode(int key, TreapNode* left, TreapNode* right, int priority) : Key(key),
		Left(left), Right(right), Priority(priority) {}
};

class Treap
{
private:
	//Корень дерева
	TreapNode* _root;
	//Глубина дерева
	int _depth;

	/// <summary>
	/// Слияние двух деревьев
	/// </summary>
	/// <param name="leftTree"> левое дерево (leftkey меньше rigth key )</param>
	/// <param name="rightTree"> правое дерево (rightkey больше leftkey)</param>
	/// <returns> указатель на корень</returns>
	TreapNode* Merge(TreapNode* leftTree, TreapNode* rightTree);

	/// <summary>
	/// Разделение на два дерева по ключу
	/// </summary>
	/// <param name="root"> корень дерева</param>
	/// <param name="key"> ключ, по которому идет разделение</param>
	/// <param name="leftTree"> левое дерево</param>
	/// <param name="rightTree"> правое дерево</param>
	void Split(TreapNode* root, int key, TreapNode*& leftTree, TreapNode*& rightTree);

	/// <summary>
	/// Ищет указатель с меньшем приоритетом чем заданный, нужен для опт-ой функции
	/// </summary>
	/// <param name="root"></param>
	/// <param name="priority"></param>
	/// <returns></returns>
	TreapNode** FindLessPriorityNode(TreapNode** root, int priority);

public:
	/// <summary>
	///Не оптимизированная вставка 1 сплит, 2 мерж
	/// </summary>
	/// <param name="key"> ключ</param>
	void InsertNotOptimized(int key);

	/// <summary>
	/// Поиск элемента
	/// </summary>
	/// <param name="key"> ключ по которому идет поиск</param>
	/// <param name="root"> корень дерева</param>
	/// <returns> указатель на элемент с данным ключом</returns>
	TreapNode* Find(int key, TreapNode* root);

	/// <summary>
	/// Неоптимизированное удаление элемента
	/// </summary>
	/// <param name="key"></param>
	void EraseNotOptimized(int key);

	/// <summary>
	/// Оптимизированная вставка
	/// </summary>
	/// <param name="key"> ключ</param>
	void InsertOptimized(int key);

	/// <summary>
	///Оптимизированное удаление
	/// </summary>
	void EraseOptimized(int key);

	/// <summary>
	/// Ищет указатель на узел с данным ключем
	/// </summary>
	TreapNode** FindPointerToNode(int key, TreapNode** root);

	/// <summary>
	/// Возвращает корень дерева
	/// </summary>
	/// <returns> корень</returns>
	TreapNode* GetRoot()
	{
		return _root;
	}
};