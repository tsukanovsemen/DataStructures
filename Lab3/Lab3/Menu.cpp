#include "Menu.h"

void ShowMenu(Menu variant)
{
	switch (variant)
	{
		case MAIN_MENU:
		{
			cout << endl << "---------------------Menu--------------------";
			cout << endl << "Выберите АСД:";
			cout << endl << "/////////////////////////////////////////////";
			cout << endl << "// 1.Stack.                                //";
			cout << endl << "// 2.Ring Buffer.                          //";
			cout << endl << "// 3.Queue  на основе кольцеового буффера. //";
			cout << endl << "// 4.Queue  на базе двух стеков.           //";
			cout << endl << "// 5.Выход                                 //";
			cout << endl << "/////////////////////////////////////////////";
			break;
		}
		case STACK:
		{
			cout << endl << "-------------------Stack---------------------";
			cout << endl << "/////////////////////////////////////////////";
			cout << endl << "//1.Создание стека.                        //";
			cout << endl << "//2.Помещение в стек (Push)                //";
			cout << endl << "//3.Извлечение из стека (Pop)              //";
			cout << endl << "//4.Очитска данных стека.                  //";
			cout << endl << "//5.Очитска памяти стека.                  //";
			cout << endl << "//6.Показать стек.                         //";
			cout << endl << "//7.Назад в меню.                          //";
			cout << endl << "/////////////////////////////////////////////";
			break;
		}
		case RING_BUFFER:
		{
			cout << endl << "---------------Ring Buffer-------------------";
			cout << endl << "/////////////////////////////////////////////";
			cout << endl << "//1.Создание кольцевого буффера.           //";
			cout << endl << "//2.Добавление в кольцевой буффер.         //";
			cout << endl << "//3.Удаление из кольцевого буффера.        //";
			cout << endl << "//4.Свободное место.                       //";
			cout << endl << "//5.Занятое место.                         //";
			cout << endl << "//6.Вывести буффер.                        //";
			cout << endl << "//7.Очистить буффер.                       //";
			cout << endl << "//8.Назад в меню.                          //";
			cout << endl << "/////////////////////////////////////////////";
			break;
		}
		case QUEUE_RING:
		{
			cout << endl << "-----------Queue based on Ring Buf-----------";
			cout << endl << "/////////////////////////////////////////////";
			cout << endl << "//1.Создание очереди.                      //";
			cout << endl << "//2.Добавление в очередь.                  //";
			cout << endl << "//3.Извлечь элемент.                       //";
			cout << endl << "//4.Очистить очередь(удалить память).      //";
			cout << endl << "//5.Назад в меню.                          //";
			cout << endl << "/////////////////////////////////////////////";
			break;
		}
		case QUEUE_STACK:
		{
			cout << endl << "-----------Queue based on 2xStack------------";
			cout << endl << "/////////////////////////////////////////////";
			cout << endl << "//1.Создание очереди.                      //";
			cout << endl << "//2.Добавление в очередь.                  //";
			cout << endl << "//3.Извлечь элемент.                       //";
			cout << endl << "//4.Очистить очередь(удалить элемент).     //";
			cout << endl << "//5.Назад в меню.                          //";
			cout << endl << "/////////////////////////////////////////////";
			break;
		}
	}
}

void DoMenu()
{
	int variantMenu = 0;
	do
	{
		StartOfMenu(MAIN_MENU,variantMenu);
		while (variantMenu < 1 || variantMenu > 5)
		{
			cout << endl << "Попробуйте еще раз, такого пунтка не существует: ";
			InputVariant(variantMenu);
		}

		switch (variantMenu)
		{
			case 1:
			{
				Stack* stack = nullptr;
				int variantStackMenu = 0;
				do
				{
					StartOfMenu(STACK, variantStackMenu);
					while (variantStackMenu < 1 || variantStackMenu > 7)
					{
						cout << endl << "Попробуйте еще раз, такого пунтка не существует: ";
						InputVariant(variantStackMenu);
					}
					switch (variantStackMenu)
					{
						case 1:
						{
							stack = new Stack(InputCapacity());
							cout << endl << "Стек создан! Пустой.";
							system("pause");
							break;
						}
						case 2:
						{
							if (stack == nullptr)
							{
								cout << endl << "Для начала создайте стек.";
								system("pause");
								break;
							}
							else
							{
								stack->Push(InputElement());
								cout << endl;
								stack->ShowStack();
								cout << endl << "Готово!";
								system("pause");
								break;
							}
						}
						case 3:
						{
							if (stack == nullptr)
							{
								cout << endl << "Для начала создайте стек.";
								system("pause");
								break;
							}
							else
							{
								cout << endl << "Элемент " << stack->Pop() << " извелечен: ";
								cout << endl;
								stack->ShowStack();
								system("pause");
								break;
							}
						}
						case 4:
						{
							if (stack == nullptr)
							{
								cout << endl << "Для начала создайте стек.";
								system("pause");
								break;
							}
							else
							{
								stack->DeleteStack();
								cout << "Готово! Пытаемся вывести стек ...:";
								cout << endl;
								stack->ShowStack();
								system("pause");
								break;
							}
						}
						case 5:
						{
							delete stack;
							stack = nullptr;
							cout << endl << "Стек удален. ";
							system("pause");
							break;
						}
						case 6:
						{
							if (stack == nullptr)
							{
								cout << endl << "Для начала создайте стек. ";
							}
							else
							{
								cout << endl;
								stack->ShowStack();
							}
							system("pause");
							break;
						}
					}
				} while (variantStackMenu !=7);
				system("pause");
				break;
			}
			case 2:
			{
				int variantRingBmenu = 0;
				RingBuffer* ringb = nullptr;
				do
				{
					StartOfMenu(RING_BUFFER, variantRingBmenu);
					while (variantRingBmenu < 1 || variantRingBmenu > 8)
					{
						cout << endl << "Попробуйте еще раз, такого пунтка не существует: ";
						InputVariant(variantRingBmenu);
					}

					switch (variantRingBmenu)
					{
						case 1:
						{
							ringb = new RingBuffer(InputCapacity());
							cout << endl << "Кольцевой буфер создан, пока пустой:).";
							system("pause");
							break;
						}
						case 2:
						{
							if (ringb == nullptr)
							{
								cout << endl << " Для начала создайте кольцевой буфер.";
								system("pause");
								break;
							}
							else
							{
								ringb->Push(InputElement());
								cout << endl << " Готово!";
								ringb->ShowBuffer();
								system("pause");
								break;
							}				
						}
						case 3:
						{
							if (ringb == nullptr)
							{
								cout << endl << " Для начала создайте кольцевой буфер.";
								system("pause");
								break;
							}
							else
							{
								cout << endl << "Элемент " << ringb->Pop() << " извелечен.";
								ringb->ShowBuffer();
								system("pause");
								break;
							}	
						}
						case 4:
						{
							if (ringb == nullptr)
							{
								cout << endl << " Для начала создайте кольцевой буфер.";
								system("pause");
								break;
							}
							else
							{
								cout << "Свободного места : " << ringb->GetFreePlace();
								system("pause");
								break;
							}	
						}
						case 5:
						{
							if (ringb == nullptr)
							{
								cout << endl << " Для начала создайте кольцевой буфер.";
								system("pause");
								break;
							}
							else
							{
								cout << "Занятого места : " << ringb->GetBusyPlace();
								system("pause");
								break;
							}				
						}
						case 6:
						{
							if (ringb == nullptr)
							{
								cout << endl << " Для начала создайте кольцевой буфер.";
								system("pause");
								break;
							}
							else
							{
								cout << endl;
								ringb->ShowBuffer();
								system("pause");
								break;
							}	
						}
						case 7:
						{
							if (ringb == nullptr)
							{
								cout << endl << " Для начала создайте кольцевой буфер.";
								system("pause");
								break;
							}
							else
							{
								ringb->ClearBuffer();
								cout << endl << "Буфер очищен. ";
								system("pause");
								break;
							}
						}
						case 8:
						{
							delete ringb;
							system("pause");
							break;
						}
					}
				} while (variantRingBmenu != 8);
				system("pause");
				break;
			}
			case 3:
			{
				RingQueue* rq = nullptr;
				int variantRingQMenu = 0;
				do
				{
					StartOfMenu(QUEUE_RING, variantRingQMenu);
					while (variantRingQMenu < 1 || variantRingQMenu > 5)
					{
						cout << endl << "Попробуйте еще раз, такого пунтка не существует: ";
						InputVariant(variantRingQMenu);
					}
					switch (variantRingQMenu)
					{
						case 1:
						{
							rq = new RingQueue(InputCapacity());
							cout << endl << "Кольцевая очередь создана! Пусто. ";
							system("pause");
							break;
						}
						case 2:
						{
							if (rq == nullptr)
							{
								cout << endl << " Для начала создайте очередь...";
								system("pause");
								break;
							}
							else
							{
								rq->Enqueue(InputElement());
								cout << endl << "Готово! " << endl;
								rq->ShowRing();
								system("pause");
								break;
							}	
						}
						case 3:
						{
							if (rq == nullptr)
							{
								cout << endl << " Для начала создайте очередь...";
								system("pause");
								break;
							}
							else
							{
								cout << "Элемент " << rq->Dequeue() << " извелечен и помещен в конец очереди.";
								cout << endl;
								rq->ShowRing();
								system("pause");
								break;
							}	
						}
						case 4:
						{
							if (rq == nullptr)
							{
								cout << endl << " Для начала создайте очередь...";
								system("pause");
								break;
							}
							else
							{
								delete rq;
								rq = nullptr;
								cout << endl << " Готово!";
								system("pause");
								break;
							}
						}
					}
				} while (variantRingQMenu!=5);
				system("pause");
				break;
			}
			case 4:
			{
				Queue* queue = nullptr;
				int varaintQueueMenu = 0;
				do
				{
					StartOfMenu(QUEUE_STACK, varaintQueueMenu);
					while (varaintQueueMenu < 1 || varaintQueueMenu > 5)
					{
						cout << endl << "Попробуйте еще раз, такого пунтка не существует: ";
						InputVariant(varaintQueueMenu);
					}
					switch (varaintQueueMenu)
					{
						case 1:
						{
							queue = new Queue(InputCapacity());
							cout << endl << "Готово, очередь создана. Пусто.";
							system("pause");
							break;
						}
						case 2:
						{
							if (queue == nullptr)
							{
								cout << endl << " Для начала создайте очередь!";
								system("pause");
								break;
							}
							else
							{
								int data = InputElement();
								queue->Enqueue(data);
								cout << endl << " Элемент " << data << " добавлен." << endl;
								system("pause");
								break;
							}	
						}
						case 3:
						{
							if (queue == nullptr)
							{
								cout << endl << " Для начала создайте очередь!";
								system("pause");
								break;
							}
							else
							{
								if (queue->GetLength() == 0)
								{
									cout << endl << " Элементов нет.";
								}
								else
								{
									cout << endl << " Элемент " << queue->Dequeue() << " извлечен из очереди.";
									cout << endl;
									queue->ShowQueue();
									system("pause");
									break;
								}
							}
						}
						case 4:
						{
							if (queue == nullptr)
							{
								cout << endl << " Для начала создайте очередь!";
								system("pause");
								break;
							}
							else
							{
								queue->Clear();
								queue = nullptr;
								cout << endl << " Очередь пуста.";
								system("pause");
								break;
							}
						}
					}
				} while (varaintQueueMenu !=5);
				system("pause");
				break;
			}
		}
	} while (variantMenu!= 5);
}

void InputVariant(int& variant)
{
	cout << endl << "Выберите пункт меню: ";
	cin >> variant;
}

int InputCapacity()
{
	cout << endl << "Введите емкость : ";
	int capacity;
	cin >> capacity;
	return capacity;
}

int InputElement()
{
	int data;
	cout << endl << "Введите элемент, который хотите добавить: ";
	cin >> data;
	return data;
}

void StartOfMenu(Menu name, int &variantMenu)
{
	system("cls");
	ShowMenu(name);
	InputVariant(variantMenu);
}

