#ifndef LIST_H
#define LIST_H

/**
 * struct List - doubly linked list node
 * @str: malloc'ed string
 * @prev: pointer to the previous node
 * @next: pointer to the next node
 */
typedef struct List
{
    char *str;
    struct List *prev;
    struct List *next;
} List;

List *add_node_begin(List **list, char *str);
List *add_node_end(List **list, char *str);

#endif /* LIST_H */
