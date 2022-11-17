#pragma once
#include <iostream>
#include "Stack.h"

using namespace std;

class Queue
{
public:
	/// <summary>
	/// Конструктор для инициализации членов очереди
	/// </summary>
	/// <param name="capacity"> емкость очереди</param>
	Queue(int capacity);

	/// <summary>
	/// Функция добавления в очередь
	/// </summary>
	/// <param name="data"> добавляемый элемент</param>
	void Enqueue(int data);

	/// <summary>
	/// Функция доставания из очереди
	/// </summary>
	/// <returns> ддоатсаваемый элемент</returns>
	int Dequeue();

	/// <summary>
	/// Очистка очереди
	/// </summary>
	void Clear();

	/// <summary>
	/// Выводит очередь на экран
	/// </summary>
	void ShowQueue();

	/// <summary>
	/// Возвращает кол-во элементов
	/// </summary>
	/// <returns> кол-во элементов</returns>
	int GetLength();

	~Queue();

private:
	Stack* _stack1;
	Stack* _stack2;
	/// <summary>
	/// Для вывода на экран
	/// </summary>
	int _Capacity;
	int _Length;
	float const _GrowthFactor = 1.5;
};