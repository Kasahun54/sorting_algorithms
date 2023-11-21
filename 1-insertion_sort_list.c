#include "sort.h"
/**
  * insertion_sort_list - doubly linked list insertion sort
  * @list: point to the head of linked list
  * 
  * Return: Nothing
  */
void insertion_sort_list(listint_t **list)
{
	size_t len;
	listint_t *cursor, *tmp;

	len = dlistint_len((const listint_t *) *list);
	if (len < 2)
		return;
	cursor = (*list)->next;
	while (cursor != NULL)
	{
		tmp = cursor;
		while (tmp->prev != NULL)
		{
			if (tmp->prev->n > tmp->n)
			{
				tmp = swap(list, tmp, tmp->prev);
				print_list((const listint_t *) *list);
				continue;
			}
			tmp = tmp->prev;
		}
		cursor = cursor->next;
	}
}

/**
  * dlistint_len - count nodes in doubly linked list
  * @h: point to the first node
  * 
  * Return: number of nodes
  */
size_t dlistint_len(const listint_t *h)
{
	listint_t *tmp;
	size_t count = 0;

	if (h == NULL)
		return (count);
	tmp = (listint_t *)h;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

/**
  * swap - exchange nodes in a linked list
  * @head: address of pointer
  * @cursor1: first node
  * @cursor2: previous to first node
  * 
  * Return: pointer to the first node
  */
listint_t *swap(listint_t **head, listint_t *cursor1, listint_t *cursor2)
{
	listint_t *c1_next, *c2_prev;

	c1_next = cursor1->next;
	c2_prev = cursor2->prev;
	if (*head == cursor2)
		*head = cursor1;
	else
		c2_prev->next = cursor1;
	cursor1->next = cursor2;
	cursor1->prev = c2_prev;
	if (c1_next != NULL)
		c1_next->prev = cursor2;
	cursor2->next = c1_next;
	cursor2->prev = cursor1;
	return (cursor1);
}
