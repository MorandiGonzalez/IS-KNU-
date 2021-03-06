// po_modulu_2.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <bitset>
#include <climits>
#include <algorithm>


using namespace std;

void toUpp(string &input) {
	transform(input.begin(), input.end(), input.begin(), toupper);

}

void binVal(string &input) {
	cout << "Binary value: "; //Бинарное значение букв
	for (int i = 0; i < input.length(); i++) {
		bitset<CHAR_BIT> b(input[i]);
		cout << b << " ";
	}
	cout << endl << endl;
}

void cipherText(string &input, string &key) {
	cout << "Ciphertext: ";//Вывод зашифрованныйх символов
	for (int i = 0, j = 0; i < input.length(); i++, j++) {
		if (j > key.length() - 1)
			j = 0;
		bitset<CHAR_BIT> b(input[i]);
		bitset<CHAR_BIT> b1(key[j]);
		bitset<CHAR_BIT> b2 = b ^ b1;
		cout << int(b2.to_ullong()) << " ";
	}
	cout << endl;
}

void binVal(string &input, string &key) {
	cout << "Binary value: ";
	for (int i = 0, j = 0; i < input.length(); i++, j++) {
		if (j > key.length() - 1)
			j = 0;
		bitset<CHAR_BIT> b(input[i]);
		bitset<CHAR_BIT> b1(key[j]);
		bitset<CHAR_BIT> b2 = b ^ b1;
		cout << b2 << " ";
	}
	cout << endl << endl;
}

int main()
{
	cout << "Enter plaintext: "; //Вводим текст
	string plaintext;
	getline(cin, plaintext);
	toUpp(plaintext);

	binVal(plaintext); //Бинарные значения начального текста

	cout << "Enter the key: "; //Вводим ключ
	string key;
	getline(cin, key);
	toUpp(key);

	binVal(key); //Бинарные значения ключа

	cipherText(plaintext, key);
	binVal(plaintext, key);

	
	system("pause");
	return 0;
}

