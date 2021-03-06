#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void seqNum(string &input) {
	cout << "Numerical value: "; //Порядковый номер каждой буквы в алффавите
	for (int i = 0; i < input.length(); i++) {
		cout << (input[i] - 'A') << " ";
	}
	cout << endl << endl;
}

void cipherText(string &input, string &key) {
	cout << "Ciphertext: "; //Зашифрованный текст
	int rez;
	for (int i = 0, j = 0; i < input.length(); i++, j++) {
		if (j > key.length() - 1)
			j = 0;
		rez = ((input[i] - 'A') + (key[j] - 'A')) % 26;
		cout << char('A' + rez);
	}
	cout << endl;
}

void seqNum(string &input, string &key) {
	cout << "Numerical value: "; //Порядковый номер каждой буквы в алффавите
	for (int i = 0, j = 0; i < input.length(); i++, j++) {
		if (j > key.length() - 1)
			j = 0;
		cout << ((input[i] - 'A') + (key[j] - 'A')) % 26 << " ";
	}
	cout << endl << endl;
}

void toUpp(string &input) {
	transform(input.begin(), input.end(), input.begin(), toupper);

}

int main()
{
	
	
	cout << "Enter plaintext: "; //Вводим текст
	string plaintext;
	getline(cin, plaintext);
	toUpp(plaintext);
	//cin.ignore();

	seqNum(plaintext); //Вычисляем порядковый номер букв исходного текста

	cout << "Enter the key: "; //Вводим ключ
	string key;
	getline(cin, key);
	toUpp(key);
	

	seqNum(key); //Вычисляем порядковый номер букв гаммы
	cipherText(plaintext, key);
	seqNum(plaintext, key);


	system("pause");
	return 0;
}