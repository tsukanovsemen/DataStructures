#pragma once
#include <iostream>
#include "Stack.h"
#include "RingBuffer.h"
#include "RingQueue.h"
#include "Queue.h"

enum Menu
{
	MAIN_MENU,
	STACK,
	RING_BUFFER,
	QUEUE_RING,
	QUEUE_STACK
};

/// <summary>
/// Показывает варианты меню
/// </summary>
void ShowMenu(Menu variant);

/// <summary>
/// Реализация меню 
/// </summary>
void DoMenu();

/// <summary>/// 
/// Ввод варианта меню
/// </summary>/// 
/// <param name="variant"> вариант</param>
void InputVariant(int &variant);

/// <summary>/// 
/// Ввод емкости
/// </summary>/// 
/// <returns> емкость</returns>
int InputCapacity();

/// <summary>///
/// Ввод добавляемого элемента в АСД 
/// </summary>///
///  <returns> элемент</returns>
int InputElement();

/// <summary>/// 
/// Вывод нужного меню и ввод варианта меню.
/// </summary>///
///  <param name="name"> название меню</param>
void StartOfMenu(Menu name, int &variantMenu);