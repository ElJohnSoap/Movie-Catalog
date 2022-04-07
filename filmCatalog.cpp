/*Создать структуру ВИДЕОМАГАЗИН со следующими
полями:
■ Название фильма;
■ Режиссер;
■ Жанр;
■ Рейтинг популярности;
■ Цена диска.
Реализовать следующие возможности:
■ Поиск по названию;
■ Поиск по жанру;
■ Поиск по режиссеру;
■ Самый популярный фильм в жанре;
■ Показ всех записей и добавление.
Для реализации задачи используйте функции. Объекты
структуры можно передавать в функцию целиком или
отдельными полями. Выберите верный механизм передачи в каждом конкретном случае*/
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
struct movie
{
	string name;
	string director;
	int genre;
	int rait;
	int price;
};

enum GENRE { NoName, Drama, Thriller, Action, Horror };
GENRE gnr = NoName;

string genreSelect(movie a); //выбор жанра
string genreSelect(int a);

//void menu();				//меню

movie creatFilm();			//создание элемента структуры

void printFilm(movie a);    //вывод элемента на экран

void addFilm(movie*& movieCat, int& size);//добавление в массив

void printCat(movie* a, int size); //печать массива

void searchGenre(movie* a, movie*& f, int size, int &size2);
void searchName(movie* a, int size);
void searchDir(movie* a, movie*& f, int size, int& size2);
void mostPopularFind(movie* a, int size);
void mostPopular(movie* a, int size);
void fill(movie*& movieCat) {
	movieCat[0] = { "Forrest Gump", "Robert Zemeckis", 1, 40, 200 };
	movieCat[1] = { "The Curious Case of Benjamin Button", "David Fincher", 1, 35, 225 };
	movieCat[2] = { "The Shining", "Stanley Kubrick", 2, 26, 125 };
	movieCat[3] = { "Fight Club", "David Fincher", 2, 50, 300 };
	movieCat[4] = { "Tough nut to crack", "John McTiernan", 3, 45, 250 };
	movieCat[5] = { "RoboCop", "Paul Verhoeven", 3, 45, 200 };
	movieCat[6] = { "Alien", "Ridley Scott", 4,44, 190 };
	movieCat[7] = { "World War Z", "Marc Forster", 4, 35, 150 };
	movieCat[8] = { "The Game", "David Fincher", 1, 46, 210 };
	movieCat[9] = { "Terminator 2: Judgment Day", "James Cameron", 3, 47, 250 };
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int size = 10, size2 = 0;
	movie* movieFind = new movie[size2];
	movie* movieCat = new movie[size];
	fill(movieCat);
	int menu;
	do {
		cout << "\n==========================" << endl;
		cout << "\n1 - Показ всех записей" << endl;
		cout << "2 - Добавление фильма" << endl;
		cout << "3 - сымый популярный в каталоге" << endl;
		cout << "4 - Поиск по названию" << endl;
		cout << "5 - Поиск по жанру" << endl;
		cout << "6 - Поиск по режиссеру" << endl;
		cout << "0 - Выход" << endl;
		cout << "\n==========================" << endl;
		cin >> menu;
		cin.ignore();
		switch (menu) {
		case 1: {
			printCat(movieCat, size);
		}
			  break;
		case 2: {
			addFilm(movieCat, size);

		}
			  break;
		case 3: {
			mostPopular(movieCat, size);
		}
			  break;
		case 4: {
			searchName(movieCat, size);
		}
			  break;
		case 5: {
			
			searchGenre(movieCat, movieFind, size, size2);
			printCat(movieFind, size2);
			mostPopularFind(movieFind, size2);
		}
			  break;
		case 6: {
			searchDir(movieCat, movieFind, size, size2);
			printCat(movieFind, size2);
			mostPopularFind(movieFind, size2);
		}
			  break;
		}

	} while (menu != 0);
	delete[]movieCat;
	delete[]movieFind;
	return 0;
}


string genreSelect(movie a) {
	string g;
	switch (a.genre) {
	case Drama:
	{
		g = "Драма";
		break;
	}
	case Thriller:
	{
		g = "Триллер";
		break;
	}
	case Action:
	{
		g = "Экшен";
		break;
	}
	case Horror:
	{
		g = "Ужасы";
		break;
	}
	case NoName:
	{
		g = "Жанр не задан";
		break;
	}
	default:
		g = "Жанр не задан";
	}
	return g;
}
string genreSelect(int a) {
	string g;
	switch (a) {
	case Drama:
	{
		g = "Драма";
		break;
	}
	case Thriller:
	{
		g = "Триллер";
		break;
	}
	case Action:
	{
		g = "Экшен";
		break;
	}
	case Horror:
	{
		g = "Ужасы";
		break;
	}
	case NoName:
	{
		g = "Жанр не задан";
		break;
	}
	default:
		g = "Жанр не задан";
	}
	return g;
}


movie creatFilm() {
	movie temp;
	cout << "Название ";
	getchar();
	getline(cin, temp.name);
	cout << "Режиссер ";
	getline(cin, temp.director);
	cout << "Выберите жанр\n 1 - Драма\n 2 - Триллер \n 3 - Экшен\n 4 - Ужасы\n";
	cin >> temp.genre;
	cout << "Рейтинг ";
	cin >> temp.rait;
	cout << "Цена ";
	cin >> temp.price;
	return temp;
}

void printFilm(movie a) {
	cout << endl;
	cout << "Название - " << a.name << endl;
	cout << "Режиссер - " << a.director << endl;
	cout << "Жанр     - " << genreSelect(a) << endl;
	cout << "Рейтинг  - " << a.rait << endl;
	cout << "Цена     - " << a.price << endl;
}

void addFilm(movie*& movieCat, int& size) {
	movie* temp = new movie[size + 1];
	for (int i = 0; i < size; i++) {
		temp[i] = movieCat[i];
	}
	temp[size] = creatFilm();
	delete[]movieCat;
	movieCat = temp;
	size++;
}

void printCat(movie* a, int size) {
	for (int i = 0; i < size; i++) {
		printFilm(a[i]);
	}
	cout << endl;
}

void searchGenre(movie* a, movie*& f, int size, int& size2) {
	cout << "Выберите жанр\n 1 - Драма\n 2 - Триллер \n 3 - Экшен\n 4 - Ужасы\n";
	int g;
	cin >> g;
	cout << "\nПоиск по жанру - " << genreSelect(g) << endl;
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (a[i].genre == g) {
				count++;
			}
		}
		movie* temp = new movie[count];
		for (int i = 0, j = 0; i < size; i++){
			if (a[i].genre == g) {
			temp[j] = a[i];
			j++;
			}
		}
		delete[]f;
		f = temp;
		size2 = count;
}

void searchName(movie* a, int size) {
	cout << "Введите название - ";
	string n;
	getline(cin, n);
	bool s = true;
	cout << "\nПоиск фильма - " << n << endl;
	for (int i = 0; i < size; i++) {
		if (_stricmp(a[i].name.c_str(), n.c_str()) == 0) {
			cout << i << " - " << a[i].name << endl;
			cout << "\nВывести полную инфу?\n1 - да, 0 - нет\n";
			int y;
			cin >> y;
			if (y==1) printFilm(a[i]);
			s = false;
		}
	}
	if (s) cout << "Фильм не найден";
}
void searchDir(movie* a, movie*& f, int size, int& size2) {
	cout << "Введите режиссера - ";
	string n;
	getline(cin, n);
	bool s = true;
	int count = 0;
	cout << "\nФильмы режиссера " << n << endl;
	for (int i = 0; i < size; i++) {
		
		if (_stricmp(a[i].director.c_str(), n.c_str()) == 0) {
			s = false;
			count++;
		}
	}
		if (count) {
			movie* temp = new movie[count];
			for (int i = 0, j = 0; i < size; i++) {
				if (_stricmp(a[i].director.c_str(), n.c_str()) == 0) {
					temp[j] = a[i];
					j++;
				}
			}
			delete[]f;
			f = temp;
			size2 = count;
		}
	if (s) cout << "Режиссер найден";
}

void mostPopular(movie* a, int size) {
	int top = a[0].rait, poz = 0;
	for (size_t i = 0; i < size; i++){
		if (a[i].rait > top) {
			top = a[i].rait;
			poz = i;
		}
	}
	cout << "The most popular - " << a[poz].name;
	cout << "\nВывести полную инфу?\n1 - да, 0 - нет\n";
	int y;
	cin >> y;
	if (y == 1) printFilm(a[poz]);
}
void mostPopularFind(movie* a, int size) {
	cout << "1 - Показать самый популярный?\n0 - Нет\n";
	int v;
	cin >> v;
	if (v) mostPopular(a, size);
}

