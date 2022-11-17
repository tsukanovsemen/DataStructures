#pragma once
#include <iostream>
#include <string>
#include "Menu.h"
#include "HashTable.h"
#include "Dictionary.h"

using namespace std;

/// <summary>
/// Вывод меню
/// </summary>
void ShowMenu(Menu variant);

/// <summary>
/// Выполнение меню 
/// </summary>
void DoMenu();

/// <summary>
/// Ввод вариант, исходя от типа меню
/// </summary>
/// <param name="variant"> вариант</param>
/// <param name="menu"> тип меню</param>
void InputVariant(int &variant, Menu menu);

/// <summary>
///  Для ввода ключа и значения.
/// </summary>
/// <param name="key"> Ключ</param>
/// /// <param name="value"> Значение</param>
void InputKeyValue(string& key, string& value);