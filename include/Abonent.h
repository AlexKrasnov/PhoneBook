#pragma once
#include <iostream>
#include <string>

using namespace std;

class List;
class HashTable;

// класс информации об абоненте
class Abonent
{
	char fio[50]; // имя абонента
	char phone[20]; // номер телефона
public:
	Abonent() {}
	Abonent(char* f, char* p) 
	{ 
		for (int i = 0; i< 50; i++)
			fio[i] = f[i];
		for (int i = 0; i< 20; i++)
			phone[i] = p[i];
	}
	Abonent(const Abonent& ab) 
	{ 
		for (int i = 0; i< 50; i++)
			fio[i] = ab.fio[i];
		for (int i = 0; i< 20; i++)
			phone[i] = ab.phone[i];
	}
	char* GetFIO() { return fio; }
	void SetFIO(char* f) 
	{ 
		for (int i = 0; i< 50; i++)
			fio[i] = f[i];
	}
	char* GetPhone() { return phone; }
	void SetPhone(char* p) 
	{ 
		for (int i = 0; i< 20; i++)
			phone[i] = p[i];
	}
	bool IsAbonent(char* f)
	{
		bool k = true;
		for (int i = 0; i< 50; i++)
		{
			if (GetFIO()[i] != f[i]) { k = false; break; }
		}
		if (k == true) 
			return true;
		return false;
	}
	friend class List;
	friend ostream& operator << (ostream& os, Abonent& ab)
	{
		os << "fio: " << ab.fio << " phone: " << ab.phone << endl;
		return os;
	}
};