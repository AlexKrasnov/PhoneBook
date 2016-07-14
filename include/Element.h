#pragma once
#include "Abonent.h"

// класс элемента списка
class Element
{
	Abonent info; // запись телефонной книги
	Element* next; // указатель на следующую запись в списке
public:
	Element(char* f, char* p) { info.SetFIO(f), info.SetPhone(p); next = NULL; }
	void SetNext(Element* n) { next = n; }
	char* GetFIO() { return info.GetFIO(); }
	char* GetPhone() { return info.GetPhone(); }
	Abonent GetAbonent() { return info; }
	Element* GetNext() { return next; }
	bool IsAbonent(char* f) { return info.IsAbonent(f); }
	friend class List;
};