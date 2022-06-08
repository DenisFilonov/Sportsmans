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
	if (fp == NULL) cout << "Ошибка открытия файла!\n";
	else
	{
		Vasya.saveToBinFile(fp);
		fclose(fp);
		cout << "Файл успешно сохранён, данные записаны!\n";
	}*/
	
	/*Sportsman Vasya;
	FILE* fp;
	fopen_s(&fp, "Vasya.dat", "rb");
	if (fp == NULL) cout << "Ошибка открытия файла!\n";
	else
	{
		Vasya.loadToBinFile(fp);
		fclose(fp);
		cout << "Файл успешно выгружен, данные записаны!\n\n";
	}
	Vasya.showSportsman();*/

	Sportsman* arr = nullptr;
	int size = 0;
	int menu;

	char name[100] = "";
	int id = -1;
/*1.	Добавить новую запись в конец файла. ..2
2.	Отредактировать данные по выбранному спортсмену ..6
3.	Удалить данные по выбранному спортсмену ..3
4.	Вывести данные о самом высоком спортсмене. ..7
5.	Получить фамилии трех лучших спортсменов ..8
6.	Получить список спортсменов с выбранного города ..9
7.	Отсортировать спортсменов по количеству наград (сортировка пузырьком) ..11
*/
	do
	{
		cout << "1. Загрузить данные о спортсменах.\n";//+
		cout << "2. Добавить нового спортсмена.\n";//+
		cout << "3. Удалить имеющегося спортсмена.\n";//+
		cout << "4. Показать информацию о спортсмене.\n";//+
		cout << "5. Показать список всех спортсменов.\n";//+
		cout << "6. Отредактировать данные по выбранному спортсмену.\n"; //+
		cout << "7. Вывести данные о самом высоком спортсмене.\n";//+
		cout << "8. Получить фамилии трех лучших спортсменов.\n"; //+
		cout << "9. Получить список спортсменов с выбранного города.\n";//+
		cout << "10. Сортировать спортсменов по количеству наград.\n"; //+
		cout << "11. Сохранить введённые данные.\n";//+
		cout << "0. Завершить раборту с приложением.\nВыбор: ";
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
			cout << "\nНомер удаляемого спортсмена: ";
			cin >> id;
			id--;
			delItem(arr, size, id);
			break;

		case 4: 
			cout << "\nФИО спортсмена: ";
			cin.ignore();
			cin.getline(name, 100);
			showCurrSportsman(arr, size, name);
			cout << endl;
			break;

		case 5: 
			showItems(arr, size); 
			break;

		case 6: 
			cout << "\nФИО спортсмена: ";
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
			cout << "\nГород: ";
			cin.ignore();
			cin.getline(name, 100);
			findByCity(arr, size, name);
			cout << endl;
			break;
						
		case 10:
			sortByWins(arr, size);
			cout << "\n=============== Данные отсортированы ===============\n\n";
			break;

		case 11: 
			saveDB(arr, size); 
			break;

		default: if (menu > 11 && menu != 0) cout << "Неверно выбран пункт меню.\n\n"; break;
		}
	} while (menu != 0);



	return 0;
}