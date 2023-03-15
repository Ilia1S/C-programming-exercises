// Требуется реализовать функцию, которая в данном списке находит 
// адрес блока памяти занимающий больше всего места. 
// Адрес хранится в поле address, поле size - соответствующий размер 
// данного блока. Если список пустой, то функция должна возвращать NULL.
// Если есть несколько таких блоков, то вернуть адрес любого из них. 

#include <stdio.h>

typedef struct list 
{
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
}list;

void * findMaxBlock(list *head);

int main(void)
{
	findMaxBlock(&list);
	return 0;
}

void * findMaxBlock(list *head)
{
	size_t max = 0;
	void *maxAddress = NULL;
	for (; head; head = head->next)
	{
		if (head->size > max)
		{
			max = head->size;
			maxAddress = head->address;
		}
	}
	return maxAddress;
}
