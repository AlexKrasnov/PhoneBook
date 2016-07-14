#pragma once
#include "List.h"

// класс хэш-таблицы в виде массива списков
class HashTable
{
	int n; // количество групп в хэш-таблице
	List* segments; // указатель на массив групп
public:
	HashTable(int = 26); // конструктор хэш-таблицы по заданному числу групп
	~HashTable(); // деструктор хэш-таблицы
	// метод добавления новой записи об абоненте
	void PushAbonent(char*, char*);
	// метод удаления записи по имени абонента
	void DeleteAbonent(char*);
	// метод поиска записи по имени абонента
	bool FindAbonent(char*, Abonent&);
	// дружественная функция вывода
	friend ostream& operator<<(ostream& os, HashTable& tab)
	{
		for (int i=0; i<tab.n; i++)
		{
			if (!tab.segments[i].IsEmpty())
				os << tab.segments[i];
		}
		return os;
	}
};