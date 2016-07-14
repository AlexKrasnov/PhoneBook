#include "HashTable.h"

int Menu()
{
	int k = 0;
	while(k <= 0 || k > 6)
	{
		cout << "----------- Меню ------------" << endl;
		cout << "1) Добавить абонента\n"; 
		cout << "2) Удалить абонента - 2\n";
		cout << "3) Найти абонента - 3\n";
		cout << "4) Печать телефонной книжки - 4\n";
		cout << "5) Выход - 5\n";
		cout << "Введите команду:";
		cin >> k;
	}
	return k;
}
void main()
{
	setlocale(LC_ALL, "Rus");
	cout << "\t\t***Телефонная книжка***\n\n";
	HashTable phoneBook(26);
	char phone[20];
	char str[50];
	Abonent i;
	while(true)
	{
		switch(Menu())
		{
		case 1: // вставка новой записи об абоненте
			cout << "--- Добавление абонента ---" << endl;
			while(true)
			{
				cout << " Введите имя:";
				cin >> str;
				if(str[0] >= 'a' && str[0] <= 'z')
					str[0] = 'A' + str[0] - 'a';
				if(!phoneBook.FindAbonent(str, i))
					break;
			}
			cout << "Введите номер телефона:";
			cin >> phone;
			phoneBook.PushAbonent(str, phone);
			break;
		case 2: // удаление записи по имени абонента
			cout << "-- Удаление абонента --" << endl;
			cout << "Введите имя:";
			cin >> str;
			if(str[0] >= 'a' && str[0] <= 'z')
				str[0] = 'A' + str[0] - 'a';
			phoneBook.DeleteAbonent(str);
			break;
		case 3: // поиск телефона заданного абонента
			cout << "-- поиск абонента ----" << endl;
			cout << "Введите имя:";
			cin >> str;
			if(str[0] >= 'a' && str[0] <= 'z') str[0] = 'A' + str[0] - 'a';
			if(!phoneBook.FindAbonent(str, i))
				cout << "Абонента не существует" << endl;
			else cout << "Телефон - " << i.GetPhone() << endl;
			break;
		case 4: // печать телефонной книги
			cout << endl << "- Распечатка телефонной книги -" << endl;
			cout << phoneBook << endl;
			break;
		case 5:  return; // выход из приложения
		}
	}
}