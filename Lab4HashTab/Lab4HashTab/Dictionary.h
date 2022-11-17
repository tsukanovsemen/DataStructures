#pragma once
#include <iostream>
#include "HashTable.h"

class Dictionary : public HashTable
{
public:
	/// <summary>
	/// Конструктор по умолчанию для инициализации словаря
	/// </summary>
	/// <param name="capacity"></param>
	Dictionary(int capacity);

	/// <summary>
	/// Вставка элемента
	/// </summary>
	/// <param name="key"> ключ</param>
	/// <param name="value"> значение</param>
	void Insert(string key, string value) override;

protected:
	/// <summary>
	/// Обработка повторяющихся ключей
	/// </summary>
	/// <param name="index"> индекс "полки"</param>
	/// <param name="key"> ключ</param>
	/// <returns>true - если такой ключ уже есть, false - если нету</returns>
	bool CollisionManager(int index, string key, string value);
};