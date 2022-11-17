#include <iostream>
#include <string>
#include <queue>
#include "BinaryTree.h"
#include "Treap.h"
#include "Trunk.h"

using namespace std;

void PrintMenu();

int main()
{
	setlocale(LC_ALL, "Russian");
	int variant = -1;
	BinaryTree* btrea = new BinaryTree();
	Treap* treap = new Treap();
	do
	{
		system("cls");
		PrintMenu();
		cout << endl << "�������� ������� ����: ";
		cin >> variant;

		switch (variant)
		{
			case 1:
			{
				cout << endl << "������� ����. ";
				int key;
				cin >> key;
				try
				{
					btrea->Insert(key,btrea->GetRoot());
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}
				system("pause");
				break;
			}
			case 2:
			{
				cout << endl << "������� ���� �������� ������� ������ ������� ";
				int key;
				cin >> key;
				try
				{
					btrea->Remove(key);
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}
				system("pause");
				break;
			}
			case 3:
			{
				printTree(btrea->GetRoot(), nullptr, false);
				system("pause");
				break;
			}
			case 4:
			{
				cout << endl << "������� ����. ";
				int key;
				cin >> key;
				try
				{
					treap->InsertNotOptimized(key);
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}
				system("pause");
				break;
			}
			case 5:
			{
				cout << endl << "������� ����. ";
				int key;
				cin >> key;
				try
				{
					treap->InsertOptimized(key);
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}
				system("pause");
				break;
			}
			case 6:
			{
				cout << endl << "������� ���� �������� ������� ������ ������� ";
				int key;
				cin >> key;
				try
				{
					treap->EraseNotOptimized(key);
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}
				system("pause");
				break;
			}
			case 7:
			{
				cout << endl << "������� ���� �������� ������� ������ ������� ";
				int key;
				cin >> key;
				try
				{
					treap->EraseOptimized(key);
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}
				system("pause");
				break;
			}
			case 8:
			{
				system("pause");
				printTree(treap->GetRoot(), nullptr, false);
				system("pause");
				break;
			}
		}

	} while (variant > 0 && variant < 9);

	return 0;
}


void PrintMenu()
{
	cout << endl << "			Menu			";
	cout << endl << "/////////////////////////////////////////////////";
	cout << endl << "//1.�������� ������� � �������� ������.        //";
	cout << endl << "//2.������� ������� �� ��������� ������.       //";
	cout << endl << "//3 ������� �������� ������.                   //";
	cout << endl << "//                                             //";
	cout << endl << "//4.�������� �� �������������� ������� � treap.//";
	cout << endl << "//5.�������� �������������� ������� � treap.   //";
	cout << endl << "//6.������� �� �������������� ������� � treap. //";
	cout << endl << "//7.������� �������������� ������� � treap.    //";
	cout << endl << "//8.������� treap  �� �����.                   //";
	cout << endl << "/////////////////////////////////////////////////";
}