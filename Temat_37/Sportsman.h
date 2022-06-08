#include"Date.h"
#include"MyString.h"
#include<cstdio>;


struct Sportsman
{
	MyString name; //���
	char gender = 0; //���
	Date birth; //���� ��������
	float height = 0; //����
	float weight = 0; //���
	MyString city; //�����
	MyString kindOfSport; //��� ������
	int wins = 0; //���������� ������

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