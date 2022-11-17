#pragma once
#include <iostream>
#include "List.h"

using namespace std;

class Stack
{
public:
	/// <summary>
	/// Конструктор для создания стека
	/// </summary>
	/// <param name="capacity"> емкость стека</param>
	Stack(int capacity);

	/// <summary>
	/// Добавление элемента стека(в конец стопки)
	/// </summary>
	/// <param name="data"> элемент</param>
	void Push(int data);

	/// <summary>
	/// Извлечение из стека
	/// </summary>
	/// <returns> извлеченный элемент</returns>
	int Pop();

	/// <summary>
	/// Удаление стека
	/// </summary>
	void DeleteStack();

	/// <summary>
	/// Вывести стек
	/// </summary>
	void ShowStack();

	/// <summary>
	/// Выводит сетк с верхушки
	/// </summary>
	void ReverseShowStack();

	/// <summary>
	/// Емкость стека
	/// </summary>
	/// <returns>ёмкость</returns>
	int GetCapacity();

	/// <summary>
	/// Размер стека
	/// </summary>
	/// <returns> размер</returns>
	int GetLength();

	~Stack();
private:
	List* _Stack = new List();
	List::Node* _Top = nullptr;
	int _Capacity;
	const float _GrowthFactor = 1.5;
	int _Length;
	bool _isFirstElementReady = false;

	/// <summary>
	/// Функция изменения размера стека при его переполнении
	/// </summary>
	void Resize();
};
