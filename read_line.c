#include "monty.h"
#include <stdio.h>
/**
 * read_line - tokenize the lines of file.
 * @strline: content of file.
 * @line: line of file.
 */
void read_line(char *strline, int line)
{
	char *action = NULL;
        action = strtok(strline, "\n ");
	get_op_code(action,line);
}
