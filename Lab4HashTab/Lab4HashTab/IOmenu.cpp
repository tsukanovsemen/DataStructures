#include "IOmenu.h"
using namespace std;

void ShowMenu(Menu variant)
{
	switch (variant)
	{
		case MAIN_MENU:
		{
			cout << endl << "                MENU                  " << endl;
			cout << endl << "////////////Выберите сд///////////////";
			cout << endl << "//////////////////////////////////////";
			cout << endl << "// 1.Хэш-таблица.                   //";
			cout << endl << "// 2.Словарь.                       //";
			cout << endl << "// 3.Выход.                         //";
			cout << endl << "//////////////////////////////////////";
			break;
		}
		case INTERNAL_MENU:
		{
			cout << endl << "//////////////////////////////////////";
			cout << endl << "// 1. Создать СД.                   //";
			cout << endl << "// 2. Добавить ключ - значение.     //";
			cout << endl << "// 3. Удалить значение по ключу.    //";
			cout << endl << "// 4. Поиск значения по ключу.      //";
			cout << endl << "// 5. Вывод на экран СД.            //";
			cout << endl << "// 6. Назад.                        //";
			cout << endl << "//////////////////////////////////////";
			break;
		}
	}
}

void DoMenu()
{
	int variantMenu = 0;
	HashTable* hashtable = nullptr;
	const int EXIT = 3;
	Dictionary* dictionary = nullptr;
	do
	{
		system("cls");
		ShowMenu(MAIN_MENU);
		InputVariant(variantMenu, MAIN_MENU);
		switch (variantMenu)
		{
			case 1:
			{
				const int EXIT_HASHTABLE = 6;
				bool isCreated = false;
				do
				{
					system("cls");
					ShowMenu(INTERNAL_MENU);
					InputVariant(variantMenu, INTERNAL_MENU);
					switch (variantMenu)
					{
						case 1:
						{
							if (isCreated)
							{
								cout << endl << "Хэш таблица уже создана.";
								system("pause");
								break;
							}
							else
							{
								cout << endl << "Введите ёмкость хэш-таблицы: ";
								int capacity = 0;
								cin >> capacity;
								hashtable = new HashTable(capacity);
								cout << endl << "Готово! Хэш-таблица создана.";
								isCreated = true;
								system("pause");
								break;
							}
						}
						case 2:
						{
							if (isCreated)
							{
								string key = " ";
								string value = " ";
								InputKeyValue(key, value);
								hashtable->Insert(key, value);
								system("pause");
								break;
							}
							else
							{
								cout << endl << "Для начала создайте таблицу.";
								system("pause");
								break;
							}
						}
						case 3:
						{
							if (isCreated)
							{
								cout << endl << "Введите ключ, по которму хотите"
									<< " удалить значение.";
								string key;
								cin >> key;
								hashtable->Delete(key);
								cout << endl << "Готово! Удалено";
								system("pause");
								break;
							}
							else
							{

								cout << endl << "Для начала создайте таблицу.";
								system("pause");
								break;
							}
						}
						case 4:
						{
							if (isCreated)
							{
								cout << endl << "Введите ключ, по которому "
									<< "хотите найти значение";
								string key;
								cin >>  key;
								cout << endl << hashtable->Search(key);
								system("pause");
								break;
							}
							else
							{
								cout << endl << "Для начала создайте таблицу.";
								system("pause");
								break;
							}
						}
						case 5:
						{
							if (isCreated)
							{
								cout << endl;
								hashtable->ShowHashTable();
								system("pause");
								break;
							}
							else
							{
								cout << endl << "Для начала создайте таблицу.";
								system("pause");
								break;
							}
						}
					}
				} while (variantMenu != EXIT_HASHTABLE);
				system("pause");
				break;
			}
			case 2:
			{
				const int EXIT_DICTIONARY = 6;
				bool isCreated = false;
				do
				{
					system("cls");
					ShowMenu(INTERNAL_MENU);
					InputVariant(variantMenu, INTERNAL_MENU);
					switch (variantMenu)
					{
						case 1:
						{
							if (isCreated)
							{
								cout <<endl << "Словарь уже создан!";
								system("pause");
								break;
							}
							else
							{
								cout << endl << "Введите ёмкость словаря: ";
								int capacity = 0;
								cin >> capacity;
								dictionary = new Dictionary(capacity);
								cout << endl << "Готово! Словарь создан.";
								isCreated = true;
								system("pause");
								break;
							}
						}
						case 2:
						{
							if (isCreated)
							{
								string key = " ";
								string value = " ";
								InputKeyValue(key, value);
								dictionary->Insert(key, value);
								system("pause");
								break;
							}
							else
							{
								cout << endl << "Для начала создайте словарь.";
								system("pause");
								break;
							}
						}
						case 3:
						{
							if (isCreated)
							{
								cout << endl << "Введите ключ, по которму хотите"
									<< " удалить значение.";
								string key;
								cin >> key;
								dictionary->Delete(key);
								cout << endl << "Готово! Удалено";
								system("pause");
								break;
							}
							else
							{
								cout << endl << "Для начала создайте словарь.";
								system("pause");
								break;
							}
						}
						case 4:
						{
							if (isCreated)
							{
								cout << endl << "Введите ключ, по которому "
									<< "хотите найти значение";
								string key;
								cin >> key;
								cout << endl << dictionary->Search(key);
								system("pause");
								break;
							}
							else
							{
								cout << endl << "Для начала создайте словарь.";
								system("pause");
								break;
							}
						}
						case 5:
						{
							if (isCreated)
							{
								cout << endl;
								dictionary->ShowHashTable();
								system("pause");
								break;
							}
							else
							{
								cout << endl << "Для начала создайте словарь.";
								system("pause");
								break;
							}
						}
					}

				} while (variantMenu != EXIT_DICTIONARY);


				system("pause");
				break;
			} 
		}

		 
	} while (variantMenu != EXIT);
}

void InputVariant(int& variant, Menu menu)
{
	switch (menu)
	{
		case MAIN_MENU:
		{
			cout << endl << "Выберите вариант меню: ";
			cin >> variant;
			while (variant < 1 || variant > 3)
			{
				cout << endl << " Пункта " << variant << " не сущетсвует, "
					<< "выберите существующий: ";
				cin >> variant;
			}
			break;
		}
		case INTERNAL_MENU:
		{
			cout << endl << "Выберите вариант меню: ";
			cin >> variant;
			while (variant < 1 || variant > 6)
			{
				cout << endl << " Пункта " << variant << " не сущетсвует, "
					<< "выберите существующий: ";
				cin >> variant;
			}
			break;
		}
	}
}

void InputKeyValue(string& key, string& value)
{
	cout << endl << "Введите ключ: ";
	cin >> key;
	cout << endl << "Введите значение: ";
	cin >> value;
}

