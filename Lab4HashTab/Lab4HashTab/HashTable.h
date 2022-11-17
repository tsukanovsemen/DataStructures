#pragma once
#include <iostream>
#include "List.h"

using namespace std;

class HashTable
{
public:
	/// <summary>
	/// Конструктор для инициализации
	/// </summary>
	/// <param name="capacity"> ёмкость хэш таблицы</param>
	HashTable(int capacity);

	/// <summary>
	/// Вставка элемента по ключу
	/// </summary>
	/// <param name="key"> ключ</param>
	/// <param name="value"> значение</param>
	virtual void Insert(string key, string value);

	/// <summary>
	/// Удаление по ключу
	/// </summary>
	/// <param name="key"> ключ</param>
	void Delete(string key);

	/// <summary>
	/// Поиск по ключу
	/// </summary>
	/// <param name="key"> ключ</param>
	/// <returns> значение</returns>
	string Search(string key);

	/// <summary>
	/// Выводит хэштаблицу
	/// </summary>
	void ShowHashTable();

protected:
	/// <summary>
	/// Перехэширование в случае перезаполнения буффера
	/// </summary>
	void ReHash();

	/// <summary>
	/// Нахождение хэш значения
	/// </summary>
	/// <returns> хэш код</returns>
	int HashCode(string key);

	List** _hashTable = nullptr;
	int _Capacity = 0;
	int _Length = 0;
	const float _GROWTH_FACTOR = 1.5;

	/// <summary>
	/// Проверка коллизии
	/// </summary>
	/// <param name="index"> индекс найденный по хэшкоду</param>
	/// <returns> тру  елси есть коллизия, фолс если нет</returns>
	virtual bool CollisionManager(int index);

};