#include <iostream>
#include <windows.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cmath>

using namespace std;
unsigned long long int G, P, X, iSimple;
bool bSimple = true;
string s;

void Numbers() {
	cout << "Введите простое P и целое G (G < P):" << endl;
	cin >> P >> G; //ввод чисел

	for (int i = 2; i < P; i++) {
		if (P % i == 0)
			bSimple = false;
	}
	if (G > P || bSimple == false) {
		cout << "Неправильный ввод!!!" << endl;
		G = 0;
		P = 0;
		bSimple = true;
		Numbers();
	}
}

void Number2() {
	cout << "Введите целое X (1 < X <= P - 1):" << endl;
	cin >> X;
	if (X < 1 || (P - 1) < X) {
		cout << "Неправильный ввод!!!" << endl;
		X = 0;
		Number2();
	}
}

void GenK() { //Генерация К
	int K;
	K = ((rand() + 1) % (P - 1));

	for (int i = K; i > 0; i--) {
		if (K % i == 0 && (P - 1) % i == 0 && i != 1 && K != 1) {
			i = 0;
			K = 0;
			GenK();
		}
		if (i == 1) {
			iSimple = K;
			if (iSimple == 1)
				iSimple += 1;
			cout << "K = " << iSimple << endl;
			i = 0;
			K = 0;
		}
	}
}

void matr() {
	int x1, x2, x3;
	int pos;
	int key;
	int ii[1488];
	int pos2;
	int pos3;
	string str1 = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя.,-?!: "; //Используемый алфавит
	string s2;
	string s3;
	string s4;
	cout << "Matrix 3x3\n" << "Enter first strochka:\n";
	int z1, z2, z3;
	cin >> z1 >> z2 >> z3;
	cout << "Enter second strochka :\n"; //Ввод матрицы
	int z4, z5, z6;
	cin >> z4 >> z5 >> z6;
	cout << "Enter third strochka :\n";
	int z7, z8, z9;
	cin >> z7 >> z8 >> z9;
	int A = (z1 * z5 * z9 + z2 * z6 * z7 + z3 * z4 * z8) - (z3 * z5 * z7 + z2 * z4 * z9 + z1 * z8 * z6);
	if (A == 0) { //Проверка обратимости матрицы
		cout << "Matrix ne obratima!\n";
	}
	else {
		int dlina = s.size();
		if (dlina % 3 == 1)
			dlina = dlina + 2;
		if (dlina % 3 == 2)
			dlina = dlina + 1;
		cout << "crypt info:\n";
		for (int i = 0; i < dlina; i++) { //считывание размера сообщения и цикл работы с каждым символом
			if (i % 3 == 0 & i < s.size())
				pos = str1.find(s[i]);
			if (i % 3 == 1 & i < s.size()) //Нахождение позиции символов в алфавите
				pos2 = str1.find(s[i]);
			if (i % 3 == 2 & i < s.size())
			{
				pos3 = str1.find(s[i]); //определение позиции символа в алфавите
				ii[i - 2] = pos * z1 + pos2 * z2 + pos3 * z3;
				ii[i - 1] = pos * z4 + pos2 * z5 + pos3 * z6;
				ii[i] = pos * z7 + pos2 * z8 + pos3 * z9;
				cout << ii[i - 2] << " " << ii[i - 1] << " " << ii[i] << " ";
				//шифрование символа
			}
			if (i % 3 == 1 & i > s.size() - 1)
				pos2 = 0;
			if (i % 3 == 2 & i > s.size() - 1)
			{
				pos3 = 0; //определение позиции символа в алфавите
				ii[i - 2] = pos * z1 + pos2 * z2 + pos3 * z3;
				ii[i - 1] = pos * z4 + pos2 * z5 + pos3 * z6;
				ii[i] = pos * z7 + pos2 * z8 + pos3 * z9;
				if (pos2 == 0)
					cout << ii[i - 2];
				if (pos3 == 0 & pos2 != 0)
					cout << ii[i - 2] << " " << ii[i - 1];
				//Шифрование последнего блока символов
			}
		}
		cout << endl << endl;
		int v1, v2, v3, v4, v5, v6, v7, v8, v9;
		v1 = z5 * z9 - z6 * z8;
		v4 = (-1) * (z4 * z9 - z7 * z6);
		v7 = z4 * z8 - z7 * z5;
		v2 = (-1) * (z2 * z9 - z3 * z8);//Расчёт обратной матрицы
		v5 = z1 * z9 - z7 * z3;
		v8 = (-1) * (z1 * z8 - z7 * z2);
		v3 = z2 * z6 - z5 * z3;
		v6 = (-1) * (z1 * z6 - z4 * z3);
		v9 = z1 * z5 - z4 * z2;
		cout << "Matrix dopolneniya:\n" << v1 << "  " << v4 << "  " << v7 << endl << v2 << "  " << v5 << "  " << v8 << endl << v3 << "  " << v6 << "  " << v9 << endl;
		cout << "Matrix transponirovannaya:\n" << v1 << "  " << v2 << "  " << v3 << endl << v4 << "  " << v5 << "  " << v6 << endl << v7 << "  " << v8 << "  " << v9 << endl;
		cout << "Matrix obratnaya:\n" << v1 << "/" << A << "  " << v2 << "/" << A << "  " << v3 << "/" << A << "  " << endl << v4 << "/" << A << "  " << v5 << "/" << A << "  " << v6 << "/" << A << "  " << endl << v7 << "/" << A << "  " << v8 << "/" << A << "  " << v9 << "/" << A << "  " << endl;
		for (int i = 0; i < dlina; i++) { //считывание размера сообщения и цикл работы с каждым символом
			if (i % 3 == 0 & i < s.size())
				pos = str1.find(s[i]);
			if (i % 3 == 1 & i < s.size()) //Определение позиции символов в алфавите
				pos2 = str1.find(s[i]);
			if (i % 3 == 2 & i < s.size())
			{
				pos3 = str1.find(s[i]); //определение позиции символа в алфавите
				s[i - 2] = str1[(ii[i - 2] * v1 + ii[i - 1] * v2 + ii[i] * v3) / A];
				s[i - 1] = str1[(ii[i - 2] * v4 + ii[i - 1] * v5 + ii[i] * v6) / A];
				s[i] = str1[(ii[i - 2] * v7 + ii[i - 1] * v8 + ii[i] * v9) / A];
				//шифрование символа
			}
			if (i % 3 == 1 & i > s.size() - 1)
				pos2 = 0;
			if (i % 3 == 2 & i > s.size() - 1)
			{
				pos3 = 0; //определение позиции символа в алфавите
				s[i - 2] = str1[(ii[i - 2] * v1 + ii[i - 1] * v2 + ii[i] * v3) / A];
				s[i - 1] = str1[(ii[i - 2] * v4 + ii[i - 1] * v5 + ii[i] * v6) / A];
				//Шифрование последних символов
			}
		}
		cout << "decrypt info:\n" << s << "\n"; //вывод расшифрованного сообщения
	}
}

void pleif() {
	int pos;
	int pos2;
	int pos3;
	int pos4;
	int pos5;
	string str1 = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
	string str2 = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //используемые алфавиты
	string str3 = ".,-?!: ";
	for (int i = 1; i < s.size(); i++) { //Разделение олинаковых букв
		if (str1.find(s[i]) != string::npos) //определение нахождения символа в алфавите
			pos2 = str1.find(s[i]);
		if (str2.find(s[i]) != string::npos)  //определение нахождения символа в алфавите
			pos2 = str2.find(s[i]);
		if (str3.find(s[i]) != string::npos)  //определение нахождения символа в алфавите
			pos2 = str3.find(s[i]);
		if (str1.find(s[i - 1]) != string::npos)  //определение нахождения символа в алфавите
			pos3 = str1.find(s[i - 1]);
		if (str2.find(s[i - 1]) != string::npos)  //определение нахождения символа в алфавите
			pos3 = str2.find(s[i - 1]);
		if (str3.find(s[i - 1]) != string::npos)  //определение нахождения символа в алфавите
			pos3 = str3.find(s[i - 1]);
		if (pos2 == pos3) {
			s.insert(i, 1, 'Ъ'); // вставим 1 СИМВОЛ 'a', в позицию 0
		}
	}
	cout << "Сообщение без рядом стоящих одинаковых букв:\n" << s << endl;
	cout << "Введите ключ(ТОЛЬКО ЗАГЛАВНЫЕ БУКВЫ):\n";
	string key;
	cin >> key;
	if (s.size() % 2 != 0)
		s = s + "Ъ"; //Дополнение сообщения до четного количества символов
	int registr[1488];
	for (int p = 0; p < s.size(); p++) { //Перевод сообщения в строчные буквы

		if (str1.find(s[p]) != string::npos) {
			registr[p] = 1;
			pos = str1.find(s[p]); //Определение позиции символа в алфавите
		}
		if (str2.find(s[p]) != string::npos) {
			registr[p] = 2;
			pos = str2.find(s[p]); //Определение позиции символа в алфавите
		}
		if (str3.find(s[p]) != string::npos) {
			registr[p] = 3;
			pos = str3.find(s[p]); //Определение позиции символа в алфавите
		}
		s[p] = str2[pos]; //Замена символа

	}

	cout << "Сообщение в нужном регистре:" << endl << s << endl;
	string str4 = "                                ";
	int alf[33]; //Создание таблицы
	for (int i = 0; i < 33; i++)
		alf[i] = 0;
	for (int o = 0; o < key.size(); o++) { //Добавление ключа в начале таблицы
		pos2 = str2.find(key[o]);
		str4[o] = str2[pos2];
		alf[pos2] = 1;
	}
	int j = key.size();
	for (int u = 0; u < 33; u++) { //Добавление оставшихся букв в таблицу
		if (alf[u] == 0) {
			str4[j] = str2[u];
			j++;
		}
	}
	cout << "Таблица 8х4:\n";
	for (int i = 0; i < 8; i++)
		cout << str4[i];
	cout << endl;
	for (int i = 8; i < 16; i++)
		cout << str4[i];
	cout << endl;
	for (int i = 16; i < 24; i++) //Вывод таблицы
		cout << str4[i];
	cout << endl;
	for (int i = 24; i < 32; i++)
		cout << str4[i];
	cout << endl;
	for (int b = 1; b < s.size(); b++) { //Шифрование
		pos4 = str4.find(s[b - 1]);  //Определение мест символов в алфавите
		pos5 = str4.find(s[b]);
		if (pos4 / 8 == pos5 / 8) {
			s[b - 1] = str4[((pos4 + 1) % 8) + (pos4 / 8) * 8];
			s[b] = str4[((pos5 + 1) % 8) + (pos5 / 8) * 8]; //Замена в случае нахождения букв на одной строчке
		}
		if (pos4 % 8 == pos5 % 8) {
			s[b - 1] = str4[(pos4 + 8) % 32]; //Замена в случае нахождения букв в одном столбце
			s[b] = str4[(pos5 + 8) % 32];
		}
		if (pos4 / 8 != pos5 / 8 & pos4 % 8 != pos5 % 8) {
			s[b - 1] = str4[pos4 - (pos4 % 8) + (pos5 % 8)]; //Замена в случае нахождения букв в противоположных местах
			s[b] = str4[pos5 - (pos5 % 8) + (pos4 % 8)];
		}
		//cout << s[b - 1] << s[b] << endl;
		b++;
	}
	cout << "Зашифрованное сообщение:" << endl << s << endl; //Вывод зашифрованного сообщения
	for (int bb = 1; bb < s.size(); bb++) { //Расшифрование
		pos4 = str4.find(s[bb - 1]);
		pos5 = str4.find(s[bb]); //Определение мест символов в алфавите
		if (pos4 / 8 == pos5 / 8) {
			s[bb - 1] = str4[((pos4 + 7) % 8) + (pos4 / 8) * 8]; //Замена в случае нахождения букв на одной строчке
			s[bb] = str4[((pos5 + 7) % 8) + (pos5 / 8) * 8];
		}
		if (pos4 % 8 == pos5 % 8) {
			s[bb - 1] = str4[(pos4 + 24) % 32]; //Замена в случае нахождения букв в одном столбце
			s[bb] = str4[(pos5 + 24) % 32];
		}
		if (pos4 / 8 != pos5 / 8 & pos4 % 8 != pos5 % 8) {
			s[bb - 1] = str4[pos4 - (pos4 % 8) + (pos5 % 8)]; //Замена в случае нахождения букв в противоположных местах
			s[bb] = str4[pos5 - (pos5 % 8) + (pos4 % 8)];
		}
		//cout << s[bb - 1] << s[bb] << endl;
		bb++;
	}
	cout << "Pacшифрованное сообщение(без учета регистра):" << endl << s << endl;
	for (int n = 0; n < s.size(); n++) {
		pos = str2.find(s[n]);
		if (registr[n] == 1)
			s[n] = str1[pos];
		if (registr[n] == 2) //Постановка символов в нужный регистр
			s[n] = str2[pos];
		if (registr[n] == 3)
			s[n] = str3[pos];
	}
	cout << "Pacшифрованное сообщение:" << endl;
	for (int iii = 0; iii < s.size(); iii++) {
		if (s[iii] != 'Ъ') {
			cout << s[iii];
		}
	}
	cout << endl;
}

void VertP() {
	int pos;
	int pos2;
	int pos3;
	string str1 = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя.,-?!: "; //Используемый алфавит
	std::cout << "Введите ключ (только буквы одного регистра):\n";
	string key;
	cin >> key;
	//string s2 = key + s;
	string s3 = "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            ";

	while (s.size() % key.size() != 0) {
		s = s + " ";
	}//Дополнение сообщения
	int schet[25];
	for (int i = 0; i < 25; i++)
		schet[i] = 0;
	for (int c = 0; c < key.size(); c++) { //Расчёт позиций букв ключа
		for (int v = 0; v < key.size(); v++) {
			if (str1.find(key[c]) > str1.find(key[v]))
				schet[c]++;
		}
		cout << schet[c];
	}
	for (int i = 0; i < key.size(); i++)
		schet[i] = schet[i] + 1;
	cout << endl << "Зашифрованное сообщение:" << endl;
	int zz = 1;
	int zx = 0;
	for (int x = 0; x < key.size(); x++) {
		for (int b = 0; b < key.size(); b++) {
			if (schet[b] == zz) {
				for (int n = 0; n < s.size(); n++) {
					if (n % key.size() == b) {
						s3[zx] = s[n]; //замена символов относительно ключа
						zx++;
					}
				}
				zz++;
			}
		}
	}
	for (int vv = 0; vv < s.size(); vv++)
		cout << s3[vv]; //Вывод зашифрованного сообщения
	zz--;
	zx--;
	int nn = s.size();
	for (int x = 0; x < key.size(); x++) {
		for (int b = 0; b < key.size(); b++) {
			if (schet[b] == zz) {
				for (int n = nn; n > 0; n--) {
					if (n % key.size() == b) {
						if (b == 0) {
							n = n - key.size();
						}
						//cout << zx << "->" << n << endl;
						//cout << s[n];
						s[n] = s3[zx]; //Обратная замена символов
									   //cout << s[n] << endl;
						if (b == 0) {
							n = n + key.size();
						}
						zx--;
					}
				}
				zz--;
			}
		}
	}
	cout << endl << "Расшифрованное сообщение:" << endl << s << endl; //Вывод расшифрованного сообщения
}

void Kard() {
	int ii[1488];
	int randd;
	string str1 = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя.,-?!: "; //Используемый алфавит
	string s2;
	int zz = s.size();
	cout << "Решетка Кардано 10х6:\n\n" //Вывод используемой решетки
		<< "0100000000\n1000101100\n0100010001\n0001000100\n0100000000\n0010011001\n\n";
	while (s.size() % 60 != 0) { //Дополонение сообщения
		randd = rand() % 65;
		s2 = str1[randd];
		s = s + s2;
	}
	cout << "Зашифрование:\n"; //вывод зашифрованного сообщения
	for (int i = 59; i < s.size(); i++) { //Замена символов
										  //Первый десяток
		ii[i - 59] = str1.find(s[i - 44]);
		ii[i - 58] = str1.find(s[i - 59]);
		ii[i - 57] = str1.find(s[i - 29]);
		ii[i - 56] = str1.find(s[i - 43]);
		ii[i - 55] = str1.find(s[i - 42]);
		ii[i - 54] = str1.find(s[i - 28]);
		ii[i - 53] = str1.find(s[i - 27]);
		ii[i - 52] = str1.find(s[i - 41]);
		ii[i - 51] = str1.find(s[i - 14]);
		ii[i - 50] = str1.find(s[i - 26]);
		//Второй десяток
		ii[i - 49] = str1.find(s[i - 58]);
		ii[i - 48] = str1.find(s[i - 25]);
		ii[i - 47] = str1.find(s[i - 13]);
		ii[i - 46] = str1.find(s[i - 12]);
		ii[i - 45] = str1.find(s[i - 56]);
		ii[i - 44] = str1.find(s[i - 11]);
		ii[i - 43] = str1.find(s[i - 57]);
		ii[i - 42] = str1.find(s[i - 55]);
		ii[i - 41] = str1.find(s[i - 40]);
		ii[i - 40] = str1.find(s[i - 10]);
		//Третий десяток
		ii[i - 39] = str1.find(s[i - 9]);
		ii[i - 38] = str1.find(s[i - 54]);
		ii[i - 37] = str1.find(s[i - 39]);
		ii[i - 36] = str1.find(s[i - 24]);
		ii[i - 35] = str1.find(s[i - 8]);
		ii[i - 34] = str1.find(s[i - 53]);
		ii[i - 33] = str1.find(s[i - 38]);
		ii[i - 32] = str1.find(s[i - 23]);
		ii[i - 31] = str1.find(s[i - 7]);
		ii[i - 30] = str1.find(s[i - 52]);
		//четвертый десяток
		ii[i - 29] = str1.find(s[i - 37]);
		ii[i - 28] = str1.find(s[i - 22]);
		ii[i - 27] = str1.find(s[i - 6]);
		ii[i - 26] = str1.find(s[i - 51]);
		ii[i - 25] = str1.find(s[i - 36]);
		ii[i - 24] = str1.find(s[i - 21]);
		ii[i - 23] = str1.find(s[i - 5]);
		ii[i - 22] = str1.find(s[i - 50]);
		ii[i - 21] = str1.find(s[i - 35]);
		ii[i - 20] = str1.find(s[i - 20]);
		//пятый десяток
		ii[i - 19] = str1.find(s[i - 19]);
		ii[i - 18] = str1.find(s[i - 49]);
		ii[i - 17] = str1.find(s[i - 34]);
		ii[i - 16] = str1.find(s[i - 33]);
		ii[i - 15] = str1.find(s[i - 18]);
		ii[i - 14] = str1.find(s[i - 32]);
		ii[i - 13] = str1.find(s[i - 17]);
		ii[i - 12] = str1.find(s[i - 16]);
		ii[i - 11] = str1.find(s[i - 4]);
		ii[i - 10] = str1.find(s[i - 31]);
		//Шестой десяток
		ii[i - 9] = str1.find(s[i - 3]);
		ii[i - 8] = str1.find(s[i - 15]);
		ii[i - 7] = str1.find(s[i - 48]);
		ii[i - 6] = str1.find(s[i - 2]);
		ii[i - 5] = str1.find(s[i - 1]);
		ii[i - 4] = str1.find(s[i - 47]);
		ii[i - 3] = str1.find(s[i - 46]);
		ii[i - 2] = str1.find(s[i - 0]);
		ii[i - 1] = str1.find(s[i - 30]);
		ii[i - 0] = str1.find(s[i - 45]);
		i += 59;
	}

	for (int y = 0; y < s.size(); y++) {
		s[y] = str1[ii[y]];
	}
	cout << s << endl;

	for (int ij = 59; ij < s.size(); ij++) { //считывание размера сообщения и цикл работы с каждым символом
											 //Обратная замена символов
											 //Первый десяток
		ii[ij - 44] = str1.find(s[ij - 59]);
		ii[ij - 59] = str1.find(s[ij - 58]);
		ii[ij - 29] = str1.find(s[ij - 57]);
		ii[ij - 43] = str1.find(s[ij - 56]);
		ii[ij - 42] = str1.find(s[ij - 55]);
		ii[ij - 28] = str1.find(s[ij - 54]);
		ii[ij - 27] = str1.find(s[ij - 53]);
		ii[ij - 41] = str1.find(s[ij - 52]);
		ii[ij - 14] = str1.find(s[ij - 51]);
		ii[ij - 26] = str1.find(s[ij - 50]);
		//Второй десяток
		ii[ij - 58] = str1.find(s[ij - 49]);
		ii[ij - 25] = str1.find(s[ij - 48]);
		ii[ij - 13] = str1.find(s[ij - 47]);
		ii[ij - 12] = str1.find(s[ij - 46]);
		ii[ij - 56] = str1.find(s[ij - 45]);
		ii[ij - 11] = str1.find(s[ij - 44]);
		ii[ij - 57] = str1.find(s[ij - 43]);
		ii[ij - 55] = str1.find(s[ij - 42]);
		ii[ij - 40] = str1.find(s[ij - 41]);
		ii[ij - 10] = str1.find(s[ij - 40]);
		//Третий десяток
		ii[ij - 9] = str1.find(s[ij - 39]);
		ii[ij - 54] = str1.find(s[ij - 38]);
		ii[ij - 39] = str1.find(s[ij - 37]);
		ii[ij - 24] = str1.find(s[ij - 36]);
		ii[ij - 8] = str1.find(s[ij - 35]);
		ii[ij - 53] = str1.find(s[ij - 34]);
		ii[ij - 38] = str1.find(s[ij - 33]);
		ii[ij - 23] = str1.find(s[ij - 32]);
		ii[ij - 7] = str1.find(s[ij - 31]);
		ii[ij - 52] = str1.find(s[ij - 30]);
		//четвертый десяток
		ii[ij - 37] = str1.find(s[ij - 29]);
		ii[ij - 22] = str1.find(s[ij - 28]);
		ii[ij - 6] = str1.find(s[ij - 27]);
		ii[ij - 51] = str1.find(s[ij - 26]);
		ii[ij - 36] = str1.find(s[ij - 25]);
		ii[ij - 21] = str1.find(s[ij - 24]);
		ii[ij - 5] = str1.find(s[ij - 23]);
		ii[ij - 50] = str1.find(s[ij - 22]);
		ii[ij - 35] = str1.find(s[ij - 21]);
		ii[ij - 20] = str1.find(s[ij - 20]);
		//пятый десяток
		ii[ij - 19] = str1.find(s[ij - 19]);
		ii[ij - 49] = str1.find(s[ij - 18]);
		ii[ij - 34] = str1.find(s[ij - 17]);
		ii[ij - 33] = str1.find(s[ij - 16]);
		ii[ij - 18] = str1.find(s[ij - 15]);
		ii[ij - 32] = str1.find(s[ij - 14]);
		ii[ij - 17] = str1.find(s[ij - 13]);
		ii[ij - 16] = str1.find(s[ij - 12]);
		ii[ij - 4] = str1.find(s[ij - 11]);
		ii[ij - 31] = str1.find(s[ij - 10]);
		//Шестой десяток
		ii[ij - 3] = str1.find(s[ij - 9]);
		ii[ij - 15] = str1.find(s[ij - 8]);
		ii[ij - 48] = str1.find(s[ij - 7]);
		ii[ij - 2] = str1.find(s[ij - 6]);
		ii[ij - 1] = str1.find(s[ij - 5]);
		ii[ij - 47] = str1.find(s[ij - 4]);
		ii[ij - 46] = str1.find(s[ij - 3]);
		ii[ij - 0] = str1.find(s[ij - 2]);
		ii[ij - 30] = str1.find(s[ij - 1]);
		ii[ij - 45] = str1.find(s[ij - 0]);
		ij += 59;
	}
	for (int yu = 0; yu < s.size(); yu++) {
		s[yu] = str1[ii[yu]];
	}
	cout << "\nРасшифрование:\n";
	for (int jh = 0; jh < zz; jh++) {
		cout << s[jh]; //вывод расшифрованного сообщения*/
	}
	cout << endl << endl;
}

void a52() {
	string str1 = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя.,-?!: "; //Используемый алфавит
	string s2;
	unsigned long long int pos, np, randd, F;
	np = s.size();
	while (s.size() % 9 != 0) {
		randd = rand() % 65;
		s2 = str1[randd];
		s = s + s2;
	} //Дополнение сообщения
	int dva[5000];
	for (int i = 0; i < 5000; i++)
		dva[i] = 0;
	for (int i = 0; i < s.size(); i++) { //Перевод в 2-иную систему счисления
										 //256||128||64||32||16||8||4||2||1
		pos = str1.find(s[i]);
		if (pos >= 256) {
			dva[i * 9 + 0] = 1;
			pos = pos - 256;
		}
		if (pos >= 128) {
			dva[i * 9 + 1] = 1;
			pos = pos - 128;
		}
		if (pos >= 64) {
			dva[i * 9 + 2] = 1;
			pos = pos - 64;
		}
		if (pos >= 32) {
			dva[i * 9 + 3] = 1;
			pos = pos - 32;
		}
		if (pos >= 16) {
			dva[i * 9 + 4] = 1;
			pos = pos - 16;
		}
		if (pos >= 8) {
			dva[i * 9 + 5] = 1;
			pos = pos - 8;
		}
		if (pos >= 4) {
			dva[i * 9 + 6] = 1;
			pos = pos - 4;
		}
		if (pos >= 2) {
			dva[i * 9 + 7] = 1;
			pos = pos - 2;
		}
		if (pos == 1) {
			dva[i * 9 + 8] = 1;
		}
	}
	cout << "Двочный код:" << endl;
	for (int i = 0; i < s.size() * 9; i++)
		cout << dva[i];
	cout << endl;
	int sh[5000];
	int gamma[81];
	cout << "Сгенерированный ключ:" << endl;
	for (int i = 0; i < 81; i++) { //Генерация ключа
		randd = rand() % 2; //Рандом от 0 до 1
		gamma[i] = randd;
		cout << gamma[i];
	}
	cout << endl;
	int zam;
	for (int i = 0; i < 5000; i++)
		sh[i] = 0;
	cout << "Зашифрованный двоичный код:" << endl;
	for (int j = 0; j < 5000; j++) {
		F = gamma[67] * gamma[71] | gamma[71] * gamma[74] | gamma[74] * gamma[67];
		if (F == gamma[8]) {
			zam = gamma[18] ^ gamma[17] ^ gamma[16] ^ gamma[13];
			gamma[18] = gamma[17];
			gamma[17] = gamma[16];
			gamma[16] = gamma[15];
			gamma[15] = gamma[14];
			gamma[14] = gamma[13];
			gamma[13] = gamma[12];
			gamma[12] = gamma[11];
			gamma[11] = gamma[10];
			gamma[10] = gamma[9];
			gamma[9] = gamma[8];
			gamma[8] = gamma[7];
			gamma[7] = gamma[6];
			gamma[6] = gamma[5];
			gamma[5] = gamma[4];
			gamma[4] = gamma[3];
			gamma[3] = gamma[2];
			gamma[2] = gamma[1];
			gamma[1] = gamma[0];
			gamma[0] = zam;
		}
		if (F == gamma[29]) {
			zam = gamma[40] ^ gamma[39];
			gamma[40] = gamma[39];
			gamma[39] = gamma[38];
			gamma[38] = gamma[37];
			gamma[37] = gamma[36];
			gamma[36] = gamma[35];
			gamma[35] = gamma[34];
			gamma[34] = gamma[33];
			gamma[33] = gamma[32];
			gamma[32] = gamma[31];
			gamma[31] = gamma[30];
			gamma[30] = gamma[29];
			gamma[29] = gamma[28];
			gamma[28] = gamma[27];
			gamma[27] = gamma[26];
			gamma[26] = gamma[25];
			gamma[25] = gamma[24];
			gamma[24] = gamma[23];
			gamma[23] = gamma[22];
			gamma[22] = gamma[21];
			gamma[21] = gamma[20];
			gamma[20] = gamma[19];
			gamma[19] = zam;
		}
		if (F == gamma[51]) {
			zam = gamma[63] ^ gamma[62] ^ gamma[61] ^ gamma[48];
			gamma[63] = gamma[62];
			gamma[62] = gamma[61];
			gamma[61] = gamma[60];
			gamma[60] = gamma[59];
			gamma[59] = gamma[58];
			gamma[58] = gamma[57];
			gamma[57] = gamma[56];
			gamma[56] = gamma[55];
			gamma[55] = gamma[54];
			gamma[54] = gamma[53];
			gamma[53] = gamma[52];
			gamma[52] = gamma[51];
			gamma[51] = gamma[50];
			gamma[50] = gamma[49];
			gamma[49] = gamma[48];
			gamma[48] = gamma[47];
			gamma[47] = gamma[46];
			gamma[46] = gamma[45];
			gamma[45] = gamma[44];
			gamma[44] = gamma[43];
			gamma[43] = gamma[42];
			gamma[42] = gamma[41];
			gamma[41] = zam;
		}
		zam = gamma[80] ^ gamma[74];
		gamma[80] = gamma[79];
		gamma[79] = gamma[78];
		gamma[78] = gamma[77];
		gamma[77] = gamma[76];
		gamma[76] = gamma[75];
		gamma[75] = gamma[74];
		gamma[74] = gamma[73];
		gamma[73] = gamma[72];
		gamma[72] = gamma[71];
		gamma[71] = gamma[70];
		gamma[70] = gamma[69];
		gamma[69] = gamma[68];
		gamma[68] = gamma[67];
		gamma[67] = gamma[66];
		gamma[66] = gamma[65];
		gamma[65] = gamma[64];
		gamma[64] = zam;
		//нахождение выходного бита
		sh[j] = gamma[12] ^ gamma[14] ^ gamma[15] ^ gamma[18] ^ gamma[40] ^ gamma[35] ^ gamma[32] ^ gamma[28] ^ gamma[54] ^ gamma[57] ^ gamma[59] ^ gamma[63];
	}
	for (int i = 0; i < s.size() * 9; i++) {
		cout << sh[i];
	}
	cout << endl;
	cout << "Зашифрованный текст (в двоичном виде):" << endl;
	for (int i = 0; i < s.size() / 9; i++) {
		for (int j = 0; j < 81; j++) {
			dva[j + i * 81] = dva[j + i * 81] ^ sh[j];
			cout << dva[j + i * 81];
		}
	}
	cout << endl << "Расшифрованный текст (в двоичном виде):" << endl;
	for (int i = 0; i < s.size() / 9; i++) {
		for (int j = 0; j < 81; j++) {
			dva[j + i * 81] = dva[j + i * 81] ^ sh[j];
			cout << dva[j + i * 81];
		}
	}
	for (int i = 0; i < s.size(); i++) { //Перевод в 10-ричную систему счисления
										 //128||64||32||16||8||4||2||1
		pos = 0;
		if (dva[i * 9 + 0] == 1)
			pos = pos + 256;
		if (dva[i * 9 + 1] == 1)
			pos = pos + 128;
		if (dva[i * 9 + 2] == 1)
			pos = pos + 64;
		if (dva[i * 9 + 3] == 1)
			pos = pos + 32;
		if (dva[i * 9 + 4] == 1)
			pos = pos + 16;
		if (dva[i * 9 + 5] == 1)
			pos = pos + 8;
		if (dva[i * 9 + 6] == 1)
			pos = pos + 4;
		if (dva[i * 9 + 7] == 1)
			pos = pos + 2;
		if (dva[i * 9 + 8] == 1)
			pos = pos + 1;
		s[i] = str1[pos];
	}
	cout << endl << "Расшифрованный текст:" << endl;
	for (int i = 0; i < np; i++)
		cout << s[i];
	cout << endl;
}

int rsa() {
	uint64_t pp = 0;
	uint64_t qq = 0;
	string str1 = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя.,-?!: "; //Испольщуемый алфавит

	cout << "Введите простые числа P и Q:\nР = ";
	cin >> pp;
	if (pp == 2) {
		cout << "P - не простое. Введите другое значение Р" << endl;
		system("pause");
		return 0;
	}
	for (int i = 2; i < pp; i++) {
		if (pp % i == 0) {
			cout << "P - не простое. Введите другое значение Р" << endl;
			system("pause");
			return 0;
		}
	}
	cout << "Q = ";
	cin >> qq; //Ввод Q
	if (qq == 2) {
		cout << "Q - не простое. Введите другое значение Q" << endl;
		system("pause");
		return 0;
	}
	for (int i = 2; i < qq; i++) {
		if (qq % i == 0) {
			cout << "Q - не простое. Введите другое значение Q" << endl;
			system("pause");
			return 0;
		}
	}
	cout << endl;
	uint64_t n = pp * qq; //Высчитывание n
	if (n < str1.size()) {
		cout << "Число N меньше длины алфавита. Введите Р и Q большей длины" << endl;
		system("pause");
		return 0;
	}
	uint64_t m = (pp - 1) * (qq - 1); //Высчитывание М
	uint64_t d;
	cout << "Введите целое число D:\nD = ";
	cin >> d;
	//cout << endl;
	for (int i = d; i > 1; i--) {
		if (d % i == 0 && m % i == 0) {
			cout << "D и M - не взаимно простые. Введите другое значение переменных" << endl;
			system("pause");
			return 0;
		}
	}

	// РАСШИРЕННЫЙ АЛГОРИТМ ЕВКЛИДА
	uint64_t e;
	uint64_t ostatok[100];
	uint64_t q[100];
	uint64_t i;
	while (d > m)
		d = d - m;
	for (i = 0; i < 1000; i++) {
		if (i == 0) {
			q[i] = m / d;
			ostatok[i] = m % d;
		}
		else {
			if (i == 1) {
				q[i] = d / ostatok[i - 1];
				ostatok[i] = d % ostatok[i - 1];
				if (ostatok[i] == 0)
					break;
			}
			else {
				q[i] = ostatok[i - 2] / ostatok[i - 1];
				ostatok[i] = ostatok[i - 2] % ostatok[i - 1];
				if (ostatok[i] == 0)
					break;
			}
		}
	}
	i = i + 1;
	uint64_t ch;
	uint64_t ch2;
	uint64_t ch3;
	for (int z = 0; z < i - 1; z++) {
		if (z == 0) {
			ch = q[z];
		}
		else {
			if (z == 1) {
				ch2 = ch;
				ch3 = ch2;
				ch = q[z] * ch + 1;
			}
			else {
				ch3 = ch;
				ch = ch * q[z] + ch2;
				ch2 = ch3;
			}
		}
	}
	if (i % 2 == 0)
		e = ch * (-1) + m;
	else e = ch;
	cout << e << endl;
	//КОНЕЦ АЛГОРИТМА ЕВКЛИДА
	cout << "D = " << d << " N = " << n << endl;
	uint64_t soob2[600];
	for (int i = 0; i < 600; i++)
		soob2[i] = 1;
	uint64_t ost;
	uint64_t ost2;
	uint64_t pos;
	uint64_t hash(0);
	for (int i(0); i < s.size(); i++) {
		hash = ((hash + str1.find(s[i]) * (i + 1))) % (pp - 1); //Нахождение Хеша от сообщения
	}
	if (hash == 1)
		hash += 1;

	cout << "Хэш-значение: " << hash << endl;
	uint64_t ss(1);
	for (int b = 0; b < d; b++) {
		ss = (ss * hash) % n;
	}
	cout << "S = " << ss << endl; //Расчёт S
	uint64_t mm(1);
	for (int b = 0; b < e; b++) {
		mm = (mm * ss) % n;
	}
	cout << "M' = " << mm << endl; //Расчёт М
	if (mm == hash) {
		cout << "Все здорово!" << endl;
	}
	else {
		cout << "Всё плохо!" << endl;
	}
	return 0;
}

int g341094() {
	string str1 = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя.,-?!: ";
	unsigned long long int P, Q, a, aa, x, y, k, r, ss, hash, v, z1, z2, u, u1, u2;
	cout << "Введите большое простое P и простой сомножитель числа (Р-1) Q (Q < (P-1)):" << endl;
	cin >> P >> Q; //ввод чисел
	for (int i = 2; i < Q; i++) {
		if (Q % i == 0) {
			cout << "G не простое число. Введите другое значение G" << endl;
			return 0;
		}
	}
	if ((P - 1) % Q != 0) {
		cout << "G не является простым сомножителем (Р-1). Введите другое значение G" << endl;
		std::system("pause");
		return 0;
	}
	cout << "Введите число а, меньшее (р-1), такое, что а^q mod P =1: " << endl;
	cin >> a;
	aa = pow(a, Q);
	if (aa % P != 1) {
		cout << "уравнение а^q mod P =1 не выполняется. Введите другое значение а." << endl;
		std::system("pause");
		return 0;
	}
	if (a >= P) {
		cout << "а не меньше (Р-1). Введите другое значение а" << endl;
		std::system("pause");
		return 0;
	}
	cout << "Введите число x, меньшее Q: " << endl;
	cin >> x;
	if (x >= Q) {
		cout << "x не меньше Q. Введите другое значение x" << endl;
		std::system("pause");
		return 0;
	}
	y = 1;
	for (int h = 0; h < x; h++) {
		y = (y * a) % P;
	}
	cout << "y = " << y << endl;
	k = rand() % Q;
	r = 1;
	for (int h = 0; h < k; h++) {
		r = (r * a) % P;
		if (r == 0)
			r = r + 1;
	}
	r = r % Q;
	hash = 3;
	for (int i(0); i < s.size(); i++) {
		hash = ((hash + str1.find(s[i]) * (i + 1))) % (P - 1);
	}
	if (hash % Q == 0) {
		hash += 2;
	}
	if (hash == 1)
		hash += 1;
	cout << "Хеш - значение = " << hash << endl;
	ss = (x * r + k * hash) % Q;
	cout << "r = " << r << " s = " << ss << endl;

	v = 1;
	for (int h = 0; h < Q - 2; h++) {
		v = (v * hash) % Q;
		if (v == 0)
			v = v + 1;
	}
	z1 = (ss * v) % Q;
	z2 = ((Q - r) * v) % Q;
	u1 = 1;
	u2 = 1;
	for (int h = 0; h < z1; h++) {
		u1 = (u1 * a) % P;
		if (u1 == 0)
			u1 = u1 + 1;
	}

	for (int h = 0; h < z2; h++) {
		u2 = (u2 * y) % P;
		if (u2 == 0)
			u2 = u2 + 1;
	}
	u = ((u1 * u2) % P) % Q;
	cout << "u = " << u << endl;
	if (u == r) {
		cout << "Подпись верна!" << endl;
	}
	else {
		cout << "Подпись не верна!" << endl;
	}
	return 0;
}

int g341012() {
	string str1 = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя.,-?!: "; //Используемый алфавит
	int p;
	cout << "Введите простое значение p:" << endl << "p = ";
	cin >> p;
	for (int i = 2; i < p; i++) {
		if (p % i == 0) {
			cout << "p - не простое. Введите другое значение p" << endl;
			std::system("pause");
			return 0;
		}
	}

	int a, b;
	cout << "Введите коэффициенты эллиптической кривой:" << endl << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	int D = (4 * a * a * a + 27 * b * b) % p;
	cout << "Дискрименант D = " << D << endl;
	if (D == 0) {
		cout << "Выберите другие коэффициенты эллиптической кривой" << endl;
		std::system("pause");
		return 0;
	}

	int x = 0;
	int y2, t1, t2, k, l, xx, yy, zn, y, kmax(0), kol(1), kk[500], xuni(0);
	for (int i = 0; i < 500; i++)
		kk[i] = 0;
	//Нахождение точек
	for (x; x < p; x++) {
		y2 = (x * x * x + a * x + b) % p;
		if (y2 == 0) {
			t1 = 0;
			t2 = 0;
			cout << "x = " << x << " y = 0";
			k = 2;
			kk[xuni] = k;
			xuni++;
			kol++;
			cout << " K = 2" << endl;
			if (kmax < k)
				kmax = k;
		}
		if (y2 != 0) {
			for (int i = 0; i < p; i++) {
				if ((i * i) % p == y2) {
					t1 = i;
					t2 = i * (-1) + p;
					cout << "x = " << x << " y1 = " << t1 << " y2 = " << t2;
					kol++;
					kol++;
					break;
				}
			}
		}
		for (int i = 0; i < p; i++) {
			if (y2 != 0) {
				if ((i * i) % p == y2) {
					l = 1;
					zn = 2 * t1;
					for (int j = 0; j < p - 2; j++) {
						l = (l * zn) % p;
					}
					l = (l * (3 * x * x + a)) % p;
					if (l < 0)
						l = l + p;
					xx = (l * l - x - x) % p;
					if (xx < 0)
						xx = xx + p;
					yy = (l * (x - xx) - t1) % p;
					if (yy < 0)
						yy = yy + p;
					//cout << endl << "L " << l << " X " << xx << " Y " << yy;
					k = 2;
					while (xx - x != 0 && yy - t1 != 0) {
						l = 1;
						zn = xx - x;
						for (int j = 0; j < p - 2; j++) {
							l = (l * zn) % p;
						}
						l = (l * (yy - t1)) % p;
						if (l < 0)
							l = l + p;
						xx = (l * l - xx - x) % p;
						if (xx < 0)
							xx = xx + p;
						yy = (l * (x - xx) - t1) % p;
						if (yy < 0)
							yy = yy + p;
						k++;
						//cout << endl << "L " << l << " X " << xx << " Y " << yy;
					}
					k++;
					cout << " K1 = " << k;
					kk[xuni] = k;
					xuni++;

					if (kmax < k)
						kmax = k;
					k = 0;
					break;
				}
			}
		}
		//Расчёт порядков
		for (int i = 0; i < p; i++) {
			if (y2 != 0) {
				if ((i * i) % p == y2) {
					l = 1;
					zn = 2 * t2;
					for (int j = 0; j < p - 2; j++) {
						l = (l * zn) % p;
					}
					l = (l * (3 * x * x + a)) % p;
					if (l < 0)
						l = l + p;
					xx = (l * l - x - x) % p;
					if (xx < 0)
						xx = xx + p;
					yy = (l * (x - xx) - t2) % p;
					if (yy < 0)
						yy = yy + p;
					//cout << endl << "L " << l << " X " << xx << " Y " << yy;
					k = 2;
					while (xx - x != 0 && yy - t2 != 0) {
						l = 1;
						zn = xx - x;
						for (int j = 0; j < p - 2; j++) {
							l = (l * zn) % p;
						}
						l = (l * (yy - t2)) % p;
						if (l < 0)
							l = l + p;
						xx = (l * l - xx - x) % p;
						if (xx < 0)
							xx = xx + p;
						yy = (l * (x - xx) - t2) % p;
						if (yy < 0)
							yy = yy + p;
						k++;
						//cout << endl << "L " << l << " X " << xx << " Y " << yy;
					}
					k++;
					cout << " K2 = " << k << endl;
					kk[xuni] = k;
					xuni++;
					if (kmax < k)
						kmax = k;
					k = 0;
					break;
				}
			}
		}
	}
	//Расчёт q и n
	int vb, z(0);
	for (int i = 0; i < kol - 1; i++) {
		if (kol % kk[i] == 0) {
			if (kk[i] == 2 && z < kk[i])
				z = kk[i];
			for (int j = 2; j < kk[i]; j++) {
				if (kk[i] % j == 0) {
					break;
				}
				if (j == kk[i] - 1) {
					if (z < kk[i])
						z = kk[i];
				}
			}
		}
	}
	cout << "q = " << z << endl;
	cout << "n = " << kol << endl;
	int h = kol / z;
	cout << "h = " << h << endl;

	cout << "Введите координаты одной из точек:" << endl << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	if ((y * y) % p != (x * x * x + a * x + b) % p) {
		cout << "Точки не существует. Введите существующие значения" << endl;
		system("pause");
		return 0;
	}


	int Gx(1), Gy;
	//Расчёт генератора
	if (h != 1) {
		l = 1;
		zn = 2 * y;
		for (int j = 0; j < p - 2; j++) {
			l = (l * zn) % p;
		}
		l = (l * (3 * x * x + a)) % p;
		if (l < 0)
			l = l + p;
		Gx = (l * l - x - x) % p;
		if (Gx < 0)
			Gx = Gx + p;
		Gy = (l * (x - Gx) - y) % p;
		if (Gy < 0)
			Gy = Gy + p;
	}
	else {
		Gx = x;
		Gy = y;
	}
	for (int i = 1; i < h - 1; i++) {
		if (Gx - x == 0 || Gy - y == 0) {
			cout << "G = 0. Необходимо выбрать другую точку." << endl;
			system("pause");
			return 1;
		}
		l = 1;
		zn = Gx - x;
		for (int j = 0; j < p - 2; j++) {
			l = (l * zn) % p;
		}
		l = (l * (Gy - y)) % p;
		if (l < 0)
			l = l + p;
		Gx = (l * l - Gx - x) % p;
		if (Gx < 0)
			Gx = Gx + p;
		Gy = (l * (x - Gx) - y) % p;
		if (Gy < 0)
			Gy = Gy + p;
	}
	cout << "G = (" << Gx << ", " << Gy << ")" << endl;

	int X;
	cout << "Введите значение X, меньшее q: X = ";
	cin >> X;
	if (X >= z) {
		cout << "Х больше или равно q. Введите другое значение Х." << endl;
		std::system("pause");
		return 0;
	}
	if (X <= 0) {
		cout << "Х меньше или равен 0. Введите другое значение Х." << endl;
		std::system("pause");
		return 0;
	}

	xx = 1;
	if (X != 1) {
		l = 1;
		zn = 2 * Gy;
		for (int j = 0; j < p - 2; j++) {
			l = (l * zn) % p;
		}
		l = (l * (3 * Gx * Gx + a)) % p;
		if (l < 0)
			l = l + p;
		xx = (l * l - Gx - Gx) % p;
		if (xx < 0)
			xx = xx + p;
		yy = (l * (Gx - xx) - Gy) % p;
		if (yy < 0)
			yy = yy + p;
	}
	else {
		xx = Gx;
		yy = Gy;
	}
	//Расчёт Y
	for (int i = 1; i < X - 1; i++) {
		l = 1;
		zn = xx - Gx;
		for (int j = 0; j < p - 2; j++) {
			l = (l * zn) % p;
		}
		l = (l * (yy - Gy)) % p;
		if (l < 0)
			l = l + p;
		xx = (l * l - xx - Gx) % p;
		if (xx < 0)
			xx = xx + p;
		yy = (l * (Gx - xx) - Gy) % p;
		if (yy < 0)
			yy = yy + p;
	}
	cout << "Y = (" << xx << ", " << yy << ")" << endl;

	int hash = 3;
	for (int i = 0; i < s.size(); i++) { //Нахождение хеш-значения
		hash = ((hash + str1.find(s[i]) * str1.find(s[i]))) % p;
	}
	cout << "Хеш-значение: " << hash << endl;

	int randd;
	randd = rand() % (z - 2) + 1;
	cout << "k = " << randd << endl;

	int xxx = 1;
	int yyy;
	//Расчёт P
	if (randd != 1) {
		l = 1;
		zn = 2 * Gy;
		for (int j = 0; j < p - 2; j++) {
			l = (l * zn) % p;
		}
		l = (l * (3 * Gx * Gx + a)) % p;
		if (l < 0)
			l = l + p;
		xxx = (l * l - Gx - Gx) % p;
		if (xxx < 0)
			xxx = xxx + p;
		yyy = (l * (Gx - xxx) - Gy) % p;
		if (yyy < 0)
			yyy = yyy + p;
	}
	else {
		xxx = Gx;
		yyy = Gy;
	}
	for (int i = 1; i < randd - 1; i++) {
		l = 1;
		zn = xxx - Gx;
		for (int j = 0; j < p - 2; j++) {
			l = (l * zn) % p;
		}
		l = (l * (yyy - Gy)) % p;
		if (l < 0)
			l = l + p;
		xxx = (l * l - xxx - Gx) % p;
		if (xxx < 0)
			xxx = xxx + p;
		yyy = (l * (x - xxx) - Gy) % p;
		if (yyy < 0)
			yyy = yyy + p;
	}
	cout << "P = (" << xxx << ", " << yyy << ")" << endl;

	int r = xxx % z; //Расчёт R
	int ss = (randd * hash + r * X) % z; //Расчёт S
	cout << "R = " << r << " S = " << ss << endl;

	if (r == 0 || ss == 0) {
		cout << "r или s равны 0. Необходимы другие значения." << endl;
		system("pause");
		return 0;
	}

	cout << endl << "ПРОВЕРКА ПОДПИСИ" << endl;
	hash = 3;
	for (int i = 0; i < s.size(); i++) { //Нахождение хеш-значений
		hash = ((hash + str1.find(s[i]) * str1.find(s[i]))) % p;
	}
	cout << "Хеш-значение: " << hash << endl;
	if (r > z || ss > z || r <= 0 || ss <= 0) {
		cout << "r или s выходят за границы допустимых значений. Подпись неверна!" << endl;
		system("pause");
		return 0;
	}

	int u1(1), u2(1);
	for (int i = 0; i < z - 2; i++) { //Расчёт U1
		u1 = (u1 * hash) % z;
	}
	u1 = (u1 * ss) % z;
	if (u1 < 0)
		u1 = u1 + z;
	for (int i = 0; i < z - 2; i++) { //Расчёт U2
		u2 = (u2 * hash) % z;
	}
	u2 = (u2 * r * (-1)) % z;
	if (u2 < 0)
		u2 = u2 + z;
	cout << "U1 = " << u1 << " U2 = " << u2 << endl;

	int xxxx = 1;
	int yyyy;
	if (u1 != 1) {
		l = 1;
		zn = 2 * Gy;
		for (int j = 0; j < p - 2; j++) { //Расчёт P1
			l = (l * zn) % p;
		}
		l = (l * (3 * Gx * Gx + a)) % p;
		if (l < 0)
			l = l + p;
		xxxx = (l * l - Gx - Gx) % p;
		if (xxxx < 0)
			xxxx = xxxx + p;
		yyyy = (l * (Gx - xxxx) - Gy) % p;
		if (yyyy < 0)
			yyyy = yyyy + p;
	}
	else {
		xxxx = Gx;
		yyyy = Gy;
	}
	for (int i = 1; i < u1 - 1; i++) {
		l = 1;
		zn = xxxx - Gx;
		for (int j = 0; j < p - 2; j++) {
			l = (l * zn) % p;
		}
		l = (l * (yyyy - Gy)) % p;
		if (l < 0)
			l = l + p;
		xxxx = (l * l - xxxx - Gx) % p;
		if (xxxx < 0)
			xxxx = xxxx + p;
		yyyy = (l * (Gx - xxxx) - Gy) % p;
		if (yyyy < 0)
			yyyy = yyyy + p;
	}
	cout << "P1 = (" << xxxx << ", " << yyyy << ")" << endl;

	int xxxxx = 1;
	int yyyyy;
	if (u2 != 1) {
		l = 1;
		zn = 2 * yy;
		for (int j = 0; j < p - 2; j++) {
			l = (l * zn) % p;
		}
		l = (l * (3 * xx * xx + a)) % p;
		if (l < 0)
			l = l + p;
		xxxxx = (l * l - xx - xx) % p;
		if (xxxxx < 0)
			xxxxx = xxxxx + p;
		yyyyy = (l * (xx - xxxxx) - yy) % p;
		if (yyyyy < 0)
			yyyyy = yyyyy + p;
	}
	else {
		xxxxx = xx;
		yyyyy = yy;
	}
	for (int i = 1; i < u2 - 1; i++) { //Расчёт P2
		l = 1;
		zn = xxxxx - xx;
		for (int j = 0; j < p - 2; j++) {
			l = (l * zn) % p;
		}
		l = (l * (yyyyy - yy)) % p;
		if (l < 0)
			l = l + p;
		xxxxx = (l * l - xxxxx - xx) % p;
		if (xxxxx < 0)
			xxxxx = xxxxx + p;
		yyyyy = (l * (xx - xxxxx) - yy) % p;
		if (yyyyy < 0)
			yyyyy = yyyyy + p;
	}
	cout << "P2 = (" << xxxxx << ", " << yyyyy << ")" << endl;

	int xxxxxx;
	int yyyyyy;

	l = 1;
	zn = xxxxx - xxxx;
	for (int j = 0; j < p - 2; j++) {
		l = (l * zn) % p;
	}
	l = (l * (yyyyy - yyyy)) % p; //Расчёт P
	if (l < 0)
		l = l + p;
	xxxxxx = (l * l - xxxxx - xxxx) % p;
	if (xxxxxx < 0)
		xxxxxx = xxxxxx + p;
	yyyyyy = (l * (xxxx - xxxxxx) - yyyy) % p;
	if (yyyyyy < 0)
		yyyyyy = yyyyyy + p;
	cout << "P = (" << xxxxxx << ", " << yyyyyy << ")" << endl;
	int geog = xxxxxx % z;
	cout << "x mod q = " << geog << endl;
	if (geog == r) {
		cout << "Подпись верна!" << endl;
	}
	else {
		cout << "Подпись не верна!" << endl;
	}
	return 0;
}

void imitovstavka() {

	setlocale(LC_ALL, "Russian"); //добавление русского языка
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str1 = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя.,-?!: "; //Используемый алфавит
	int np = s.size();
	int randd;
	string s2;
	while (s.size() < 16) {  //Дополнение сообщения
		randd = rand() % 65;
		s2 = str1[randd];
		s = s + s2;
	}
	while (s.size() % 8 != 0) { //Дополнение сообщения
		randd = rand() % 65;
		s2 = str1[randd];
		s = s + s2;
	}
	int dva[1100];
	int shifr[1100];
	for (int i = 0; i < 1100; i++) {
		dva[i] = 0;
		shifr[i] = 0;
	}

	int key[64]; //Генерация ключа
	for (int i = 0; i < 64; i++)
		key[i] = rand() % 16;

	int pos;
	for (int i = 0; i < s.size(); i++) { //перевод в 16-ричную систему счисления
		pos = str1.find(s[i]);
		dva[i * 2] = pos / 16;
		dva[i * 2 + 1] = pos % 16;
	}

	int dlina;
	for (int i = 0; i < s.size() * 2; i++) {
		dlina = i + 1;
	}

	int l[8], r[8];
	cout << "16-ричное сообщение:" << endl;
	for (int i = 0; i < dlina; i++)
		cout << dva[i] << " ";
	cout << endl;
	//Начало сети фейстеля
	for (int i = 0; i < 8; i++) {
		l[i] = dva[i];
		r[i] = dva[i + 8];
	}
	int l_zap;
	int dvadva[32];
	for (int i = 0; i < 32; i++)
		dvadva[i] = 0;
	int dvadva_zam;


	for (int x = 1; x < dlina / 16; x++) {
		for (int h = 0; h < 16; h++) {
			for (int i = 0; i < 8; i++) {
				l_zap = l[i];
				//Сложение с ключом
				l[i] = l[i] ^ key[i + ((h * 8) % 64)];
				//С-блок
				if (i % 8 == 0) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 4;
						else {
							if (l[i] == 2)
								l[i] = 6;
							else {
								if (l[i] == 3)
									l[i] = 2;
								else {
									if (l[i] == 4)
										l[i] = 10;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 11;
											else {
												if (l[i] == 7)
													l[i] = 9;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 8;
														else {
															if (l[i] == 10)
																l[i] = 13;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 0;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 15;
																			else {
																				if (l[i] == 15)
																					l[i] = 1;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 1) {
					if (l[i] == 0)
						l[i] = 6;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 3;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 10;
										else {
											if (l[i] == 6)
												l[i] = 5;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 1;
													else {
														if (l[i] == 9)
															l[i] = 14;
														else {
															if (l[i] == 10)
																l[i] = 4;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 13;
																		else {
																			if (l[i] == 14)
																				l[i] = 0;
																			else {
																				if (l[i] == 15)
																					l[i] = 15;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 2) {
					if (l[i] == 0)
						l[i] = 11;
					else {
						if (l[i] == 1)
							l[i] = 3;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 8;
								else {
									if (l[i] == 4)
										l[i] = 2;
									else {
										if (l[i] == 5)
											l[i] = 15;
										else {
											if (l[i] == 6)
												l[i] = 10;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 1;
														else {
															if (l[i] == 10)
																l[i] = 7;
															else {
																if (l[i] == 11)
																	l[i] = 4;
																else {
																	if (l[i] == 12)
																		l[i] = 12;
																	else {
																		if (l[i] == 13)
																			l[i] = 9;
																		else {
																			if (l[i] == 14)
																				l[i] = 6;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 3) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 1;
								else {
									if (l[i] == 4)
										l[i] = 13;
									else {
										if (l[i] == 5)
											l[i] = 4;
										else {
											if (l[i] == 6)
												l[i] = 15;
											else {
												if (l[i] == 7)
													l[i] = 6;
												else {
													if (l[i] == 8)
														l[i] = 7;
													else {
														if (l[i] == 9)
															l[i] = 0;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 5;
																else {
																	if (l[i] == 12)
																		l[i] = 3;
																	else {
																		if (l[i] == 13)
																			l[i] = 14;
																		else {
																			if (l[i] == 14)
																				l[i] = 9;
																			else {
																				if (l[i] == 15)
																					l[i] = 11;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 4) {
					if (l[i] == 0)
						l[i] = 7;
					else {
						if (l[i] == 1)
							l[i] = 15;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 10;
								else {
									if (l[i] == 4)
										l[i] = 8;
									else {
										if (l[i] == 5)
											l[i] = 1;
										else {
											if (l[i] == 6)
												l[i] = 6;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 0;
													else {
														if (l[i] == 9)
															l[i] = 9;
														else {
															if (l[i] == 10)
																l[i] = 3;
															else {
																if (l[i] == 11)
																	l[i] = 14;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 4;
																		else {
																			if (l[i] == 14)
																				l[i] = 2;
																			else {
																				if (l[i] == 15)
																					l[i] = 12;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 5) {
					if (l[i] == 0)
						l[i] = 5;
					else {
						if (l[i] == 1)
							l[i] = 13;
						else {
							if (l[i] == 2)
								l[i] = 15;
							else {
								if (l[i] == 3)
									l[i] = 6;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 2;
										else {
											if (l[i] == 6)
												l[i] = 12;
											else {
												if (l[i] == 7)
													l[i] = 10;
												else {
													if (l[i] == 8)
														l[i] = 11;
													else {
														if (l[i] == 9)
															l[i] = 7;
														else {
															if (l[i] == 10)
																l[i] = 8;
															else {
																if (l[i] == 11)
																	l[i] = 1;
																else {
																	if (l[i] == 12)
																		l[i] = 4;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 14;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 6) {
					if (l[i] == 0)
						l[i] = 8;
					else {
						if (l[i] == 1)
							l[i] = 14;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 5;
								else {
									if (l[i] == 4)
										l[i] = 6;
									else {
										if (l[i] == 5)
											l[i] = 9;
										else {
											if (l[i] == 6)
												l[i] = 1;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 15;
													else {
														if (l[i] == 9)
															l[i] = 4;
														else {
															if (l[i] == 10)
																l[i] = 11;
															else {
																if (l[i] == 11)
																	l[i] = 0;
																else {
																	if (l[i] == 12)
																		l[i] = 13;
																	else {
																		if (l[i] == 13)
																			l[i] = 10;
																		else {
																			if (l[i] == 14)
																				l[i] = 3;
																			else {
																				if (l[i] == 15)
																					l[i] = 7;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 7) {
					if (l[i] == 0)
						l[i] = 1;
					else {
						if (l[i] == 1)
							l[i] = 7;
						else {
							if (l[i] == 2)
								l[i] = 14;
							else {
								if (l[i] == 3)
									l[i] = 13;
								else {
									if (l[i] == 4)
										l[i] = 0;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 8;
											else {
												if (l[i] == 7)
													l[i] = 3;
												else {
													if (l[i] == 8)
														l[i] = 4;
													else {
														if (l[i] == 9)
															l[i] = 15;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 6;
																else {
																	if (l[i] == 12)
																		l[i] = 9;
																	else {
																		if (l[i] == 13)
																			l[i] = 12;
																		else {
																			if (l[i] == 14)
																				l[i] = 11;
																			else {
																				if (l[i] == 15)
																					l[i] = 2;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				//Перевод в 2-ичную систему счисления
				for (int v = 0; v < 4; v++) {
					if (l[2 * v] >= 8) {
						dvadva[0 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 8;
					}
					if (l[2 * v] >= 4) {
						dvadva[1 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 4;
					}
					if (l[2 * v] >= 2) {
						dvadva[2 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 2;
					}
					if (l[2 * v] >= 1) {
						dvadva[3 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 1;
					}
					if (l[2 * v + 1] >= 8) {
						dvadva[4 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 8;
					}
					if (l[2 * v + 1] >= 4) {
						dvadva[5 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 4;
					}
					if (l[2 * v + 1] >= 2) {
						dvadva[6 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 2;
					}
					if (l[2 * v + 1] >= 1) {
						dvadva[7 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 1;
					}
				}
				//Сдвиг регистра
				for (int v = 0; v < 11; v++) {
					dvadva_zam = dvadva[0];
					for (int j = 1; j < 32; j++)
						dvadva[j - 1] = dvadva[j];
					dvadva[31] = dvadva_zam;
				}
				//Перевод в 16-ричнуб систему счисления
				for (int v = 0; v < 4; v++) {
					if (dvadva[0 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 8;
					if (dvadva[1 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 4;
					if (dvadva[2 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 2;
					if (dvadva[3 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 1;
					if (dvadva[4 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 8;
					if (dvadva[5 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 4;
					if (dvadva[6 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 2;
					if (dvadva[7 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 1;
				}

				for (int v = 0; v < 32; v++) {
					dvadva[v] = 0;
				}
				//Сложение сторон
				l[i] = l[i] ^ r[i];
				r[i] = l_zap;
			}
		}
		//Сложение с открытым текстом
		for (int ii = 0; ii < 8; ii++) {
			l[ii] = l[ii] ^ dva[ii + 16 * x];
			r[ii] = r[ii] ^ dva[ii + 8 + 16 * x];
		}
	}
	cout << "Имитовставка:" << endl;
	for (int i = 0; i < 8; i++) {
		if (l[i] == 10) {
			cout << "A";
		}
		else {
			if (l[i] == 11) {
				cout << "B";
			}
			else {
				if (l[i] == 12) {
					cout << "C";
				}
				else {
					if (l[i] == 13) {
						cout << "D";
					}
					else {
						if (l[i] == 14) {
							cout << "E";
						}
						else {
							if (l[i] == 15) {
								cout << "F";
							}
							else {
								cout << l[i];
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		if (r[i] == 10) {
			cout << "A";
		}
		else {
			if (r[i] == 11) {
				cout << "B";
			}
			else {
				if (r[i] == 12) {
					cout << "C";
				}
				else {
					if (r[i] == 13) {
						cout << "D";
					}
					else {
						if (r[i] == 14) {
							cout << "E";
						}
						else {
							if (r[i] == 15) {
								cout << "F";
							}
							else {
								cout << r[i];
							}
						}
					}
				}
			}
		}
	}
	cout << endl;
}

void prZamena() {
	string str1 = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя.,-?!: "; //Используемый алфавит
	int np = s.size();
	int randd;
	string s2;
	while (s.size() % 8 != 0) { //Дополнение сообщения
		randd = rand() % 65;
		s2 = str1[randd];
		s = s + s2;
	}

	int dva[1100];
	int shifr[1100];
	for (int i = 0; i < 1100; i++) {
		dva[i] = 0;
		shifr[i] = 0;
	}

	int key[64]; //Генерация ключа
	for (int i = 0; i < 64; i++)
		key[i] = rand() % 16;

	int pos;
	for (int i = 0; i < s.size(); i++) { //Перевод в 16-ричную систему счисления
		pos = str1.find(s[i]);
		dva[i * 2] = pos / 16;
		dva[i * 2 + 1] = pos % 16;
	}

	int dlina;
	for (int i = 0; i < s.size() * 2; i++) {
		dlina = i + 1;
	}
	int l[8], r[8];
	for (int i = 0; i < 8; i++) {
		l[i] = 0;
		r[i] = 0;
	}

	cout << "16-ричное сообщение:" << endl;
	for (int i = 0; i < dlina; i++)
		cout << dva[i] << " ";
	cout << endl;
	int proverka;
	int l_zap;
	int dvadva[32];
	for (int i = 0; i < 32; i++)
		dvadva[i] = 0;
	int dvadva_zam;

	for (int x = 0; x < dlina / 16; x++) {
		for (int ii = 0; ii < 8; ii++) {
			l[ii] = dva[ii + 16 * x];
			r[ii] = dva[ii + 8 + 16 * x];
		}
		//Начало сети Фейстеля
		for (int h = 0; h < 32; h++) {
			for (int i = 0; i < 8; i++) {
				l_zap = l[i];
				if (h < 24) { //Сложение с ключом
					l[i] = l[i] ^ key[i + ((h * 8) % 64)];
				}
				else {
					l[i] = l[i] ^ key[56 + i - ((h * 8) % 64)];
				}
				//С-блок
				if (i % 8 == 0) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 4;
						else {
							if (l[i] == 2)
								l[i] = 6;
							else {
								if (l[i] == 3)
									l[i] = 2;
								else {
									if (l[i] == 4)
										l[i] = 10;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 11;
											else {
												if (l[i] == 7)
													l[i] = 9;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 8;
														else {
															if (l[i] == 10)
																l[i] = 13;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 0;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 15;
																			else {
																				if (l[i] == 15)
																					l[i] = 1;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 1) {
					if (l[i] == 0)
						l[i] = 6;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 3;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 10;
										else {
											if (l[i] == 6)
												l[i] = 5;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 1;
													else {
														if (l[i] == 9)
															l[i] = 14;
														else {
															if (l[i] == 10)
																l[i] = 4;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 13;
																		else {
																			if (l[i] == 14)
																				l[i] = 0;
																			else {
																				if (l[i] == 15)
																					l[i] = 15;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 2) {
					if (l[i] == 0)
						l[i] = 11;
					else {
						if (l[i] == 1)
							l[i] = 3;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 8;
								else {
									if (l[i] == 4)
										l[i] = 2;
									else {
										if (l[i] == 5)
											l[i] = 15;
										else {
											if (l[i] == 6)
												l[i] = 10;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 1;
														else {
															if (l[i] == 10)
																l[i] = 7;
															else {
																if (l[i] == 11)
																	l[i] = 4;
																else {
																	if (l[i] == 12)
																		l[i] = 12;
																	else {
																		if (l[i] == 13)
																			l[i] = 9;
																		else {
																			if (l[i] == 14)
																				l[i] = 6;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 3) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 1;
								else {
									if (l[i] == 4)
										l[i] = 13;
									else {
										if (l[i] == 5)
											l[i] = 4;
										else {
											if (l[i] == 6)
												l[i] = 15;
											else {
												if (l[i] == 7)
													l[i] = 6;
												else {
													if (l[i] == 8)
														l[i] = 7;
													else {
														if (l[i] == 9)
															l[i] = 0;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 5;
																else {
																	if (l[i] == 12)
																		l[i] = 3;
																	else {
																		if (l[i] == 13)
																			l[i] = 14;
																		else {
																			if (l[i] == 14)
																				l[i] = 9;
																			else {
																				if (l[i] == 15)
																					l[i] = 11;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 4) {
					if (l[i] == 0)
						l[i] = 7;
					else {
						if (l[i] == 1)
							l[i] = 15;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 10;
								else {
									if (l[i] == 4)
										l[i] = 8;
									else {
										if (l[i] == 5)
											l[i] = 1;
										else {
											if (l[i] == 6)
												l[i] = 6;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 0;
													else {
														if (l[i] == 9)
															l[i] = 9;
														else {
															if (l[i] == 10)
																l[i] = 3;
															else {
																if (l[i] == 11)
																	l[i] = 14;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 4;
																		else {
																			if (l[i] == 14)
																				l[i] = 2;
																			else {
																				if (l[i] == 15)
																					l[i] = 12;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 5) {
					if (l[i] == 0)
						l[i] = 5;
					else {
						if (l[i] == 1)
							l[i] = 13;
						else {
							if (l[i] == 2)
								l[i] = 15;
							else {
								if (l[i] == 3)
									l[i] = 6;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 2;
										else {
											if (l[i] == 6)
												l[i] = 12;
											else {
												if (l[i] == 7)
													l[i] = 10;
												else {
													if (l[i] == 8)
														l[i] = 11;
													else {
														if (l[i] == 9)
															l[i] = 7;
														else {
															if (l[i] == 10)
																l[i] = 8;
															else {
																if (l[i] == 11)
																	l[i] = 1;
																else {
																	if (l[i] == 12)
																		l[i] = 4;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 14;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 6) {
					if (l[i] == 0)
						l[i] = 8;
					else {
						if (l[i] == 1)
							l[i] = 14;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 5;
								else {
									if (l[i] == 4)
										l[i] = 6;
									else {
										if (l[i] == 5)
											l[i] = 9;
										else {
											if (l[i] == 6)
												l[i] = 1;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 15;
													else {
														if (l[i] == 9)
															l[i] = 4;
														else {
															if (l[i] == 10)
																l[i] = 11;
															else {
																if (l[i] == 11)
																	l[i] = 0;
																else {
																	if (l[i] == 12)
																		l[i] = 13;
																	else {
																		if (l[i] == 13)
																			l[i] = 10;
																		else {
																			if (l[i] == 14)
																				l[i] = 3;
																			else {
																				if (l[i] == 15)
																					l[i] = 7;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 7) {
					if (l[i] == 0)
						l[i] = 1;
					else {
						if (l[i] == 1)
							l[i] = 7;
						else {
							if (l[i] == 2)
								l[i] = 14;
							else {
								if (l[i] == 3)
									l[i] = 13;
								else {
									if (l[i] == 4)
										l[i] = 0;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 8;
											else {
												if (l[i] == 7)
													l[i] = 3;
												else {
													if (l[i] == 8)
														l[i] = 4;
													else {
														if (l[i] == 9)
															l[i] = 15;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 6;
																else {
																	if (l[i] == 12)
																		l[i] = 9;
																	else {
																		if (l[i] == 13)
																			l[i] = 12;
																		else {
																			if (l[i] == 14)
																				l[i] = 11;
																			else {
																				if (l[i] == 15)
																					l[i] = 2;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				//Сложение сторон
				l[i] = l[i] ^ r[i];
				r[i] = l_zap;
			}
		}
		//Перевод в 10-ричную систему счисления
		for (int z = 0; z < 8; z++) {
			shifr[z + 16 * x] = l[z];
			shifr[z + 8 + 16 * x] = r[z];
		}
	}
	cout << "Зашифрованное сообщение:" << endl;
	for (int i = 0; i < dlina; i++)
		cout << shifr[i] << " ";
	cout << endl;

	for (int x = 0; x < dlina / 16; x++) {
		for (int ii = 0; ii < 8; ii++) {
			r[ii] = shifr[ii + 16 * x];
			l[ii] = shifr[ii + 8 + 16 * x];
		}
		//Начало сети Фейстеля
		for (int h = 0; h < 32; h++) {
			for (int i = 0; i < 8; i++) {
				l_zap = l[i];
				//Сложение с ключом
				if (h < 8) {
					l[i] = l[i] ^ key[i + ((h * 8) % 64)];
				}
				else {
					l[i] = l[i] ^ key[56 + i - ((h * 8) % 64)];
				}
				//С-блок
				if (i % 8 == 0) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 4;
						else {
							if (l[i] == 2)
								l[i] = 6;
							else {
								if (l[i] == 3)
									l[i] = 2;
								else {
									if (l[i] == 4)
										l[i] = 10;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 11;
											else {
												if (l[i] == 7)
													l[i] = 9;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 8;
														else {
															if (l[i] == 10)
																l[i] = 13;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 0;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 15;
																			else {
																				if (l[i] == 15)
																					l[i] = 1;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 1) {
					if (l[i] == 0)
						l[i] = 6;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 3;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 10;
										else {
											if (l[i] == 6)
												l[i] = 5;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 1;
													else {
														if (l[i] == 9)
															l[i] = 14;
														else {
															if (l[i] == 10)
																l[i] = 4;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 13;
																		else {
																			if (l[i] == 14)
																				l[i] = 0;
																			else {
																				if (l[i] == 15)
																					l[i] = 15;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 2) {
					if (l[i] == 0)
						l[i] = 11;
					else {
						if (l[i] == 1)
							l[i] = 3;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 8;
								else {
									if (l[i] == 4)
										l[i] = 2;
									else {
										if (l[i] == 5)
											l[i] = 15;
										else {
											if (l[i] == 6)
												l[i] = 10;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 1;
														else {
															if (l[i] == 10)
																l[i] = 7;
															else {
																if (l[i] == 11)
																	l[i] = 4;
																else {
																	if (l[i] == 12)
																		l[i] = 12;
																	else {
																		if (l[i] == 13)
																			l[i] = 9;
																		else {
																			if (l[i] == 14)
																				l[i] = 6;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 3) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 1;
								else {
									if (l[i] == 4)
										l[i] = 13;
									else {
										if (l[i] == 5)
											l[i] = 4;
										else {
											if (l[i] == 6)
												l[i] = 15;
											else {
												if (l[i] == 7)
													l[i] = 6;
												else {
													if (l[i] == 8)
														l[i] = 7;
													else {
														if (l[i] == 9)
															l[i] = 0;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 5;
																else {
																	if (l[i] == 12)
																		l[i] = 3;
																	else {
																		if (l[i] == 13)
																			l[i] = 14;
																		else {
																			if (l[i] == 14)
																				l[i] = 9;
																			else {
																				if (l[i] == 15)
																					l[i] = 11;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 4) {
					if (l[i] == 0)
						l[i] = 7;
					else {
						if (l[i] == 1)
							l[i] = 15;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 10;
								else {
									if (l[i] == 4)
										l[i] = 8;
									else {
										if (l[i] == 5)
											l[i] = 1;
										else {
											if (l[i] == 6)
												l[i] = 6;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 0;
													else {
														if (l[i] == 9)
															l[i] = 9;
														else {
															if (l[i] == 10)
																l[i] = 3;
															else {
																if (l[i] == 11)
																	l[i] = 14;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 4;
																		else {
																			if (l[i] == 14)
																				l[i] = 2;
																			else {
																				if (l[i] == 15)
																					l[i] = 12;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 5) {
					if (l[i] == 0)
						l[i] = 5;
					else {
						if (l[i] == 1)
							l[i] = 13;
						else {
							if (l[i] == 2)
								l[i] = 15;
							else {
								if (l[i] == 3)
									l[i] = 6;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 2;
										else {
											if (l[i] == 6)
												l[i] = 12;
											else {
												if (l[i] == 7)
													l[i] = 10;
												else {
													if (l[i] == 8)
														l[i] = 11;
													else {
														if (l[i] == 9)
															l[i] = 7;
														else {
															if (l[i] == 10)
																l[i] = 8;
															else {
																if (l[i] == 11)
																	l[i] = 1;
																else {
																	if (l[i] == 12)
																		l[i] = 4;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 14;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 6) {
					if (l[i] == 0)
						l[i] = 8;
					else {
						if (l[i] == 1)
							l[i] = 14;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 5;
								else {
									if (l[i] == 4)
										l[i] = 6;
									else {
										if (l[i] == 5)
											l[i] = 9;
										else {
											if (l[i] == 6)
												l[i] = 1;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 15;
													else {
														if (l[i] == 9)
															l[i] = 4;
														else {
															if (l[i] == 10)
																l[i] = 11;
															else {
																if (l[i] == 11)
																	l[i] = 0;
																else {
																	if (l[i] == 12)
																		l[i] = 13;
																	else {
																		if (l[i] == 13)
																			l[i] = 10;
																		else {
																			if (l[i] == 14)
																				l[i] = 3;
																			else {
																				if (l[i] == 15)
																					l[i] = 7;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 7) {
					if (l[i] == 0)
						l[i] = 1;
					else {
						if (l[i] == 1)
							l[i] = 7;
						else {
							if (l[i] == 2)
								l[i] = 14;
							else {
								if (l[i] == 3)
									l[i] = 13;
								else {
									if (l[i] == 4)
										l[i] = 0;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 8;
											else {
												if (l[i] == 7)
													l[i] = 3;
												else {
													if (l[i] == 8)
														l[i] = 4;
													else {
														if (l[i] == 9)
															l[i] = 15;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 6;
																else {
																	if (l[i] == 12)
																		l[i] = 9;
																	else {
																		if (l[i] == 13)
																			l[i] = 12;
																		else {
																			if (l[i] == 14)
																				l[i] = 11;
																			else {
																				if (l[i] == 15)
																					l[i] = 2;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				//Сложение сторон
				l[i] = l[i] ^ r[i];
				r[i] = l_zap;

			}
		}
		for (int z = 0; z < 8; z++) {
			dva[z + 8 + 16 * x] = l[z];
			dva[z + 16 * x] = r[z];
		}
	}
	cout << "Расшифрованное 16-ричное сообщение:" << endl;
	for (int i = 0; i < dlina; i++)
		cout << dva[i] << " ";
	cout << endl << "Расшифрованное сообщение:" << endl;

	for (int i = 0; i < np; i++) {
		s[i] = str1[dva[i * 2] * 16 + dva[i * 2 + 1]];
		cout << s[i];
	}
	cout << endl;
}

void Gamma() {
	string str1 = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя.,-?!: "; //Используемый алфавит
	int consts[8]; //Запоминание констант
	consts[0] = 4;
	for (int i = 1; i < 8; i++) {
		consts[i] = 1;
	}
	int zz = s.size();
	int randd;
	string s2;
	while (s.size() % 8 != 0) { //Дополнение сообщения
		randd = rand() % 65;
		s2 = str1[randd];
		s = s + s2;
	}

	std::cout << endl << "Дополненное сообщение: " << endl << s << endl;

	int posilka[8], posilka_zap[8];
	for (int i = 0; i < 8; i++) {
		posilka[i] = rand() % 71;
	}

	for (int i = 0; i < 8; i++) {
		posilka_zap[i] = posilka[i];
	}
	int xx;
	int zzz = 0;
	int kost[5000];
	for (int i = 0; i < 5000; i++)
		kost[i] = 0;
	int dva[16];
	for (int i = 0; i < 16; i++)
		dva[i] = 0;
	int l[8], r[8];
	for (int i = 0; i < 8; i++) {
		l[i] = 0;
		r[i] = 0;
	}
	int l_zap;

	int key[64];
	for (int i = 0; i < 64; i++)
		key[i] = rand() % 16;
	int dvadva[32];
	for (int i = 0; i < 32; i++)
		dvadva[i] = 0;
	int dvadva_zam;
	for (int j = 0; j < (s.size() / 8); j++) {
		//Начало сети Фейстеля
		for (int i = 0; i < 8; i++) {
			dva[i * 2] = posilka[i] / 16;
			dva[i * 2 + 1] = posilka[i] % 16;
		}
		for (int ii = 0; ii < 8; ii++) {
			l[ii] = dva[ii];
			r[ii] = dva[ii + 8];
		}
		for (int h = 0; h < 32; h++) {
			for (int i = 0; i < 8; i++) {
				l_zap = l[i];
				//Сложение с ключом
				if (h < 24) {
					l[i] = l[i] ^ key[i + ((h * 8) % 64)];
				}
				else {
					l[i] = l[i] ^ key[56 + i - ((h * 8) % 64)];
				}
				//С-блок
				if (i % 8 == 0) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 4;
						else {
							if (l[i] == 2)
								l[i] = 6;
							else {
								if (l[i] == 3)
									l[i] = 2;
								else {
									if (l[i] == 4)
										l[i] = 10;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 11;
											else {
												if (l[i] == 7)
													l[i] = 9;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 8;
														else {
															if (l[i] == 10)
																l[i] = 13;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 0;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 15;
																			else {
																				if (l[i] == 15)
																					l[i] = 1;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 1) {
					if (l[i] == 0)
						l[i] = 6;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 3;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 10;
										else {
											if (l[i] == 6)
												l[i] = 5;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 1;
													else {
														if (l[i] == 9)
															l[i] = 14;
														else {
															if (l[i] == 10)
																l[i] = 4;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 13;
																		else {
																			if (l[i] == 14)
																				l[i] = 0;
																			else {
																				if (l[i] == 15)
																					l[i] = 15;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 2) {
					if (l[i] == 0)
						l[i] = 11;
					else {
						if (l[i] == 1)
							l[i] = 3;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 8;
								else {
									if (l[i] == 4)
										l[i] = 2;
									else {
										if (l[i] == 5)
											l[i] = 15;
										else {
											if (l[i] == 6)
												l[i] = 10;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 1;
														else {
															if (l[i] == 10)
																l[i] = 7;
															else {
																if (l[i] == 11)
																	l[i] = 4;
																else {
																	if (l[i] == 12)
																		l[i] = 12;
																	else {
																		if (l[i] == 13)
																			l[i] = 9;
																		else {
																			if (l[i] == 14)
																				l[i] = 6;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 3) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 1;
								else {
									if (l[i] == 4)
										l[i] = 13;
									else {
										if (l[i] == 5)
											l[i] = 4;
										else {
											if (l[i] == 6)
												l[i] = 15;
											else {
												if (l[i] == 7)
													l[i] = 6;
												else {
													if (l[i] == 8)
														l[i] = 7;
													else {
														if (l[i] == 9)
															l[i] = 0;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 5;
																else {
																	if (l[i] == 12)
																		l[i] = 3;
																	else {
																		if (l[i] == 13)
																			l[i] = 14;
																		else {
																			if (l[i] == 14)
																				l[i] = 9;
																			else {
																				if (l[i] == 15)
																					l[i] = 11;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 4) {
					if (l[i] == 0)
						l[i] = 7;
					else {
						if (l[i] == 1)
							l[i] = 15;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 10;
								else {
									if (l[i] == 4)
										l[i] = 8;
									else {
										if (l[i] == 5)
											l[i] = 1;
										else {
											if (l[i] == 6)
												l[i] = 6;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 0;
													else {
														if (l[i] == 9)
															l[i] = 9;
														else {
															if (l[i] == 10)
																l[i] = 3;
															else {
																if (l[i] == 11)
																	l[i] = 14;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 4;
																		else {
																			if (l[i] == 14)
																				l[i] = 2;
																			else {
																				if (l[i] == 15)
																					l[i] = 12;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 5) {
					if (l[i] == 0)
						l[i] = 5;
					else {
						if (l[i] == 1)
							l[i] = 13;
						else {
							if (l[i] == 2)
								l[i] = 15;
							else {
								if (l[i] == 3)
									l[i] = 6;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 2;
										else {
											if (l[i] == 6)
												l[i] = 12;
											else {
												if (l[i] == 7)
													l[i] = 10;
												else {
													if (l[i] == 8)
														l[i] = 11;
													else {
														if (l[i] == 9)
															l[i] = 7;
														else {
															if (l[i] == 10)
																l[i] = 8;
															else {
																if (l[i] == 11)
																	l[i] = 1;
																else {
																	if (l[i] == 12)
																		l[i] = 4;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 14;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 6) {
					if (l[i] == 0)
						l[i] = 8;
					else {
						if (l[i] == 1)
							l[i] = 14;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 5;
								else {
									if (l[i] == 4)
										l[i] = 6;
									else {
										if (l[i] == 5)
											l[i] = 9;
										else {
											if (l[i] == 6)
												l[i] = 1;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 15;
													else {
														if (l[i] == 9)
															l[i] = 4;
														else {
															if (l[i] == 10)
																l[i] = 11;
															else {
																if (l[i] == 11)
																	l[i] = 0;
																else {
																	if (l[i] == 12)
																		l[i] = 13;
																	else {
																		if (l[i] == 13)
																			l[i] = 10;
																		else {
																			if (l[i] == 14)
																				l[i] = 3;
																			else {
																				if (l[i] == 15)
																					l[i] = 7;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 7) {
					if (l[i] == 0)
						l[i] = 1;
					else {
						if (l[i] == 1)
							l[i] = 7;
						else {
							if (l[i] == 2)
								l[i] = 14;
							else {
								if (l[i] == 3)
									l[i] = 13;
								else {
									if (l[i] == 4)
										l[i] = 0;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 8;
											else {
												if (l[i] == 7)
													l[i] = 3;
												else {
													if (l[i] == 8)
														l[i] = 4;
													else {
														if (l[i] == 9)
															l[i] = 15;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 6;
																else {
																	if (l[i] == 12)
																		l[i] = 9;
																	else {
																		if (l[i] == 13)
																			l[i] = 12;
																		else {
																			if (l[i] == 14)
																				l[i] = 11;
																			else {
																				if (l[i] == 15)
																					l[i] = 2;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				//Перевод в 2-ичную систему счисления
				for (int v = 0; v < 4; v++) {
					if (l[2 * v] >= 8) {
						dvadva[0 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 8;
					}
					if (l[2 * v] >= 4) {
						dvadva[1 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 4;
					}
					if (l[2 * v] >= 2) {
						dvadva[2 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 2;
					}
					if (l[2 * v] >= 1) {
						dvadva[3 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 1;
					}
					if (l[2 * v + 1] >= 8) {
						dvadva[4 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 8;
					}
					if (l[2 * v + 1] >= 4) {
						dvadva[5 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 4;
					}
					if (l[2 * v + 1] >= 2) {
						dvadva[6 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 2;
					}
					if (l[2 * v + 1] >= 1) {
						dvadva[7 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 1;
					}
				}
				//Сдвиг регистров
				for (int v = 0; v < 11; v++) {
					dvadva_zam = dvadva[0];
					for (int j = 1; j < 32; j++)
						dvadva[j - 1] = dvadva[j];
					dvadva[31] = dvadva_zam;
				}
				//Перевод в 16-ричную систему счисления
				for (int v = 0; v < 4; v++) {
					if (dvadva[0 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 8;
					if (dvadva[1 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 4;
					if (dvadva[2 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 2;
					if (dvadva[3 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 1;
					if (dvadva[4 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 8;
					if (dvadva[5 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 4;
					if (dvadva[6 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 2;
					if (dvadva[7 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 1;
				}

				for (int v = 0; v < 32; v++) {
					dvadva[v] = 0;
				}

				l[i] = l[i] ^ r[i];
				r[i] = l_zap;
			}
		}
		for (int i = 0; i < 4; i++) {
			posilka[i] = l[i * 2] * 16 + l[i * 2 + 1];
			posilka[i + 4] = r[i * 2] * 16 + r[i * 2 + 1];
		}
		//Конец сети Фейстеля

		for (int i = 0; i < 8; i++) {
			posilka[i] = posilka[i] ^ consts[i];
			if (i == 3)
				posilka[i] = posilka[i] - 1;
		}

		//Начало сети Фейстеля
		for (int i = 0; i < 8; i++) {
			dva[i * 2] = posilka[i] / 16;
			dva[i * 2 + 1] = posilka[i] % 16;
		}
		for (int ii = 0; ii < 8; ii++) {
			l[ii] = dva[ii];
			r[ii] = dva[ii + 8];
		}
		for (int h = 0; h < 32; h++) {
			for (int i = 0; i < 8; i++) {
				l_zap = l[i];
				if (h < 24) {//Сложение с ключом
					l[i] = l[i] ^ key[i + ((h * 8) % 64)];
				}
				else {
					l[i] = l[i] ^ key[56 + i - ((h * 8) % 64)];
				}
				//С-блок
				if (i % 8 == 0) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 4;
						else {
							if (l[i] == 2)
								l[i] = 6;
							else {
								if (l[i] == 3)
									l[i] = 2;
								else {
									if (l[i] == 4)
										l[i] = 10;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 11;
											else {
												if (l[i] == 7)
													l[i] = 9;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 8;
														else {
															if (l[i] == 10)
																l[i] = 13;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 0;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 15;
																			else {
																				if (l[i] == 15)
																					l[i] = 1;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 1) {
					if (l[i] == 0)
						l[i] = 6;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 3;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 10;
										else {
											if (l[i] == 6)
												l[i] = 5;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 1;
													else {
														if (l[i] == 9)
															l[i] = 14;
														else {
															if (l[i] == 10)
																l[i] = 4;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 13;
																		else {
																			if (l[i] == 14)
																				l[i] = 0;
																			else {
																				if (l[i] == 15)
																					l[i] = 15;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 2) {
					if (l[i] == 0)
						l[i] = 11;
					else {
						if (l[i] == 1)
							l[i] = 3;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 8;
								else {
									if (l[i] == 4)
										l[i] = 2;
									else {
										if (l[i] == 5)
											l[i] = 15;
										else {
											if (l[i] == 6)
												l[i] = 10;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 1;
														else {
															if (l[i] == 10)
																l[i] = 7;
															else {
																if (l[i] == 11)
																	l[i] = 4;
																else {
																	if (l[i] == 12)
																		l[i] = 12;
																	else {
																		if (l[i] == 13)
																			l[i] = 9;
																		else {
																			if (l[i] == 14)
																				l[i] = 6;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 3) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 1;
								else {
									if (l[i] == 4)
										l[i] = 13;
									else {
										if (l[i] == 5)
											l[i] = 4;
										else {
											if (l[i] == 6)
												l[i] = 15;
											else {
												if (l[i] == 7)
													l[i] = 6;
												else {
													if (l[i] == 8)
														l[i] = 7;
													else {
														if (l[i] == 9)
															l[i] = 0;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 5;
																else {
																	if (l[i] == 12)
																		l[i] = 3;
																	else {
																		if (l[i] == 13)
																			l[i] = 14;
																		else {
																			if (l[i] == 14)
																				l[i] = 9;
																			else {
																				if (l[i] == 15)
																					l[i] = 11;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 4) {
					if (l[i] == 0)
						l[i] = 7;
					else {
						if (l[i] == 1)
							l[i] = 15;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 10;
								else {
									if (l[i] == 4)
										l[i] = 8;
									else {
										if (l[i] == 5)
											l[i] = 1;
										else {
											if (l[i] == 6)
												l[i] = 6;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 0;
													else {
														if (l[i] == 9)
															l[i] = 9;
														else {
															if (l[i] == 10)
																l[i] = 3;
															else {
																if (l[i] == 11)
																	l[i] = 14;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 4;
																		else {
																			if (l[i] == 14)
																				l[i] = 2;
																			else {
																				if (l[i] == 15)
																					l[i] = 12;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 5) {
					if (l[i] == 0)
						l[i] = 5;
					else {
						if (l[i] == 1)
							l[i] = 13;
						else {
							if (l[i] == 2)
								l[i] = 15;
							else {
								if (l[i] == 3)
									l[i] = 6;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 2;
										else {
											if (l[i] == 6)
												l[i] = 12;
											else {
												if (l[i] == 7)
													l[i] = 10;
												else {
													if (l[i] == 8)
														l[i] = 11;
													else {
														if (l[i] == 9)
															l[i] = 7;
														else {
															if (l[i] == 10)
																l[i] = 8;
															else {
																if (l[i] == 11)
																	l[i] = 1;
																else {
																	if (l[i] == 12)
																		l[i] = 4;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 14;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 6) {
					if (l[i] == 0)
						l[i] = 8;
					else {
						if (l[i] == 1)
							l[i] = 14;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 5;
								else {
									if (l[i] == 4)
										l[i] = 6;
									else {
										if (l[i] == 5)
											l[i] = 9;
										else {
											if (l[i] == 6)
												l[i] = 1;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 15;
													else {
														if (l[i] == 9)
															l[i] = 4;
														else {
															if (l[i] == 10)
																l[i] = 11;
															else {
																if (l[i] == 11)
																	l[i] = 0;
																else {
																	if (l[i] == 12)
																		l[i] = 13;
																	else {
																		if (l[i] == 13)
																			l[i] = 10;
																		else {
																			if (l[i] == 14)
																				l[i] = 3;
																			else {
																				if (l[i] == 15)
																					l[i] = 7;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 7) {
					if (l[i] == 0)
						l[i] = 1;
					else {
						if (l[i] == 1)
							l[i] = 7;
						else {
							if (l[i] == 2)
								l[i] = 14;
							else {
								if (l[i] == 3)
									l[i] = 13;
								else {
									if (l[i] == 4)
										l[i] = 0;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 8;
											else {
												if (l[i] == 7)
													l[i] = 3;
												else {
													if (l[i] == 8)
														l[i] = 4;
													else {
														if (l[i] == 9)
															l[i] = 15;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 6;
																else {
																	if (l[i] == 12)
																		l[i] = 9;
																	else {
																		if (l[i] == 13)
																			l[i] = 12;
																		else {
																			if (l[i] == 14)
																				l[i] = 11;
																			else {
																				if (l[i] == 15)
																					l[i] = 2;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				//Перевод в 2-ичную систему счисления
				for (int v = 0; v < 4; v++) {
					if (l[2 * v] >= 8) {
						dvadva[0 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 8;
					}
					if (l[2 * v] >= 4) {
						dvadva[1 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 4;
					}
					if (l[2 * v] >= 2) {
						dvadva[2 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 2;
					}
					if (l[2 * v] >= 1) {
						dvadva[3 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 1;
					}
					if (l[2 * v + 1] >= 8) {
						dvadva[4 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 8;
					}
					if (l[2 * v + 1] >= 4) {
						dvadva[5 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 4;
					}
					if (l[2 * v + 1] >= 2) {
						dvadva[6 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 2;
					}
					if (l[2 * v + 1] >= 1) {
						dvadva[7 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 1;
					}
				}
				//Сдвиг регистров
				for (int v = 0; v < 11; v++) {
					dvadva_zam = dvadva[0];
					for (int j = 1; j < 32; j++)
						dvadva[j - 1] = dvadva[j];
					dvadva[31] = dvadva_zam;
				}
				//Перевод в 16-ричную систему счисления
				for (int v = 0; v < 4; v++) {
					if (dvadva[0 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 8;
					if (dvadva[1 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 4;
					if (dvadva[2 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 2;
					if (dvadva[3 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 1;
					if (dvadva[4 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 8;
					if (dvadva[5 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 4;
					if (dvadva[6 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 2;
					if (dvadva[7 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 1;
				}

				for (int v = 0; v < 32; v++) {
					dvadva[v] = 0;
				}

				l[i] = l[i] ^ r[i];
				r[i] = l_zap;
			}
		}
		for (int i = 0; i < 4; i++) {
			posilka[i] = l[i * 2] * 16 + l[i * 2 + 1];
			posilka[i + 4] = r[i * 2] * 16 + r[i * 2 + 1];
		}
		//Конец сети Фейстеля

		for (int i = 8 * j; i < 8 + 8 * j; i++) {
			int pos = str1.find(s[i]);
			xx = pos ^ posilka[zzz];
			if (xx >= 71)
				kost[i] = 71;
			if (xx >= 142)
				kost[i] = 142;
			if (xx >= 213)
				kost[i] = 213;
			s[i] = str1[(pos ^ posilka[zzz]) % 71];
			zzz++;
		}
		zzz = 0;
	}

	std::cout << endl << "Зашифрованное сообщение:\n" << s << endl;

	//расшифрование

	for (int j = 0; j < (s.size() / 8); j++) {
		//Начало сети Фейстеля
		for (int i = 0; i < 8; i++) {
			dva[i * 2] = posilka_zap[i] / 16;
			dva[i * 2 + 1] = posilka_zap[i] % 16;
		}
		for (int ii = 0; ii < 8; ii++) {
			l[ii] = dva[ii];
			r[ii] = dva[ii + 8];
		}
		for (int h = 0; h < 32; h++) {
			for (int i = 0; i < 8; i++) {
				l_zap = l[i];
				if (h < 24) {//Сложение с ключом
					l[i] = l[i] ^ key[i + ((h * 8) % 64)];
				}
				else {
					l[i] = l[i] ^ key[56 + i - ((h * 8) % 64)];
				}
				//С-блок
				if (i % 8 == 0) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 4;
						else {
							if (l[i] == 2)
								l[i] = 6;
							else {
								if (l[i] == 3)
									l[i] = 2;
								else {
									if (l[i] == 4)
										l[i] = 10;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 11;
											else {
												if (l[i] == 7)
													l[i] = 9;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 8;
														else {
															if (l[i] == 10)
																l[i] = 13;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 0;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 15;
																			else {
																				if (l[i] == 15)
																					l[i] = 1;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 1) {
					if (l[i] == 0)
						l[i] = 6;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 3;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 10;
										else {
											if (l[i] == 6)
												l[i] = 5;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 1;
													else {
														if (l[i] == 9)
															l[i] = 14;
														else {
															if (l[i] == 10)
																l[i] = 4;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 13;
																		else {
																			if (l[i] == 14)
																				l[i] = 0;
																			else {
																				if (l[i] == 15)
																					l[i] = 15;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 2) {
					if (l[i] == 0)
						l[i] = 11;
					else {
						if (l[i] == 1)
							l[i] = 3;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 8;
								else {
									if (l[i] == 4)
										l[i] = 2;
									else {
										if (l[i] == 5)
											l[i] = 15;
										else {
											if (l[i] == 6)
												l[i] = 10;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 1;
														else {
															if (l[i] == 10)
																l[i] = 7;
															else {
																if (l[i] == 11)
																	l[i] = 4;
																else {
																	if (l[i] == 12)
																		l[i] = 12;
																	else {
																		if (l[i] == 13)
																			l[i] = 9;
																		else {
																			if (l[i] == 14)
																				l[i] = 6;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 3) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 1;
								else {
									if (l[i] == 4)
										l[i] = 13;
									else {
										if (l[i] == 5)
											l[i] = 4;
										else {
											if (l[i] == 6)
												l[i] = 15;
											else {
												if (l[i] == 7)
													l[i] = 6;
												else {
													if (l[i] == 8)
														l[i] = 7;
													else {
														if (l[i] == 9)
															l[i] = 0;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 5;
																else {
																	if (l[i] == 12)
																		l[i] = 3;
																	else {
																		if (l[i] == 13)
																			l[i] = 14;
																		else {
																			if (l[i] == 14)
																				l[i] = 9;
																			else {
																				if (l[i] == 15)
																					l[i] = 11;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 4) {
					if (l[i] == 0)
						l[i] = 7;
					else {
						if (l[i] == 1)
							l[i] = 15;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 10;
								else {
									if (l[i] == 4)
										l[i] = 8;
									else {
										if (l[i] == 5)
											l[i] = 1;
										else {
											if (l[i] == 6)
												l[i] = 6;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 0;
													else {
														if (l[i] == 9)
															l[i] = 9;
														else {
															if (l[i] == 10)
																l[i] = 3;
															else {
																if (l[i] == 11)
																	l[i] = 14;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 4;
																		else {
																			if (l[i] == 14)
																				l[i] = 2;
																			else {
																				if (l[i] == 15)
																					l[i] = 12;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 5) {
					if (l[i] == 0)
						l[i] = 5;
					else {
						if (l[i] == 1)
							l[i] = 13;
						else {
							if (l[i] == 2)
								l[i] = 15;
							else {
								if (l[i] == 3)
									l[i] = 6;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 2;
										else {
											if (l[i] == 6)
												l[i] = 12;
											else {
												if (l[i] == 7)
													l[i] = 10;
												else {
													if (l[i] == 8)
														l[i] = 11;
													else {
														if (l[i] == 9)
															l[i] = 7;
														else {
															if (l[i] == 10)
																l[i] = 8;
															else {
																if (l[i] == 11)
																	l[i] = 1;
																else {
																	if (l[i] == 12)
																		l[i] = 4;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 14;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 6) {
					if (l[i] == 0)
						l[i] = 8;
					else {
						if (l[i] == 1)
							l[i] = 14;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 5;
								else {
									if (l[i] == 4)
										l[i] = 6;
									else {
										if (l[i] == 5)
											l[i] = 9;
										else {
											if (l[i] == 6)
												l[i] = 1;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 15;
													else {
														if (l[i] == 9)
															l[i] = 4;
														else {
															if (l[i] == 10)
																l[i] = 11;
															else {
																if (l[i] == 11)
																	l[i] = 0;
																else {
																	if (l[i] == 12)
																		l[i] = 13;
																	else {
																		if (l[i] == 13)
																			l[i] = 10;
																		else {
																			if (l[i] == 14)
																				l[i] = 3;
																			else {
																				if (l[i] == 15)
																					l[i] = 7;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 7) {
					if (l[i] == 0)
						l[i] = 1;
					else {
						if (l[i] == 1)
							l[i] = 7;
						else {
							if (l[i] == 2)
								l[i] = 14;
							else {
								if (l[i] == 3)
									l[i] = 13;
								else {
									if (l[i] == 4)
										l[i] = 0;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 8;
											else {
												if (l[i] == 7)
													l[i] = 3;
												else {
													if (l[i] == 8)
														l[i] = 4;
													else {
														if (l[i] == 9)
															l[i] = 15;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 6;
																else {
																	if (l[i] == 12)
																		l[i] = 9;
																	else {
																		if (l[i] == 13)
																			l[i] = 12;
																		else {
																			if (l[i] == 14)
																				l[i] = 11;
																			else {
																				if (l[i] == 15)
																					l[i] = 2;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				//Перевод в 2-ричную систему счисления
				for (int v = 0; v < 4; v++) {
					if (l[2 * v] >= 8) {
						dvadva[0 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 8;
					}
					if (l[2 * v] >= 4) {
						dvadva[1 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 4;
					}
					if (l[2 * v] >= 2) {
						dvadva[2 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 2;
					}
					if (l[2 * v] >= 1) {
						dvadva[3 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 1;
					}
					if (l[2 * v + 1] >= 8) {
						dvadva[4 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 8;
					}
					if (l[2 * v + 1] >= 4) {
						dvadva[5 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 4;
					}
					if (l[2 * v + 1] >= 2) {
						dvadva[6 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 2;
					}
					if (l[2 * v + 1] >= 1) {
						dvadva[7 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 1;
					}
				}
				//Сдвиг регистров
				for (int v = 0; v < 11; v++) {
					dvadva_zam = dvadva[0];
					for (int j = 1; j < 32; j++)
						dvadva[j - 1] = dvadva[j];
					dvadva[31] = dvadva_zam;
				}
				//Перевод в 16-ричную систему счисления
				for (int v = 0; v < 4; v++) {
					if (dvadva[0 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 8;
					if (dvadva[1 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 4;
					if (dvadva[2 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 2;
					if (dvadva[3 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 1;
					if (dvadva[4 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 8;
					if (dvadva[5 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 4;
					if (dvadva[6 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 2;
					if (dvadva[7 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 1;
				}

				for (int v = 0; v < 32; v++) {
					dvadva[v] = 0;
				}
				//Сложение блоков
				l[i] = l[i] ^ r[i];
				r[i] = l_zap;
			}
		}
		for (int i = 0; i < 4; i++) {
			posilka_zap[i] = l[i * 2] * 16 + l[i * 2 + 1];
			posilka_zap[i + 4] = r[i * 2] * 16 + r[i * 2 + 1];
		}
		//Конец сети Фейстеля

		for (int i = 0; i < 8; i++) {
			posilka_zap[i] = posilka_zap[i] ^ consts[i];
			if (i == 3)
				posilka_zap[i] = posilka_zap[i] - 1;
		}

		//Начало сети Фейстеля
		for (int i = 0; i < 8; i++) {
			dva[i * 2] = posilka_zap[i] / 16;
			dva[i * 2 + 1] = posilka_zap[i] % 16;
		}
		for (int ii = 0; ii < 8; ii++) {
			l[ii] = dva[ii];
			r[ii] = dva[ii + 8];
		}
		for (int h = 0; h < 32; h++) {
			for (int i = 0; i < 8; i++) {
				l_zap = l[i];
				if (h < 24) { //Сложение с ключом
					l[i] = l[i] ^ key[i + ((h * 8) % 64)];
				}
				else {
					l[i] = l[i] ^ key[56 + i - ((h * 8) % 64)];
				}
				//С-блок
				if (i % 8 == 0) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 4;
						else {
							if (l[i] == 2)
								l[i] = 6;
							else {
								if (l[i] == 3)
									l[i] = 2;
								else {
									if (l[i] == 4)
										l[i] = 10;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 11;
											else {
												if (l[i] == 7)
													l[i] = 9;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 8;
														else {
															if (l[i] == 10)
																l[i] = 13;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 0;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 15;
																			else {
																				if (l[i] == 15)
																					l[i] = 1;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 1) {
					if (l[i] == 0)
						l[i] = 6;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 3;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 10;
										else {
											if (l[i] == 6)
												l[i] = 5;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 1;
													else {
														if (l[i] == 9)
															l[i] = 14;
														else {
															if (l[i] == 10)
																l[i] = 4;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 13;
																		else {
																			if (l[i] == 14)
																				l[i] = 0;
																			else {
																				if (l[i] == 15)
																					l[i] = 15;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 2) {
					if (l[i] == 0)
						l[i] = 11;
					else {
						if (l[i] == 1)
							l[i] = 3;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 8;
								else {
									if (l[i] == 4)
										l[i] = 2;
									else {
										if (l[i] == 5)
											l[i] = 15;
										else {
											if (l[i] == 6)
												l[i] = 10;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 1;
														else {
															if (l[i] == 10)
																l[i] = 7;
															else {
																if (l[i] == 11)
																	l[i] = 4;
																else {
																	if (l[i] == 12)
																		l[i] = 12;
																	else {
																		if (l[i] == 13)
																			l[i] = 9;
																		else {
																			if (l[i] == 14)
																				l[i] = 6;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 3) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 1;
								else {
									if (l[i] == 4)
										l[i] = 13;
									else {
										if (l[i] == 5)
											l[i] = 4;
										else {
											if (l[i] == 6)
												l[i] = 15;
											else {
												if (l[i] == 7)
													l[i] = 6;
												else {
													if (l[i] == 8)
														l[i] = 7;
													else {
														if (l[i] == 9)
															l[i] = 0;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 5;
																else {
																	if (l[i] == 12)
																		l[i] = 3;
																	else {
																		if (l[i] == 13)
																			l[i] = 14;
																		else {
																			if (l[i] == 14)
																				l[i] = 9;
																			else {
																				if (l[i] == 15)
																					l[i] = 11;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 4) {
					if (l[i] == 0)
						l[i] = 7;
					else {
						if (l[i] == 1)
							l[i] = 15;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 10;
								else {
									if (l[i] == 4)
										l[i] = 8;
									else {
										if (l[i] == 5)
											l[i] = 1;
										else {
											if (l[i] == 6)
												l[i] = 6;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 0;
													else {
														if (l[i] == 9)
															l[i] = 9;
														else {
															if (l[i] == 10)
																l[i] = 3;
															else {
																if (l[i] == 11)
																	l[i] = 14;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 4;
																		else {
																			if (l[i] == 14)
																				l[i] = 2;
																			else {
																				if (l[i] == 15)
																					l[i] = 12;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 5) {
					if (l[i] == 0)
						l[i] = 5;
					else {
						if (l[i] == 1)
							l[i] = 13;
						else {
							if (l[i] == 2)
								l[i] = 15;
							else {
								if (l[i] == 3)
									l[i] = 6;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 2;
										else {
											if (l[i] == 6)
												l[i] = 12;
											else {
												if (l[i] == 7)
													l[i] = 10;
												else {
													if (l[i] == 8)
														l[i] = 11;
													else {
														if (l[i] == 9)
															l[i] = 7;
														else {
															if (l[i] == 10)
																l[i] = 8;
															else {
																if (l[i] == 11)
																	l[i] = 1;
																else {
																	if (l[i] == 12)
																		l[i] = 4;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 14;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 6) {
					if (l[i] == 0)
						l[i] = 8;
					else {
						if (l[i] == 1)
							l[i] = 14;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 5;
								else {
									if (l[i] == 4)
										l[i] = 6;
									else {
										if (l[i] == 5)
											l[i] = 9;
										else {
											if (l[i] == 6)
												l[i] = 1;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 15;
													else {
														if (l[i] == 9)
															l[i] = 4;
														else {
															if (l[i] == 10)
																l[i] = 11;
															else {
																if (l[i] == 11)
																	l[i] = 0;
																else {
																	if (l[i] == 12)
																		l[i] = 13;
																	else {
																		if (l[i] == 13)
																			l[i] = 10;
																		else {
																			if (l[i] == 14)
																				l[i] = 3;
																			else {
																				if (l[i] == 15)
																					l[i] = 7;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 7) {
					if (l[i] == 0)
						l[i] = 1;
					else {
						if (l[i] == 1)
							l[i] = 7;
						else {
							if (l[i] == 2)
								l[i] = 14;
							else {
								if (l[i] == 3)
									l[i] = 13;
								else {
									if (l[i] == 4)
										l[i] = 0;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 8;
											else {
												if (l[i] == 7)
													l[i] = 3;
												else {
													if (l[i] == 8)
														l[i] = 4;
													else {
														if (l[i] == 9)
															l[i] = 15;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 6;
																else {
																	if (l[i] == 12)
																		l[i] = 9;
																	else {
																		if (l[i] == 13)
																			l[i] = 12;
																		else {
																			if (l[i] == 14)
																				l[i] = 11;
																			else {
																				if (l[i] == 15)
																					l[i] = 2;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				//Перевод в 2-ичную систему счисления
				for (int v = 0; v < 4; v++) {
					if (l[2 * v] >= 8) {
						dvadva[0 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 8;
					}
					if (l[2 * v] >= 4) {
						dvadva[1 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 4;
					}
					if (l[2 * v] >= 2) {
						dvadva[2 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 2;
					}
					if (l[2 * v] >= 1) {
						dvadva[3 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 1;
					}
					if (l[2 * v + 1] >= 8) {
						dvadva[4 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 8;
					}
					if (l[2 * v + 1] >= 4) {
						dvadva[5 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 4;
					}
					if (l[2 * v + 1] >= 2) {
						dvadva[6 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 2;
					}
					if (l[2 * v + 1] >= 1) {
						dvadva[7 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 1;
					}
				}
				//Сдвиг регистров
				for (int v = 0; v < 11; v++) {
					dvadva_zam = dvadva[0];
					for (int j = 1; j < 32; j++)
						dvadva[j - 1] = dvadva[j];
					dvadva[31] = dvadva_zam;
				}
				//Перевод в 16-ричную систему счисления
				for (int v = 0; v < 4; v++) {
					if (dvadva[0 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 8;
					if (dvadva[1 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 4;
					if (dvadva[2 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 2;
					if (dvadva[3 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 1;
					if (dvadva[4 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 8;
					if (dvadva[5 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 4;
					if (dvadva[6 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 2;
					if (dvadva[7 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 1;
				}

				for (int v = 0; v < 32; v++) {
					dvadva[v] = 0;
				}
				//Сложение сторон
				l[i] = l[i] ^ r[i];
				r[i] = l_zap;
			}
		}
		for (int i = 0; i < 4; i++) {
			posilka_zap[i] = l[i * 2] * 16 + l[i * 2 + 1];
			posilka_zap[i + 4] = r[i * 2] * 16 + r[i * 2 + 1];
		}
		//Конец сети Фейстеля

		for (int i = 8 * j; i < 8 + 8 * j; i++) {
			int pos = str1.find(s[i]);
			pos = pos + kost[i];
			s[i] = str1[(pos ^ posilka_zap[zzz]) % 71];
			zzz++;
		}
		zzz = 0;
	}

	std::cout << endl << "Расшифрованное сообщение:\n";
	for (int i = 0; i < zz; i++) {
		std::cout << s[i];
	}
	std::cout << endl;
}

void GammaOBR() {
	string str1 = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя.,-?!: "; //Используемый алфавит
	int zz = s.size();
	int randd;
	string s2;
	while (s.size() % 8 != 0) { //Дополнение сообщения
		randd = rand() % 65;
		s2 = str1[randd];
		s = s + s2;
	}

	std::cout << endl << "Дополненное сообщение: " << endl << s << endl;

	int posilka[8], posilka_zap[8];
	for (int i = 0; i < 8; i++) {
		posilka[i] = rand() % 71;
	}

	for (int i = 0; i < 8; i++) {
		posilka_zap[i] = posilka[i];
	}
	int xx;
	int zzz = 0;
	int kost[5000];
	for (int i = 0; i < 5000; i++)
		kost[i] = 0;
	int dva[16];
	for (int i = 0; i < 16; i++)
		dva[i] = 0;
	int l[8], r[8];
	for (int i = 0; i < 8; i++) {
		l[i] = 0;
		r[i] = 0;
	}
	int l_zap;

	int key[64];
	for (int i = 0; i < 64; i++)
		key[i] = rand() % 16;

	int dvadva[32];
	for (int i = 0; i < 32; i++)
		dvadva[i] = 0;
	int dvadva_zam;


	for (int j = 0; j < (s.size() / 8); j++) {
		//Начало сети Фейстеля
		for (int i = 0; i < 8; i++) {
			dva[i * 2] = posilka[i] / 16;
			dva[i * 2 + 1] = posilka[i] % 16;
		}
		for (int ii = 0; ii < 8; ii++) {
			l[ii] = dva[ii];
			r[ii] = dva[ii + 8];
		}
		for (int h = 0; h < 32; h++) {
			for (int i = 0; i < 8; i++) {
				l_zap = l[i];
				if (h < 24) { //Сложение с ключом
					l[i] = l[i] ^ key[i + ((h * 8) % 64)];
				}
				else {
					l[i] = l[i] ^ key[56 + i - ((h * 8) % 64)];
				}
				//С-блок
				if (i % 8 == 0) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 4;
						else {
							if (l[i] == 2)
								l[i] = 6;
							else {
								if (l[i] == 3)
									l[i] = 2;
								else {
									if (l[i] == 4)
										l[i] = 10;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 11;
											else {
												if (l[i] == 7)
													l[i] = 9;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 8;
														else {
															if (l[i] == 10)
																l[i] = 13;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 0;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 15;
																			else {
																				if (l[i] == 15)
																					l[i] = 1;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 1) {
					if (l[i] == 0)
						l[i] = 6;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 3;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 10;
										else {
											if (l[i] == 6)
												l[i] = 5;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 1;
													else {
														if (l[i] == 9)
															l[i] = 14;
														else {
															if (l[i] == 10)
																l[i] = 4;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 13;
																		else {
																			if (l[i] == 14)
																				l[i] = 0;
																			else {
																				if (l[i] == 15)
																					l[i] = 15;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 2) {
					if (l[i] == 0)
						l[i] = 11;
					else {
						if (l[i] == 1)
							l[i] = 3;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 8;
								else {
									if (l[i] == 4)
										l[i] = 2;
									else {
										if (l[i] == 5)
											l[i] = 15;
										else {
											if (l[i] == 6)
												l[i] = 10;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 1;
														else {
															if (l[i] == 10)
																l[i] = 7;
															else {
																if (l[i] == 11)
																	l[i] = 4;
																else {
																	if (l[i] == 12)
																		l[i] = 12;
																	else {
																		if (l[i] == 13)
																			l[i] = 9;
																		else {
																			if (l[i] == 14)
																				l[i] = 6;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 3) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 1;
								else {
									if (l[i] == 4)
										l[i] = 13;
									else {
										if (l[i] == 5)
											l[i] = 4;
										else {
											if (l[i] == 6)
												l[i] = 15;
											else {
												if (l[i] == 7)
													l[i] = 6;
												else {
													if (l[i] == 8)
														l[i] = 7;
													else {
														if (l[i] == 9)
															l[i] = 0;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 5;
																else {
																	if (l[i] == 12)
																		l[i] = 3;
																	else {
																		if (l[i] == 13)
																			l[i] = 14;
																		else {
																			if (l[i] == 14)
																				l[i] = 9;
																			else {
																				if (l[i] == 15)
																					l[i] = 11;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 4) {
					if (l[i] == 0)
						l[i] = 7;
					else {
						if (l[i] == 1)
							l[i] = 15;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 10;
								else {
									if (l[i] == 4)
										l[i] = 8;
									else {
										if (l[i] == 5)
											l[i] = 1;
										else {
											if (l[i] == 6)
												l[i] = 6;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 0;
													else {
														if (l[i] == 9)
															l[i] = 9;
														else {
															if (l[i] == 10)
																l[i] = 3;
															else {
																if (l[i] == 11)
																	l[i] = 14;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 4;
																		else {
																			if (l[i] == 14)
																				l[i] = 2;
																			else {
																				if (l[i] == 15)
																					l[i] = 12;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 5) {
					if (l[i] == 0)
						l[i] = 5;
					else {
						if (l[i] == 1)
							l[i] = 13;
						else {
							if (l[i] == 2)
								l[i] = 15;
							else {
								if (l[i] == 3)
									l[i] = 6;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 2;
										else {
											if (l[i] == 6)
												l[i] = 12;
											else {
												if (l[i] == 7)
													l[i] = 10;
												else {
													if (l[i] == 8)
														l[i] = 11;
													else {
														if (l[i] == 9)
															l[i] = 7;
														else {
															if (l[i] == 10)
																l[i] = 8;
															else {
																if (l[i] == 11)
																	l[i] = 1;
																else {
																	if (l[i] == 12)
																		l[i] = 4;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 14;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 6) {
					if (l[i] == 0)
						l[i] = 8;
					else {
						if (l[i] == 1)
							l[i] = 14;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 5;
								else {
									if (l[i] == 4)
										l[i] = 6;
									else {
										if (l[i] == 5)
											l[i] = 9;
										else {
											if (l[i] == 6)
												l[i] = 1;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 15;
													else {
														if (l[i] == 9)
															l[i] = 4;
														else {
															if (l[i] == 10)
																l[i] = 11;
															else {
																if (l[i] == 11)
																	l[i] = 0;
																else {
																	if (l[i] == 12)
																		l[i] = 13;
																	else {
																		if (l[i] == 13)
																			l[i] = 10;
																		else {
																			if (l[i] == 14)
																				l[i] = 3;
																			else {
																				if (l[i] == 15)
																					l[i] = 7;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 7) {
					if (l[i] == 0)
						l[i] = 1;
					else {
						if (l[i] == 1)
							l[i] = 7;
						else {
							if (l[i] == 2)
								l[i] = 14;
							else {
								if (l[i] == 3)
									l[i] = 13;
								else {
									if (l[i] == 4)
										l[i] = 0;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 8;
											else {
												if (l[i] == 7)
													l[i] = 3;
												else {
													if (l[i] == 8)
														l[i] = 4;
													else {
														if (l[i] == 9)
															l[i] = 15;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 6;
																else {
																	if (l[i] == 12)
																		l[i] = 9;
																	else {
																		if (l[i] == 13)
																			l[i] = 12;
																		else {
																			if (l[i] == 14)
																				l[i] = 11;
																			else {
																				if (l[i] == 15)
																					l[i] = 2;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				//Перевод в 2-ичную систему счисления
				for (int v = 0; v < 4; v++) {
					if (l[2 * v] >= 8) {
						dvadva[0 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 8;
					}
					if (l[2 * v] >= 4) {
						dvadva[1 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 4;
					}
					if (l[2 * v] >= 2) {
						dvadva[2 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 2;
					}
					if (l[2 * v] >= 1) {
						dvadva[3 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 1;
					}
					if (l[2 * v + 1] >= 8) {
						dvadva[4 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 8;
					}
					if (l[2 * v + 1] >= 4) {
						dvadva[5 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 4;
					}
					if (l[2 * v + 1] >= 2) {
						dvadva[6 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 2;
					}
					if (l[2 * v + 1] >= 1) {
						dvadva[7 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 1;
					}
				}
				//Сдвиг регистров
				for (int v = 0; v < 11; v++) {
					dvadva_zam = dvadva[0];
					for (int j = 1; j < 32; j++)
						dvadva[j - 1] = dvadva[j];
					dvadva[31] = dvadva_zam;
				}
				//Перевод в 16-ричную систему счисления
				for (int v = 0; v < 4; v++) {
					if (dvadva[0 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 8;
					if (dvadva[1 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 4;
					if (dvadva[2 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 2;
					if (dvadva[3 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 1;
					if (dvadva[4 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 8;
					if (dvadva[5 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 4;
					if (dvadva[6 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 2;
					if (dvadva[7 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 1;
				}

				for (int v = 0; v < 32; v++) {
					dvadva[v] = 0;
				}

				l[i] = l[i] ^ r[i];
				r[i] = l_zap;
			}
		}
		for (int i = 0; i < 4; i++) {
			posilka[i] = l[i * 2] * 16 + l[i * 2 + 1];
			posilka[i + 4] = r[i * 2] * 16 + r[i * 2 + 1];
		}
		//Конец сети Фейстеля

		for (int i = 8 * j; i < 8 + 8 * j; i++) {
			int pos = str1.find(s[i]);
			xx = pos ^ posilka[zzz];
			if (xx >= 71)
				kost[i] = 71;
			if (xx >= 142)
				kost[i] = 142;
			if (xx >= 213)
				kost[i] = 213;
			s[i] = str1[(pos ^ posilka[zzz]) % 71];
			zzz++;
		}
		zzz = 0;
	}

	std::cout << endl << "Зашифрованное сообщение:\n" << s << endl;

	//расшифрование

	for (int j = 0; j < (s.size() / 8); j++) {
		//Начало сети Фейстеля
		for (int i = 0; i < 8; i++) {
			dva[i * 2] = posilka_zap[i] / 16;
			dva[i * 2 + 1] = posilka_zap[i] % 16;
		}
		for (int ii = 0; ii < 8; ii++) {
			l[ii] = dva[ii];
			r[ii] = dva[ii + 8];
		}
		for (int h = 0; h < 32; h++) {
			for (int i = 0; i < 8; i++) {
				l_zap = l[i];
				if (h < 24) { //Сложение с ключом
					l[i] = l[i] ^ key[i + ((h * 8) % 64)];
				}
				else {
					l[i] = l[i] ^ key[56 + i - ((h * 8) % 64)];
				}
				//С-блок
				if (i % 8 == 0) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 4;
						else {
							if (l[i] == 2)
								l[i] = 6;
							else {
								if (l[i] == 3)
									l[i] = 2;
								else {
									if (l[i] == 4)
										l[i] = 10;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 11;
											else {
												if (l[i] == 7)
													l[i] = 9;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 8;
														else {
															if (l[i] == 10)
																l[i] = 13;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 0;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 15;
																			else {
																				if (l[i] == 15)
																					l[i] = 1;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 1) {
					if (l[i] == 0)
						l[i] = 6;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 3;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 10;
										else {
											if (l[i] == 6)
												l[i] = 5;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 1;
													else {
														if (l[i] == 9)
															l[i] = 14;
														else {
															if (l[i] == 10)
																l[i] = 4;
															else {
																if (l[i] == 11)
																	l[i] = 7;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 13;
																		else {
																			if (l[i] == 14)
																				l[i] = 0;
																			else {
																				if (l[i] == 15)
																					l[i] = 15;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 2) {
					if (l[i] == 0)
						l[i] = 11;
					else {
						if (l[i] == 1)
							l[i] = 3;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 8;
								else {
									if (l[i] == 4)
										l[i] = 2;
									else {
										if (l[i] == 5)
											l[i] = 15;
										else {
											if (l[i] == 6)
												l[i] = 10;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 14;
													else {
														if (l[i] == 9)
															l[i] = 1;
														else {
															if (l[i] == 10)
																l[i] = 7;
															else {
																if (l[i] == 11)
																	l[i] = 4;
																else {
																	if (l[i] == 12)
																		l[i] = 12;
																	else {
																		if (l[i] == 13)
																			l[i] = 9;
																		else {
																			if (l[i] == 14)
																				l[i] = 6;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 3) {
					if (l[i] == 0)
						l[i] = 12;
					else {
						if (l[i] == 1)
							l[i] = 8;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 1;
								else {
									if (l[i] == 4)
										l[i] = 13;
									else {
										if (l[i] == 5)
											l[i] = 4;
										else {
											if (l[i] == 6)
												l[i] = 15;
											else {
												if (l[i] == 7)
													l[i] = 6;
												else {
													if (l[i] == 8)
														l[i] = 7;
													else {
														if (l[i] == 9)
															l[i] = 0;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 5;
																else {
																	if (l[i] == 12)
																		l[i] = 3;
																	else {
																		if (l[i] == 13)
																			l[i] = 14;
																		else {
																			if (l[i] == 14)
																				l[i] = 9;
																			else {
																				if (l[i] == 15)
																					l[i] = 11;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 4) {
					if (l[i] == 0)
						l[i] = 7;
					else {
						if (l[i] == 1)
							l[i] = 15;
						else {
							if (l[i] == 2)
								l[i] = 5;
							else {
								if (l[i] == 3)
									l[i] = 10;
								else {
									if (l[i] == 4)
										l[i] = 8;
									else {
										if (l[i] == 5)
											l[i] = 1;
										else {
											if (l[i] == 6)
												l[i] = 6;
											else {
												if (l[i] == 7)
													l[i] = 13;
												else {
													if (l[i] == 8)
														l[i] = 0;
													else {
														if (l[i] == 9)
															l[i] = 9;
														else {
															if (l[i] == 10)
																l[i] = 3;
															else {
																if (l[i] == 11)
																	l[i] = 14;
																else {
																	if (l[i] == 12)
																		l[i] = 11;
																	else {
																		if (l[i] == 13)
																			l[i] = 4;
																		else {
																			if (l[i] == 14)
																				l[i] = 2;
																			else {
																				if (l[i] == 15)
																					l[i] = 12;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 5) {
					if (l[i] == 0)
						l[i] = 5;
					else {
						if (l[i] == 1)
							l[i] = 13;
						else {
							if (l[i] == 2)
								l[i] = 15;
							else {
								if (l[i] == 3)
									l[i] = 6;
								else {
									if (l[i] == 4)
										l[i] = 9;
									else {
										if (l[i] == 5)
											l[i] = 2;
										else {
											if (l[i] == 6)
												l[i] = 12;
											else {
												if (l[i] == 7)
													l[i] = 10;
												else {
													if (l[i] == 8)
														l[i] = 11;
													else {
														if (l[i] == 9)
															l[i] = 7;
														else {
															if (l[i] == 10)
																l[i] = 8;
															else {
																if (l[i] == 11)
																	l[i] = 1;
																else {
																	if (l[i] == 12)
																		l[i] = 4;
																	else {
																		if (l[i] == 13)
																			l[i] = 3;
																		else {
																			if (l[i] == 14)
																				l[i] = 14;
																			else {
																				if (l[i] == 15)
																					l[i] = 0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 6) {
					if (l[i] == 0)
						l[i] = 8;
					else {
						if (l[i] == 1)
							l[i] = 14;
						else {
							if (l[i] == 2)
								l[i] = 2;
							else {
								if (l[i] == 3)
									l[i] = 5;
								else {
									if (l[i] == 4)
										l[i] = 6;
									else {
										if (l[i] == 5)
											l[i] = 9;
										else {
											if (l[i] == 6)
												l[i] = 1;
											else {
												if (l[i] == 7)
													l[i] = 12;
												else {
													if (l[i] == 8)
														l[i] = 15;
													else {
														if (l[i] == 9)
															l[i] = 4;
														else {
															if (l[i] == 10)
																l[i] = 11;
															else {
																if (l[i] == 11)
																	l[i] = 0;
																else {
																	if (l[i] == 12)
																		l[i] = 13;
																	else {
																		if (l[i] == 13)
																			l[i] = 10;
																		else {
																			if (l[i] == 14)
																				l[i] = 3;
																			else {
																				if (l[i] == 15)
																					l[i] = 7;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (i % 8 == 7) {
					if (l[i] == 0)
						l[i] = 1;
					else {
						if (l[i] == 1)
							l[i] = 7;
						else {
							if (l[i] == 2)
								l[i] = 14;
							else {
								if (l[i] == 3)
									l[i] = 13;
								else {
									if (l[i] == 4)
										l[i] = 0;
									else {
										if (l[i] == 5)
											l[i] = 5;
										else {
											if (l[i] == 6)
												l[i] = 8;
											else {
												if (l[i] == 7)
													l[i] = 3;
												else {
													if (l[i] == 8)
														l[i] = 4;
													else {
														if (l[i] == 9)
															l[i] = 15;
														else {
															if (l[i] == 10)
																l[i] = 10;
															else {
																if (l[i] == 11)
																	l[i] = 6;
																else {
																	if (l[i] == 12)
																		l[i] = 9;
																	else {
																		if (l[i] == 13)
																			l[i] = 12;
																		else {
																			if (l[i] == 14)
																				l[i] = 11;
																			else {
																				if (l[i] == 15)
																					l[i] = 2;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				//Перевод в 2-ичную систему счисления
				for (int v = 0; v < 4; v++) {
					if (l[2 * v] >= 8) {
						dvadva[0 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 8;
					}
					if (l[2 * v] >= 4) {
						dvadva[1 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 4;
					}
					if (l[2 * v] >= 2) {
						dvadva[2 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 2;
					}
					if (l[2 * v] >= 1) {
						dvadva[3 + 8 * v] = 1;
						l[2 * v] = l[2 * v] - 1;
					}
					if (l[2 * v + 1] >= 8) {
						dvadva[4 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 8;
					}
					if (l[2 * v + 1] >= 4) {
						dvadva[5 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 4;
					}
					if (l[2 * v + 1] >= 2) {
						dvadva[6 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 2;
					}
					if (l[2 * v + 1] >= 1) {
						dvadva[7 + 8 * v] = 1;
						l[2 * v + 1] = l[2 * v + 1] - 1;
					}
				}
				//Сдвиг регистров
				for (int v = 0; v < 11; v++) {
					dvadva_zam = dvadva[0];
					for (int j = 1; j < 32; j++)
						dvadva[j - 1] = dvadva[j];
					dvadva[31] = dvadva_zam;
				}
				//Перевод в 16-ричную систему счисления
				for (int v = 0; v < 4; v++) {
					if (dvadva[0 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 8;
					if (dvadva[1 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 4;
					if (dvadva[2 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 2;
					if (dvadva[3 + 8 * v] == 1)
						l[2 * v] = l[2 * v] + 1;
					if (dvadva[4 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 8;
					if (dvadva[5 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 4;
					if (dvadva[6 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 2;
					if (dvadva[7 + 8 * v] == 1)
						l[2 * v + 1] = l[2 * v + 1] + 1;
				}

				for (int v = 0; v < 32; v++) {
					dvadva[v] = 0;
				}
				//Сложение блоков
				l[i] = l[i] ^ r[i];
				r[i] = l_zap;
			}
		}
		for (int i = 0; i < 4; i++) {
			posilka_zap[i] = l[i * 2] * 16 + l[i * 2 + 1];
			posilka_zap[i + 4] = r[i * 2] * 16 + r[i * 2 + 1];
		}
		//Конец сети Фейстеля

		for (int i = 8 * j; i < 8 + 8 * j; i++) { //перевод из символов в буквы
			int pos = str1.find(s[i]);
			pos = pos + kost[i];
			s[i] = str1[(pos ^ posilka_zap[zzz]) % 71];
			zzz++;
		}
		zzz = 0;
	}

	std::cout << endl << "Расшифрованное сообщение:\n";
	for (int i = 0; i < zz; i++) {
		std::cout << s[i];
	}
	std::cout << endl;
}

void Magma() {
	cout << "Введите номер нужного режима:\n1. Простая замена\n2. Гаммирование\n3. Гаммирование с обратной связью\n4. Имитовставка\n";
	int a;
	cin >> a;
	if (a == 1)
		prZamena();
	if (a == 2)
		Gamma();
	if (a == 3)
		GammaOBR();
	if (a == 4)
		imitovstavka();
}

int main() {
	setlocale(LC_ALL, "Russian"); //добавление русского языка
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int i = 0;
	while (i == 0) {
		cout << "\nВведите сообщение:\n";
		getline(cin, s); //считывание строки с сообщением
		int c;
		cout << "\nВведите номер нужного шифра : \n   Python - 1.Атбаш\n   Python - 2.Цезарь\n   Python - 3.Полибий\n   Python - 4.Тритемий\n"
			"   Python - 5.Белазо\n   Python - 6.Виженер\n\n   С++ - 7.Матричный\n   С++ - 8.Плейфер\n"
			"   С++ - 9.Вертикальная перестановка\n   C++ - 10.Решетка Кардано\n\n   Python - 11.Блокнот Шеннона\n"
			"   Python - 12.А5/1\n\n   С++ - 13.А5/2\n\n   Python - 14.АES\n\n   С++ - 15.RSA\n\n   Python - 16.Эль-Гамаль\n\n"
			"   C++ - 17.ГОСТ 34.10-94\n   С++ - 18.ГОСТ 34.10-2012\n   С++ - 19.Магма\n\n   Python - 20.Диффи-Хеллман\n\n"
			"   21.Выход из программы\n";
		cin >> c;
		system("cls");
		switch (c) {
		case 1:
			system("atbash.py");
			break;
		case 2:
			system("cezar.py");
			break;
		case 3:
			system("polibiy.py");
			break;
		case 4:
			system("tritemiy.py");
			break;
		case 5:
			system("belazo.py");
			break;
		case 6:
			system("vizhener.py");
			break;
		case 7:
			matr();
			break;
		case 8:
			pleif();
			break;
		case 9:
			VertP();
			break;
		case 10:
			Kard();
			break;
		case 11:
			system("vernam.py");
			break;
		case 12:
			system("A5f.py");
			break;
		case 13:
			a52();
			break;
		case 14:
			system("AES.py");
			break;
		case 15:
			rsa();
			break;
		case 16:
			system("ElGamal.py");
			break;
		case 17:
			g341094();
			break;
		case 18:
			g341012();
			break;
		case 19:
			Magma();
			break;
		case 20:
			system("Diffie-Hellman.py");
			break;
		case 21:
			i++;
			break;
		default:
			cout << "Данного значения не существует. Введите верное значение." << endl;
			break;
		}
	}
	std::system("pause");
	return 0;
}