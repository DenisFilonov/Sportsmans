#include "Sportsman.h"

void Sportsman::fillSportsman()
{
	char tmp[100] = "";
	cout << "������� ��� ����������: ";
	cin.ignore();
	cin.getline(tmp, 100);
	name.setMyString(tmp);

	cout << "������� ��� ���������� (�/�): "; //��������
	cin >> gender;
	
	cout << "������� ���� �������� ����������: ";
	birth.fillDate();

	cout << "������� ���� ����������: ";
	cin >> height;

	cout << "������� ��� ����������: ";
	cin >> weight;

	cout << "������� ����� ����������: ";
	cin.ignore(); // ����� ���������, �.�. ���� �������� "���"
	cin.getline(tmp, 100);
	city.setMyString(tmp);

	cout << "������� ����������: ";
	cin.getline(tmp, 100);
	kindOfSport.setMyString(tmp);

	cout << "������� ���������� ������: ";
	cin >> wins;
	cout << endl;
}

void Sportsman::showSportsman()
{
	cout << "��� ����������: " << name.str << endl;
	cout << "��� ����������: " << gender << endl;
	cout << "���� �������� ����������: " << birth.toString(); cout << endl;
	cout << "���� ����������: " << height << endl;
	cout << "��� ����������: " << weight << endl;
	cout << "����� ����������: " << city.str << endl;
	cout << "���������� ����������: " << kindOfSport.str << endl;
	cout << "���������� ������: " << wins << endl << endl;
}

void Sportsman::saveToBinFile(FILE* fp)
{
	fwrite(&name.length, sizeof(int), 1, fp);
	fwrite(name.str, sizeof(char), name.length, fp); // + 1 ��� ����������� �����

	fwrite(&gender, sizeof(char), 1, fp);
	//fwrite(&birth, sizeof(Date), 1, fp); // 12 ���� ����� �������

	fwrite(&birth.day, sizeof(int), 1, fp);
	fwrite(&birth.month, sizeof(int), 1, fp);
	fwrite(&birth.year, sizeof(int), 1, fp);

	fwrite(&height, sizeof(float), 1, fp);
	fwrite(&weight, sizeof(float), 1, fp);

	fwrite(&city.length, sizeof(int), 1, fp);
	fwrite(city.str, sizeof(char), city.length, fp);

	fwrite(&kindOfSport.length, sizeof(int), 1, fp);
	fwrite(kindOfSport.str, sizeof(char), kindOfSport.length, fp);

	fwrite(&wins, sizeof(int), 1, fp);
}

void Sportsman::loadFromBinFile(FILE* fp)
{
	int size = 0;
	fread(&size, sizeof(int), 1, fp);
	name.str = new char[size];
	fread(name.str, sizeof(char), size, fp);

	fread(&gender, sizeof(char), 1, fp);
	//fread(&birth, sizeof(Date), 1, fp);
	fread(&birth.day, sizeof(int), 1, fp);
	fread(&birth.month, sizeof(int), 1, fp);
	fread(&birth.year, sizeof(int), 1, fp);

	fread(&height, sizeof(float), 1, fp);
	fread(&weight, sizeof(float), 1, fp);

	fread(&size, sizeof(int), 1, fp);
	city.str = new char[size];
	fread(city.str, sizeof(char), size, fp);

	fread(&size, sizeof(int), 1, fp);
	kindOfSport.str = new char[size];
	fread(kindOfSport.str, sizeof(char), size, fp);

	fread(&wins, sizeof(int), 1, fp);
}

void Sportsman::clearMemory()
{
	if (name.str!=NULL)	delete[] name.str;	
	if (city.str!=NULL)	delete[] city.str;
	if (kindOfSport.str!=NULL)	delete[] kindOfSport.str;
}

void Sportsman::editData()
{
	int choise;
	cout << "�������� ����������:\n";
	cout << "1. ����.\n";
	cout << "2. ���.\n";
	cout << "3. ���������� ������.\n�����: ";
	cin >> choise;
	/*	float height = 0; //����
	float weight = 0; //���
	MyString city; //�����
	MyString kindOfSport; //��� ������
	int wins = 0; //���������� ������ */
	switch (choise)
	{
	case 1: 
		cout << "\n����: ";
		cin >> height;
		cout << "\n���� ������!\n\n";
		break;

	case 2: 
		cout << "\n���: ";
		cin >> weight;
		cout << "\n��� ������!\n\n";
		break;

	case 3: 
		cout << "\n���������� ������: ";
		cin >> wins;
		cout << "\n���������� ������ ��������!\n\n";
		break;

	default: if (choise > 3 && choise != 0) cout << "������� ������ ����� ����.\n\n"; break;
	}
}

void addItem(Sportsman*& arr, int& size)
{
	cout << endl;
	Sportsman* tmp = new Sportsman[++size];
	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = arr[i];
	}
	if (arr != NULL) delete[] arr;
	cout << "������� ������ � ����� ����������: \n";
	tmp[size - 1].fillSportsman();
	arr = tmp;
	cout << "=========== ��������� �������� � ���� ������ ==========\n\n";
}

void delItem(Sportsman*& arr, int& size, int number)
{
	Sportsman* tmp = new Sportsman[--size];

	for (int i = 0; i < size; i++)
	{
		if (i < number) tmp[i] = arr[i];
		else if (i >= number) tmp[i] = arr[i + 1];
	}
	arr[number].clearMemory();
	if (arr != NULL) delete[] arr;
	arr = tmp;
	cout << "\n��������� #" << number + 1 << " ����� � ���� ������.\n\n";
}

void showItems(Sportsman*& arr, int& size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "��������� #" << i + 1 << endl;
		arr[i].showSportsman();
		cout << "\n====================================================\n\n";
	}
}

void showCurrSportsman(Sportsman*& arr, int& size, const char* name)
{
	int id = -1;
	for (int i = 0; i < size; i++)	if (strcmp(arr[i].name.str, name) == 0)	id = i;

	if (id == -1)	cout << "��������� \"" << name << "\" �� ������.\n";
	else	arr[id].showSportsman();
}

void editDataOfSportsman(Sportsman* arr, int size, const char* name)
{
	int id = -1;
	for (int i = 0; i < size; i++)	if (strcmp(arr[i].name.str, name) == 0)	id = i;

	if (id == -1)	cout << "��������� \"" << name << "\" �� ������.\n";
	else	arr[id].editData();
}

void tallSportsman(Sportsman* arr, int size)
{
	float max = arr[0].height;
	int id = -1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].height > max)
		{
			max = arr[i].height;
			id = i;
		}
	}
	cout << "\n����� ������� ���������:\n" << arr[id].name.str << ", � ������: " << arr[id].height << " ��.\n\n";
}

void threeBestSportsmans(Sportsman* arr, int size)
{
	sortByWins(arr, size);
	cout << "\n================ ������ ��� ������ ���������� ================\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "\n��� ����������: " << arr[i].name.str;
		cout << "\n����������: " << arr[i].kindOfSport.str;
		cout << "\n����� �����: " << arr[i].wins << endl << endl;
	}
	cout << "==============================================================\n\n";
}

void sortByWins(Sportsman* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j + 1].wins > arr[j].wins)
			{
				swap(arr[j + 1], arr[j]);
			}
		}
	}
}

void findByCity(Sportsman* arr, int size, const char* name)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].city.str, name) == 0) arr[i].showSportsman();
	}
}



void saveDB(Sportsman* arr, int size)
{
	FILE* fp;
	fopen_s(&fp, "Sportsmans.dat", "wb");
	if (fp == NULL)
	{
		cout << "\n======================================================\n";
		cout << "==  ������ ���������� ���� ������! ��������� �����  ==";
		cout << "\n======================================================\n\n";
	}
	else
	{
		fwrite(&size, sizeof(int), 1, fp);
		for (int i = 0; i < size; i++)
		{
			arr[i].saveToBinFile(fp);
		}
		fclose(fp);
		cout << "\n==============================================\n";
		cout << "==  ������ ������� ��������� � ���� ������  ==";
		cout << "\n==============================================\n\n";
	}
}

void loadDB(Sportsman*& arr, int& size)
{
	FILE* fp;
	fopen_s(&fp, "Sportsmans.dat", "rb");
	if (fp == NULL)
	{
		cout << "\n=====================================================\n";
		cout << "==  ������ �������� ���� ������! ��������� �����  ==";
		cout << "\n=====================================================\n\n";
		arr = nullptr;
		size = 0;
	}
	else
	{
		fread(&size, sizeof(int), 1, fp);
		arr = new Sportsman[size];
		for (int i = 0; i < size; i++)
		{
			arr[i].loadFromBinFile(fp);
		}
		fclose(fp);
		cout << "\n==============================================\n";
		cout << "==  ������ ������� ��������� � ���� ������  ==";
		cout << "\n==============================================\n\n";
	}
}
