#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct node
{
	char data;
	struct node *left, *right;
}node;

typedef struct head
{
	node *root;
}head;

typedef struct stack
{
	node *s[MAX];
	int tos;
}stack;

void push(stack *t, node *ele)
{
	t -> s[++t -> tos] = ele;
}

node *pop(stack *t)
{
	t -> tos--;
	return(t -> s[t -> tos + 1]);
}

int isoperand(char ch)
{
	return(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z');
}

void inorder(node *x)
{
	if(x != NULL)
	{
		inorder(x -> left);
		printf("%c ", x -> data);
		inorder(x -> right);
	}
}

void preorder(node *x)
{
	if(x != NULL)
	{
		printf("%c ", x -> data);
		preorder(x -> left);
		preorder(x -> right);
	}
}

void postorder(node *x)
{
	if(x != NULL)
	{
		postorder(x -> left);
		postorder(x -> right);
		printf("%c ", x -> data);
	}
}

node *construct(char post[])
{
	stack x;
	int i, l = strlen(post);
	x.tos = -1;
	for(i = 0; i < l; i++)
	{
		node *p;
		p = (node*)malloc(sizeof(node));
		p -> data = post[i];
		p -> left = p -> right = NULL;
		if(isoperand(post[i]))
			push(&x, p);
		else
		{
			p -> right = pop(&x);
			p -> left = pop(&x);
			push(&x, p);
		}
	}
	return(pop(&x));
}

void main()
{
	head x;
	char postfix[MAX];
	printf("Enter Postfixed Expression: ");
	gets(postfix);
	x.root = construct(postfix);
	inorder(x.root);
	printf("\n");
	preorder(x.root);
	printf("\n");
	postorder(x.root);
	printf("\n");
}
