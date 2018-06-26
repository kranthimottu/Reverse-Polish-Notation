#include "Header.h"

void main()
{
	char *infix, *postfix;
	int count, i;
	double result;

	infix = (char*)malloc(sizeof(char)*SIZE + 1);
	printf("Please type your formal expression:");
	fgets(infix, SIZE, stdin);

	count = findVariables(infix);

	printf("Your expression has %d parameters. ", count);
	for (i = 0; i < count; i++)
	{
		printf("%c", variables[i]);
		if (i == count - 2)
			printf(" and ");
		else if (i < count - 2)
			printf(", ");
	}
	printf("\n");

	values = (double*)malloc(sizeof(double)*count);
	for (i = 0; i < count; i++)
	{
		printf("Please give an integer value for %c: ", variables[i]);
		scanf("%lf", &values[i]);
	}

	postfix = (char*)malloc(sizeof(char)*strlen(infix) + 1);
	infixToPostfix(infix, postfix);

	result = reversePolish(postfix);

	printf("Processing (");
	for (i = 0; i < strlen(infix); i++)
	{
		if (isalpha(infix[i]))
		{
			printf("%d", (int)values[lookup(infix[i],variables)]);
		}
		else
		{
			printf("%c", infix[i]);
		}
	}
	printf(" using Reverse Polish Notation algorithm\n");
	printf("Result: %lf\n", result);

	system("pause");
}