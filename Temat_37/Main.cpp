#include "Sportsman.h"
#include<Windows.h>

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*Sportsman Vasya;
	Vasya.fillSportsman();
	cout << "==========================================\n";
	Vasya.showSportsman();

	FILE* fp;
	fopen_s(&fp, "Vasya.dat", "wb");
	if (fp == NULL) cout << "������ �������� �����!\n";
	else
	{
		Vasya.saveToBinFile(fp);
		fclose(fp);
		cout << "���� ������� �������, ������ ��������!\n";
	}*/
	
	/*Sportsman Vasya;
	FILE* fp;
	fopen_s(&fp, "Vasya.dat", "rb");
	if (fp == NULL) cout << "������ �������� �����!\n";
	else
	{
		Vasya.loadToBinFile(fp);
		fclose(fp);
		cout << "���� ������� ��������, ������ ��������!\n\n";
	}
	Vasya.showSportsman();*/

	Sportsman* arr = nullptr;
	int size = 0;
	int menu;

	char name[100] = "";
	int id = -1;
/*1.	�������� ����� ������ � ����� �����. ..2
2.	��������������� ������ �� ���������� ���������� ..6
3.	������� ������ �� ���������� ���������� ..3
4.	������� ������ � ����� ������� ����������. ..7
5.	�������� ������� ���� ������ ����������� ..8
6.	�������� ������ ����������� � ���������� ������ ..9
7.	������������� ����������� �� ���������� ������ (���������� ���������) ..11
*/
	do
	{
		cout << "1. ��������� ������ � �����������.\n";//+
		cout << "2. �������� ������ ����������.\n";//+
		cout << "3. ������� ���������� ����������.\n";//+
		cout << "4. �������� ���������� � ����������.\n";//+
		cout << "5. �������� ������ ���� �����������.\n";//+
		cout << "6. ��������������� ������ �� ���������� ����������.\n"; //+
		cout << "7. ������� ������ � ����� ������� ����������.\n";//+
		cout << "8. �������� ������� ���� ������ �����������.\n"; //+
		cout << "9. �������� ������ ����������� � ���������� ������.\n";//+
		cout << "10. ����������� ����������� �� ���������� ������.\n"; //+
		cout << "11. ��������� �������� ������.\n";//+
		cout << "0. ��������� ������� � �����������.\n�����: ";
		cin >> menu;

		switch (menu)
		{
		case 1: 
			loadDB(arr, size);
			break;

		case 2:
			addItem(arr, size); 
			break;

		case 3: 
			cout << "\n����� ���������� ����������: ";
			cin >> id;
			id--;
			delItem(arr, size, id);
			break;

		case 4: 
			cout << "\n��� ����������: ";
			cin.ignore();
			cin.getline(name, 100);
			showCurrSportsman(arr, size, name);
			cout << endl;
			break;

		case 5: 
			showItems(arr, size); 
			break;

		case 6: 
			cout << "\n��� ����������: ";
			cin.ignore();
			cin.getline(name, 100);
			editDataOfSportsman(arr, size, name);			
			break;
			
		case 7: 
			tallSportsman(arr, size);
			break;
			
		case 8: 
			threeBestSportsmans(arr, size);
			break;
			
		case 9: 
			cout << "\n�����: ";
			cin.ignore();
			cin.getline(name, 100);
			findByCity(arr, size, name);
			cout << endl;
			break;
						
		case 10:
			sortByWins(arr, size);
			cout << "\n=============== ������ ������������� ===============\n\n";
			break;

		case 11: 
			saveDB(arr, size); 
			break;

		default: if (menu > 11 && menu != 0) cout << "������� ������ ����� ����.\n\n"; break;
		}
	} while (menu != 0);



	return 0;
}