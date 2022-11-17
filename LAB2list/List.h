#pragma once
#include <iostream>

using namespace std;

/// <summary>
/// Двусязный список, 
/// с возможностью двунаправленного перебора элементов
/// </summary>
class List
{
private:
/// <summary>
/// Структура узла списка с полями следующего 
/// и предыдущего элемента и храненим данных
/// </summary>
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
		Node(Node* prev, Node* next, int data);
		/// <summary>
		/// указатель на следующий элемент
		/// </summary>
		Node* NextElement = nullptr;
		/// <summary>
		/// указатель на предыдущий элемент
		/// </summary>
		Node* PrevElement = nullptr;
		/// <summary>
		/// данные узла
		/// </summary>
		int Data;
	};
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
	Node* FindElementByData(int data);

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
	List(int count, int* array);

	/// <summary>
	/// Добавление элементов (по умолчанию в конец списка)
	/// </summary>
	/// <param name="data"> Добавляемый элемент</param>
	void AddElement(int data);

	/// <summary>
	/// Добавление элемента по определнному индексу
	/// </summary>
	/// <param name="data">Значение добавляемого элемента</param>
	/// <param name="index">позиция данного элемента</param>
	void AddElemByIndex(int data,int index);

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
	/// <param name="value">значение</param>
	/// <returns>0 если нашел такой элемент, -1 если элмент был не найден</returns>
	int DeleteElemByValue(int value);

	/// <summary>
	/// Вставка в начало
	/// </summary>
	/// <param name="data"> значение</param>
	void InsertInStart(int data);

	/// <summary>
	/// Вставка в конец
	/// </summary>
	/// <param name="data"> значение</param>
	void InsertInEnd(int data);

	/// <summary>
	/// Вставка после определнного элемента
	/// </summary>
	/// <param name="indexElement"> индекс 
	/// вставляемого элемента</param>
	/// <param name="indexSelectedElem"> индекс элемента 
	/// после которого идет вставка</param>
	void InsertAfterSelectedElem(int data, int selectedElem);

	/// <summary>
	/// Вставка перед выбранным элементом
	/// </summary>
	/// <param name="indexElement">индекс 
	/// вставляемого элемента</param>
	/// <param name="indexSelectedElem">индекс элемента
	///  перед которым идет вставка</param>
	void InsertBeforeSelectedElem(int data, int selectedData);

	/// <summary>
	/// Сортировка списка
	/// </summary>
	void Sort();

	/// <summary>
	/// Поиск элемента по индексу
	/// </summary>
	/// <param name="index"> индекс элемента</param>
	/// <returns> значение </returns>
	int LiningSearchByIndex(int index);

	/// <summary>
	/// Поиск по значению
	/// </summary>
	/// <param name="value"> значение элемента</param>
	/// <returns> индекс</returns>
	int LiningSeacrhByValue(int value);

	/// <summary>
	/// Возвращает кол-во элементов
	/// </summary>
	/// <returns> колличесвто элементов списка</returns>
	int GetCountList();
};