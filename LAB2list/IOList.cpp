#include "IOList.h"

using namespace std;

void ShowList(List* list)
{
	for (int i = 0; i < list->GetCountList(); i++)
	{
		try
		{
			cout <<"["<< i <<"] "<< list->LiningSearchByIndex(i) << " ";
		}
		catch (exception &ex)
		{
			cout << ex.what();
		}
	}
}

void PrintMenu()
{
	cout << endl << "---------------------Menu--------------------------";
	cout << endl << "// // // // // // // // // // // // // // // // // ";
	cout << endl << "// 1.�������� � ������������� ������.           // ";
	cout << endl << "// 2.�������� �������(� �����).                 // ";
	cout << endl << "// 3.�������� ������� � ��������� �����.        // ";
	cout << endl << "// 4.������� ������� (���������).               // ";
	cout << endl << "// 5.������� ��������� �������(�� �������).     // ";
	cout << endl << "// 6.������� ������� �� ��������.               // ";
	cout << endl << "// 7.�������� �������� � ������.                // ";
	cout << endl << "// 8.�������� �������� � �����.                 // ";
	cout << endl << "// 9.�������� ����� ������������� ��������.     // ";
	cout << endl << "// 10.�������� ����� ������������ ���������.    // ";
	cout << endl << "// 11.����������� ������.                       // ";
	cout << endl << "// 12.����� �� �������.                         // ";
	cout << endl << "// 13.����� �� ��������.                        // ";
	cout << endl << "// 14.�������� ���-�� ��������� ������.         // ";
	cout << endl << "// 15.�������� ������.                          // ";
	cout << endl << "// 16.EXIT.                                     // ";
	cout << endl << "// // // // // // // // // // // // // // // // // ";
	cout << endl;
}

void DoMenu()
{
	int variantMenu;
	List* list = nullptr;
	bool isCreated = false;
	do
	{
		system("cls");
		PrintMenu();
		cout << endl << "�������� ����� ����: ";
		cin >> variantMenu;
		while (true)
		{
			if (variantMenu < 1 || variantMenu > 16)
			{
				cout << endl << "�������� ����� ����: ";
				cin >> variantMenu;
			}
			else
			{
				break;
			}
		}
		switch (variantMenu)
		{
			case 1:
			{
				if (isCreated)
				{
					cout << endl << "������ ��� ������.";
					system("pause");
					break;
				}
				else
				{
					cout << endl << "������ �� ��������� ����� ����������? ";
					cout << endl << " 1. ��     2.���  :";
					int variant;
					cin >> variant;
					if (variant == 1)
					{
						int count = 0;
						cout << endl << " ������� ���-�� ���������: ";
						cin >> count;
						int* array = new int[count];
						for (int i = 0; i < count; i++)
						{
							cin >> array[i];
							cout << endl;
						}
						list = new List(count, array);
						cout << endl << "������ ������ :  " << endl;
						ShowList(list);
						system("pause");
					}
					else
					{
						list = new List();
						cout << endl << " ������ ������ ������. ";
						system("pause");
					}
					isCreated = true;
					break;
				}
			}
			case 2:
			{
				if (isCreated)
				{
					int data;
					cout << endl << "������� ����� ������� ������ ��������: ";
					cin >> data;
					list->AddElement(data);
					cout << endl << " ������!" << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "��� ������ �������� ������. ";
					system("pause");
					break;
				}
			}
			case 3:
			{
				if (isCreated)
				{
					int data;
					cout << endl << "������� ������� ������� ������ ��������: ";
					cin >> data;
					int index;
					cout << endl << "����� � ������� ����� ��������: ";
					for (int i = 0; i < list->GetCountList() - 1; i++)
					{
						cout << endl << "[" << i << "]";
					}
					cout << endl << "������� ����� � ������� ������ ��������: ";
					cin >> index;
					if (index == 0)
					{
						list->AddElement(data);
					}
					else
					{
						while (true)
						{
							if (index < 0 || index > list->GetCountList() - 1)
							{
								cout << endl << "������ ����� �� ����������, ���������� �����: ";
								cin >> index;
							}
							else
							{
								break;
							}
						}
						list->AddElemByIndex(data, index);
					}
					cout << endl << "������!: " << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "��� ������ �������� ������. ";
					system("pause");
					break;
				}
			}
			case 4:
			{
				if (isCreated)
				{
					if (list->GetCountList() == 0)
					{
						cout << endl << " ������ ����. �������� �� ����������.";
						system("pause");
						break;
					}
					else
					{
						list->DeleteElement();
						cout << endl << "������!: " << endl;
						ShowList(list);
						if (list->GetCountList() == 0)
						{
							isCreated = false;
							cout << endl << " ������ ����. ��� �������� �������.";
							delete list;
						}
						system("pause");
						break;
					}
				}
				else
				{
					cout << endl << "��� ������ �������� ������. ";
					system("pause");
					break;
				}
			}
			case 5:
			{
				if (isCreated)
				{
					int index;
					cout << endl << "������� ������ ��������, ������� ������ �������: " << endl;
					ShowList(list);
					cout << endl;
					cin >> index;
					while (index < 0 || index > list->GetCountList() - 1)
					{
						cout << endl << "������ ����� �� ����������, ���������� �����: ";
						cin >> index;
					}
					list->DeleteElemByIndex(index);
					cout << endl << "������!:" << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "��� ������ �������� ������. ";
					system("pause");
					break;
				}
			}
			case 6:
			{
				if (isCreated)
				{
					cout << endl << "������� �������� ��������, ������� �� ������ �������: " << endl;
					ShowList(list);
					int data;
					cout << endl;
					cin >> data;
					int result = list->DeleteElemByValue(data);
					if (result == 0)
					{
						cout << endl << "������!: " << endl;
						ShowList(list);
						system("pause");
						break;
					}
					else
					{
						cout << endl << "������� �� �����!: " << endl;
						ShowList(list);
						system("pause");
						break;
					}
				}
				else
				{
					cout << endl << "��� ������ �������� ������. ";
					system("pause");
					break;
				}
			}
			case 7:
			{
				if (isCreated)
				{
					cout << endl << "������� ����� ������� �� ������ �������� � ������: " << endl;
					ShowList(list);
					int data;
					cout << endl;
					cin >> data;
					list->InsertInStart(data);
					cout << endl << "������!: " << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "��� ������ �������� ������. ";
					system("pause");
					break;
				}
			}
			case 8:
			{
				if (isCreated)
				{
					cout << endl << "������� ����� ������� �� ������ �������� � �����: " << endl;
					ShowList(list);
					int data;
					cout << endl;
					cin >> data;
					list->InsertInEnd(data);
					cout << endl << "������!: " << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "��� ������ �������� ������. ";
					system("pause");
					break;
				}
			}
			case 9:
			{
				if (isCreated)
				{
					cout << endl << "������� ������� ������� �� ����� �����������: " << endl;
					ShowList(list);
					int data;
					cout << endl;
					cin >> data;
					cout << endl << "������� ������� ����� �������� ����� �������: " << endl;
					int selectedData;
					cin >> selectedData;
					if (data == selectedData)
					{
						cout << endl << "������� ��� ������������ � ������� �����,"
							<< "�������� ����������� ������� ���������";
					}
					else
					{
						list->InsertAfterSelectedElem(data, selectedData);
					}
					cout << endl << "���������!: " << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "��� ������ �������� ������. ";
					system("pause");
					break;
				}
			}
			case 10:
			{
				if (isCreated)
				{
					cout << endl << "������� ������� ������� �� ����� �����������: " << endl;
					ShowList(list);
					int data;
					cout << endl;
					cin >> data;
					cout << endl << "������� ������� ����� ������� ����� �������: " << endl;
					int selectedData;
					cin >> selectedData;
					if (data == selectedData)
					{
						cout << endl << "������� ��� ������������ � ������� �����,"
							<< "�������� ����������� ������� ���������";
					}
					else
					{
						list->InsertBeforeSelectedElem(data, selectedData);
					}
					cout << endl << "���������!: " << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "��� ������ �������� ������. ";
					system("pause");
					break;
				}
			}
			case 11:
			{
				if (isCreated)
				{
					list->Sort();
					cout << endl << "������ ������������!: " << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "��� ������ �������� ������. ";
					system("pause");
					break;
				}
			}
			case 12:
			{
				if (isCreated)
				{
					cout << endl << "������� ������ ��������: " << endl;
					int index;
					cin >> index;
					try
					{
						cout << endl << " �������� - " << list->LiningSearchByIndex(index);
					}
					catch (exception& ex)
					{
						cout << endl << ex.what();
					}

					system("pause");
					break;
				}
				else
				{
					cout << endl << "��� ������ �������� ������. ";
					system("pause");
					break;
				}
			}
			case 13:
			{
				if (isCreated)
				{
					cout << endl << "������� �������� ��������: " << endl;
					int value;
					cin >> value;
					if (list->LiningSeacrhByValue(value) == -1)
					{
						cout << endl << "������ �������� �� ����������. ";
					}
					else
					{
						cout << endl << "������ ��������: " << list->LiningSeacrhByValue(value);
						system("pause");
						break;
					}
				}
				else
				{
					cout << endl << "��� ������ �������� ������. ";
					system("pause");
					break;
				}
			}
			case 14:
			{
				if (isCreated)
				{
					cout << endl << " ���-�� ��������� : " << list->GetCountList();
					system("pause");
					break;
				}
				else
				{
					cout << endl << "��� ������ �������� ������. ";
					system("pause");
					break;
				}
			}
			case 15:
			{
				if (isCreated)
				{
					cout << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "��� ������ �������� ������. ";
					system("pause");
					break;
				}
			}
		}
	} while (variantMenu != 16);
}