#include "Menu.h"

void ShowMenu(Menu variant)
{
	switch (variant)
	{
		case MAIN_MENU:
		{
			cout << endl << "---------------------Menu--------------------";
			cout << endl << "�������� ���:";
			cout << endl << "/////////////////////////////////////////////";
			cout << endl << "// 1.Stack.                                //";
			cout << endl << "// 2.Ring Buffer.                          //";
			cout << endl << "// 3.Queue  �� ������ ����������� �������. //";
			cout << endl << "// 4.Queue  �� ���� ���� ������.           //";
			cout << endl << "// 5.�����                                 //";
			cout << endl << "/////////////////////////////////////////////";
			break;
		}
		case STACK:
		{
			cout << endl << "-------------------Stack---------------------";
			cout << endl << "/////////////////////////////////////////////";
			cout << endl << "//1.�������� �����.                        //";
			cout << endl << "//2.��������� � ���� (Push)                //";
			cout << endl << "//3.���������� �� ����� (Pop)              //";
			cout << endl << "//4.������� ������ �����.                  //";
			cout << endl << "//5.������� ������ �����.                  //";
			cout << endl << "//6.�������� ����.                         //";
			cout << endl << "//7.����� � ����.                          //";
			cout << endl << "/////////////////////////////////////////////";
			break;
		}
		case RING_BUFFER:
		{
			cout << endl << "---------------Ring Buffer-------------------";
			cout << endl << "/////////////////////////////////////////////";
			cout << endl << "//1.�������� ���������� �������.           //";
			cout << endl << "//2.���������� � ��������� ������.         //";
			cout << endl << "//3.�������� �� ���������� �������.        //";
			cout << endl << "//4.��������� �����.                       //";
			cout << endl << "//5.������� �����.                         //";
			cout << endl << "//6.������� ������.                        //";
			cout << endl << "//7.�������� ������.                       //";
			cout << endl << "//8.����� � ����.                          //";
			cout << endl << "/////////////////////////////////////////////";
			break;
		}
		case QUEUE_RING:
		{
			cout << endl << "-----------Queue based on Ring Buf-----------";
			cout << endl << "/////////////////////////////////////////////";
			cout << endl << "//1.�������� �������.                      //";
			cout << endl << "//2.���������� � �������.                  //";
			cout << endl << "//3.������� �������.                       //";
			cout << endl << "//4.�������� �������(������� ������).      //";
			cout << endl << "//5.����� � ����.                          //";
			cout << endl << "/////////////////////////////////////////////";
			break;
		}
		case QUEUE_STACK:
		{
			cout << endl << "-----------Queue based on 2xStack------------";
			cout << endl << "/////////////////////////////////////////////";
			cout << endl << "//1.�������� �������.                      //";
			cout << endl << "//2.���������� � �������.                  //";
			cout << endl << "//3.������� �������.                       //";
			cout << endl << "//4.�������� �������(������� �������).     //";
			cout << endl << "//5.����� � ����.                          //";
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
			cout << endl << "���������� ��� ���, ������ ������ �� ����������: ";
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
						cout << endl << "���������� ��� ���, ������ ������ �� ����������: ";
						InputVariant(variantStackMenu);
					}
					switch (variantStackMenu)
					{
						case 1:
						{
							stack = new Stack(InputCapacity());
							cout << endl << "���� ������! ������.";
							system("pause");
							break;
						}
						case 2:
						{
							if (stack == nullptr)
							{
								cout << endl << "��� ������ �������� ����.";
								system("pause");
								break;
							}
							else
							{
								stack->Push(InputElement());
								cout << endl;
								stack->ShowStack();
								cout << endl << "������!";
								system("pause");
								break;
							}
						}
						case 3:
						{
							if (stack == nullptr)
							{
								cout << endl << "��� ������ �������� ����.";
								system("pause");
								break;
							}
							else
							{
								cout << endl << "������� " << stack->Pop() << " ���������: ";
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
								cout << endl << "��� ������ �������� ����.";
								system("pause");
								break;
							}
							else
							{
								stack->DeleteStack();
								cout << "������! �������� ������� ���� ...:";
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
							cout << endl << "���� ������. ";
							system("pause");
							break;
						}
						case 6:
						{
							if (stack == nullptr)
							{
								cout << endl << "��� ������ �������� ����. ";
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
						cout << endl << "���������� ��� ���, ������ ������ �� ����������: ";
						InputVariant(variantRingBmenu);
					}

					switch (variantRingBmenu)
					{
						case 1:
						{
							ringb = new RingBuffer(InputCapacity());
							cout << endl << "��������� ����� ������, ���� ������:).";
							system("pause");
							break;
						}
						case 2:
						{
							if (ringb == nullptr)
							{
								cout << endl << " ��� ������ �������� ��������� �����.";
								system("pause");
								break;
							}
							else
							{
								ringb->Push(InputElement());
								cout << endl << " ������!";
								ringb->ShowBuffer();
								system("pause");
								break;
							}				
						}
						case 3:
						{
							if (ringb == nullptr)
							{
								cout << endl << " ��� ������ �������� ��������� �����.";
								system("pause");
								break;
							}
							else
							{
								cout << endl << "������� " << ringb->Pop() << " ���������.";
								ringb->ShowBuffer();
								system("pause");
								break;
							}	
						}
						case 4:
						{
							if (ringb == nullptr)
							{
								cout << endl << " ��� ������ �������� ��������� �����.";
								system("pause");
								break;
							}
							else
							{
								cout << "���������� ����� : " << ringb->GetFreePlace();
								system("pause");
								break;
							}	
						}
						case 5:
						{
							if (ringb == nullptr)
							{
								cout << endl << " ��� ������ �������� ��������� �����.";
								system("pause");
								break;
							}
							else
							{
								cout << "�������� ����� : " << ringb->GetBusyPlace();
								system("pause");
								break;
							}				
						}
						case 6:
						{
							if (ringb == nullptr)
							{
								cout << endl << " ��� ������ �������� ��������� �����.";
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
								cout << endl << " ��� ������ �������� ��������� �����.";
								system("pause");
								break;
							}
							else
							{
								ringb->ClearBuffer();
								cout << endl << "����� ������. ";
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
						cout << endl << "���������� ��� ���, ������ ������ �� ����������: ";
						InputVariant(variantRingQMenu);
					}
					switch (variantRingQMenu)
					{
						case 1:
						{
							rq = new RingQueue(InputCapacity());
							cout << endl << "��������� ������� �������! �����. ";
							system("pause");
							break;
						}
						case 2:
						{
							if (rq == nullptr)
							{
								cout << endl << " ��� ������ �������� �������...";
								system("pause");
								break;
							}
							else
							{
								rq->Enqueue(InputElement());
								cout << endl << "������! " << endl;
								rq->ShowRing();
								system("pause");
								break;
							}	
						}
						case 3:
						{
							if (rq == nullptr)
							{
								cout << endl << " ��� ������ �������� �������...";
								system("pause");
								break;
							}
							else
							{
								cout << "������� " << rq->Dequeue() << " ��������� � ������� � ����� �������.";
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
								cout << endl << " ��� ������ �������� �������...";
								system("pause");
								break;
							}
							else
							{
								delete rq;
								rq = nullptr;
								cout << endl << " ������!";
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
						cout << endl << "���������� ��� ���, ������ ������ �� ����������: ";
						InputVariant(varaintQueueMenu);
					}
					switch (varaintQueueMenu)
					{
						case 1:
						{
							queue = new Queue(InputCapacity());
							cout << endl << "������, ������� �������. �����.";
							system("pause");
							break;
						}
						case 2:
						{
							if (queue == nullptr)
							{
								cout << endl << " ��� ������ �������� �������!";
								system("pause");
								break;
							}
							else
							{
								int data = InputElement();
								queue->Enqueue(data);
								cout << endl << " ������� " << data << " ��������." << endl;
								system("pause");
								break;
							}	
						}
						case 3:
						{
							if (queue == nullptr)
							{
								cout << endl << " ��� ������ �������� �������!";
								system("pause");
								break;
							}
							else
							{
								if (queue->GetLength() == 0)
								{
									cout << endl << " ��������� ���.";
								}
								else
								{
									cout << endl << " ������� " << queue->Dequeue() << " �������� �� �������.";
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
								cout << endl << " ��� ������ �������� �������!";
								system("pause");
								break;
							}
							else
							{
								queue->Clear();
								queue = nullptr;
								cout << endl << " ������� �����.";
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
	cout << endl << "�������� ����� ����: ";
	cin >> variant;
}

int InputCapacity()
{
	cout << endl << "������� ������� : ";
	int capacity;
	cin >> capacity;
	return capacity;
}

int InputElement()
{
	int data;
	cout << endl << "������� �������, ������� ������ ��������: ";
	cin >> data;
	return data;
}

void StartOfMenu(Menu name, int &variantMenu)
{
	system("cls");
	ShowMenu(name);
	InputVariant(variantMenu);
}

