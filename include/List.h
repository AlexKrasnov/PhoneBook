#pragma once
#include "Element.h"

// класс группы хэш-таблицы в виде списка
class List
{
	Element* head; // указатель на первый элемент списка
public:
	// конструктор создания пустого списка
	List();
	// деструктор списка
	~List();
	bool IsEmpty() { return head == NULL; }
	// метод добавления в конец новой записи об абоненте
	void PushAbonent(char*, char*);
	// метод удаления из списка по имени абонента
	void DeleteAbonent(char*);
	// метод поиска элемента списка по имени абонента
	bool FindAbonent(char*, Abonent&);
	// дружественные функции вывода
	friend ostream& operator << (ostream& os, List& l)
	{
		Element* tmp = l.head;
		while (tmp != NULL)
		{
			os << tmp->GetAbonent();
			tmp = tmp->GetNext();
		}
		return os;
	}
};