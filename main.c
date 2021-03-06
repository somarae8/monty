#include "monty.h"
#include <stdio.h>
stack_t *head = NULL;
/**
 * main - Entry Point
 * @argc: Number of command line arguments.
 * @argv: An array containing the arguments.
 * Return: Always Zero.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	freen();
	return (0);
}
/**
 * push - pushes an element to the stack.
 * @node: node
 * @line: Line number of the instruction
 */
void push(stack_t **node, unsigned int line)
{
	stack_t *temp;
	(void)line;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	temp = head;
	head = *node;
	head->next = temp;
	temp->prev = head;
}
/**
 * pall - prints all the values on the stack,
 * starting from the top .
 * @stack: double pointer to linked list
 * @line: Line number
 */
void pall(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	temp = *stack;
	(void)line;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
#include "monty.h"
/**
 * freen - Function to free the list
 * Return: Void
 */
void freen(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
#include <stdio.h>
/**
 * creat_nod - Creates a node.
 * @n: Value to the node
 * Return: On sucess -> pointer to the node. On failure  NULL.
 */
stack_t *creat_nod(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		freen();
		exit(EXIT_FAILURE);
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;
	return (new_node);
}

