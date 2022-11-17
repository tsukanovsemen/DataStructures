#pragma once
#include <iostream>
#include <string>
#include "Menu.h"
#include "HashTable.h"
#include "Dictionary.h"

using namespace std;

/// <summary>
/// ����� ����
/// </summary>
void ShowMenu(Menu variant);

/// <summary>
/// ���������� ���� 
/// </summary>
void DoMenu();

/// <summary>
/// ���� �������, ������ �� ���� ����
/// </summary>
/// <param name="variant"> �������</param>
/// <param name="menu"> ��� ����</param>
void InputVariant(int &variant, Menu menu);

/// <summary>
///  ��� ����� ����� � ��������.
/// </summary>
/// <param name="key"> ����</param>
/// /// <param name="value"> ��������</param>
void InputKeyValue(string& key, string& value);