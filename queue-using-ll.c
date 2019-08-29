#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct head
{
	node *start;
}head;

void insert(head *t, int ele)
{
	node *p, *q;
	int i;
	p = (node *)malloc(sizeof(node));
	p -> data = ele;
	p -> next = NULL;
	if(t -> start == NULL)
	{
		t -> start = p;
		return;
	}
	q = t -> start;
	if(p -> data > q -> data)
	{
		p -> next = t -> start;
		t -> start = p;
	}
	else
	{
		while(q -> next != NULL)
		{
			if(p-> data > q -> next -> data)
				break;
			else
				q = q -> next;
		}
		p -> next = q -> next;
		q -> next = p;
	}
}

int delete1(head *t)
{
	node *p;
	if(t -> start == NULL)
	{
		printf("Queue Underflow\n");
		return -1;
	}
	p = t -> start;
	t -> start = t -> start -> next;
	return ( p -> data );
}

int queuefront(head *t)
{
	return(t -> start -> data);
}

void display(head *t)
{
	node *q;
	if(t -> start == NULL)
	{
		printf("Queue Empty\n");
		return;
	}
	q = t -> start;
	printf("Queue: ");
	while(q != NULL)
	{
		printf("%d ", q -> data);
		q = q -> next;
	}
	printf("\n");
}

void main()
{
	head x;
	int ele, ch;
	x.start = NULL;

	while(1)
	{
		printf("\nMENU: 1. Insert  2. Delete  3. Queue Front  4. Display  5. Exit\n");
		printf("Choice: ");
		scanf("%d", &ch);

		if(ch == 5)
			break;

		switch(ch)
		{
			case 1: printf("Enter Element to be Inserted: ");
			        scanf("%d", &ele);
			        insert(&x, ele);
			        display(&x);
			        break;
			case 2: if(x.start == NULL)
								printf("Queue Underflow\n");
							else
			        {
								ele = delete1(&x);
								printf("Deleted Element: %d\n", ele);
			        }
			        display(&x);
			        break;
			case 3: if(x.start == NULL)
								printf("Queue Empty\n");
			        else
			        {
								ele = queuefront(&x);
								printf("Queue Front Element: %d\n", ele);
			        }
			        break;
			case 4: display(&x);
			        break;
			default:printf("Invalid Choice\n");
		}
	}
}
