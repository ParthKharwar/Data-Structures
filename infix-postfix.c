#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct stack
{
	char s[MAX];
	int tos;
}stack;

void push(stack *t, char ele)
{
	t -> s[++t -> tos] = ele;
}

int isempty(stack *t)
{
	return(t -> tos == -1);
}

int stacktop(stack *t)
{
	return(t -> s[t -> tos]);
}

char pop(stack *t)
{
	char z;
	z = t -> s[t -> tos];
	t -> tos--;
	return z;
}

int ipr(char ch)
{
	switch(ch)
	{
		case '(': return 3;
		case '*':
		case '/': return 2;
		case '+':
		case '-': return 1;
	}
	return -1;
	}

	int rpr(char ch)
	{
	switch(ch)
	{
		case '(': return 0;
		case '*':
		case '/': return 2;
		case '+':
		case '-': return 1;
	}
	return -1;
}

int isoperand(char ch)
{
	if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
		return 1;
	else
		return 0;
}

void convert(char in[], char post[])
{
	stack x;
	int i, l = strlen(in), k = 0;
	char ele;
	x.tos = -1;

	for (i = 0; i < l; i++)
	{
		if (in[i] == '(')
			push(&x, in[i]);
		else if (in[i] == ')')
		{
			while(stacktop(&x) != '(')
				post[k++] = pop(&x);
			pop(&x);
		}
		else if(isoperand(in[i]))
			post[k++] = in[i];
		else if(isempty(&x))
			push(&x, in[i]);
		else if (ipr(in[i]) > rpr(stacktop(&x)))
			push(&x, in[i]);
		else
		{
			while (ipr(in[i]) <= rpr(stacktop(&x)) && isempty(&x) == 0)
				post[k++] = pop(&x);
			push(&x, in[i]);
		}
	}
	while(isempty(&x) == 0)
		post[k++] = pop(&x);
	post[i] = '\0';
}

void main()
{
	char in[MAX], post[MAX];
	printf("Enter an Infixed Expression: ");
	gets(in);
	convert(in, post);
	printf("Postfixed Expression: %s", post);
}
