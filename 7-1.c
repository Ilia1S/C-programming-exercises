// Дана строка, состоящая из английских букв и пробелов. В конце строки символ точка.
// Все слова разделены одним пробелом. Необходимо составить из слов односвязный список
// и упорядочить по алфавиту. Список необходимо удалить в конце программы

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
   char word[20];
   struct list *next;
};

void add_to_list(struct list **);
void swap_elements(struct list **);
void print_list(struct list *);
void delete_list(struct list **);

int main(void)
{
    struct list *head = NULL;
    add_to_list(&head);
    swap_elements(&head);
    print_list(head);
    delete_list(&head);
    return 0;
}
void add_to_list(struct list **head)
{
    char *string = calloc(1001, sizeof(char));
    for (int i=0; (string[i]=getchar())!='.'; i++);
    string[strlen(string)-1] = '\0';
    char *astr = calloc(20, sizeof(char));
    struct list *new = calloc(1, sizeof(struct list));
    astr = strtok(string, " ");
    strcpy(new->word, astr);
    new->next =  *head;
    *head = new;
    while((astr = strtok(NULL, " ")) != NULL)
    {
        new = calloc(1, sizeof(struct list));
        strcpy(new->word, astr);
        new->next = *head;
        *head = new;
    }
    free(string);
    free(astr);
}
void swap_elements(struct list **head)
{
    int swapped = 0;
    char *tmp = calloc(20, sizeof(char));
    struct list *sorted;
    do
    {
        swapped = 0;
        sorted = *head;
        while (sorted->next)
        {
            if (strcmp(sorted->word, sorted->next->word) > 0)
            {
                swapped = 1;
                strcpy(tmp, sorted->word);
                strcpy(sorted->word, sorted->next->word);
                strcpy(sorted->next->word, tmp);
            }
            sorted = sorted->next;
        }
    }
    while (swapped);
    free(tmp);
}
void print_list(struct list *head)
{
    while (head)
    {
        printf("%s", head->word);
        if (head->next)
            printf(" ");
        head = head->next;
    }
    printf("\n");
}
void delete_list(struct list **head)
{
    struct list *temp;
    temp = *head;
    free(temp);
}
