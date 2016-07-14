#include "List.h"

List:: List() 
{
	head=NULL;
}

List:: ~List()
{
	Element * cur, *help;
	cur = head;
	while(cur != NULL)
	{
		help = cur->GetNext();
		delete cur;
		cur = help;
	}
}

void List:: PushAbonent(char* f, char* p)
{
	Element *last = new Element (f,p);
	if (head == NULL) head = last;
	else
	{
		Element* tmp = head;
		while (tmp->next != NULL)
			tmp = tmp->GetNext();
		tmp->SetNext(last);
	}
}

void List::DeleteAbonent(char* f)
{
	Element* current, *help;
	while(head != NULL && head->IsAbonent(f))
	{
		help = head;
		head = head -> GetNext();
		delete help;
	}
	if(head != NULL)
	{
		current = head;
		while(current->GetNext() != NULL)
		{
			help = current->GetNext();
			if(help->IsAbonent(f))
			{
				current -> SetNext(help->GetNext());
				delete help;
			}
			else current = current->GetNext();
		}
	}
}

bool List::FindAbonent(char* f, Abonent& ab)
{
	if (head == NULL) return false;
	Element* tmp = head;
	while (tmp!= NULL)
	{
		if (tmp->IsAbonent(f))
		{
			ab.SetPhone(tmp->GetPhone());
			return true;
		}
		tmp = tmp->GetNext();
	}
	return false;
}