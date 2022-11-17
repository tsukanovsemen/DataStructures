#pragma once
#include <iostream>
#include "List.h"

using namespace std;

class RingBuffer
{
public:
	/// <summary>
	/// Инициализация буффера
	/// </summary>
	/// <param name="capacity"> емкость буффера</param>
	RingBuffer(int capacity);

	/// <summary>
	/// Возвращает свободное место
	/// </summary>
	/// <returns> кол-во свободного места</returns>
	int GetFreePlace();

	/// <summary>
	/// Занятое место
	/// </summary>
	/// <returns> кол-во занятого места</returns>
	int GetBusyPlace();

	/// <summary>
	/// Добавляет элмент в буффер 
	/// </summary>
	/// <param name="data"> значение элемента</param>
	void Push(int data);

	/// <summary>
	/// Извлекает элемент из буффера(первый добавленный (FIFO)) 
	/// </summary>
	/// <returns> Извлеченный элемент</returns>
	int Pop();

	/// <summary>
	/// Првоеряет заполен ли буффер
	/// </summary>
	/// <returns> да/нет(тру/фолс))</returns>
	bool isFulling();

	/// <summary>
	/// Проверяет пустой ли буффер</summary>
	/// <returns> true/false</returns>
	bool isEmpty();

	/// <summary>
	/// Выводит кольцевой буффер
	/// </summary>
	void ShowBuffer();

	/// <summary>
	/// Возвращает последний добавленный элемент в буффер
	/// </summary>
	/// <returns> последний добавленный элемент</returns>
	List::Node* GetTop();

	/// <summary>
	/// Возвращает первый добавленный элемент в буффер
	/// </summary>
	/// <returns>первый добавленный элемент</returns>
	List::Node* GetHead();

	/// <summary>
	/// Очищает кольцевой буффер
	/// </summary>
	void ClearBuffer();

	~RingBuffer();

private:
	List* _ringBuffer;
	int _Capacity;
	int _Length;
	List::Node* _Top;
	bool _isFirstElementReady = false;
};