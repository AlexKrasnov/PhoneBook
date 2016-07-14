#include "HashTable.h"

HashTable:: HashTable(int chislo): n(chislo)
{
	/*
	Для хранения телефонной книги будем использовать хэш-таблицу из
	26 групп (по количеству букв латинского алфавита). Ключевым
	значением поиска будет являться имя абонента. Хэш-функция будет
	определять номер группы по первой букве этого имени.
	*/
	segments = new List[n];
}

HashTable:: ~HashTable() { delete[] segments; }

// метод добавления новой записи об абоненте
void HashTable::PushAbonent(char* f, char* p)
{
	// вычисление номера группы по имени абонента
	int num = f[0] - 'A';
	// добавление записи в группу с номером num
	segments[num].PushAbonent(f, p);
}
// метод удаления из списка записи по имени абонента
void HashTable::DeleteAbonent(char* f)
{
	// вычисление номера группы по имени абонента
	int num = f[0] - 'A';
	// удаление записи из группы с номером num
	segments[num].DeleteAbonent(f);
}
// метод поиска записи по имени абонента
bool HashTable::FindAbonent(char* f, Abonent& ab)
{
	// вычисление номера группы по имени абонента
	int num =f[0] - 'A';
	// возвращаем true, если абонент найден в группе num,
	// false – в противном случае
	return segments[num].FindAbonent(f, ab);
}