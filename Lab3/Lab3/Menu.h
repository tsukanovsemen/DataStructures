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
/// ���������� �������� ����
/// </summary>
void ShowMenu(Menu variant);

/// <summary>
/// ���������� ���� 
/// </summary>
void DoMenu();

/// <summary>/// 
/// ���� �������� ����
/// </summary>/// 
/// <param name="variant"> �������</param>
void InputVariant(int &variant);

/// <summary>/// 
/// ���� �������
/// </summary>/// 
/// <returns> �������</returns>
int InputCapacity();

/// <summary>///
/// ���� ������������ �������� � ��� 
/// </summary>///
///  <returns> �������</returns>
int InputElement();

/// <summary>/// 
/// ����� ������� ���� � ���� �������� ����.
/// </summary>///
///  <param name="name"> �������� ����</param>
void StartOfMenu(Menu name, int &variantMenu);