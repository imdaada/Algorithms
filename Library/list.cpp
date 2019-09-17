#include <stdlib.h>
#include "list.h"

struct ListItem
{
	Data data;
	ListItem *next;
};

struct List
{
	ListItem *head;
	ListItem *tail;
};

List *list_create()
{
	List *list = new List;
	//ListItem *tmp = new ListItem;
	//tmp->next = NULL;
	//list->head = tmp;
	//list->tail = tmp;
	list->head = NULL;
	list->tail = NULL;
    return list;
}

void list_delete(List *list)
{
	while (list->head != NULL)
	{
		ListItem *tmp;
		tmp = list->head;
		list->head = list->head->next;
		delete tmp;
	}
	ListItem *tmp = list->head;
	delete tmp;
	delete list;
}

ListItem *list_first(List *list)
{
	ListItem *tmp = list->head;
	return tmp;
}

Data list_item_data(const ListItem *item)
{
	Data a;
	a = item->data;
    return a;
}

ListItem *list_item_next(ListItem *item)
{
	ListItem *temp;
	temp = item->next;
    return temp;
}

ListItem *list_item_prev(ListItem *item)
{
    return item;
}

ListItem *list_insert(List *list, Data data)
{
	if (list->head == NULL)
	{
		ListItem *temp = new ListItem;
		list->head = temp;
		list->tail = temp;
		temp->data = data;
		temp->next = NULL;
		return temp;
	}
	else {
		ListItem *a = new ListItem;
		a->next = list->head;
		a->data = data;
		list->head = a;
		return a;
	}
    
}

ListItem *list_insert_after(List *list, ListItem *item, Data data)
{
	ListItem *tmp = new ListItem;
	ListItem *mp = list->head;
	if (mp == item);
	else {
		while (mp->next != item)
		{
			mp = mp->next;
		}
	}
	tmp->data = data;
	tmp->next = item;
	if (list->head == item) {
		list->head = tmp;
	}
	else {
		mp->next = tmp;
	}
    return tmp;
}

ListItem *list_erase(List *list, ListItem *item)
{
	if (item == list->head)
	{
		ListItem *tmp = list->head;
		list->head = tmp->next;
		ListItem *mp = new ListItem;
		*mp = *tmp;
		delete tmp;
		return mp;
	}
	else {
	if (item->next == NULL)
	{
		ListItem *tmp = list->head;
		ListItem *mp = new ListItem;
		*mp = *tmp;
		list->head = NULL;
		delete tmp;
		return mp;
	}
		
		ListItem *tmp = list->head;
		while (tmp->next != item)
		{
			tmp = tmp->next;
		}
		ListItem *mp = new ListItem;
		*mp = *item;
		tmp->next = item->next;
		delete item;
		return mp;
	}
    
}

ListItem *list_erase_next(List *list, ListItem *item)
{
	if (item == list->head->next)
	{
		ListItem *tmp = list->head;
		list->head = tmp->next;
		ListItem *mp = new ListItem;
		*mp = *tmp;
		delete tmp;
		return mp;
	}
	else {
		ListItem *tmp = list->head;
		while (tmp->next->next != item)
		{
			tmp = tmp->next;
		}
		ListItem *mp = new ListItem;
		*mp = *tmp->next;
		tmp->next = item->next;
		tmp = tmp->next;
		delete tmp;
		return mp;
	}
}
