#include "monty.h"

/**
* free_mode - function that frees a doubly linked list
* @head: head pointer to the stack
*
* Return: always 0
*/
void free_mode(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
* f_mode - function that prints the top
* @head: head of stack
* @counter: line count
*
* Return: always 0
*/
void f_mode(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
