#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 1024
#define TRUE 1
#define FALSE 0

//Gobal variables
double *values;
int charTop;
char *variables, charStack[SIZE];
typedef struct stack
{
	double data;
	struct stack *next;
} stack;


//Function prototypes

int findVariables(char*);
int isExist(char, char*);
int lookup(char, char*);

double reversePolish(char*);
void push(stack**, double);
double pop(stack**);
double eval(char, stack**);


void infixToPostfix(char*, char*);
void charPush(char);
char charPop();
int is_operator(char);
int precedence(char);