#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

/// <summary>
/// Двусязный список, 
/// с возможностью двунаправленного перебора элементов
/// </summary>
class List
{
private:
	/// <summary>
	/// Счетчик элементов списка
	/// </summary>
	int _CountList = 0;
	/// <summary>
	/// указатель на голову
	/// </summary>
	Node* _HeadList = nullptr;
	/// <summary>
	/// указатель на хвост
	/// </summary>
	Node* _TailList = nullptr;

	/// <summary>
	/// Поиск элемента по индексу
	/// </summary>
	/// <param name="index"> индекс элемента</param>
	/// <returns> указатель на узел списка</returns>
	Node* FindElement(int index);

	/// <summary>
	/// Поиск элмента по данным
	/// </summary>
	/// <param name="data"> данные</param>
	/// <returns> указатель на данный элемент</returns>
	Node* FindElementData(string data);

	/// <summary>
	/// Меняет узлы местами
	/// </summary>
	/// <param name="elem1">первый элемент</param>
	/// <param name="elem2">второй элемент</param>
	void SwapNodes(Node* elem1, Node* elem2);

public:
	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	List();

	/// <summary>
	/// Конструктор для инициализации списка
	/// на основе существующего массива
	/// </summary>
	/// <param name="count"> колличесвто 
	/// элементов массива</param>
	/// <param name="array"> массив</param>
	List(int count, string key, string* array);

	Node* GetHead();

	/// <summary>
	/// Добавление элементов (по умолчанию в конец списка)
	/// </summary>
	/// <param name="data"> Добавляемый элемент</param>
	void AddElement(string key, string data);

	/// <summary>
	/// Добавление элемента по определнному индексу
	/// </summary>
	/// <param name="data">Значение добавляемого элемента</param>
	/// <param name="index">позиция данного элемента</param>
	void AddElemByIndex(string key, string data, int index);

	/// <summary>
	/// Удаление последнего добавленного элемента
	/// </summary>
	void DeleteElement();

	/// <summary>
	/// Удаление элемента по индексу
	/// </summary>
	/// <param name="index"> индекс элемента</param>
	void DeleteElemByIndex(int index);

	/// <summary>
	/// Удаление элемента по значению
	/// </summary>
	/// <param name="value"> значение</param>
	void DeleteElemByValue(string value);

	/// <summary>
	/// Вставка в начало
	/// </summary>
	/// <param name="indexElement"> значение
	/// вставляемого элемента</param>
	void InsertInStart(string data);

	/// <summary>
	/// Вставка в конец
	/// </summary>
	/// <param name="indexEelememt"> индекс 
	/// вставляемого элемента</param>
	void InsertInEnd(string data);

	/// <summary>
	/// Вставка после определнного элемента
	/// </summary>
	/// <param name="indexElement"> индекс 
	/// вставляемого элемента</param>
	/// <param name="indexSelectedElem"> индекс элемента 
	/// после которого идет вставка</param>
	void InsertAfterSelectedElem(string data, string selectedElem);

	/// <summary>
	/// Вставка перед выбранным элементом
	/// </summary>
	/// <param name="indexElement">индекс 
	/// вставляемого элемента</param>
	/// <param name="indexSelectedElem">индекс элемента
	///  перед которым идет вставка</param>
	void InsertBeforeSelectedElem(string data, string selectedData);

	/// <summary>
	/// Сортировка списка
	/// </summary>
	void Sort();

	/// <summary>
	/// Поиск элемента по индексу
	/// </summary>
	/// <param name="index"> индекс элемента</param>
	/// <returns> значение </returns>
	string LiningSearchByIndex(int index);

	/// <summary>
	/// Поиск по значению
	/// </summary>
	/// <param name="value"> значение элемента</param>
	/// <returns> индекс</returns>
	string LiningSeacrhByValue(string value);

	/// <summary>
	/// Возвращает кол-во элементов
	/// </summary>
	/// <returns> колличесвто элементов списка</returns>
	int GetCountList();
}; 
