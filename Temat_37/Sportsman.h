#include"Date.h"
#include"MyString.h"
#include<cstdio>;


struct Sportsman
{
	MyString name; //ФИО
	char gender = 0; //Пол
	Date birth; //Дата рождения
	float height = 0; //Рост
	float weight = 0; //Вес
	MyString city; //Город
	MyString kindOfSport; //Вид спорта
	int wins = 0; //Количество наград

	void fillSportsman();
	void showSportsman();
	void saveToBinFile(FILE* fp);
	void loadFromBinFile(FILE* fp);
	void clearMemory();
	void editData();
};

void addItem(Sportsman*& arr, int& size);
void delItem(Sportsman*& arr, int& size, int number);
void showItems(Sportsman*& arr, int& size);
void showCurrSportsman(Sportsman*& arr, int& size, const char* name);
void editDataOfSportsman(Sportsman* arr, int size, const char* name);
void tallSportsman(Sportsman* arr, int size);
void threeBestSportsmans(Sportsman* arr, int size);
void sortByWins(Sportsman* arr, int size);
void findByCity(Sportsman* arr, int size, const char* name);






void saveDB(Sportsman* arr, int size);
void loadDB(Sportsman*& arr, int& size);