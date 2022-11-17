#pragma once
#include <iostream>
#include "List.h"

class RingQueue
{
public:
	/// <summary>
	/// Конструктор для инициализации полей 
	/// </summary>
	/// <param name="capacity"> емкость</param>
	RingQueue(int capacity);

	/// <summary>
	/// Функция возвращает свободное место
	/// </summary>
	/// <returns></returns>
	int GetFreePlace();

	/// <summary>
	/// Функция возвращает занятое место
	/// </summary>
	/// <returns></returns>
	int GetBusyPlace();

	/// <summary>
	/// Добавляет элемент в буффер
	/// </summary>
	/// <param name="data"> добавляемый элемент</param>
	void Enqueue(int data);

	/// <summary>
	/// Проверяет пустой ли буффер или нет
	/// </summary>
	/// <returns> тру ор фолс</returns>
	bool isEmpty();

	/// <summary>
	/// Проверяет полностью заполнен ли буффер
	/// </summary>
	/// <returns> тру ор фолс</returns>
	bool isFulling();

	/// <summary>
	/// Достает элемент и кладет его в конец очереди
	/// </summary>
	/// <returns> элемент</returns>
	int Dequeue();

	/// <summary>
	/// Выводит значение буффера на экран
	/// </summary>
	void ShowRing();

	/// <summary>
	/// Очищает буффер
	/// </summary>
	void Clear();

	~RingQueue();

private:
	List* _RingQueue = nullptr;
	int _Capacity;
	int _Length;
	float const _GrowthFactor = 1.5;
	bool _IsFirstElementReady = false;
	List::Node* _Top = nullptr;

	/// <summary>
	/// При переполнении буффера, увеличивает его емкость.
	/// </summary>
	void Resize();
};