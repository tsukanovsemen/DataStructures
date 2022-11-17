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
	cout << endl << "// 1.Создание и инициализация списка.           // ";
	cout << endl << "// 2.Добавить элемент(в конец).                 // ";
	cout << endl << "// 3.Добавить элемент в указанное место.        // ";
	cout << endl << "// 4.Удалить элемент (последний).               // ";
	cout << endl << "// 5.Удалить указанный элемент(по индексу).     // ";
	cout << endl << "// 6.Удалить элемент по значению.               // ";
	cout << endl << "// 7.Вставить элемента в начало.                // ";
	cout << endl << "// 8.Вставить элемента в конец.                 // ";
	cout << endl << "// 9.Вставить после определенного элемента.     // ";
	cout << endl << "// 10.Вставить перед определенным элементом.    // ";
	cout << endl << "// 11.Сортировать список.                       // ";
	cout << endl << "// 12.Поиск по индексу.                         // ";
	cout << endl << "// 13.Поиск по значению.                        // ";
	cout << endl << "// 14.Получить кол-во элементов списка.         // ";
	cout << endl << "// 15.Показать список.                          // ";
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
		cout << endl << "Выберите пункт меню: ";
		cin >> variantMenu;
		while (true)
		{
			if (variantMenu < 1 || variantMenu > 16)
			{
				cout << endl << "Выберите пункт меню: ";
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
					cout << endl << "Список уже создан.";
					system("pause");
					break;
				}
				else
				{
					cout << endl << "Хотите ли заполнить сразу элементами? ";
					cout << endl << " 1. Да     2.Нет  :";
					int variant;
					cin >> variant;
					if (variant == 1)
					{
						int count = 0;
						cout << endl << " Введите кол-во элементов: ";
						cin >> count;
						int* array = new int[count];
						for (int i = 0; i < count; i++)
						{
							cin >> array[i];
							cout << endl;
						}
						list = new List(count, array);
						cout << endl << "Список создан :  " << endl;
						ShowList(list);
						system("pause");
					}
					else
					{
						list = new List();
						cout << endl << " Пустой список создан. ";
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
					cout << endl << "Введите число которое хотите добавить: ";
					cin >> data;
					list->AddElement(data);
					cout << endl << " Готово!" << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "Для начала создайте список. ";
					system("pause");
					break;
				}
			}
			case 3:
			{
				if (isCreated)
				{
					int data;
					cout << endl << "Введите элемент который хотите добавить: ";
					cin >> data;
					int index;
					cout << endl << "Места в которые можно добавить: ";
					for (int i = 0; i < list->GetCountList() - 1; i++)
					{
						cout << endl << "[" << i << "]";
					}
					cout << endl << "Введите место в которое хотите добавить: ";
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
								cout << endl << "Такого места не существует, попробуйте снова: ";
								cin >> index;
							}
							else
							{
								break;
							}
						}
						list->AddElemByIndex(data, index);
					}
					cout << endl << "Готово!: " << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "Для начала создайте список. ";
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
						cout << endl << " Список пуст. Элементы не существуют.";
						system("pause");
						break;
					}
					else
					{
						list->DeleteElement();
						cout << endl << "Готово!: " << endl;
						ShowList(list);
						if (list->GetCountList() == 0)
						{
							isCreated = false;
							cout << endl << " Список пуст. Все элементы удалены.";
							delete list;
						}
						system("pause");
						break;
					}
				}
				else
				{
					cout << endl << "Для начала создайте список. ";
					system("pause");
					break;
				}
			}
			case 5:
			{
				if (isCreated)
				{
					int index;
					cout << endl << "Введите индекс элемента, который хотиет удалить: " << endl;
					ShowList(list);
					cout << endl;
					cin >> index;
					while (index < 0 || index > list->GetCountList() - 1)
					{
						cout << endl << "Такого места не существует, попробуйте снова: ";
						cin >> index;
					}
					list->DeleteElemByIndex(index);
					cout << endl << "Готово!:" << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "Для начала создайте список. ";
					system("pause");
					break;
				}
			}
			case 6:
			{
				if (isCreated)
				{
					cout << endl << "Введите значение элемента, который вы хотите удалить: " << endl;
					ShowList(list);
					int data;
					cout << endl;
					cin >> data;
					int result = list->DeleteElemByValue(data);
					if (result == 0)
					{
						cout << endl << "Готово!: " << endl;
						ShowList(list);
						system("pause");
						break;
					}
					else
					{
						cout << endl << "Элемент не найдн!: " << endl;
						ShowList(list);
						system("pause");
						break;
					}
				}
				else
				{
					cout << endl << "Для начала создайте список. ";
					system("pause");
					break;
				}
			}
			case 7:
			{
				if (isCreated)
				{
					cout << endl << "Введите какой элемент вы хотите вставить в начало: " << endl;
					ShowList(list);
					int data;
					cout << endl;
					cin >> data;
					list->InsertInStart(data);
					cout << endl << "Готово!: " << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "Для начала создайте список. ";
					system("pause");
					break;
				}
			}
			case 8:
			{
				if (isCreated)
				{
					cout << endl << "Введите какой элемент вы хотите вставить в конец: " << endl;
					ShowList(list);
					int data;
					cout << endl;
					cin >> data;
					list->InsertInEnd(data);
					cout << endl << "Готово!: " << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "Для начала создайте список. ";
					system("pause");
					break;
				}
			}
			case 9:
			{
				if (isCreated)
				{
					cout << endl << "Введите элемент который вы хотие переставить: " << endl;
					ShowList(list);
					int data;
					cout << endl;
					cin >> data;
					cout << endl << "Введите элемент после которого будет вставка: " << endl;
					int selectedData;
					cin >> selectedData;
					if (data == selectedData)
					{
						cout << endl << "Элемент для перестановки и элемент после,"
							<< "которого выполняется вставка одинаковы";
					}
					else
					{
						list->InsertAfterSelectedElem(data, selectedData);
					}
					cout << endl << "Выполнено!: " << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "Для начала создайте список. ";
					system("pause");
					break;
				}
			}
			case 10:
			{
				if (isCreated)
				{
					cout << endl << "Введите элемент который вы хотие переставить: " << endl;
					ShowList(list);
					int data;
					cout << endl;
					cin >> data;
					cout << endl << "Введите элемент перед которым будет вставка: " << endl;
					int selectedData;
					cin >> selectedData;
					if (data == selectedData)
					{
						cout << endl << "Элемент для перестановки и элемент после,"
							<< "которого выполняется вставка одинаковы";
					}
					else
					{
						list->InsertBeforeSelectedElem(data, selectedData);
					}
					cout << endl << "Выполнено!: " << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "Для начала создайте список. ";
					system("pause");
					break;
				}
			}
			case 11:
			{
				if (isCreated)
				{
					list->Sort();
					cout << endl << "Список отсортирован!: " << endl;
					ShowList(list);
					system("pause");
					break;
				}
				else
				{
					cout << endl << "Для начала создайте список. ";
					system("pause");
					break;
				}
			}
			case 12:
			{
				if (isCreated)
				{
					cout << endl << "Введите индекс элемента: " << endl;
					int index;
					cin >> index;
					try
					{
						cout << endl << " Значение - " << list->LiningSearchByIndex(index);
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
					cout << endl << "Для начала создайте список. ";
					system("pause");
					break;
				}
			}
			case 13:
			{
				if (isCreated)
				{
					cout << endl << "Введите значение элемента: " << endl;
					int value;
					cin >> value;
					if (list->LiningSeacrhByValue(value) == -1)
					{
						cout << endl << "Такого элемента не существует. ";
					}
					else
					{
						cout << endl << "Индекс значения: " << list->LiningSeacrhByValue(value);
						system("pause");
						break;
					}
				}
				else
				{
					cout << endl << "Для начала создайте список. ";
					system("pause");
					break;
				}
			}
			case 14:
			{
				if (isCreated)
				{
					cout << endl << " Кол-во элементов : " << list->GetCountList();
					system("pause");
					break;
				}
				else
				{
					cout << endl << "Для начала создайте список. ";
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
					cout << endl << "Для начала создайте список. ";
					system("pause");
					break;
				}
			}
		}
	} while (variantMenu != 16);
}