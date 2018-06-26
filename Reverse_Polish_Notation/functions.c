#include "Header.h"

void push(stack **head, double value)
{
	stack* node = malloc(sizeof(stack));

	if (node == NULL) {
		fputs("Error: Out of memory\n", stderr);
		exit(1);
	}
	else {
		node->data = value;
		node->next = *head;
		*head = node;
	}
}


double pop(stack **head)
{
	if (*head == NULL) {
		fputs("Error: bottom of stack!\n", stderr);
		system("pause");
		exit(1);
	}
	else {
		stack* top = *head;
		double value = top->data;
		*head = top->next;
		free(top);
		return value;
	}
}

double eval(char op, stack** head)
{
	double temp;
	switch (op) {
	case '+': return pop(head) + pop(head);
	case '*': return pop(head) * pop(head);
	case '-': temp = pop(head); return pop(head) - temp;
	case '/': temp = pop(head); return pop(head) / temp;
	}
}

int findVariables(char* input)
{
	int count = 0, i;
	variables = (char*)malloc(sizeof(char) + 1);

	for (i = 0; i < strlen(input); i++)
	{
		if (isalpha(input[i]))
		{
			if (isExist(input[i],variables) != TRUE)
			{
				if (count != 0)
					variables = (char*)realloc(variables, sizeof(char)*strlen(variables) + 1);

				variables[count] = input[i];
				count++;
				variables[count] = '\0';
			}
		}
	}

	return count;
}

double reversePolish(char* postfix)
{
	int i, j = 0;
	stack* head = NULL;

	for (i = 0; i < strlen(postfix); i++)
	{
		if (isalpha(postfix[i]))
		{
			j = lookup(postfix[i], variables);
			push(&head, values[j]);
		}
		else if (isdigit(postfix[i]))
		{
			int k = 0, temp = 0;
			do
			{
				if (k == 0)
					temp = postfix[i] - 48;
				else
					temp = (temp * 10) + (postfix[i + k] - 48);
				k++;
			} while (isdigit(postfix[i+k]));

			i += --k;

			push(&head, temp);
		}
		else if (is_operator(postfix[i]) == TRUE)
		{
			push(&head, eval(postfix[i], &head));
		}
	}

	return head->data;
}

int isExist(char a, char* charPtr)
{
	int result = FALSE;
	for (int i = 0; i < strlen(charPtr); i++)
	{
		if (a == charPtr[i])
		{
			result = TRUE;
			break;
		}
	}
	return result;
}

int lookup(char a, char* charPtr)
{
	int i = 0;
	for (i = 0; i < strlen(charPtr); i++)
	{
		if (a == charPtr[i])
		{
			break;
		}
	}
	return i;
}