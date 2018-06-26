#include "Header.h"

void infixToPostfix(char* infix, char* postfix)
{
	int i = 0, j = 0;
	char x;
	charTop = -1;
	
	charPush('(');
	infix[strlen(infix) - 1] = ')';
	infix[strlen(infix)] = '\0';

	for (int i = 0; i < strlen(infix); i++)
	{
		if (infix[i] == '(' || is_operator(infix[i]) == TRUE)
		{
			charPush(infix[i]);
		}
		else if (isalpha(infix[i]))
		{
			postfix[j] = infix[i];
			j++;
		}
		else if (isdigit(infix[i]))
		{
			int k = 0;
			do
			{
				postfix[j] = infix[i + k];
				j++;
				k++;
			} while (isdigit(infix[i + k]));
			postfix[j++] = ' ';
			i += --k;
		}
		else if (infix[i] == ')')
		{
			x = charPop();
			while (x != '(')
			{
				postfix[j] = x;
				j++;
				x = charPop();
			}
		}
	}
	postfix[j] = '\0';
}

void charPush(char item)
{
	if (charTop >= SIZE - 1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		charTop = charTop + 1;
		charStack[charTop] = item;
	}
}

char charPop()
{
	char item;

	if (charTop < 0)
	{
		printf("stack under flow: invalid infix expression");
		system("pause");
		exit(1);
	}
	else
	{
		item = charStack[charTop];
		charTop = charTop - 1;
		return item;
	}
}

int is_operator(char symbol)
{
	if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int precedence(char symbol)
{
	if (symbol == '^')
	{
		return 3;
	}
	else if (symbol == '*' || symbol == '/')
	{
		return 2;
	}
	else if (symbol == '+' || symbol == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
