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

char pop(stack *t)
{
	char z;
	if(isempty(t))
		return -1;
	z = t -> s[t -> tos];
	t -> tos--;
	return z;
}

int check(char in[])
{
	stack x;
	char ch;
	int i, l = strlen(in);
	x.tos = -1;

	for(i = 0; i < l; i++)
	{
		if(in[i] == '(' || in[i] == '{' || in[i] == '[')
			push(&x, in[i]);
		else if(in[i] == ')' || in[i] == '}' || in[i] == ']')
		{
			if(isempty(&x))
				return 0;
			ch = pop(&x);
			switch(in[i])
			{
				case ')': if(ch != '(')
									return 0;
									break;
				case '}': if(ch != '{')
									return 0;
									break;
				case ']': if(ch != '[')
									return 0;
									break;
				default: return 0;
			}
		}
	}
	if(isempty(&x))
		return 1;
	else
		return 0;
}

void main()
{
	char eqn[MAX];

	printf("Enter an Infixed Equation: ");
	gets(eqn);

	if(check(eqn))
		printf("Equation Valid");
	else
		printf("Equation Invalid");
}
