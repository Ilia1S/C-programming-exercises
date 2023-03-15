// Требуется реализовать функцию, которая анализирует данный список
// и возвращает сколько всего памяти используется. 
// Адрес хранится в поле address, поле size - соответствующий размер 
// данного блока. Если список пустой, то функция должна возвращать NULL.

#include <stdio.h>

typedef struct list 
{
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
}list;

size_t totalMemoryUsage(list *head);

int main(void)
{
	totalMemoryUsage(&list);
	return 0;
}

size_t totalMemoryUsage(list *head)
{
	size_t sizeTotal = 0;
	for (; head; head = head->next)
	{
		sizeTotal += head->size;
	}
	return sizeTotal;
}
